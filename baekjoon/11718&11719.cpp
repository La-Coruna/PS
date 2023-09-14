#include <iostream>
#include <string>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    string lines;

    while(getline(cin, input)){
        cout << input << "\n";
    }
    
    return 0;
}