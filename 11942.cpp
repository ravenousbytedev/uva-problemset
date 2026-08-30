#include <ios>
#include <iostream>

constexpr unsigned int lumberjack_count = 10;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n;
    std::cin >> n;
    unsigned int left, right;
    bool is_reversed, are_ordered;
    std::cout << "Lumberjacks:\n";
    while (n-- > 0) {
        std::cin >> left >> right;
        is_reversed = left > right;
        are_ordered = true;
        for (unsigned int i = 2; i < lumberjack_count; ++i) {
            left = right;
            std::cin >> right;
            if (is_reversed ? left < right : left > right) {
                are_ordered = false;
            }
        }
        std::cout << (are_ordered ? "Ordered\n" : "Unordered\n");
    }
    return 0;
}
