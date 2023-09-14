// #include <iostream>
// #include <string>
// #include <map>

// using namespace std;

// int main(void){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     string input_name;
//     string input_status;
//     map<string,bool> myMap;

//     cin >> n;

//     for(int i = 0; i < n; i++){
//         cin >> input_name;
//         cin >> input_status;
//         if(input_status == "enter"){
//             myMap[input_name] = true;
//         }
//         else if (input_status == "leave"){
//             myMap[input_name] = false;
//         }
//     }

//     for(map<string,bool>::reverse_iterator it = myMap.rbegin(); it != myMap.rend(); it++){
//         if(it->second)
//             cout << it->first << "\n";
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string input_name;
    string input_status;
    set<string> S;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input_name;
        cin >> input_status;
        if(input_status == "enter")
            S.insert(input_name);
        else if (input_status == "leave"){
            S.erase(input_name);
        }
    }

    for(set<string>::reverse_iterator it = S.rbegin(); it != S.rend(); it++){
        cout << *it << "\n";
    }

    return 0;
}

/* 
    map으로 하든 set으로 하든 차이 없다.
    계속 시간 초과가 일어났는데,

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    이 두 줄과 endl를 "\n"으로 바꿔주니
    시간초과를 해결할 수 있었다.

 */