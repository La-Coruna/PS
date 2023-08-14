#include <vector>
#include <iostream>

using namespace std;

int main(void){
/*
end: 1
v[n-1]

end: 2
v[n-2]

end: 3
v[n-3]

*/
    int T, n;
    vector<int> v;
    cin >> T;
    
    v.push_back(0);
    v.push_back(1); //1
    v.push_back(2); //2 = 1+1
    v.push_back(4); //3 = 1+1+1 = 1+2 = 2+1
    
    while(T--){
        cin >> n;
        for(int i = 4; i <= n; i++){
            if( v.size() < i+1 )
                v.push_back( v[i-1] + v[i-2] + v[i-3] );
        }
    
        cout << v[n] << endl;    
    }
    
    return 0;
}