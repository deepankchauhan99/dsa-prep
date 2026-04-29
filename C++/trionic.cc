#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i=1;
            if(nums[i - 1] < nums[i]) {
                while(i < nums.size() && nums[i - 1] < nums[i]){ cout<<i<<endl;i++;}
                if(i < nums.size() - 1) {
                    if(nums[i - 1] > nums[i]) {
                        while(i < nums.size() && nums[i - 1] > nums[i]){ cout<<i<<endl; i++;}
                        if(i < nums.size()) {
                            if(nums[i - 1] < nums[i]) {
                                return true;
                            }
                        }
                    }
                }
            }
        
        return false;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    if(sol.isTrionic(nums)) {
        cout << "YES - The array is Trionic." << endl;
    } else {
        cout << "NO - The array is not Trionic." << endl;
    }

    return 0;
}
