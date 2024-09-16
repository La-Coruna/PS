/* 
[로또]
- date: 24.09.14
- 분류: backtracking
 */
#include<bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int k;
        cin >> k;
        if(k == 0) break;


        int arr[49];
        for(int i = 0; i < k; i++){
            cin >> arr[i];
        }

        vector<bool> passed(6,false);
        for(int i = 6; i < k; i++){
            passed.push_back(1);
        }

        do{
            for(int i = 0; i < k; i++){
                if(!passed[i]) cout << arr[i] << ' ';
            }
            cout << '\n';
            
        } while(next_permutation(passed.begin(), passed.end()));
        cout << '\n';
    }

    return 0;
}