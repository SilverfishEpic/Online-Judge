#include <iostream>
#include <string>
#include <array>

// 有空歌啊....

using namespace std;

int main ()
{
    enum Note { c, d, e, f, g, a, b, C, D, E, F, G, A, B };
    array<array<unsigned short, 10>, 14> const table {{
        { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 0, 0, 1, 1, 1, 0 },
        { 0, 1, 1, 1, 0, 0, 1, 1, 0, 0 },
        { 0, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 1, 1, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 1, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
        { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    }};
    unsigned short t;
    cin >> t;
    string song;
    getline(cin, song);
    while (t--)
    {
        getline(cin, song);
        array<unsigned short, 10> count {};
        array<unsigned short, 10> previous{}; // note prev state
        for (auto const& ch : song)
        {
            unsigned short note;
            switch (ch) {
            case 'c': note = c; break;
            case 'd': note = d; break;
            case 'e': note = e; break;
            case 'f': note = f; break;
            case 'g': note = g; break;
            case 'a': note = a; break;
            case 'b': note = b; break;
            case 'C': note = C; break;
            case 'D': note = D; break;
            case 'E': note = E; break;
            case 'F': note = F; break;
            case 'G': note = G; break;
            case 'A': note = A; break;
            case 'B': note = B; break;
            default:
                note = -1;
            }
            for (size_t i = 0; i < 10; ++i)
                if (!previous[i] && table[note][i])
                    ++count[i];
            previous = table[note];
        }
        bool is_first = true;
        for (auto const& ele : count)
        {
            if (!is_first) cout << ' ';
            is_first = false;
            cout << ele;
        }
        cout << '\n';
    }
}
