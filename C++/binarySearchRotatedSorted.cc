#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // this search with multiple same values and returns lowest index of target r=mid-1
    // for upper bound or largest index for target nums change l=mid+1;

    // in each iteration only one operation is performed thus if ifelse else for only one operation at a time
    // avoid equals to nums[mid] for moving left or right 
    // if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
    // l++; r--;
    // continue;
    // }
    // this removes duplicate ambiguity if array is full of only one element multiple times and this operation should once in each iteration

    int search(vector<int>& nums, int target) {
        // TODO: Implement your logic here
        int l=0;
        int r=nums.size()-1;
        int mid;
        int res=-1;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){res=mid;l=mid+1;}
            else if(nums[l]<=nums[mid]){
                if(nums[l]<=target&&target<nums[mid])r=mid-1;
                else l=mid+1;
            }else{
                if(nums[mid]<target&&target<=nums[r])l=mid+1;
                else r=mid-1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Normal rotated array
    vector<int> nums1 = {4,4,4,5,6,7,0,1,2};
    int target1 = 4;
    cout << "Test 1 Output: " << sol.search(nums1, target1) << endl;
    // Expected: 2

    // Test Case 2: Target not present
    vector<int> nums2 = {4,4,4,5,5,6,6,6,7,7,8,8,9,9,9,10,10,0,0,1,2,2,2,3};
    int target2 = 6;
    int ans2=sol.search(nums2, target2);
    cout << "Test 2 Output: " << ans2 << endl;
    for(int i=0;i<nums2.size();i++){
        if(ans2==i){
            cout<<i<<"-"<<nums2[i]<<"<- ans bro"<<endl;
        }
        else {cout<<i<<"-"<<nums2[i]<<endl;}
    }
    // Expected: 7 last occurence

    // Test Case 3: Single element
    vector<int> nums3 = {1};
    int target3 = 0;
    cout << "Test 3 Output: " << sol.search(nums3, target3) << endl;
    // Expected: -1

    // Test Case 4: Not rotated (pure sorted array)
    vector<int> nums4 = {8,8,9,9,9,0,1,2,3,4,5,6,7};
    int target4 = 9;
    cout << "Test 4 Output: " << sol.search(nums4, target4) << endl;
    // Expected: 2

    return 0;
}
//
//  binarySearchRotatedSorted.cc
//  
//
//  Created by Sanskar Masurkar on 03/05/26.
//

