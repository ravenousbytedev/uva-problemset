#include <array>
#include <cctype>
#include <ios>
#include <iostream>

bool solve(
    bool opposite,
    std::array<std::array<char, 8>, 8> &board,
    unsigned int ky,
    unsigned int kx
) {
    char
        p = opposite ? 'P' : 'p',
        n = opposite ? 'N' : 'n',
        b = opposite ? 'B' : 'b',
        r = opposite ? 'R' : 'r',
        q = opposite ? 'Q' : 'q';
    if (
        (opposite ? ky <= 6 : ky >= 1) &&
        (
            (kx >= 1 && board[opposite ? ky + 1 : ky - 1][kx - 1] == p) ||
            (kx <= 6 && board[opposite ? ky + 1 : ky - 1][kx + 1] == p)
        )
    ) {
        return true;
    }
    if (
        (ky <= 6 && kx <= 5 && board[ky + 1][kx + 2] == n) ||
        (ky <= 5 && kx <= 6 && board[ky + 2][kx + 1] == n) ||
        (ky <= 6 && kx >= 2 && board[ky + 1][kx - 2] == n) ||
        (ky <= 5 && kx >= 1 && board[ky + 2][kx - 1] == n) ||
        (ky >= 1 && kx <= 5 && board[ky - 1][kx + 2] == n) ||
        (ky >= 2 && kx <= 6 && board[ky - 2][kx + 1] == n) ||
        (ky >= 1 && kx >= 2 && board[ky - 1][kx - 2] == n) ||
        (ky >= 2 && kx >= 1 && board[ky - 2][kx - 1] == n)
    ) {
        return true;
    }
    for (unsigned int i = 1; ky + i < 8 && kx + i < 8; ++i) {
        if (board[ky + i][kx + i] == b || board[ky + i][kx + i] == q) {
            return true;
        } else if (board[ky + i][kx + i] != '.') {
            break;
        }
    }
    for (unsigned int i = 1; ky + i < 8 && kx >= i; ++i) {
        if (board[ky + i][kx - i] == b || board[ky + i][kx - i] == q) {
            return true;
        } else if (board[ky + i][kx - i] != '.') {
            break;
        }
    }
    for (unsigned int i = 1; ky >= i && kx + i < 8; ++i) {
        if (board[ky - i][kx + i] == b || board[ky - i][kx + i] == q) {
            return true;
        } else if (board[ky - i][kx + i] != '.') {
            break;
        }
    }
    for (unsigned int i = 1; ky >= i && kx >= i; ++i) {
        if (board[ky - i][kx - i] == b || board[ky - i][kx - i] == q) {
            return true;
        } else if (board[ky - i][kx - i] != '.') {
            break;
        }
    }
    for (unsigned int y = ky + 1; y < 8; ++y) {
        if (board[y][kx] == r || board[y][kx] == q) {
            return true;
        } else if (board[y][kx] != '.') {
            break;
        }
    }
    for (unsigned int y = ky; y-- > 0; ) {
        if (board[y][kx] == r || board[y][kx] == q) {
            return true;
        } else if (board[y][kx] != '.') {
            break;
        }
    }
    for (unsigned int x = kx + 1; x < 8; ++x) {
        if (board[ky][x] == r || board[ky][x] == q) {
            return true;
        } else if (board[ky][x] != '.') {
            break;
        }
    }
    for (unsigned int x = kx; x-- > 0; ) {
        if (board[ky][x] == r || board[ky][x] == q) {
            return true;
        } else if (board[ky][x] != '.') {
            break;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case = 0;
    std::array<std::array<char, 8>, 8> board;
    unsigned int ky1, kx1, ky2, kx2;
    while (true) {
        ky1 = 8;
        for (unsigned int y = 0; y < 8; ++y) {
            for (unsigned int x = 0; x < 8; ++x) {
                std::cin.get(board[y][x]);
                if (board[y][x] == 'K') {
                    ky1 = y;
                    kx1 = x;
                } else if (board[y][x] == 'k') {
                    ky2 = y;
                    kx2 = x;
                }
            }
            std::cin.get();
        }
        if (ky1 == 8) {
            break;
        }
        std::cin.get();
        std::cout << "Game #" << ++test_case << ": ";
        if (solve(false, board, ky1, kx1)) {
            std::cout << "white";
        } else if (solve(true, board, ky2, kx2)) {
            std::cout << "black";
        } else {
            std::cout << "no";
        }
        std::cout << " king is in check.\n";
    }
    return 0;
}
