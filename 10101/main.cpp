#include <iostream>
#include <iomanip>
#include <string>

namespace {
constexpr unsigned long long kKuti  = 10000000ULL;
constexpr unsigned long long kLakh  = 100000ULL;
constexpr unsigned long long kHajar = 1000ULL;
constexpr unsigned long long kShata = 100ULL;

// Prints the Bangla representation of n into out.
// Returns true if anything was printed.
bool PrintBangla(std::ostream& out, unsigned long long n) {
    bool printed = false;

    if (n >= kKuti) {
        printed |= PrintBangla(out, n / kKuti);
        if (printed) out << ' ';
        out << "kuti";
        printed = true;
        n %= kKuti;
    }

    auto emit = [&](unsigned long long value, const char* unit) {
        if (value == 0) return;
        if (printed) out << ' ';
        out << value << ' ' << unit;
        printed = true;
    };

    emit(n / kLakh, "lakh");
    n %= kLakh;

    emit(n / kHajar, "hajar");
    n %= kHajar;

    emit(n / kShata, "shata");
    n %= kShata;

    if (n != 0) {
        if (printed) out << ' ';
        out << n;
        printed = true;
    }

    return printed;
}
}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long n = 0;
    int case_no = 1;

    while (std::cin >> n) {
        std::cout << std::setw(4) << case_no++ << ". ";
        if (n == 0) {
            std::cout << 0 << '\n';
            continue;
        }
        PrintBangla(std::cout, n);
        std::cout << '\n';
    }
}
