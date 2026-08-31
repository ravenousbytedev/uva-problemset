#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int h, u, d, f, day;
    double curr_height, curr_climb_distance, fatigue_amount;
    bool succeeds;
    while (std::cin >> h >> u >> d >> f, h != 0) {
        day = 0;
        curr_height = 0.0;
        curr_climb_distance = u;
        fatigue_amount = curr_climb_distance * f / 100.0;
        succeeds = false;
        while (curr_height >= 0.0) {
            ++day;
            curr_height += curr_climb_distance;
            if (curr_height > h) {
                succeeds = true;
                break;
            }
            curr_height -= d;
            if (curr_climb_distance > 0.0) {
                curr_climb_distance -= fatigue_amount;
            }
        }
        std::cout
            << (succeeds ? "success" : "failure")
            << " on day "
            << day
            << '\n';
    }
    return 0;
}
