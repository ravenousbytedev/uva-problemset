#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int n, m;
    while (t-- > 0) {
        std::cin >> n >> m;
        std::cout << ((n / 3) * (m / 3)) << '\n';
    }
    return 0;
}
