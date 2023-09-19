/* 
[큐 2]
- date: 0920
- 분류: queue, list

 */
#include <iostream>
#include <list>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, input;
    string cmd;
    list<int> q;

    cin >> N;
    while(N--){
        cin >> cmd;
        if(!cmd.compare("push")){
            cin >> input;
            q.push_back(input);
        }
        else if(!cmd.compare("pop")){
            if(q.empty())
                cout << -1 << "\n";
            else{
                cout << q.front() << "\n";
                q.pop_front();            
            }
        }
        else if(!cmd.compare("size")){
            cout << q.size() << "\n";
        }
        else if(!cmd.compare("empty")){
            cout << q.empty() << "\n";
        }
        else if(!cmd.compare("front")){
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if(!cmd.compare("back")){
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
        }
    }
        
    return 0;
}