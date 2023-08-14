#include <vector>
#include <iostream>

using namespace std;

int main(void){
/*
end: []
dp[n-1] * 1

end: [ ] [-]
dp[n-2] * 2

*/
    int n;
    vector<int> v;
    cin >> n;
    
    v.push_back(0);
    v.push_back(1); //1
    v.push_back(3); //2
    
    for(int i = 3; i <= n; i++){
        v.push_back((v[i-1]+v[i-2]*2)%10007);
    }
    
    cout << v[n];
    
    return 0;
}