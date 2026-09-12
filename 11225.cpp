#include <ios>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int m;
    std::string card;
    unsigned int oudler_count, double_pts, double_pts_requirement;
    for (unsigned int test_case = 1; test_case <= t; ++test_case) {
        std::cin >> m;
        oudler_count = 0;
        double_pts = 0;
        while (m--) {
            std::cin >> card;
            if (card == "fool" || card == "one" || card == "twenty-one") {
                ++oudler_count;
                double_pts += 4.5 * 2;
            } else if (card == "king") {
                double_pts += 4.5 * 2;
            } else if (card == "queen") {
                double_pts += 3.5 * 2;
            } else if (card == "knight") {
                double_pts += 2.5 * 2;
            } else if (card == "jack") {
                double_pts += 1.5 * 2;
            } else {
                double_pts += 0.5 * 2;
            }
            std::getline(std::cin, card);
        }
        switch (oudler_count) {
        case 0:
            double_pts_requirement = 56 * 2;
            break;
        case 1:
            double_pts_requirement = 51 * 2;
            break;
        case 2:
            double_pts_requirement = 41 * 2;
            break;
        case 3:
            double_pts_requirement = 36 * 2;
        }
        if (test_case != 1) {
            std::cout << '\n';
        }
        std::cout << "Hand #" << test_case << '\n';
        if (double_pts < double_pts_requirement) {
            std::cout
                << "Game lost by "
                << ((double_pts_requirement - double_pts) / 2)
                << " point(s).\n";
        } else {
            std::cout
                << "Game won by "
                << ((double_pts - double_pts_requirement) / 2)
                << " point(s).\n";
        }
    }
    return 0;
}
