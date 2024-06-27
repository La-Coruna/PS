/* 
[하노이 탑 이동 순서]
- date: 24.06.27
- 분류: recursion

- 하노이탑 이동 횟수: 2^n+1
 */
#include <bits/stdc++.h>
using namespace std;
void func(int before, int after, int n){
    if(n==1){
        cout << before << ' ' << after << '\n';
        return;
    }
    func(before, 6-before-after, n-1);
    cout << before << ' ' << after << '\n';
    func(6-before-after, after, n-1);
    return;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    cout << (1<<N) - 1 << '\n';
    func(1,3,N);
    return 0;
}