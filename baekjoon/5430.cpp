/* 
[AC]
- date: 24.09.10
- 분류: string, deque, parsing
 */
#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        string p, str;
        deque<int> list;
        bool isReversed = false;
        bool isError = false;
        cin >> p >> n >> str;
        int p_len = p.length();
        int str_len = str.length();
        
        string num ="";
        for(int i = 1; i < str_len; i++){
            if(isdigit(str[i])){
                num += str[i];
            }
            else if(!num.empty()){
                list.push_back(stoi(num));
                num = "";
            }
        }

        for(int i = 0; i < p_len; i++){
            if(p[i] == 'R') isReversed = !isReversed;
            else{
                if(list.empty()){
                    isError = true;
                    break;
                }
                if(!isReversed) list.pop_front();
                else list.pop_back();
            } 
        }

        // [print]
        // error
        if(isError){
            cout << "error\n";
            continue;
        }
        // empty
        if(list.empty()){
            cout << "[]\n";
            continue;
        }
        // else
        cout << '[';
        if(isReversed){
            auto st = list.rbegin();
            auto en = prev(list.rend());
            for(auto iter = st; iter != en; iter++){
                cout << *iter <<',';
            }            
            cout << *en;
        }
        else{
            auto st = list.begin();
            auto en = prev(list.end());
            for(auto iter = st; iter != en; iter++){
                cout << *iter <<',';
            }
            cout << *en;
        }
        cout << "]\n";
    }

    return 0;
}