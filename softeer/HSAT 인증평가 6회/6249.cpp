/*
[염기서열 커버] 
- date: 24.11.05
- url: https://softeer.ai/practice/6249
*/
#include <bits/stdc++.h>
using namespace std;

int N, M, totalCaseNum;
vector<string> str;
vector<string> superDNA;

string mergeStr(string& str1, string& str2){
    string res = "";
    if(str1 == "" || str2 == "") return "";

    for(int c = 0; c < M; c++){
        if(str1[c] == '.') res += str2[c];
        else if(str2[c] == '.') res += str1[c];
        else if(str1[c] == str2[c]) res += str1[c];
        else {
            return "";
        }
    }

    return res;
}

void GenSuperDNA(){
    superDNA.resize(totalCaseNum,"");
    for(int i = 0; i < N; i++){
        superDNA[(1<<i)] = str[i];
    }
    for(int i = 1; i < totalCaseNum; i++){
        if(superDNA[i] != "") continue;
        int first1BitIdx = 0;
        int tmp = i;
        while ((tmp & 1) == 0) {
            tmp >>= 1;
            first1BitIdx++;
        }


        int leftIdx = (1<<first1BitIdx);
        int rightIdx = i - leftIdx;

        //cout << "i: " << i << " = " << leftIdx << " + " << rightIdx << "\n";
        string merged = mergeStr(superDNA[leftIdx], superDNA[rightIdx]);
        if(!merged.empty()) superDNA[i] = merged;
        else superDNA[i] = "";
        //superDNA[i] = mergeStr(superDNA[leftIdx], superDNA[rightIdx]);
    }
    return;
}

void CountAllSuperDNA(){
    vector<int> dp(totalCaseNum, 0);
    for(int index = 1; index < totalCaseNum; index++){
        if(superDNA[index] != "") {
            dp[index] = 1;
            continue;
        }
        
        int cur_cnt = N;
        for (int number1 = (index - 1) & index; number1 > (index / 2); number1 = (number1 - 1) & index){
            int number2 = index - number1;
            cur_cnt = min(cur_cnt, dp[number1] + dp[number2]);
        }
        dp[index] = cur_cnt;
    }
    cout << dp[totalCaseNum-1];
}



int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    totalCaseNum = (1 << N);

    str.resize(N, "");
    for(int i = 0; i < N; i++){
        cin >> str[i];
    }
    
    GenSuperDNA();
    CountAllSuperDNA();

    return 0;
}