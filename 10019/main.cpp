#include <iostream>
#include <string>
#include <bitset>
#include <cstdint>

uint16_t popcount_swar_u16(uint16_t x) {
    uint32_t v = x;                                      // promote to avoid any 16-bit-only arithmetic quirks
    v = v - ((v >> 1) & 0x5555u);                        // 2-bit chunks
    v = (v & 0x3333u) + ((v >> 2) & 0x3333u);            // 4-bit chunks
    v = (v + (v >> 4)) & 0x0F0Fu;                        // per byte (8-bit chunks)
    v = v + (v >> 8);                                    // sum the two byte counts
    return static_cast<uint16_t>(v & 0x001Fu);           // 0..16
}

uint32_t popcount_swar_u32(uint32_t x) {
    x = x - ((x >> 1) & 0x55555555u);                    // count bits in each 2-bit chunk
    x = (x & 0x33333333u) + ((x >> 2) & 0x33333333u);    // count bits in each 4-bit chunk
    x = (x + (x >> 4)) & 0x0F0F0F0Fu;                    // count bits in each 8-bit chunk (per byte)
    x = x * 0x01010101u;                                 // sum byte counts into top byte
    return x >> 24;                                      // 0..32
}

unsigned popcount_kernighan(unsigned x) {
    unsigned cnt = 0;
    while (x) {
        x &= (x - 1);  // clear lowest set bit
        ++cnt;
    }
    return cnt;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned short N;
    std::cin >> N;
    while (N--)
    {
        std::string M;
        std::cin >> M;
        unsigned short X(0);
        for (const auto& ch : M)
            X = X * 10 + ch - '0';
        std::cout << std::bitset<16>(X).count();
        X = 0;
        for (const auto& ch : M)
            X = X * 16 + ch - '0';
        std::cout << ' ' << std::bitset<16>(X).count() << '\n';
    }
}