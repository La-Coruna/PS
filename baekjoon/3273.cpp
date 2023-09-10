/* 
[에디터]
- date: 0909
- 분류: linked list
- 알고리즘:


- 오답 사유: 1) B 커맨드에서

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
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,x;
    int ans = 0;
    cin >> n;
    
    vector<int> arr(n+1,0);
    vector<bool> table(2000001,0);
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        table[arr[i]] = i;
    }
    
    cin >> x;
    for(int i = 1; i <= n; i++){
        int diff = x - arr[i];
        if(diff <= 0)
            continue;
        if(table[diff]){
            ans++;
        }
    }
    
    cout << ans/2;

    return 0;
}