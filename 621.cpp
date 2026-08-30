#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n;
    std::cin >> n;
    std::string seq;
    while (n-- > 0) {
        std::cin >> seq;
        if (seq == "1" || seq == "4" || seq == "78") {
            std::cout << '+';
        } else if (seq.length() >= 2 && seq.substr(seq.length() - 2) == "35") {
            std::cout << '-';
        } else if (seq.length() >= 2 && seq.front() == '9' && seq.back() == '4') {
            std::cout << '*';
        } else {
            std::cout << '?';
        }
        std::cout << '\n';
    }
    return 0;
}
