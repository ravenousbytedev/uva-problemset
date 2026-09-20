#include <algorithm>
#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int m, n;
    while (std::cin >> m >> n, m != 0) {
        if (m == 1 || n == 1) {
            std::cout << (m * n);
        } else if (m == 2 || n == 2) {
            switch (std::max(m, n) % 4) {
            case 0:
                std::cout << std::max(m, n);
                break;
            case 1:
                std::cout << (std::max(m, n) / 4 * 4 + 2);
                break;
            case 2:
            case 3:
                std::cout << (std::max(m, n) / 4 * 4 + 4);
            }
        } else {
            std::cout << ((m * n + 1) / 2);
        }
        std::cout
            << " knights may be placed on a "
            << m
            << " row "
            << n
            << " column board.\n";
    }
    return 0;
}
