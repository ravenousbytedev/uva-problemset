#include <ios>
#include <iostream>
#include <utility>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int salary1, salary2, salary3;
    for (unsigned int test_case = 1; test_case <= t; ++test_case) {
        std::cin >> salary1 >> salary2 >> salary3;
        if (salary1 > salary2) {
            std::swap(salary1, salary2);
        }
        if (salary2 > salary3) {
            std::swap(salary2, salary3);
        }
        if (salary1 > salary2) {
            std::swap(salary1, salary2);
        }
        std::cout << "Case " << test_case << ": " << salary2 << '\n';
    }
    return 0;
}
