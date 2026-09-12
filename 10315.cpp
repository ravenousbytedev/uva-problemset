#include <algorithm>
#include <array>
#include <bitset>
#include <functional>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>

constexpr unsigned int
    hand_size = 5,
    player_count = 2,
    rank_count = 13,
    suit_count = 4,
    black = 0,
    white = 1;

const char *black_win = "Black wins.\n", *white_win = "White wins.\n";

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string input;
    unsigned int rank, suit;
    std::array<std::array<unsigned int, hand_size>, player_count> hand_ranks;
    std::array<std::array<unsigned int, rank_count>, player_count> hand_rank_count;
    std::array<std::array<unsigned int, suit_count>, player_count> hand_suit_count;
    std::bitset<player_count> flush, straight;
    std::array<std::bitset<rank_count>, player_count> pairs;
    std::array<unsigned int, player_count>
        highest_card_rank, four_of_a_kind, three_of_a_kind;
    while (std::getline(std::cin, input)) {
        hand_rank_count[black].fill(0);
        hand_rank_count[white].fill(0);
        hand_suit_count[black].fill(0);
        hand_suit_count[white].fill(0);
        flush.reset();
        straight.reset();
        pairs[black].reset();
        pairs[white].reset();
        highest_card_rank.fill(0);
        four_of_a_kind.fill(rank_count);
        three_of_a_kind.fill(rank_count);
        for (unsigned int i = 0; i < player_count; ++i) {
            for (unsigned int j = 0; j < hand_size; ++j) {
                switch (input[hand_size * 3 * i + j * 3]) {
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    rank = input[hand_size * 3 * i + j * 3] - '2';
                    break;
                case 'T':
                    rank = 8;
                    break;
                case 'J':
                    rank = 9;
                    break;
                case 'Q':
                    rank = 10;
                    break;
                case 'K':
                    rank = 11;
                    break;
                case 'A':
                    rank = 12;
                }
                switch (input[hand_size * 3 * i + j * 3 + 1]) {
                case 'C':
                    suit = 0;
                    break;
                case 'D':
                    suit = 1;
                    break;
                case 'S':
                    suit = 2;
                    break;
                case 'H':
                    suit = 3;
                }
                hand_ranks[i][j] = rank;
                switch (++hand_rank_count[i][rank]) {
                case 4:
                    three_of_a_kind[i] = rank_count;
                    four_of_a_kind[i] = rank;
                    break;
                case 3:
                    pairs[i][rank] = false;
                    three_of_a_kind[i] = rank;
                    break;
                case 2:
                    pairs[i][rank] = true;
                }
                if (rank > highest_card_rank[i]) {
                    highest_card_rank[i] = rank;
                }
                if (++hand_suit_count[i][suit] == hand_size) {
                    flush[i] = true;
                }
            }
            std::sort(
                hand_ranks[i].begin(),
                hand_ranks[i].end(),
                std::greater<unsigned int> {}
            );
            unsigned int idx = std::distance(
                hand_rank_count[i].begin(),
                std::find(hand_rank_count[i].begin(), hand_rank_count[i].end(), 1)
            );
            if (idx <= rank_count - hand_size) {
                straight[i] = true;
                for (unsigned int j = 1; j < hand_size; ++j) {
                    if (hand_rank_count[i][idx + j] != 1) {
                        straight[i] = false;
                        break;
                    }
                }
            }
        }
        if (straight[black] && flush[black]) {
            if (straight[white] && flush[white]) {
                if (highest_card_rank[black] != highest_card_rank[white]) {
                    std::cout << (
                        highest_card_rank[black] > highest_card_rank[white] ?
                            black_win : white_win
                    );
                    continue;
                }
            } else {
                std::cout << black_win;
                continue;
            }
        } else if (straight[white] && flush[white]) {
            std::cout << white_win;
            continue;
        }
        if (four_of_a_kind[black] != rank_count) {
            if (four_of_a_kind[white] != rank_count) {
                std::cout << (
                    four_of_a_kind[black] > four_of_a_kind[white] ?
                        black_win : white_win
                );
            } else {
                std::cout << black_win;
            }
            continue;
        } else if (four_of_a_kind[white] != rank_count) {
            std::cout << white_win;
            continue;
        }
        if (three_of_a_kind[black] != rank_count && pairs[black].any()) {
            if (three_of_a_kind[white] != rank_count && pairs[white].any()) {
                std::cout << (
                    three_of_a_kind[black] > three_of_a_kind[white] ?
                        black_win : white_win
                );
            } else {
                std::cout << black_win;
            }
            continue;
        } else if (three_of_a_kind[white] != rank_count && pairs[white].any()) {
            std::cout << white_win;
            continue;
        }
        if (flush[black]) {
            if (flush[white]) {
                if (hand_ranks[black] != hand_ranks[white]) {
                    std::cout << (
                        hand_ranks[black] > hand_ranks[white] ?
                            black_win : white_win
                    );
                    continue;
                }
            } else {
                std::cout << black_win;
                continue;
            }
        } else if (flush[white]) {
            std::cout << white_win;
            continue;
        }
        if (hand_ranks[black] == hand_ranks[white]) {
            std::cout << "Tie.\n";
            continue;
        }
        if (straight[black]) {
            if (straight[white]) {
                std::cout << (
                    hand_ranks[black].front() > hand_ranks[white].front() ?
                        black_win : white_win
                );
            } else {
                std::cout << black_win;
            }
            continue;
        } else if (straight[white]) {
            std::cout << white_win;
            continue;
        }
        if (three_of_a_kind[black] != rank_count) {
            if (three_of_a_kind[white] != rank_count) {
                std::cout << (
                    three_of_a_kind[black] > three_of_a_kind[white] ?
                        black_win : white_win
                );
            } else {
                std::cout << black_win;
            }
            continue;
        } else if (three_of_a_kind[white] != rank_count) {
            std::cout << white_win;
            continue;
        }
        if (pairs[black].count() == 2) {
            if (pairs[white].count() == 2) {
                std::array<unsigned int, player_count>
                    high_pair_rank { 0, 0 }, low_pair_rank, other_rank;
                for (unsigned int i = 0; i < player_count; ++i) {
                    for (unsigned int j = 0; j < hand_size - 1; ++j) {
                        if (hand_ranks[i][j] != hand_ranks[i][j + 1]) {
                            other_rank[i] = hand_ranks[i][j];
                            continue;
                        } else if (hand_ranks[i][++j] > high_pair_rank[i]) {
                            low_pair_rank[i] = high_pair_rank[i];
                            high_pair_rank[i] = hand_ranks[i][j];
                        } else {
                            low_pair_rank[i] = hand_ranks[i][j];
                        }
                    }
                }
                if (high_pair_rank[black] != high_pair_rank[white]) {
                    std::cout << (
                        high_pair_rank[black] > high_pair_rank[white] ?
                            black_win : white_win
                    );
                } else if (low_pair_rank[black] != low_pair_rank[white]) {
                    std::cout << (
                        low_pair_rank[black] > low_pair_rank[white] ?
                            black_win : white_win
                    );
                } else {
                    std::cout << (
                        other_rank[black] > other_rank[white] ? black_win : white_win
                    );
                }
            } else {
                std::cout << black_win;
            }
            continue;
        } else if (pairs[white].count() == 2) {
            std::cout << white_win;
            continue;
        }
        if (pairs[black].count() == 1) {
            if (pairs[white].count() == 1) {
                std::array<unsigned int, player_count> pair_rank;
                for (unsigned int i = 0; i < player_count; ++i) {
                    for (unsigned int j = 0; j < hand_size - 1; ++j) {
                        if (hand_ranks[i][j] == hand_ranks[i][j + 1]) {
                            pair_rank[i] = hand_ranks[i][j];
                            hand_ranks[i][j] = 0;
                            hand_ranks[i][j + 1] = 0;
                            break;
                        }
                    }
                    std::sort(
                        hand_ranks[i].begin(),
                        hand_ranks[i].end(),
                        std::greater<unsigned int> {}
                    );
                }
                if (pair_rank[black] != pair_rank[white]) {
                    std::cout << (
                        pair_rank[black] > pair_rank[white] ? black_win : white_win
                    );
                } else {
                    std::cout << (
                        hand_ranks[black] > hand_ranks[white] ? black_win : white_win
                    );
                }
            } else {
                std::cout << black_win;
            }
            continue;
        } else if (pairs[white].count() == 1) {
            std::cout << white_win;
            continue;
        }
        std::cout << (
            hand_ranks[black] > hand_ranks[white] ? black_win : white_win
        );
    }
    return 0;
}
