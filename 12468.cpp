#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a, b;
    unsigned int min_fwd_presses, min_bwd_presses;
    while (std::cin >> a >> b, a != -1) {
        if (a < b) {
            min_fwd_presses = b - a;
            min_bwd_presses = 100 + a - b;
        } else {
            min_fwd_presses = 100 + b - a;
            min_bwd_presses = a - b;
        }
        std::cout
            << (min_fwd_presses < min_bwd_presses ? min_fwd_presses : min_bwd_presses)
            << '\n';
    }
    return 0;
}
