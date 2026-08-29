#include <cmath>
#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    int n;
    while (t-- > 0) {
        std::cin >> n;
        std::cout
            << std::abs(((n * 567 / 9 + 7492) * 235 / 47 - 498) / 10 % 10)
            << '\n';
    }
    return 0;
}
