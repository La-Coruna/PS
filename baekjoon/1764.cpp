#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    string input;
    set<string> no_listen;
    set<string> neither_listen_nor_see;

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> input;
        no_listen.insert(input);
    }
    
    for(int i = 0; i < M; i++){
        cin >> input;
        if(no_listen.find(input) != no_listen.end()){
            neither_listen_nor_see.insert(input);
        }
    }

    cout << neither_listen_nor_see.size() << "\n"; 
    for(set<string>::iterator it = neither_listen_nor_see.begin(); it != neither_listen_nor_see.end(); it++){
        cout << *it << "\n";
    }

    return 0;
}