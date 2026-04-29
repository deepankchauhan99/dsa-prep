#include<iostream>
#include<set>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(8);
    s.insert(1);
    s.insert(3);

    cout << "Elements in the set: ";
    for (auto & i : s) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}