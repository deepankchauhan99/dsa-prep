#include<iostream>
#include<vector>

using namespace std;


void solve(string&s,int i,string sub,vector<string>&res){

    if(i==s.size()){
        res.push_back(sub);
        return;
    }

    solve(s,i+1,sub,res);
    solve(s,i+1,sub+s[i],res);

    return;
}

int main(){
    string s="abd";

    vector<string>res;
    solve(s,0,"",res);
    for(string ss:res){
        for(auto i:ss){
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}