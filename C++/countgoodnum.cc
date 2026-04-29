#include<iostream>
#include<vector>

using namespace std;

long long countGoodNumbers(long long n) {
    int mod = 1e9 + 7;

    long long even = (n + 1) / 2; 
    long long odd = n / 2;
    long long res = 1;
    for(long long i = 0; i < even; i++){
        res = (res * 5) % mod; 
    }
    for(long long i = 0; i < odd; i++){
        res = (res * 4) % mod;
    }
    return res;
}