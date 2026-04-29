#include<iostream>
#include<vector>    

using namespace std;

int main(){
    vector<int> nums = {1,2,2};
    int n = nums.size();
    vector<int> res;
    function<void(int, int)> subsetsum = [&](int i, int sum){
        if(i >= n){
            res.push_back(sum);
            return;
        }
        subsetsum(i+1, sum + nums[i]);
        subsetsum(i+1, sum);
    };
    subsetsum(0, 0);
    sort(res.begin(), res.end());
    for (int s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}