#include <array>
#include <ios>
#include <iostream>
#include <string>

constexpr unsigned int
    n_max = 100,
    song_word_count = 16,
    special_word_idx = 11;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n;
    std::cin >> n;
    std::array<std::string, n_max> names;
    for (unsigned int i = 0; i < n; ++i) {
        std::cin >> names[i];
    }
    unsigned int i = 0, word_idx = 0;
    bool everyone_has_sung = false;
    do {
        std::cout << names[i] << ": ";
        switch (word_idx % 4) {
        case 0:
            std::cout << "Happy\n";
            break;
        case 1:
            std::cout << "birthday\n";
            break;
        case 2:
            std::cout << "to\n";
            break;
        case 3:
            std::cout << (word_idx == special_word_idx ? "Rujia\n" : "you\n");
        }
        if (++i == n) {
            i = 0;
            everyone_has_sung = true;
        }
        if (++word_idx == song_word_count) {
            word_idx = 0;
        }
    } while (!everyone_has_sung || word_idx != 0);
    return 0;
}
