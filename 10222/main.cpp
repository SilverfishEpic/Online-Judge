#include <iostream>
#include <utility>
#include <map>
#include <cctype>
#include <stdexcept>

int main()
{
    std::map<char, char> table {
        {'e', 'q'},
        {'d', 'a'},
        {'c', 'z'},
        {'r', 'w'},
        {'f', 's'},
        {'v', 'x'},
        {'t', 'e'},
        {'g', 'd'},
        {'b', 'c'},
        {'y', 'r'},
        {'h', 'f'},
        {'n', 'v'},
        {'u', 't'},
        {'j', 'g'},
        {'m', 'b'},
        {'i', 'y'},
        {'k', 'h'},
        {',', 'n'},
        {'o', 'u'},
        {'l', 'j'},
        {'.', 'm'},
        {'p', 'i'},
        {';', 'k'},
        {'[', 'o'},
        {'\'', 'l'},
        {']', 'p'},
    };
    char ch;
    while (std::cin.get(ch))
        try
        {
            std::cout << table.at(static_cast<char>(std::tolower(static_cast<unsigned char>(ch))));
        }
        catch(const std::out_of_range& e)
        {
            std::cout << ch;
        }
}