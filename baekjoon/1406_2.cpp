/* 
[에디터]
- date: 240529
- 분류: linked list
- 알고리즘: 중간에 insert하고 erase할 때 빠른 자료형인 linked list를 써야한다. array는 느려서 안된다.
*/
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    list<char> text;
    string inital_text;
    char input;
    int n;
    list<char>::iterator cursor;
    
    cin >> inital_text;
    for(char c: inital_text)
        text.emplace_back(c);
    cursor = text.end();

    cin >> n;
    while(n--){
        cin >> input;
        // 커서 왼쪽으로 옮김
        if(input == 'L'){
            if(cursor != text.begin()) cursor--;
        }

        // 커서 오른쪽으로 옮김
        else if(input == 'D'){
            if(cursor != text.end()) cursor++;
        }
        
        // 커서 왼쪽의 문자 삭제
        else if(input == 'B'){
            if(cursor != text.begin())
                cursor = text.erase(--cursor);
        }

        // 커서 왼쪽에 문자 추가
        else if(input == 'P'){
            cin >> input;
            text.insert(cursor, input);
        }
    }

    for(char c:text){
        cout << c;
    }

    return 0;
}