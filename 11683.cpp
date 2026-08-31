#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int a, c, x_i, op_count;
    while (std::cin >> a >> c, a != 0) {
        op_count = 0;
        while (c-- > 0) {
            std::cin >> x_i;
            if (x_i < a) {
                op_count += a - x_i;
            }
            a = x_i;
        }
        std::cout << op_count << '\n';
    }
    return 0;
}
