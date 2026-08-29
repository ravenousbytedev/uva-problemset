#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int k;
    int n, m, x, y;
    while (std::cin >> k, k != 0) {
        std::cin >> n >> m;
        while (k-- > 0) {
            std::cin >> x >> y;
            if (x == n || y == m) {
                std::cout << "divisa\n";
            } else if (x < n) {
                std::cout << (y < m ? "SO\n" : "NO\n");
            } else {
                std::cout << (y < m ? "SE\n" : "NE\n");
            }
        }
    }
    return 0;
}
