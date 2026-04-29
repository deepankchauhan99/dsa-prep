#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

unordered_map<string,string> parent;
unordered_map<string,int> rankk;

string findParent(string email){
    if(parent[email] == email){
        return email;
    }
    return parent[email] = findParent(parent[email]);
}

void unionByRank(string u, string v){
    string pu = findParent(u);
    string pv = findParent(v);

    if(pu == pv) return;

    if(rankk[pu] < rankk[pv]){
        parent[pu] = pv;
    }
    else if(rankk[pu] > rankk[pv]){
        parent[pv] = pu;
    }
    else{
        parent[pv] = pu;
        rankk[pu]++;
    }
}

vector<vector<string>> accountMerge(vector<vector<string>>& accounts){

    unordered_map<string,string> emailToName;

    for(auto &acc : accounts){
        string name = acc[0];
        for(int i=1;i<acc.size();i++){
            string email = acc[i];

            if(parent.find(email) == parent.end()){
                parent[email] = email;
                rankk[email] = 0;
            }

            emailToName[email] = name;
        }
    }

    for(auto &acc : accounts){
        for(int i=2;i<acc.size();i++){
            unionByRank(acc[i-1], acc[i]);
        }
    }

    unordered_map<string, vector<string>> groups;

    for(auto &it : parent){
        string email = it.first;
        string p = findParent(email);
        groups[p].push_back(email);
    }

    vector<vector<string>> res;

    for(auto &it : groups){
        string parentEmail = it.first;
        auto &emails = it.second;

        sort(emails.begin(), emails.end());

        vector<string> temp;
        temp.push_back(emailToName[parentEmail]); // correct name
        temp.insert(temp.end(), emails.begin(), emails.end());

        res.push_back(temp);
    }

    return res;
}

int main(){
    vector<vector<string>> accounts = {
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    vector<vector<string>> res = accountMerge(accounts);

    for(auto &acc : res){
        for(auto &s : acc){
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}