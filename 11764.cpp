#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int n, src_height, dst_height, high_jump_count, low_jump_count;
    for (unsigned int test_case = 1; test_case <= t; ++test_case) {
        std::cin >> n >> dst_height;
        high_jump_count = 0;
        low_jump_count = 0;
        while (--n > 0) {
            src_height = dst_height;
            std::cin >> dst_height;
            if (src_height != dst_height) {
                ++(src_height < dst_height ? high_jump_count : low_jump_count);
            }
        }
        std::cout
            << "Case "
            << test_case
            << ": "
            << high_jump_count
            << ' '
            << low_jump_count
            << '\n';
    }
    return 0;
}
