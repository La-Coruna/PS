/* 
[나는야 포켓몬 마스터 이다솜]
- date: 24.07.26
- 분류: Hash
 */
#include <bits/stdc++.h>
using namespace std;

string arr[100003];
unordered_map<string, int> m;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        m[arr[i]] = i;
    }

    for(int i = 0; i < M; i++){
        string input;
        cin >> input;
        if(input[0] >= '0' && input[0] <= '9') {
            cout << arr[stoi(input)] << '\n';
        } else {
            cout << m[input] << '\n';
        }
    }

    return 0;
}