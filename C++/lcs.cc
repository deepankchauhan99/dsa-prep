#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> lcs(string text1,string text2){
        int n1=text1.size();
        int n2=text2.size();

        vector<int>dp(n2,0);
        // vector<int>curr(n2,0);
        // int res=0;
        for(int i=0;i<n1;i++){
            int prev=0;
            for(int j=0;j<n2;j++){
                int temp=dp[j];
                int equal=0;
                if(text1[i]==text2[j]){
                    equal=1;
                    if(i>0&&j>0)equal+=prev;
                }
                int notequal=0;
                int ne1=(i>0)?dp[j]:0;
                int ne2=(j>0)?dp[j-1]:0;
                notequal=max(ne1,ne2);
                dp[j]=max(notequal,equal);
                prev=temp;
            }
            // dp=curr;
        }
        return dp;
    }

    string longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<int>verticle=lcs(text2,text1);
        vector<int>horizontal=lcs(text1,text2);
        for(auto i:verticle)cout<<i;
        cout<<endl;
        for(auto i:horizontal)cout<<i;
        cout<<endl;
        cout<<endl;

        string res="";
        // int chnge=0;
        // for(int i=0;i<n2;i++){
        //     if(dp[i]!=chnge){
        //         res+=text2[i];
        //         chnge=dp[i];
        //     }
        //     cout<<dp[i];
        // }
        // cout<<endl;
        // reverse(res.begin(),res.end());
        int sz=horizontal.back();
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(verticle[i]==horizontal[j]&&text1[i]==text2[j])res+=text1[i];
                if(sz==res.size())return res;
            }
        }
        return res;
    }

};

int main() {

    Solution sol;

    vector<pair<string, string>> testcases = {

        {"abcde", "ace"},
        {"abc", "abc"},
        {"abc", "def"},
        {"AGGTAB", "GXTXAYB"},
        {"aaaa", "aa"},
        {"", "abc"},
        {"abcdef", "fbdamn"}

    };

    for(int i = 0; i < testcases.size(); i++) {

        string text1 = testcases[i].first;
        string text2 = testcases[i].second;

        string ans = sol.longestCommonSubsequence(text1, text2);

        cout << "Test Case " << i + 1 << "\n";

        cout << "Text1 : " << text1 << "\n";
        cout << "Text2 : " << text2 << "\n";

        cout << "LCS string : " << ans << "\n";

        cout << "--------------------------\n";
    }

    return 0;
}