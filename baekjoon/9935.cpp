/*
[문자열 폭발] 
- date: 25.09.29
*/
#include <bits/stdc++.h>
using namespace std;

string input_str;
string bomb_str;
unordered_map<char,char> nxt;
vector<char> S;
vector<char> answer;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> input_str;
    cin >> bomb_str;

    int n = bomb_str.length()-1;
    char first_of_bomb = bomb_str[0];
    char last_of_bomb = bomb_str[n];

    // 폭발 문자열이 하나의 문자일 때
    if(first_of_bomb == last_of_bomb){
        input_str.erase(remove(input_str.begin(), input_str.end(), first_of_bomb), input_str.end());

        cout << ((input_str.length() == 0) ? "FRULA" : input_str);
        return 0;
    }

    for(int i = 0; i < n; i++){
        nxt[bomb_str[i]] = bomb_str[i+1];
    }

    for(char& c : input_str){
        if(c == first_of_bomb){
            S.emplace_back(c);
        } else if(!S.empty() && c == nxt[S.back()]){
            if(c == last_of_bomb)
                S.erase(S.end() - n, S.end());
            else
                S.emplace_back(c);
        } else{
            if(!S.empty()){
                answer.insert(answer.end(), S.begin(), S.end());
                S.clear();
            }
            answer.push_back(c);
        }
    }

    // 터지지 않고 남은 문자열 처리
    if(!S.empty()){
        answer.insert(answer.end(), S.begin(), S.end());
    }

    if(answer.empty())
        cout << "FRULA";
    else{
        for(char& c : answer){
            cout << c;
        }
    }

    return 0;
}