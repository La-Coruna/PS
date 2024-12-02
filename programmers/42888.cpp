/*
[오픈채팅방]
- date: 24.11.30
- url: https://school.programmers.co.kr/learn/courses/30/lessons/42888
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> id2name;
    for(auto iter = record.begin(); iter != record.end(); iter++){
        string idAndName;
        if((*iter)[0] == 'E') idAndName = iter->substr(6);
        else if((*iter)[0] == 'C') idAndName = iter->substr(7);
        else continue;
        
        int spaceIdx = idAndName.find(' ');
        string id = idAndName.substr(0,spaceIdx);
        string name = idAndName.substr(spaceIdx+1);
        id2name[id] = name;
        
        //cout << id << " " << id2name[id] << '\n';
    }
    
    answer.reserve(record.size());
    for(auto iter = record.begin(); iter != record.end(); iter++){
        string cmd;
        if((*iter)[0] == 'E') cmd = "님이 들어왔습니다.";
        else if((*iter)[0] == 'L') cmd = "님이 나갔습니다.";
        else continue;
        
        string idAndName = iter->substr(6);
        int spaceIdx = idAndName.find(' ');
        string id = idAndName.substr(0,spaceIdx);
        string name = id2name[id];
        answer.emplace_back(name + cmd);
    }
    
    return answer;
}