#include <cstdlib>
#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x1, y1, x2, y2;
    while (std::cin >> x1 >> y1 >> x2 >> y2, x1 != 0) {
        if (x1 == x2 && y1 == y2) {
            std::cout << "0\n";
        } else if (x1 == x2 || y1 == y2 || std::abs(y1 - y2) == std::abs(x1 - x2)) {
            std::cout << "1\n";
        } else {
            std::cout << "2\n";
        }
    }
    return 0;
}
