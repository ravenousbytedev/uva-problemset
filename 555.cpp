#include <algorithm>
#include <array>
#include <ios>
#include <iostream>

constexpr unsigned int
    deck_size = 52, player_count = 4, hand_size = deck_size / player_count;

class Card {
    enum Suit : unsigned int {
        SUIT_C,
        SUIT_D,
        SUIT_S,
        SUIT_H,
        SUIT_UNDEFINED
    };
    enum Rank : unsigned int {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_T,
        RANK_J,
        RANK_Q,
        RANK_K,
        RANK_A,
        RANK_UNDEFINED
    };
    char suit_ch, rank_ch;
    unsigned int suit, rank;
public:
    Card() :
        suit_ch { '\0' },
        rank_ch { '\0' },
        suit { SUIT_UNDEFINED },
        rank { RANK_UNDEFINED }
    {}
    Card(char suit_ch, char rank_ch) :
        suit_ch { suit_ch },
        rank_ch { rank_ch },
        suit { SUIT_UNDEFINED },
        rank { RANK_UNDEFINED }
    {
        switch (suit_ch) {
        case 'C':
            suit = SUIT_C;
            break;
        case 'D':
            suit = SUIT_D;
            break;
        case 'S':
            suit = SUIT_S;
            break;
        case 'H':
            suit = SUIT_H;
        }
        switch (rank_ch) {
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            rank = rank_ch - '2';
            break;
        case 'T':
            rank = RANK_T;
            break;
        case 'J':
            rank = RANK_J;
            break;
        case 'Q':
            rank = RANK_Q;
            break;
        case 'K':
            rank = RANK_K;
            break;
        case 'A':
            rank = RANK_A;
        }
    }
    bool operator<(const Card &other) const {
        return suit < other.suit || (suit == other.suit && rank < other.rank);
    }
    friend std::ostream &operator<<(std::ostream &os, const Card &self) {
        os << self.suit_ch << self.rank_ch;
        return os;
    }
};

constexpr std::array<char, 4> sides { 'S', 'W', 'N', 'E' };

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    char dealer_side, suit_ch, rank_ch;
    std::array<std::array<Card, hand_size>, player_count> hands;
    unsigned int i, j;
    while (std::cin.get(dealer_side), std::cin.get(), dealer_side != '#') {
        switch (dealer_side) {
        case 'S':
            j = 0;
            break;
        case 'W':
            j = 1;
            break;
        case 'N':
            j = 2;
            break;
        case 'E':
            j = 3;
        }
        for (i = 0; i < deck_size / 2; ++i) {
            std::cin.get(suit_ch);
            std::cin.get(rank_ch);
            hands[++j == player_count ? (j = 0) : j][i / player_count] =
                { suit_ch, rank_ch };
        }
        std::cin.get();
        for (; i < deck_size; ++i) {
            std::cin.get(suit_ch);
            std::cin.get(rank_ch);
            hands[++j == player_count ? (j = 0) : j][i / player_count] =
                { suit_ch, rank_ch };
        }
        std::cin.get();
        for (j = 0; j < player_count; ++j) {
            std::sort(hands[j].begin(), hands[j].end());
            std::cout << sides[j] << ':';
            for (const Card &card : hands[j]) {
                std::cout << ' ' << card;
            }
            std::cout << '\n';
        }
    }
    return 0;
}
