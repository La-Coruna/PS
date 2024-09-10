/*
[21년 재직자 대회 예선] 회의실 예약
- date: 24.09.10
- tag: simulation
- url: https://softeer.ai/class/devcrew/study/resource/detail/description/6266?id=280&resourceId=328
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> name_id;
bool isReserved[50][9]; // 9 10 11 12 13 14 15 16 17
int isAvailable[50];

int main(void)
{
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string name;
        cin >> name;
        name_id.emplace(name, i);
    }
    for(int i = 0; i < M; i++){
        string name;
        int id, st, en;
        cin >> name >> st >> en;
        id = name_id[name];
        for(int i = st; i < en; i++){
            isReserved[id][i - 9] = true;
            isAvailable[id]--;
        }
    }
    
    for(auto iter = name_id.begin(); iter != name_id.end(); iter++){
        string name = (*iter).first;
        int id = (*iter).second;
        cout << "Room " << name << ":\n";
        vector<pair<int,int>> available_time;
        bool last_available = false;
        for(int i = 0; i < 9; i++){
            if(!isReserved[id][i]){
                if(last_available)
                    (*available_time.rbegin()).second++;
                else
                    available_time.emplace_back(i+9,i+10);
            }
            last_available = !isReserved[id][i];
        }

        if(available_time.empty()){
            cout << "Not available\n";
        } else{
            cout << available_time.size() << " available:\n";
        }
        for(auto time: available_time){
            cout << setw(2) << setfill('0') << time.first << '-' << time.second <<'\n';
        }
        if(iter != prev(name_id.end())) cout << "-----\n";
    }
    return 0;
}