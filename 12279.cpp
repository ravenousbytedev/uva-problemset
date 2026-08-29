#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case = 0, n, ev;
    int emoogle_balance;
    while (std::cin >> n, n != 0) {
        emoogle_balance = 0;
        while (n-- > 0) {
            std::cin >> ev;
            if (ev == 0) {
                --emoogle_balance;
            } else {
                ++emoogle_balance;
            }
        }
        std::cout << "Case " << ++test_case << ": " << emoogle_balance << '\n';
    }
    return 0;
}
