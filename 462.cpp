#include <algorithm>
#include <array>
#include <bitset>
#include <ios>
#include <iostream>
#include <iterator>

constexpr unsigned int hand_size = 13, suit_count = 4, face_count = 4;

enum Suit : unsigned int {
    SUIT_S,
    SUIT_H,
    SUIT_D,
    SUIT_C
};

enum Face : unsigned int {
    FACE_A,
    FACE_K,
    FACE_Q,
    FACE_J
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    char rank_ch, suit_ch;
    unsigned int suit, base_hand_strength, extra_hand_strength, total_hand_strength;
    std::array<unsigned int, suit_count> hand_suit_card_counts;
    std::bitset<suit_count> hand_stopped_suits;
    std::array<std::bitset<face_count>, suit_count> hand_suit_faces;
    while (std::cin.peek() != EOF) {
        base_hand_strength = 0;
        extra_hand_strength = 0;
        hand_suit_card_counts.fill(0);
        for (unsigned int i = 0; i < hand_size; ++i) {
            std::cin.get(rank_ch);
            std::cin.get(suit_ch);
            std::cin.get();
            switch (suit_ch) {
            case 'S':
                suit = SUIT_S;
                break;
            case 'H':
                suit = SUIT_H;
                break;
            case 'D':
                suit = SUIT_D;
                break;
            case 'C':
                suit = SUIT_C;
            }
            ++hand_suit_card_counts[suit];
            switch (rank_ch) {
            case 'A':
                base_hand_strength += 4;
                hand_stopped_suits[suit] = true;
                hand_suit_faces[suit][FACE_A] = true;
                break;
            case 'K':
                base_hand_strength += 3;
                hand_suit_faces[suit][FACE_K] = true;
                break;
            case 'Q':
                base_hand_strength += 2;
                hand_suit_faces[suit][FACE_Q] = true;
                break;
            case 'J':
                ++base_hand_strength;
                hand_suit_faces[suit][FACE_J] = true;
            }
        }
        for (unsigned int suit = 0; suit < suit_count; ++suit) {
            if (hand_suit_faces[suit][FACE_K]) {
                if (hand_suit_card_counts[suit] == 1) {
                    --base_hand_strength;
                } else {
                    hand_stopped_suits[suit] = true;
                }
            }
            if (hand_suit_faces[suit][FACE_Q]) {
                if (hand_suit_card_counts[suit] <= 2) {
                    --base_hand_strength;
                } else {
                    hand_stopped_suits[suit] = true;
                }
            }
            if (hand_suit_faces[suit][FACE_J] && hand_suit_card_counts[suit] <= 3) {
                --base_hand_strength;
            }
            if (hand_suit_card_counts[suit] == 2) {
                ++extra_hand_strength;
            } else if (hand_suit_card_counts[suit] <= 1) {
                extra_hand_strength += 2;
            }
        }
        total_hand_strength = base_hand_strength + extra_hand_strength;
        if (total_hand_strength < 14) {
            std::cout << "PASS\n";
        } else if (base_hand_strength >= 16 && hand_stopped_suits.all()) {
            std::cout << "BID NO-TRUMP\n";
        } else {
            std::cout << "BID ";
            switch (
                std::distance(
                    hand_suit_card_counts.begin(),
                    std::max_element(
                        hand_suit_card_counts.begin(),
                        hand_suit_card_counts.end()
                    )
                )
            ) {
            case SUIT_S:
                std::cout << 'S';
                break;
            case SUIT_H:
                std::cout << 'H';
                break;
            case SUIT_D:
                std::cout << 'D';
                break;
            case SUIT_C:
                std::cout << 'C';
            }
            std::cout << '\n';
        }
        hand_stopped_suits.reset();
        hand_suit_faces.fill({});
    }
    return 0;
}
