#include <algorithm>
#include <array>
#include <ios>
#include <iostream>
#include <string>
#include <utility>

constexpr unsigned int str_length_max = 1000000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case = 0;
    std::string str;
    str.reserve(str_length_max);
    std::array<unsigned int, str_length_max + 1> ranges;
    unsigned int idx, n, i, j;
    while (std::cin >> str) {
        ranges[idx = 0] = i = 0;
        for (i = 0; i <= str.length(); ++i) {
            if (str[i] != str[ranges[idx]]) {
                ranges[++idx] = i;
            }
        }
        std::cin >> n;
        std::cout << "Case " << ++test_case << ":\n";
        while (n-- > 0) {
            std::cin >> i >> j;
            if (i > j) {
                std::swap(i, j);
            }
            std::cout << (
                *std::upper_bound(ranges.begin(), ranges.begin() + idx, i) > j ?
                    "Yes\n" : "No\n"
            );
        }
    }
    return 0;
}
