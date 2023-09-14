#include <iostream>
#include <unordered_map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,M;
    int input;
    unordered_map<int, int> card;
    unordered_map<int, int>::iterator it;

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> input;
        it = card.find(input);
        if(it == card.end())
            card.insert(make_pair(input,1));
        else
            it->second++;
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> input;
        it = card.find(input);
        if(it == card.end())
            cout << 0 << " ";
        else
            cout << it->second << " ";
    }

    return 0;
}