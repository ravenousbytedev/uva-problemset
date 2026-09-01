#include <array>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>

constexpr unsigned int deck_size = 52;

unsigned int sim(
    std::array<std::vector<char>, 3> &decks,
    unsigned int player,
    unsigned int count,
    bool is_face
) {
    while (count-- > 0) {
        if (decks[player].empty()) {
            return player == 1 ? 2 : 1;
        }
        decks[0].push_back(decks[player].back());
        decks[player].pop_back();
        switch (decks[0].back()) {
        case 'J':
            count = 1;
            break;
        case 'Q':
            count = 2;
            break;
        case 'K':
            count = 3;
            break;
        case 'A':
            count = 4;
            break;
        default:
            continue;
        }
        return sim(decks, player == 1 ? 2 : 1, count, true);
    }
    if (is_face) {
        decks[player == 1 ? 2 : 1].insert(
            decks[player == 1 ? 2 : 1].begin(),
            decks[0].rbegin(),
            decks[0].rend()
        );
        decks[0].clear();
    }
    return sim(decks, player == 1 ? 2 : 1, 1, false);
}

unsigned int sim(std::array<std::vector<char>, 3> &decks) {
    return sim(decks, 2, 1, false);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::array<std::vector<char>, 3> decks;
    decks[0].reserve(deck_size);
    decks[1].reserve(deck_size);
    decks[2].reserve(deck_size);
    unsigned int winner;
    std::cout << std::setfill(' ');
    while (std::cin.get() != '#') {
        decks[2].push_back(std::cin.get());
        std::cin.get();
        for (unsigned int i = 1; i < deck_size; ++i) {
            std::cin.get();
            decks[(~i & 1) + 1].push_back(std::cin.get());
            std::cin.get();
        }
        winner = sim(decks);
        std::cout << winner << std::setw(3) << decks[winner].size() << '\n';
        decks[0].clear();
        decks[winner].clear();
    }
    return 0;
}
