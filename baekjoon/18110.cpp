#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void){
    // variable
    int num;
    int excludedNum;
    int arr[300000];
    double result=0;

    // input1
    scanf("%d", &num);
    if(num == 0){
        printf("0");
        return 0;
    }

    // input2
    for (int i = 0; i < num ; i++){
        scanf("%d", &arr[i]);
    }
    
    // sort
    sort(arr, arr+num);

    // calculate
    excludedNum = (int) round(num * 0.15);
    for (int i = excludedNum; i<num-excludedNum; i++){
        result += arr[i];
    }
    result = round(result / (num - 2 * excludedNum));
    
    printf("%0.f", result);

    return 0;
}