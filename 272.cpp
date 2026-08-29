#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    char ch;
    bool is_in_quotes = false;
    while (std::cin.get(ch)) {
        if (ch != '"') {
            std::cout << ch;
        } else {
            std::cout
                << (is_in_quotes ? '\'' : '`')
                << (is_in_quotes ? '\'' : '`');
            is_in_quotes = !is_in_quotes;
        }
    }
    return 0;
}
