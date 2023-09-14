/* 
날짜: 230814
 */
#include <iostream>

using namespace std;

int main(void){
    int memo[10] = {1,1,1,1,1,1,1,1,1,1};
    int N;
    int res = 0;

    cin >> N;
    for(int i = 1; i < N; i++){
        int tmp[10] = {0,0,0,0,0,0,0,0,0,0};
        tmp[0] = memo[0];
        for(int j = 1; j < 10; j++){
            for(int k = 0; k <= j; k++)
                tmp[j] += memo[k];
        }
        for(int j = 1; j < 10; j++){
            memo[j] = tmp[j] % 10007;
        }
    }
    for(int i = 0; i < 10; i++){
        res = res + memo[i];
    }
    cout << res % 10007;

    return 0;
}