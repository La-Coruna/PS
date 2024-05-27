#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    int sex, grade;
    int students[2][6] = {0};
    int answer = 0;

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> sex >> grade;
        students[sex][grade-1]++;
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 6; j++){
            answer += ((students[i][j] + K - 1) / K);
        }
    }
    
    cout << answer;

    return 0;
}