#include <ios>
#include <iostream>

constexpr unsigned int store_pos_max = 99;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int n, store_pos, min_store_pos, max_store_pos;
    while (t-- > 0) {
        std::cin >> n;
        min_store_pos = store_pos_max;
        max_store_pos = 0;
        while (n-- > 0) {
            std::cin >> store_pos;
            if (store_pos < min_store_pos) {
                min_store_pos = store_pos;
            }
            if (store_pos > max_store_pos) {
                max_store_pos = store_pos;
            }
        }
        std::cout << ((max_store_pos - min_store_pos) * 2) << '\n';
    }
    return 0;
}
