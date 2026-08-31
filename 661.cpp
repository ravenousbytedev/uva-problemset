#include <array>
#include <bitset>
#include <ios>
#include <iostream>

constexpr unsigned int n_max = 20;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int seq = 0, n, m, c;
    std::array<unsigned int, n_max + 1> cc;
    unsigned int i;
    std::bitset<n_max + 1> states;
    unsigned int curr_consumption, max_consumption;
    while (std::cin >> n >> m >> c, n != 0) {
        for (i = 1; i <= n; ++i) {
            std::cin >> cc[i];
        }
        curr_consumption = 0;
        max_consumption = 0;
        while (m--) {
            std::cin >> i;
            states[i].flip();
            if (states[i]) {
                curr_consumption += cc[i];
            } else {
                curr_consumption -= cc[i];
            }
            if (curr_consumption > max_consumption) {
                max_consumption = curr_consumption;
            }
        }
        std::cout
            << "Sequence "
            << ++seq
            << (max_consumption > c ? "\nFuse was blown.\n" : "\nFuse was not blown.\n");
        if (max_consumption <= c) {
            std::cout
                << "Maximal power consumption was "
                << max_consumption
                << " amperes.\n";
        }
        std::cout << '\n';
        states.reset();
    }
    return 0;
}
