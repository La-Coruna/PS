/* 
[에디터]
- date: 0909
- 분류: linked list
- 알고리즘: 중간에 insert하고 erase할 때 빠른 자료형인 linked list를 써야한다. array는 느려서 안된다.

- 오답 사유: 1) B 커맨드에서 linked list의 요소를 하나 지웠을 때 cursor를 미리 이동시켜야 했다.

            # 틀린 예시 
            if(cursor == text.end()){
                text.erase(--cursor);
            }

            # 맞게 짠 예시
            if(cursor != text.begin()){
                list<char>::iterator tmp = --(--cursor);
                text.erase(++cursor);
                cursor = ++tmp;
            }
*/
#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string input;
    char cmd;
    cin >> input;
    
    list<char> text;
    for(int i = 0; i < input.size(); i++){
        text.emplace_back(input[i]);
    }
    list<char>::iterator cursor = text.end();
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> input;
        if(input[0] == 'L'){
            if(cursor != text.begin())
                cursor--;
        }
        else if(input[0] == 'D'){
            if(cursor != text.end())
                cursor++;
        }
        else if(input[0] == 'B'){
            if(cursor != text.begin()){
                list<char>::iterator tmp = --(--cursor);
                text.erase(++cursor);
                cursor = ++tmp;
            }
        }
        else if(input[0] == 'P'){
            cin >> input;
            text.insert(cursor, input[0]);
        }
        
/*         cout << "text: ";
        for(list<char>::iterator i = text.begin(); i != text.end(); i++)
            cout << *i;
        if(cursor != text.end())
            cout << " cursor: " << *cursor << "\n" <<endl;
        else
            cout << " cursor: " << "void" << "\n" <<endl;
        cout << endl; */

    }
    
    for(list<char>::iterator i = text.begin(); i != text.end(); i++)
        cout << *i;
    
    return 0;
}