#include<iostream>
#include<vector>

using namespace std;

void findSubsequences(vector<int>& nums, int i, int n, vector<int> temp, vector<vector<int>>& res){
    if(i >= n){
    res.push_back(temp);
        return;
    }

    findSubsequences(nums, i + 1, n, temp, res);
    temp.push_back(nums[i]);
    findSubsequences(nums, i + 1, n, temp, res);
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 10;
    vector<int> temp;
     vector<vector<int>>res;
    int n = nums.size();
    findSubsequences(nums, 0, n, temp, res);
    cout<<"All Subsequences are: "<< res.size()<<endl;
    for(auto v: res){
        if(v.empty()){cout<<"{}"<<endl;continue;}
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;

}