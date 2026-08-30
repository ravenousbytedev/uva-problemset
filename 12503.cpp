#include <bitset>
#include <ios>
#include <iostream>
#include <string>

constexpr unsigned int n_max = 100;

constexpr bool command_left = false, command_right = true;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int n;
    std::string command_text;
    unsigned int idx;
    std::bitset<n_max + 1> commands;
    int p;
    while (t-- > 0) {
        std::cin >> n;
        p = 0;
        for (unsigned int i = 1; i <= n; ++i) {
            std::cin >> command_text;
            if (command_text == "LEFT") {
                commands[i] = command_left;
                --p;
            } else if (command_text == "RIGHT") {
                commands[i] = command_right;
                ++p;
            } else {
                std::cin >> command_text >> idx;
                commands[i] = commands[idx];
                if (commands[idx] == command_left) {
                    --p;
                } else {
                    ++p;
                }
            }
        }
        std::cout << p << '\n';
    }
    return 0;
}
