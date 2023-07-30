#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void){
    int N, M;
    int result = 0;
    string input;
    set<string> S;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> input;
        S.insert(input);
    }

    for(int i = 0; i < M; i++){
        cin >> input;
        if(S.find(input) != S.end())
            result++;
    }

    cout << result;
    
    return 0;
}