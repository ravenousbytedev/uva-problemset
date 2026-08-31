#include <ios>
#include <iostream>
#include <limits>
#include <string>

unsigned int next_x_i(unsigned int x_i) {
    unsigned int result = 0;
    while (x_i > 0) {
        ++result;
        x_i /= 10;
    }
    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string input;
    unsigned int i, x_i, x_i_1;
    while (std::getline(std::cin, input), input != "END") {
        if (input == "1") {
            std::cout << "1\n";
            continue;
        }
        x_i = input.length();
        for (i = 2; (x_i_1 = next_x_i(x_i)) != x_i; ++i) {
            x_i = x_i_1;
        }
        std::cout << i << '\n';
    }
    return 0;
}
