#include <cctype>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <utility>

unsigned int digit_sum(unsigned int val) {
    unsigned int result = 0;
    while (val > 0) {
        result += val % 10;
        val /= 10;
    }
    return result;
}

unsigned int recursive_digit_sum(unsigned int val) {
    while (val >= 10) {
        val = digit_sum(val);
    }
    return val;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string name1, name2;
    unsigned int val1, val2;
    std::cout << std::fixed;
    std::cout.precision(2);
    while (std::getline(std::cin, name1), !name1.empty()) {
        std::getline(std::cin, name2);
        val1 = 0;
        for (char ch : name1) {
            if (std::isalpha(ch)) {
                val1 += std::tolower(ch) - 'a' + 1;
            }
        }
        val1 = recursive_digit_sum(val1);
        val2 = 0;
        for (char ch : name2) {
            if (std::isalpha(ch)) {
                val2 += std::tolower(ch) - 'a' + 1;
            }
        }
        val2 = recursive_digit_sum(val2);
        if (val1 > val2) {
            std::swap(val1, val2);
        }
        std::cout << (static_cast<double>(val1) * 100 / val2) << " %\n";
    }
    return 0;
}
