#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int l;
    std::string axis, decision;
    while (std::cin >> l, l != 0) {
        axis = "+x";
        while (--l > 0) {
            std::cin >> decision;
            if (decision == "No") {
                continue;
            } else if (axis == "+x") {
                axis = decision;
            } else if (axis == "-x") {
                axis[0] = decision[0] == '+' ? '-' : '+';
                axis[1] = decision[1];
            } else if (axis == decision) {
                axis = "-x";
            } else if (axis[1] == decision[1]) {
                axis = "+x";
            }
        }
        std::cout << axis << '\n';
    }
    return 0;
}
