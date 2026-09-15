#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rotationCount(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        int n = nums.size();

        while (i <= j) {
            // Case 1: Already sorted
            if (nums[i] <= nums[j]) return i;

            int mid = i + (j - i) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            // Case 2: Found minimum (pivot)
            if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
                return mid;

            // Decide direction
            if (nums[mid] <= nums[j]) {
                j = mid - 1; // go left
            } else {
                i = mid + 1; // go right
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {4,5,6,7,0,1,2};
    cout << "Test 1: " << sol.rotationCount(nums1) << endl; // Expected: 4

    // Test Case 2
    vector<int> nums2 = {1,2,3,4,5};
    cout << "Test 2: " << sol.rotationCount(nums2) << endl; // Expected: 0

    // Test Case 3
    vector<int> nums3 = {3,4,5,1,2};
    cout << "Test 3: " << sol.rotationCount(nums3) << endl; // Expected: 3

    // Test Case 4
    vector<int> nums4 = {2,1};
    cout << "Test 4: " << sol.rotationCount(nums4) << endl; // Expected: 1

    return 0;
}