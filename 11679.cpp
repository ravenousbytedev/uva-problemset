#include <array>
#include <ios>
#include <iostream>

constexpr unsigned int b_max = 20;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int b, n;
    std::array<int, b_max + 1> r;
    unsigned int d, c, v;
    bool can_liquidate;
    while (std::cin >> b >> n, b != 0) {
        for (unsigned int i = 1; i <= b; ++i) {
            std::cin >> r[i];
        }
        while (n-- > 0) {
            std::cin >> d >> c >> v;
            r[d] -= v;
            r[c] += v;
        }
        can_liquidate = true;
        for (unsigned int i = 1; i <= b; ++i) {
            if (r[i] < 0) {
                can_liquidate = false;
                break;
            }
        }
        std::cout << (can_liquidate ? "S\n" : "N\n");
    }
    return 0;
}
