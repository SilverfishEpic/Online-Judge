#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    unsigned int N, M;
    while (cin >> N >> M)
    {
        cout << N << ' ' << M << '\n';
        if (!N || !M) break;
        auto comp = [&](long a, long b) {
            if (a % M != b % M) return a % M < b % M; // according to M
            if (abs(a % 2) != abs(b % 2)) return a % 2 != 0; // odd then even
            if (a % 2) return a > b; // greater odd then lesser odd
            else return a < b; // lesser even then greater even
        };
        std::multiset<long, decltype(comp)> result(comp);
        copy_n(istream_iterator<long>(cin), N, inserter(result, result.end()));
        copy(result.begin(), result.end(), ostream_iterator<long>(cout, "\n"));
    }
}
