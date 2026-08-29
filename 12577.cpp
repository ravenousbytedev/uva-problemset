#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case = 0;
    std::string pilgrimage;
    while (std::cin >> pilgrimage, pilgrimage != "*") {
        std::cout << "Case " << ++test_case << ": ";
        if (pilgrimage == "Hajj") {
            std::cout << "Hajj-e-Akbar\n";
        } else {
            std::cout << "Hajj-e-Asghar\n";
        }
    }
    return 0;
}
