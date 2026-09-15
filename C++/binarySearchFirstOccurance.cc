#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        // TODO: Implement logic
        int i=0;
        int j=nums.size()-1;
        int mid;
        int res=-1;
        while(i<=j){
            mid=i+(j-i)/2;
            if(target<=nums[mid]){
                if(target==nums[mid])res=mid;
                j=mid-1;
            }else i=mid+1;
        }
        return res;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        // TODO: Implement logic
        int i=0;
        int j=nums.size()-1;
        int mid;
        int res=-1;
        while(i<=j){
            mid=i+(j-i)/2;
            if(target>=nums[mid]){
                if(target==nums[mid])res=mid;
                i=mid+1;
            }else j=mid-1;
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Multiple occurrences
    vector<int> nums1 = {1,2,2,2,3,4,5};
    int target1 = 2;
    int a=sol.firstOccurrence(nums1, target1);
    int b=sol.lastOccurrence(nums1, target1);
    cout << "Test 1 First: " << sol.firstOccurrence(nums1, target1) << endl; // Expected: 1
    cout << "Test 1 Last: " << sol.lastOccurrence(nums1, target1) << endl;  // Expected: 3
    cout << "Test 1 Result: "<< ((a==1&&b==3)?"passed":"failed")<<endl;

    // Test Case 2: Single occurrence
    vector<int> nums2 = {1,2,3,4,5};
    int target2 = 3;
    a=sol.firstOccurrence(nums2, target2);
    b=sol.lastOccurrence(nums2, target2);
    cout << "Test 2 First: " << sol.firstOccurrence(nums2, target2) << endl; // Expected: 2
    cout << "Test 2 Last: " << sol.lastOccurrence(nums2, target2) << endl;  // Expected: 2
    cout << "Test 2 Result: "<< ((a==2&&b==2)?"passed":"failed")<<endl;


    // Test Case 3: Target not present
    vector<int> nums3 = {1,2,3,4,5};
    int target3 = 6;

    a=sol.firstOccurrence(nums3, target3);
    b=sol.lastOccurrence(nums3, target3);
    cout << "Test 3 First: " << sol.firstOccurrence(nums3, target3) << endl; // Expected: -1
    cout << "Test 3 Last: " << sol.lastOccurrence(nums3, target3) << endl;  // Expected: -1
    cout << "Test 3 Result: "<< ((a==-1&&b==-1)?"passed":"failed")<<endl;


    // Test Case 4: All elements same
    vector<int> nums4 = {2,2,2,2,2};
    int target4 = 2;

    a=sol.firstOccurrence(nums4, target4);
    b=sol.lastOccurrence(nums4, target4);
    cout << "Test 4 First: " << sol.firstOccurrence(nums4, target4) << endl; // Expected: 0
    cout << "Test 4 Last: " << sol.lastOccurrence(nums4, target4) << endl;  // Expected: 4
    cout << "Test 4 Result: "<< ((a==0&&b==4)?"passed":"failed")<<endl;

    return 0;
}
//
//  binarySearchFirstOccurance.cc
//  
//
//  Created by Sanskar Masurkar on 03/05/26.
//

