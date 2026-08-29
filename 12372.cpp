#include <ios>
#include <iostream>

constexpr unsigned int suitcase_dim = 20;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int l, w, h;
    for (unsigned int test_case = 1; test_case <= t; ++test_case) {
        std::cin >> l >> w >> h;
        std::cout
            << "Case "
            << test_case
            << ": "
            << (
                l <= suitcase_dim && w <= suitcase_dim && h <= suitcase_dim ?
                    "good\n" : "bad\n"
            );
    }
    return 0;
}
