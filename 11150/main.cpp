#include <iostream>

using namespace std;

int main()
{
    int N;
    while (cin >> N)
    {
        int rtn = N,
            empty = N;
        while (empty >= 3)
        {
            int drink = empty / 3;
            rtn += drink;
            empty = drink + empty % 3;
        }
        if (empty % 3 == 2) ++rtn;
        cout << rtn << '\n';
    }
    // N + N / 2
}