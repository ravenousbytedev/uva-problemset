#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    char ch;
    while (std::cin.get(ch)) {
        std::cout << ch;
    }
    return 0;
}
