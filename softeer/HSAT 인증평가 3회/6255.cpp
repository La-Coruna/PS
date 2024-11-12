/*
[플레이페어 암호] 
- date: 24.11.12
- url: https://softeer.ai/practice/6255
*/

#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string plain, key, cipher;
queue<pair<char,char>> twoChars;
char board[5][5];
unordered_map<char,pair<int,int>> char2pos;

void fillBoard(){
    int curCharIdx = 0, lenPlainText = key.length();
    char c = 'A';
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            char curChar;
            // board의 현재 칸을 채울 알파벳을 결정함.
            while(curCharIdx < lenPlainText && char2pos.find(key[curCharIdx]) != char2pos.end()) curCharIdx++;
            if(curCharIdx >= lenPlainText){ // key에 있는 알파벳을 모두 사용한 경우
                while(char2pos.find(c) != char2pos.end() || c == 'J') c++;
                curChar = c;
            } else{
                curChar = key[curCharIdx];
            }
            // board를 채움.
            char2pos[curChar] = {i,j};
            board[i][j] = curChar;
        }
    }
}

// void printBoard(){
//     for(int i = 0; i < 5; i++){
//         for(int j = 0; j < 5; j++)
//             cout << board[i][j] << ' ';
//         cout << '\n';
//     }
// }

void genTwoChars(){
    int lenOfPlain = plain.length();
    for(int i = 0; i < lenOfPlain; i++){
        if(i == lenOfPlain - 1) twoChars.emplace(plain[i],'X');
        else if(plain[i] == plain[i+1]){
            if(plain[i] == 'X') twoChars.emplace(plain[i], 'Q');
            else twoChars.emplace(plain[i], 'X');
        }else{
            twoChars.emplace(plain[i], plain[i+1]);
            i++;
        }
    }
}

// void printTwoChars(){
//     while(!twoChars.empty()){
//         cout << twoChars.front().X << twoChars.front().Y << ' ';
//         twoChars.pop();
//     }
// }

void genCipher(){
    while(!twoChars.empty()){
        char c1, c2;
        tie(c1,c2) = twoChars.front();
        twoChars.pop();

        int c1x, c1y, c2x, c2y;
        tie(c1x, c1y) = char2pos[c1];
        tie(c2x, c2y) = char2pos[c2];

        // 행이 같다면
        if(c1x == c2x){
            //cout << c1 << "과 " << c2 << "는 서로 행이 같음 "<< c1x << '\n';
            cipher += board[c1x][(c1y+1)%5];
            cipher += board[c2x][(c2y+1)%5];
        }
        // 열이 같다면
        else if(c1y == c2y) {
            //cout << c1 << "과 " << c2 << "는 서로 열이 같음 "<< c1y << '\n';
            cipher += board[(c1x+1)%5][c1y];
            cipher += board[(c2x+1)%5][c2y];
        }
        // 행과 열이 모두 다르면
        else {
            //cout << c1 << "과 " << c2 << "는 서로 행과 열이 모두 다름 \n";
            cipher += board[c1x][c2y];
            cipher += board[c2x][c1y];
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> plain >> key;
    fillBoard();
    genTwoChars();
    genCipher();
    cout << cipher;

    return 0;
}