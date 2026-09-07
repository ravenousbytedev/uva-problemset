#include <array>
#include <ios>
#include <iostream>
#include <string>

constexpr unsigned int deck_size = 52, n_max = 100;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case_count;
    std::cin >> test_case_count;
    unsigned int n;
    std::array<std::array<unsigned int, deck_size>, n_max> shuffles;
    std::array<const char *, deck_size>
        starting_deck {
            "2 of Clubs",
            "3 of Clubs",
            "4 of Clubs",
            "5 of Clubs",
            "6 of Clubs",
            "7 of Clubs",
            "8 of Clubs",
            "9 of Clubs",
            "10 of Clubs",
            "Jack of Clubs",
            "Queen of Clubs",
            "King of Clubs",
            "Ace of Clubs",
            "2 of Diamonds",
            "3 of Diamonds",
            "4 of Diamonds",
            "5 of Diamonds",
            "6 of Diamonds",
            "7 of Diamonds",
            "8 of Diamonds",
            "9 of Diamonds",
            "10 of Diamonds",
            "Jack of Diamonds",
            "Queen of Diamonds",
            "King of Diamonds",
            "Ace of Diamonds",
            "2 of Hearts",
            "3 of Hearts",
            "4 of Hearts",
            "5 of Hearts",
            "6 of Hearts",
            "7 of Hearts",
            "8 of Hearts",
            "9 of Hearts",
            "10 of Hearts",
            "Jack of Hearts",
            "Queen of Hearts",
            "King of Hearts",
            "Ace of Hearts",
            "2 of Spades",
            "3 of Spades",
            "4 of Spades",
            "5 of Spades",
            "6 of Spades",
            "7 of Spades",
            "8 of Spades",
            "9 of Spades",
            "10 of Spades",
            "Jack of Spades",
            "Queen of Spades",
            "King of Spades",
            "Ace of Spades"
        },
        deck,
        next_deck;
    std::string k_str;
    unsigned int k;
    while (test_case_count-- > 0) {
        std::cin >> n;
        for (unsigned int i = 0; i < n; ++i) {
            for (unsigned int j = 0; j < deck_size; ++j) {
                std::cin >> shuffles[i][j];
            }
        }
        deck = starting_deck;
        std::cin >> std::ws;
        while (std::getline(std::cin, k_str), !k_str.empty()) {
            k = static_cast<unsigned int>(std::stoi(k_str));
            for (unsigned int i = 0; i < deck_size; ++i) {
                next_deck[i] = deck[shuffles[k - 1][i] - 1];
            }
            deck = next_deck;
        }
        for (const char *card : deck) {
            std::cout << card << '\n';
        }
        if (test_case_count > 0) {
            std::cout << '\n';
        }
    }
    return 0;
}
