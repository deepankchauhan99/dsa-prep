#include<iostream>
#include<vector>
#include<string>

using namespace std;


void findSubsequences(vector<int>& nums, int& xorsum, int i, int n, vector<int> temp){
    if(i >= n){
        temp.empty()?xorsum+=0:xorsum +=temp.back();
        return;
    }
    findSubsequences(nums, xorsum, i+1, n, temp);
    if (temp.empty())
    temp.push_back(nums[i]);
    else
    temp.back() ^= nums[i];
    findSubsequences(nums, xorsum, i+1, n, temp);
}

int main(){
    vector<int> nums = {1,3};
    int xorsum=0;
    vector<vector<int>> res;
    vector<int> temp;
    int n = nums.size();
    findSubsequences(nums, xorsum, 0, n, temp);
    cout<<xorsum<<endl;
    // for(auto v: res){
    //     if(v.empty()){cout<<"{}"<<endl;continue;}
    //     for(auto i: v){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;

}
