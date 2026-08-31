#include <ios>
#include <iostream>
#include <string>

constexpr unsigned int l_max = 2000000;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int l;
    std::string s;
    bool r_is_found, d_is_found;
    unsigned int r_idx, d_idx, curr_distance, min_distance;
    while (std::cin >> l, l != 0) {
        std::cin >> s;
        r_is_found = false;
        d_is_found = false;
        min_distance = l_max;
        for (unsigned int i = 0; i < s.length(); ++i) {
            if (s[i] == '.') {
                continue;
            } else if (s[i] == 'Z') {
                min_distance = 0;
                break;
            } else if (s[i] == 'R') {
                r_is_found = true;
                r_idx = i;
            } else if (s[i] == 'D') {
                d_is_found = true;
                d_idx = i;
            }
            if (
                r_is_found &&
                d_is_found &&
                (curr_distance = r_idx < d_idx ? d_idx - r_idx : r_idx - d_idx) <
                min_distance
            ) {
                min_distance = curr_distance;
            }
        }
        std::cout << min_distance << '\n';
    }
    return 0;
}
