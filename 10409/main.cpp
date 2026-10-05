#include <iostream>
#include <utility>
#include <string>
#include <array>

/*
  N    2
 WTEB 3146
  S    5
*/

using namespace std;

int main()
{
    unsigned short seq;
    while (cin >> seq && seq)
    {
        std::array<unsigned short, 6> die = { 1, 2, 3, 4, 5, 6 };
        auto north = [&]() {
            swap(die[0], die[1]);
            swap(die[4], die[0]);
            swap(die[5], die[4]);
        };
        auto east = [&]() {
            swap(die[0], die[3]);
            swap(die[2], die[0]);
            swap(die[5], die[2]);
        };
        auto south = [&]() {
            swap(die[0], die[4]);
            swap(die[1], die[0]);
            swap(die[5], die[1]);
        };
        auto west = [&]() {
            swap(die[0], die[2]);
            swap(die[3], die[0]);
            swap(die[5], die[3]);
        };
        while (seq--)
        {
            string command;
            cin >> command;
            if (command == "north") north();
            else if (command == "east") east();
            else if (command == "south") south();
            else west();
        }
        cout << die[0] << '\n';
    }
}