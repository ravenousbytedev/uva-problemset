#include <ios>
#include <iostream>

constexpr unsigned int turn = 40;

unsigned int diff(unsigned int pos1, unsigned int pos2) {
    return pos1 + (pos1 < pos2 ? turn : 0) - pos2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int init, step1, step2, step3;
    while (
        std::cin >> init >> step1 >> step2 >> step3,
        init != 0 || step1 != 0 || step2 != 0 || step3 != 0
    ) {
        std::cout
            << (
                (3 * turn + diff(init, step1) + diff(step2, step1) + diff(step2, step3)) *
                (360 / turn)
            )
            << '\n';
    }
    return 0;
}
