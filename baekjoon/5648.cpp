/*
[역원소 정렬] 
- date: 24.10.24
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    long long num[1000001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        reverse(str.begin(), str.end());
        num[i] = stol(str);
    }

    sort(num, num+n);
    for(int i = 0; i < n; i++){
        cout << num[i] << '\n';
    }

    return 0;
}