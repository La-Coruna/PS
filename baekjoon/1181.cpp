#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareStr(string s1, string s2);

int main(void){
    int n;
    cin >> n;
    vector<string> str_v;
    for (int i = 0; i < n; i++){
        string input;
        cin >> input;
        str_v.push_back(input);
    }

    sort(str_v.begin(), str_v.end(), compareStr);
    vector<string>::iterator str_v_end = unique(str_v.begin(), str_v.end());
    for(vector<string>::iterator itr = str_v.begin(); itr < str_v_end; itr++){
        cout << *itr << endl;
    }
}

bool compareStr(string s1, string s2)
{
    if (s1.length() < s2.length() )
        return true;
    else if (s1.length() == s2.length() && s1 < s2)
        return true;
    return false;  
}
