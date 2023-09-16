/* 
[키로거]
- date: 0916
- 분류: list
- 깨달은점:
            1) insert() 함수는 삽입된 요소를 가리키는 반복자(iterator)를 반환한다.
            2) erase() 함수를 사용한 후 해당 요소를 가리키는 반복자는 무효화된다.
                삭제 후에 다음 요소를 가리키는 반복자를 사용하려면 cursor = pwd.erase(cursor); 코드를 사용하여 cursor를 업데이트할 수 있다.
            3) 원소가 없을 때는 begin()과 end()가 같다.
- 틀린 이유:
            커맨드 백스페이스(-) 조건에서,
            if(!pwd.empty()) 로 처음에 했었는데,
            if(cursor != pwd.begin()) 로 해야 올바르게 작동한다.

 */

#include <iostream>
#include <list>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T,L;
    string input;
    cin >> T;
    while(T--){
        cin >> input;
        L = input.size();
        list<char> pwd;
        list<char>::iterator cursor = pwd.begin();
        for(int i = 0; i < L; i++){
            if(input[i] == '>'){
                if(cursor != pwd.end())
                    cursor++;
            }
            else if(input[i] == '<'){
                if(cursor != pwd.begin())
                    cursor--;
            }
            else if(input[i] == '-'){
                if(cursor != pwd.begin()){
                    cursor = pwd.erase(--cursor);
                }
            }
            else {
                pwd.insert(cursor, input[i]);
            }
        }
        for(list<char>::iterator i = pwd.begin(); i != pwd.end(); i++){
            cout << *i;
        }
        cout << "\n"; 
    }

    return 0;
}
