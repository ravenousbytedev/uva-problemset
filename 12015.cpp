#include <array>
#include <bitset>
#include <ios>
#include <iostream>
#include <string>

constexpr unsigned int site_count = 10;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    std::array<std::string, site_count> urls;
    unsigned int v_i, top;
    std::bitset<site_count> picked_sites;
    for (unsigned int test_case = 1; test_case <= t; ++test_case) {
        top = 0;
        for (unsigned int i = 0; i < site_count; ++i) {
            std::cin >> urls[i] >> v_i;
            if (v_i >= top) {
                if (v_i > top) {
                    top = v_i;
                    picked_sites.reset();
                }
                picked_sites[i] = true;
            }
        }
        std::cout << "Case #" << test_case << ":\n";
        for (unsigned int i = 0; i < site_count; ++i) {
            if (picked_sites[i]) {
                std::cout << urls[i] << '\n';
            }
        }
    }
    return 0;
}
