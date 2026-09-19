#include <algorithm>
#include <ios>
#include <iostream>

const char
    *illegal_move = "Illegal move\n",
    *move_not_allowed = "Move not allowed\n";

void solve(
    unsigned int king_a,
    unsigned int king_b,
    unsigned int queen_a,
    unsigned int queen_b,
    unsigned int queen_move_a,
    unsigned int queen_move_b
) {
    if (
        king_a == queen_a &&
        king_b >= std::min(queen_b, queen_move_b) &&
        king_b <= std::max(queen_b, queen_move_b)
    ) {
        std::cout << illegal_move;
    } else if (
        king_a == queen_a &&
        (
            king_b + 1 == queen_move_b ||
            king_b - 1 == queen_move_b
        )
    ) {
        std::cout << move_not_allowed;
    } else if (
        (
            king_a + 1 == queen_a ||
            king_a - 1 == queen_a
        ) &&
        queen_move_b == king_b
    ) {
        std::cout << move_not_allowed;
    } else if (
        (
            king_a == 0 &&
            king_b == 0 &&
            queen_move_a == 1 &&
            queen_move_b == 1
        ) ||
        (
            king_a == 7 &&
            king_b == 0 &&
            queen_move_a == 6 &&
            queen_move_b == 1
        ) ||
        (
            king_a == 0 &&
            king_b == 7 &&
            queen_move_a == 1 &&
            queen_move_b == 6
        ) ||
        (
            king_a == 7 &&
            king_b == 7 &&
            queen_move_a == 6 &&
            queen_move_b == 6
        )
    ) {
        std::cout << "Stop\n";
    } else {
        std::cout << "Continue\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int place, king_x, king_y, queen_x, queen_y, queen_move_x, queen_move_y;
    while (std::cin >> place) {
        king_x = place % 8;
        king_y = place / 8;
        std::cin >> place;
        queen_x = place % 8;
        queen_y = place / 8;
        std::cin >> place;
        queen_move_x = place % 8;
        queen_move_y = place / 8;
        if (king_x == queen_x && king_y == queen_y) {
            std::cout << "Illegal state\n";
        } else if (queen_x == queen_move_x && queen_y == queen_move_y) {
            std::cout << illegal_move;
        } else if (queen_x == queen_move_x) {
            solve(king_x, king_y, queen_x, queen_y, queen_move_x, queen_move_y);
        } else if (queen_y == queen_move_y) {
            solve(king_y, king_x, queen_y, queen_x, queen_move_y, queen_move_x);
        } else {
            std::cout << illegal_move;
        }
    }
    return 0;
}
