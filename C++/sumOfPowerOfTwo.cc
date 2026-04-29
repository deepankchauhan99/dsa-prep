#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumToPowerOfTwo(int n){
        vector<int>power;
        while(n){
        int i=0;

            while(i>=0){
                if(pow(2,i)>n){break;}
                i++;
            }
            power.insert(power.begin(),pow(2,i-1));
            n=n-pow(2,i-1);
        }
        return power;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    vector<int> result = sol.sumToPowerOfTwo(n);

    cout << "Powers of 2 that sum to " << n << ": ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << (i < result.size() - 1 ? ", " : "");
    }
    cout << endl;

    return 0;
}