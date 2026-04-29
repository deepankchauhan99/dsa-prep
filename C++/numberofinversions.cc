#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int>nums={2,3,8,6,1};
    int n=nums.size();
    int cnt=0;

    auto merge_sort=[&](auto self,int left,int right)->void{
            if(left>=right)return;
            int mid=left+(right-left)/2;

            self(self,left,mid);
            self(self,mid+1,right);

            int i=left,j=mid+1;
            vector<int>temp;
            while(i<=mid && j<=right){
                if(nums[i]<=nums[j]){
                    temp.push_back(nums[i]);
                    i++;
                }else{
                    cnt+= (mid - i + 1);
                    temp.push_back(nums[j]);
                    j++;
                }
            }
            while(i<=mid){
                temp.push_back(nums[i]);
                i++;
            }
            while(j<=right){
                temp.push_back(nums[j]);
                j++;
            }
            for(int k=0;k<temp.size();k++){
                nums[left+k]=temp[k];
            }
    };
        

    merge_sort(merge_sort,0,n-1);
    cout<<cnt<<endl;
        
    };

