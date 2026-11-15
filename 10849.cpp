#include <cstdlib>
#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int c;
    std::cin >> c;
    unsigned int t, n;
    int y1, x1, y2, x2;
    while (c-- > 0) {
        std::cin >> t >> n;
        while (t-- > 0) {
            std::cin >> y1 >> x1 >> y2 >> x2;
            if (y1 == y2 && x1 == x2) {
                std::cout << "0\n";
            } else if ((y1 + x1) % 2 != (y2 + x2) % 2) {
                std::cout << "no move\n";
            } else if (std::abs(y1 - y2) == std::abs(x1 - x2)) {
                std::cout << "1\n";
            } else {
                std::cout << "2\n";
            }
        }
    }
    return 0;
}
