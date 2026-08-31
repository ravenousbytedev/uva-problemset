#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int test_case_count;
    std::cin >> test_case_count >> std::ws;
    unsigned int m_end_count, f_end_count;
    while (test_case_count-- > 0) {
        m_end_count = 0;
        f_end_count = 0;
        do {
            ++(std::cin.get() == 'M' ? m_end_count : f_end_count);
            ++(std::cin.get() == 'M' ? m_end_count : f_end_count);
        } while (std::cin.get() != '\n');
        std::cout
            << (
                m_end_count == f_end_count && m_end_count != 1 ?
                    "LOOP\n" : "NO LOOP\n"
            );
    }
    return 0;
}
