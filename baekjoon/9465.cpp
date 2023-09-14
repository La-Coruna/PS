/* 
date: 0815
깨달은점: 이전 값들이 현재 값들에게 어떻게 영향을 미치는지를 생각.
알고리즘 방식: 다른 행의 이전 열과 그 이전 열의 값 중 최대값을 가져와 현재 값과 더하여 최대값을 산출.
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    int n;

    cin >> T;

    // repeat as test case num
    while(T--){
        // input
        cin >> n;
        int* sticker[2];
        for(int i = 0; i < 2; i++){
            sticker[i] = new int[n+2];
            sticker[i][0] = 0;
            sticker[i][1] = 0;
            for(int j = 2; j < n+2; j++){
                cin >> sticker[i][j];
            }
        }

        for(int i = 2; i < n+2; i++){
            sticker[0][i] += max(sticker[1][i-2],sticker[1][i-1]);
            sticker[1][i] += max(sticker[0][i-2],sticker[0][i-1]);
        }
        cout << max(sticker[0][n+1],sticker[1][n+1]) << "\n";
    }

    return 0;
}