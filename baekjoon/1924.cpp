#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dates_per_moth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int month, date;
    int total_days = 0;

    cin >> month >> date;

    for (int i = 0; i < month - 1; i++)
    {
        total_days += dates_per_moth[i];
    }
    total_days += date;

    cout << days[(total_days - 1) % 7 ];

    return 0;
}