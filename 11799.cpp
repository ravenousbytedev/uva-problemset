#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int n, creature_speed, max_creature_speed;
    for (unsigned int test_case = 1; test_case <= t; ++test_case) {
        std::cin >> n;
        max_creature_speed = 0;
        while (n-- > 0) {
            std::cin >> creature_speed;
            if (creature_speed > max_creature_speed) {
                max_creature_speed = creature_speed;
            }
        }
        std::cout << "Case " << test_case << ": " << max_creature_speed << '\n';
    }
    return 0;
}
