#include <array>
#include <cctype>
#include <ios>
#include <iostream>
#include <utility>

constexpr unsigned int deck_size = 52;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case_count;
    std::cin >> test_case_count;
    std::cin.get();
    std::array<std::pair<char, char>, deck_size> pile;
    unsigned int top, y, x;
    for (unsigned int test_case = 1; test_case <= test_case_count; ++test_case) {
        for (unsigned int i = 0; i < deck_size; ++i) {
            std::cin.get(pile[i].first);
            std::cin.get(pile[i].second);
            std::cin.get();
        }
        top = deck_size - 26;
        y = 0;
        for (unsigned int i = 0; i < 3; ++i) {
            x = std::isdigit(pile[top].first) ? pile[top].first - '0' : 10;
            y += x;
            top -= 11 - x;
        }
        ++top;
        for (unsigned int i = 0; i < 25; ++i) {
            pile[top + i] = pile[deck_size - 25 + i];
        }
        std::cout
            << "Case "
            << test_case
            << ": "
            << pile[y - 1].first
            << pile[y - 1].second
            << '\n';
    }
    return 0;
}
