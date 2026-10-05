#include <iostream>
#include <utility>
#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    array<char, 4> direct { 'E', 'N', 'W', 'S' };
    array<pair<short, short>, 4> turning { 
        make_pair(1, 0), // east
        make_pair(0, 1), // north
        make_pair(-1, 0), // west
        make_pair(0, -1) // south
    };
    int gx, gy;
    cin >> gx >> gy;
    vector<vector<bool>> scent(++gy, vector<bool>(++gx, false));
    int rx, ry;
    char rd;
    while (cin >> rx >> ry >> rd)
    {
        size_t rde = find(direct.begin(), direct.end(), rd) - direct.begin();
        bool lost = false;
        auto decoding_i = [&](char i) {
            switch (i)
            {
            case 'L':
                rde = (rde + 1) % 4;
                break;
            case 'R':
                rde = (rde + 3) % 4;
                break;
            case 'F':
                int nx = rx + turning[rde].first;
                int ny = ry + turning[rde].second;
                if (nx >= 0 && nx < gx &&
                    ny >= 0 && ny < gy)
                    rx = nx, ry = ny;
                else if (scent[ry][rx]) ;
                else lost = true, scent[ry][rx] = true;
            }
        };
        cin.ignore();
        string instructions;
        getline(cin, instructions);
        for (auto const& i : instructions)
            if (!lost) decoding_i(i);
            else break;
        cout << rx << ' ' << ry << ' ' << direct[rde];
        if (lost) cout << " LOST";
        cout << '\n';
    }
}