#include <algorithm>
#include <array>
#include <bitset>
#include <ios>
#include <iostream>
#include <utility>

constexpr unsigned int deck_size = 52, hand_size = 3;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::array<unsigned int, hand_size> abc;
    std::array<unsigned int, hand_size - 1> xy;
    unsigned int z;
    std::bitset<deck_size + 1> dealt_cards;
    while (std::cin >> abc[0] >> abc[1] >> abc[2] >> xy[0] >> xy[1], abc[0] != 0) {
        for (unsigned int i : abc) {
            dealt_cards[i] = true;
        }
        for (unsigned int i : xy) {
            dealt_cards[i] = true;
        }
        std::sort(abc.begin(), abc.end());
        if (xy[0] > xy[1]) {
            std::swap(xy[0], xy[1]);
        }
        z = deck_size + 1;
        if (xy[0] > abc[2]) {
            for (unsigned int i = 1; i <= deck_size; ++i) {
                if (!dealt_cards[i]) {
                    z = i;
                    break;
                }
            }
        } else {
            if (xy[1] > abc[2]) {
                for (unsigned int i = abc[2] + 1; i <= deck_size; ++i) {
                    if (!dealt_cards[i]) {
                        z = i;
                        break;
                    }
                }
            }
            if (xy[0] > abc[1] && abc[1] + 1 < z) {
                for (unsigned int i = abc[1] + 1; i <= deck_size; ++i) {
                    if (!dealt_cards[i]) {
                        z = i;
                        break;
                    }
                }
            }
        }
        if (z == deck_size + 1) {
            std::cout << "-1\n";
        } else {
            std::cout << z << '\n';
        }
        dealt_cards.reset();
    }
    return 0;
}
