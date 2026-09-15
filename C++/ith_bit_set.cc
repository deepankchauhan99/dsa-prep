#include<iostream>

using namespace std;

int main(){
    int a = 31;
    int bit = 2;

    // check if the a's bit is set or not
    // cout<<(1<<0)<<endl;
    cout<<((a&(1<<bit))?"is set":"not set")<<endl;

    // set the ith bit 
    cout<<(a|(1<<bit))<<endl;

    //clear the ith bit
    cout<<(a&(~(1<<bit)))<<endl;

    //toggle the ith bit
    cout<<(a^(1<<bit))<<endl;

    //remove last set bit
    cout<<(a&(a-1))<<endl;

    //count no. of set bits in a given number
    int a2=a;

    int cnt=0;
    while(a>1){
        cnt+=a&1;  //always counts set bits at 0th bit place 
        a>>=1;    //same as a/2
        //bit operations are faster thans division modulo mutiplcation 
    }
    if(a==1)cnt++;
    cout<<cnt<<endl;
    a=a2;
    cnt=0;

    while(a){
        a&=(a-1);  // it removes last set bit every time
        cnt++;
    }
    cout<<cnt<<endl;

    cout<<"xorr"<<endl;

    // cout<<(10^2^5^0)<<endl;


    // cout<<(~13^~10)<<endl;

    // rightmost unset bit 
    // cout<<(-(23^(-23)))<<endl;
    // 1 1 0 1
    // 1 0 0 1 1
    // 1 0 1 0 0
}