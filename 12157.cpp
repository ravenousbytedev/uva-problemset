#include <ios>
#include <iostream>

constexpr unsigned int
    mile_rate = 30, mile_rate_cost = 10, juice_rate = 60, juice_rate_cost = 15;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int n, call_dur, mile_cost, juice_cost, cheaper_cost;
    for (unsigned int test_case = 1; test_case <= t; ++test_case) {
        std::cin >> n;
        mile_cost = 0;
        juice_cost = 0;
        while (n-- > 0) {
            std::cin >> call_dur;
            mile_cost += call_dur / mile_rate * mile_rate_cost + mile_rate_cost;
            juice_cost += call_dur / juice_rate * juice_rate_cost + juice_rate_cost;
        }
        std::cout << "Case " << test_case << ": ";
        if (mile_cost <= juice_cost) {
            std::cout << "Mile ";
            cheaper_cost = mile_cost;
        }
        if (juice_cost <= mile_cost) {
            std::cout << "Juice ";
            cheaper_cost = juice_cost;
        }
        std::cout << cheaper_cost << '\n';
    }
    return 0;
}
