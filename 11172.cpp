#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int a, b;
    while (t-- > 0) {
        std::cin >> a >> b;
        if (a < b) {
            std::cout << "<\n";
        } else if (a > b) {
            std::cout << ">\n";
        } else {
            std::cout << "=\n";
        }
    }
    return 0;
}
