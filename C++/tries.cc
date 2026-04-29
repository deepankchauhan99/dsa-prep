#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Trie{
    Trie*links[26];
    bool flag;

    Trie() {
        memset(links, 0, sizeof(links));
        flag = false;
    }

    bool contains(char c){
        return links[c-'a']!=nullptr;
    }

    void put(char c, Trie* node){
        links[c-'a']=node;
    }

    Trie* get(char c){
        return links[c-'a'];
    }
};

int main(){

    

}