#include<iostream>
#include<vector>

using namespace std;

struct segmenttree {
    vector<int> st;
    vector<int> lazy; // Added lazy array
    int n = 0;

    void init(int n) {
        this->n = n;
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0); // Initialize lazy array with 0
    }

    void build(int start, int end, int node, const vector<int>& v) {
        if (start == end) {
            st[node] = v[start];
            return;
        }
        int mid = start + (end - start) / 2;

        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }
    
    void build(const vector<int>& v) {
        build(0, v.size() - 1, 0, v);
    }

    // Helper to apply pending lazy updates to the current node and push to children
    void pushDown(int start, int end, int node) {
        if (lazy[node] != 0) {
            // Apply the pending update to the current node
            // (value * number of elements in the range)
            st[node] += lazy[node] * (end - start + 1);

            // If it's not a leaf node, push the lazy value to its children
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            // Clear the lazy value for the current node
            lazy[node] = 0;
        }
    }

    // Range Update (Adds 'val' to all elements in range [l, r])
    void update(int start, int end, int l, int r, int val, int node) {
        // 1. Resolve any pending updates before processing this node
        pushDown(start, end, node);

        // 2. No overlap
        if (l > end || r < start) {
            return;
        }

        // 3. Complete overlap
        if (l <= start && r >= end) {
            lazy[node] += val; // Stage the update
            pushDown(start, end, node); // Apply it immediately to this node
            return;
        }

        // 4. Partial overlap
        int mid = start + (end - start) / 2;
        update(start, mid, l, r, val, 2 * node + 1);
        update(mid + 1, end, l, r, val, 2 * node + 2);

        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void update(int l, int r, int val) {
        update(0, n - 1, l, r, val, 0);
    }

    // Range Query
    int query(int start, int end, int l, int r, int node) {
        // Resolve any pending updates before querying this node
        pushDown(start, end, node);

        // No overlap
        if (l > end || r < start) {
            return 0;
        }
        
        // Complete overlap
        if (l <= start && r >= end) {
            return st[node];
        }
        
        // Partial overlap
        int mid = start + (end - start) / 2;
        int res = query(start, mid, l, r, 2 * node + 1);
        res += query(mid + 1, end, l, r, 2 * node + 2);

        return res;
    }

    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    segmenttree tree;
    
    tree.init(v.size());
    tree.build(v);
    
    cout << "Initial sum [0, 4]: " << tree.query(0, 4) << endl; // 1+2+3+4+5 = 15
    
    // Add 10 to all elements in range [2, 4] (indexes 2, 3, 4)
    tree.update(2, 4, 10);
    
    cout << "Sum [0, 4] after adding 10 to [2, 4]: " << tree.query(0, 4) << endl; // 15 + (10*3) = 45
    cout << "Sum [2, 2] (index 2 only): " << tree.query(2, 2) << endl; // 3 + 10 = 13
    
    return 0;
}
