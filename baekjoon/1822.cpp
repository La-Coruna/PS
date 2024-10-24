/*
[차집합] 
- date: 24.10.24
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int nA, nB, n;
    set<int> A;
    cin >> nA >> nB;
    while(nA--){
        cin >> n;
        A.emplace(n);
    }
    while(nB--){
        cin >> n;
        auto iter = A.find(n);
        if(iter != A.end()) A.erase(iter);
    }
    cout << A.size() << '\n';
    for(auto e: A){
        cout << e << ' ';
    }

    return 0;
}