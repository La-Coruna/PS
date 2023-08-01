#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    string input_str;
    int input_int;
    unordered_map<string, int>dogam_name;
    unordered_map<int, string>dogam_num;
    
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> input_str;
        dogam_name[input_str] = i;
        dogam_num[i] = input_str;
    }

    for(int i = 0; i<M; i++){
        cin >> input_str;
        try{
            input_int = stoi(input_str);
            cout << dogam_num[input_int-1] <<"\n";
        }catch(const invalid_argument& e){
            cout << dogam_name[input_str]+1 <<"\n";
        }
    }

    return 0;
}