#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    std::string op;
    unsigned int k, total = 0;
    while (t-- > 0) {
        std::cin >> op;
        if (op == "donate") {
            std::cin >> k;
            total += k;
        } else {
            std::cout << total << '\n';
        }
    }
    return 0;
}
