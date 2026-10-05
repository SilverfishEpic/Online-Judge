#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    bool is_head = true;
    unsigned long long test_case;
    cin >> test_case >> ws;
    while (test_case--)
    {
        map<string, double> table;
        double sum(0);
        string buffer;
        while (getline(cin, buffer) && buffer.size()) ++table[buffer], ++sum;
        if (!is_head) cout << '\n';
        is_head = false;
        for (const auto& e : table)
            cout << fixed << setprecision(4)
                << e.first << ' ' << e.second / sum * 100 << '\n';
    }
}