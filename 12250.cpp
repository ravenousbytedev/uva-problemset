#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case = 0;
    std::string s;
    while (std::cin >> s, s != "#") {
        std::cout << "Case " << ++test_case << ": ";
        if (s == "HELLO") {
            std::cout << "ENGLISH\n";
        } else if (s == "HOLA") {
            std::cout << "SPANISH\n";
        } else if (s == "HALLO") {
            std::cout << "GERMAN\n";
        } else if (s == "BONJOUR") {
            std::cout << "FRENCH\n";
        } else if (s == "CIAO") {
            std::cout << "ITALIAN\n";
        } else if (s == "ZDRAVSTVUJTE") {
            std::cout << "RUSSIAN\n";
        } else {
            std::cout << "UNKNOWN\n";
        }
    }
    return 0;
}
