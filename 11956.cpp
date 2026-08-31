#include <array>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

constexpr unsigned int display_mem_size = 100;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t >> std::ws;
    std::string seq;
    std::array<unsigned char, display_mem_size> display_mem;
    unsigned int ptr_idx;
    std::cout << std::uppercase << std::setfill('0');
    for (unsigned int test_case = 1; test_case <= t; ++test_case) {
        std::getline(std::cin, seq);
        display_mem.fill(0);
        ptr_idx = 0;
        for (char command : seq) {
            switch (command) {
            case '>':
                if (++ptr_idx == display_mem_size) {
                    ptr_idx = 0;
                }
                break;
            case '<':
                if (ptr_idx-- == 0) {
                    ptr_idx = display_mem_size - 1;
                }
                break;
            case '+':
                ++display_mem[ptr_idx];
                break;
            case '-':
                --display_mem[ptr_idx];
            }
        }
        std::cout << "Case " << std::dec << test_case << ':' << std::hex;
        for (unsigned char led_val : display_mem) {
            std::cout << ' ' << std::setw(2) << static_cast<unsigned int>(led_val);
        }
        std::cout << '\n';
    }
    return 0;
}
