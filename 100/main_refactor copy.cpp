#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using u64 = std::uint64_t;

static constexpr std::size_t LIMIT = 5'000'000;

int cycle_length(u64 n, std::vector<int>& cache) {
    // 如果在 cache 範圍內且已算過，直接回傳
    if (n <= LIMIT && cache[static_cast<std::size_t>(n)] != 0) {
        return cache[static_cast<std::size_t>(n)];
    }

    // 記錄路徑上遇到的 n（只記 LIMIT 內的，因為只快取這些）
    std::vector<u64> path;
    path.reserve(128);

    u64 cur = n;
    int len = 0;

    while (true) {
        if (cur <= LIMIT) {
            int known = cache[static_cast<std::size_t>(cur)];
            if (known != 0) {
                len += known;
                break;
            }
            path.push_back(cur);
        }

        ++len;                 // 這一步會「印出一個數」（包含最後的 1）
        if (cur == 1) break;

        if (cur & 1ULL) cur = 3 * cur + 1;
        else cur >>= 1;
    }

    // 回填：path[0] 是起點（或中間點），len 是它的 cycle length
    for (u64 v : path) {
        cache[static_cast<std::size_t>(v)] = len;
        --len;
    }

    return cache[static_cast<std::size_t>(n)];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> cache(LIMIT + 1, 0);
    cache[1] = 1;

    int i, j;
    while (std::cin >> i >> j) {
        const int lo = std::min(i, j);
        const int hi = std::max(i, j);

        int best = 0;
        for (int n = lo; n <= hi; ++n) {
            best = std::max(best, cycle_length(static_cast<u64>(n), cache));
        }

        std::cout << i << ' ' << j << ' ' << best << '\n';
    }
}
