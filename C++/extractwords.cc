#include<sstream>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    getline(cin,s);

    // cin>>s;
    string a="";
    vector<string>res;
    for(auto c:s){
        if(c!=' '){
            a+=c;
        }
        else{
            if(a!=""){
                res.push_back(a);
                a="";
            }
        }
    }
    if(a!=""){
        res.push_back(a);
    }
    for(auto x:res){
        cout<<"word "<<x<<endl;}
    return 0;
}   