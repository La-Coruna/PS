/*
[톱니바퀴] 
- date: 26.01.05

- 기본
        0
    7       1
 (L)6       2(R)
    5       3
        4  

- clockwise (-1)
        7
    6       0
    5       1
    4       2
        3  

- counterclockwise (+1)
        1
    8       2
    7       3
    6       4
        5  

- input
    - 시계방향: 1, 반시계방향: -1
    - N극: 0, S극: 1

- 맞닿은 부분이 다른 극이면, 다른 방향으로의 회전이 전달된다.
- 1. 왼쪽과 오른쪽으로, 총 어디서부터 어디까지 극이 연결되는 지 확인
- 2. 한번에 회전.

*/
#include <bits/stdc++.h>
using namespace std;

struct Cogwheel{
    bool initalState[8];
    int rotationCnt = 0;

    void rotate(bool isClockwise){
        if(isClockwise) rotationCnt--;
        else rotationCnt++;
    }

    int applyRotation(int idx){
        int res = (idx + rotationCnt) % 8;
        return (res < 0) ? res + 8 : res;
    }

    bool getTopState(){
        return initalState[applyRotation(0)];
    }

    bool getRightState(){
        return initalState[applyRotation(2)];
    }

    bool getLeftState(){
        return initalState[applyRotation(6)];
    }

    Cogwheel(string state_str){
        for(int i = 0; i < 8; i++){
            initalState[i] = (state_str[i] == '1');
        }
    }

    static void rotateCogwheel(vector<Cogwheel>& cogwheels, int cogNum, bool isClockwise){
        // 왼쪽 연결된 부분의 끝 찾기
        int l = cogNum;
        for(int cur = cogNum; cur-1 >= 0; cur--){
            bool rightCogState = cogwheels[cur].getLeftState();
            bool leftCogState = cogwheels[cur-1].getRightState();
            if(rightCogState ^ leftCogState) l = cur-1;
            else break;
        }

        // 오른쪽 연결된 부분의 끝 찾기
        int r = cogNum;
        for(int cur = cogNum; cur+1 <= 3; cur++){
            bool leftCogState = cogwheels[cur].getRightState();
            bool rightCogState = cogwheels[cur+1].getLeftState();
            if(rightCogState ^ leftCogState) r = cur+1;
            else break;
        }

        // l 에서의 회전 방향 정하기
        bool isCurCogClockwise = ((cogNum - l) & 1) ? !isClockwise : isClockwise;

        // l~r까지 다 회전시키기
        for(int i = l; i <= r; i++){
            cogwheels[i].rotate(isCurCogClockwise);
            isCurCogClockwise = !isCurCogClockwise;
        }
    }

    static int getScore(vector<Cogwheel>& cogwheels){
        int score = 0;
        for(int i = 0; i < 4; i++){
            if(cogwheels[i].getTopState()) score += (1 << i);
        }
        return score;
    }
    /* // 디버깅 코드
    static void printAllCogs(vector<Cogwheel>& cogwheel){
        for(int j = 0; j < 8; j++){
            if(j == 2 || j == 6) cout << j;
            else cout << ' ';
        }
        cout << '\n';
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 8; j++){
                if(cogwheel[i].initalState[cogwheel[i].applyRotation(j)]) cout << "S";
                else cout << "N";
            }
            cout << '\n';
        }
    }

    static void printAllCogsDetail(vector<Cogwheel>& cogwheel){
        string cnt;
        string top;
        string top2;
        string middle;
        string bot2;
        string bot;

        for(int i = 0; i < 4; i++){
            cnt += "    " + to_string(cogwheel[i].rotationCnt) + "    ";

            if(cogwheel[i].initalState[cogwheel[i].applyRotation(0)]) top += "    S    ";
            else top += "    N    ";

            if(cogwheel[i].initalState[cogwheel[i].applyRotation(7)]) top2 += "   S ";
            else top2 += "   N ";

            if(cogwheel[i].initalState[cogwheel[i].applyRotation(1)]) top2 += "S   ";
            else top2 += "N   ";

            if(cogwheel[i].initalState[cogwheel[i].applyRotation(6)]) middle += "  S  ";
            else middle += "  N  ";

            if(cogwheel[i].initalState[cogwheel[i].applyRotation(2)]) middle += " S  ";
            else middle += " N  ";

            if(cogwheel[i].initalState[cogwheel[i].applyRotation(5)]) bot2 += "   S ";
            else bot2 += "   N ";

            if(cogwheel[i].initalState[cogwheel[i].applyRotation(3)]) bot2 += "S   ";
            else bot2 += "N   ";

            if(cogwheel[i].initalState[cogwheel[i].applyRotation(4)]) bot += "    S    ";
            else bot += "    N    ";
        }
        cout << cnt << '\n' << top << '\n' << top2 << '\n' << middle << '\n' << bot2 << '\n' << bot << '\n';
    }
    */
};

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string state_str;
    vector<Cogwheel> cogwheels;
    for(int i = 0; i < 4; i++){
        cin >> state_str;
        cogwheels.emplace_back(state_str);
    }

    int K;
    cin >> K;
    for(int i = 0; i < K; i++){
        int cogNum, dir;
        cin >> cogNum >> dir;
        cogNum--; // 0-index
        Cogwheel::rotateCogwheel(cogwheels, cogNum, dir == 1);
    }    

    cout << Cogwheel::getScore(cogwheels);

    return 0;
}