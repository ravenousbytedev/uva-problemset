#include <algorithm>
#include <bitset>
#include <ios>
#include <iostream>

constexpr unsigned int xy_i_max = 100000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int a, b, xy_i;
    std::bitset<xy_i_max + 1> x_bitset, y_bitset;
    unsigned int n_a, n_b;
    while (std::cin >> a >> b, a != 0) {
        for (unsigned int i = 0; i < a; ++i) {
            std::cin >> xy_i;
            x_bitset[xy_i] = true;
        }
        for (unsigned int i = 0; i < b; ++i) {
            std::cin >> xy_i;
            y_bitset[xy_i] = true;
        }
        n_a = 0;
        n_b = 0;
        for (xy_i = 1; xy_i <= xy_i_max; ++xy_i) {
            if (x_bitset[xy_i] && !y_bitset[xy_i]) {
                ++n_a;
            }
            if (!x_bitset[xy_i] && y_bitset[xy_i]) {
                ++n_b;
            }
        }
        std::cout << std::min(n_a, n_b) << '\n';
        x_bitset.reset();
        y_bitset.reset();
    }
    return 0;
}
