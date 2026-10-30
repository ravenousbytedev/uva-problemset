#include <array>
#include <cctype>
#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string fen;
    std::array<std::array<char, 8>, 8> board;
    unsigned int y, x, free_squares;
    const auto is_occupied = [&](unsigned int y, unsigned int x) -> bool {
        return board[y][x] != '.' && board[y][x] != 'X';
    };
    const auto attack = [&](unsigned int y, unsigned int x) -> void {
        if (y < 8 && x < 8 && board[y][x] == '.') {
            board[y][x] = 'X';
            --free_squares;
        }
    };
    const auto do_straights = [&]() -> void {
        bool hit_ny = false, hit_py = false, hit_nx = false, hit_px = false;
        for (unsigned int i = 1; i < 8; ++i) {
            if (i > y) {
                hit_ny = true;
            }
            if (y + i >= 8) {
                hit_py = true;
            }
            if (i > x) {
                hit_nx = true;
            }
            if (x + i >= 8) {
                hit_px = true;
            }
            if (!hit_ny) {
                if (is_occupied(y - i, x)) {
                    hit_ny = true;
                } else {
                    attack(y - i, x);
                }
            }
            if (!hit_py) {
                if (is_occupied(y + i, x)) {
                    hit_py = true;
                } else {
                    attack(y + i, x);
                }
            }
            if (!hit_nx) {
                if (is_occupied(y, x - i)) {
                    hit_nx = true;
                } else {
                    attack(y, x - i);
                }
            }
            if (!hit_px) {
                if (is_occupied(y, x + i)) {
                    hit_px = true;
                } else {
                    attack(y, x + i);
                }
            }
        }
    };
    const auto do_diags = [&]() -> void {
        bool hit_nn = false, hit_np = false, hit_pn = false, hit_pp = false;
        for (unsigned int i = 1; i < 8; ++i) {
            if (i > y) {
                hit_nn = true;
                hit_np = true;
            }
            if (y + i >= 8) {
                hit_pn = true;
                hit_pp = true;
            }
            if (i > x) {
                hit_nn = true;
                hit_pn = true;
            }
            if (x + i >= 8) {
                hit_np = true;
                hit_pp = true;
            }
            if (!hit_nn) {
                if (is_occupied(y - i, x - i)) {
                    hit_nn = true;
                } else {
                    attack(y - i, x - i);
                }
            }
            if (!hit_np) {
                if (is_occupied(y - i, x + i)) {
                    hit_np = true;
                } else {
                    attack(y - i, x + i);
                }
            }
            if (!hit_pn) {
                if (is_occupied(y + i, x - i)) {
                    hit_pn = true;
                } else {
                    attack(y + i, x - i);
                }
            }
            if (!hit_pp) {
                if (is_occupied(y + i, x + i)) {
                    hit_pp = true;
                } else {
                    attack(y + i, x + i);
                }
            }
        }
    };
    while (std::getline(std::cin, fen)) {
        y = 0;
        x = 0;
        for (std::array<char, 8> &rank : board) {
            rank.fill('.');
        }
        free_squares = 8 * 8;
        for (char ch : fen) {
            if (std::isdigit(ch)) {
                x += ch - '0';
            } else if (ch == '/') {
                x = 0;
                ++y;
            } else {
                board[y][x++] = ch;
                --free_squares;
            }
        }
        for (y = 0; y < 8; ++y) {
            for (x = 0; x < 8; ++x) {
                switch (board[y][x]) {
                case 'P':
                    attack(y - 1, x - 1);
                    attack(y - 1, x + 1);
                    break;
                case 'p':
                    attack(y + 1, x - 1);
                    attack(y + 1, x + 1);
                    break;
                case 'N':
                case 'n':
                    attack(y - 1, x - 2);
                    attack(y - 1, x + 2);
                    attack(y + 1, x - 2);
                    attack(y + 1, x + 2);
                    attack(y - 2, x - 1);
                    attack(y - 2, x + 1);
                    attack(y + 2, x - 1);
                    attack(y + 2, x + 1);
                    break;
                case 'B':
                case 'b':
                    do_diags();
                    break;
                case 'R':
                case 'r':
                    do_straights();
                    break;
                case 'Q':
                case 'q':
                    do_straights();
                    do_diags();
                    break;
                case 'K':
                case 'k':
                    attack(y - 1, x - 1);
                    attack(y - 1, x);
                    attack(y - 1, x + 1);
                    attack(y, x - 1);
                    attack(y, x + 1);
                    attack(y + 1, x - 1);
                    attack(y + 1, x);
                    attack(y + 1, x + 1);
                }
            }
        }
        std::cout << free_squares << '\n';
    }
    return 0;
}
