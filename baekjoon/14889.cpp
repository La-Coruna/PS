/* 
[스타트와 링크]
- date: 24.09.09
- 분류: Backtracking
 */
#include <bits/stdc++.h>
using namespace std;

int N, S, stat[20][20], canLeft = 0, res = 0x7fffffff;
bool isLeftTeam[20];

void func(int k){
    if(k == N){
        int l = 0, r = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(isLeftTeam[i]&&isLeftTeam[j]) l += stat[i][j];
                else if((!isLeftTeam[i])&&(!isLeftTeam[j])) r += stat[i][j];
            }
        }
        res = min(abs(l-r), res);
        return;
    }
    if(canLeft > 0){
        isLeftTeam[k] = true;
        canLeft--;
        func(k+1);
        isLeftTeam[k] = false;
        canLeft++;
    }
    if(canLeft > N - k - 1) return;
    func(k+1);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> stat[i][j];
    }

    canLeft = N/2;
    func(1);
    cout << res;

    return 0;
}