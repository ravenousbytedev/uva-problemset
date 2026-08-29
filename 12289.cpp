#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int word_count;
    std::cin >> word_count;
    std::string word;
    while (word_count-- > 0) {
        std::cin >> word;
        if (word.length() == 5) {
            std::cout << "3\n";
        } else if (
            (word[0] == 't' && word[1] == 'w') ||
            (word[1] == 'w' && word[2] == 'o') ||
            (word[0] == 't' && word[2] == 'o')
        ) {
            std::cout << "2\n";
        } else {
            std::cout << "1\n";
        }
    }
    return 0;
}
