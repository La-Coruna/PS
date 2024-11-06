/*
[성적 평가] 
- date: 24.11.06
- url: https://softeer.ai/practice/6250
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> score[4];
    score[3].resize(N,0);
    for(int t = 0; t < 3; t++){
        score[t].resize(N,0);
        for(int i = 0; i < N; i++){
            cin >> score[t][i];
            score[3][i] += score[t][i];
        }
    }

    for(int t = 0; t < 4; t++){
        vector<int> scoreCurrent(score[t]);
        sort(scoreCurrent.begin(), scoreCurrent.end());
        // cout << "sorted score\n";
        // for(int e : scoreCurrent){
        //     cout << e << ' ';
        // }
        for(int i = 0; i < N; i++){
            int rank = (upper_bound(scoreCurrent.begin(), scoreCurrent.end(), score[t][i]) - scoreCurrent.begin());
            cout << N - rank + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}