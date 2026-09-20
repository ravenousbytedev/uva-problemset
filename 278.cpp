#include <algorithm>
#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case_count;
    std::cin >> test_case_count;
    char piece;
    unsigned int m, n;
    while (test_case_count-- > 0) {
        std::cin >> piece >> m >> n;
        switch (piece) {
        case 'r':
        case 'Q':
            std::cout << std::min(m, n);
            break;
        case 'k':
            std::cout << ((m * n + 1) / 2);
            break;
        case 'K':
            std::cout << ((m + 1) / 2 * ((n + 1) / 2));
        }
        std::cout << '\n';
    }
    return 0;
}
