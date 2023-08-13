#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    if(N==1){
        cout << "*";
        return 0;
    }

    // top
    for(int i = 0; i<N-1; i++)
        cout << " ";
    cout << "*\n";

    // middle
    for (int i = 1; i <= N-2; i++){
        for (int j = 0; j < N-i-1; j++){
            cout << " ";
        }
        cout << "*";
        for (int j = 0; j <2*i-1; j++){
            cout << " ";
        }
        cout << "*\n";
    }

    // bottom
    for(int i = 0; i < 2*N-1; i++)
        cout << "*";

    return 0;
}

/* 

*

 *
***

  *
 * *
*****

   *
  * *       공백 1
 *   *      공백 2
*******

 */