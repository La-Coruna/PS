#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
    int X;
    cin >> X;

    vector<int> v;
    v.push_back(-1);
    v.push_back(0); //1
    v.push_back(1); //2
    v.push_back(1); //3
    v.push_back(2); //4
    
    for(int i = 5; i <= X; i++){
        if(i%6==0){
            v.push_back(min(v[i/3], v[i/2]) + 1);
        }
        else if(i%3==0){
            v.push_back(min(v[i/3], v[i-1]) + 1);
        }
        else if(i%2==0){
            v.push_back(min(v[i/2], v[i-1]) + 1);
        }
        else
            v.push_back(v[i-1]+1);
    }
    
    cout << v[X];
    

    return 0;
}