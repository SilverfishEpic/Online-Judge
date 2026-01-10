#include <iostream>
using namespace std;

// can't process 0, but under the limit is fine
static inline unsigned long digital_root(unsigned long n) {
    return 1 + (n - 1) % 9;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long n;
    while (cin >> n && n != 0)
        std::cout << digital_root(n) << '\n';
}
