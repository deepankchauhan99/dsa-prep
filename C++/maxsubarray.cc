#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};

    int maxsum=INT_MIN;
    int sum=0;

    int l=0;
    int r=0;
    int templ=0;

    for(int i=0;i<nums.size();i++){
        if(sum==0){sum=nums[i];templ=i;}
        else sum+=nums[i];

        // maxsum=max(sum,maxsum);
        if(sum>maxsum){
            maxsum=sum;
            r=i;
            l=templ;
        }

        if(sum<0)sum=0;
    }

    for(int i=l;i<=r;i++){
        cout<<nums[i]<<endl;
    }
}