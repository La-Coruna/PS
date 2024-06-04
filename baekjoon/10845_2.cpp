/* 
date: 24.06.02
분야: 큐
 */

#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, num;
    string cmd;
    queue<int> q;

    cin >> N;
    while(N--){
        cin >> cmd;
        if(cmd == "push"){
            cin >> num;
            q.push(num);
        } else if (cmd == "pop"){
            if (q.empty()){
                cout << "-1\n";
            } else{
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (cmd == "size"){
            cout << q.size() << "\n";
        } else if (cmd == "empty"){
            if(q.empty()){
                cout << "1\n";
            }else {
                cout << "0\n";
            }
        } else if (cmd == "front"){
            if (q.empty()){
                cout << "-1\n";
            } else{
                cout << q.front() << "\n";
            }
        } else if (cmd == "back"){
            if (q.empty()){
                cout << "-1\n";
            } else{
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}