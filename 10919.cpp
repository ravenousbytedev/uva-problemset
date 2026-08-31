#include <bitset>
#include <ios>
#include <iostream>

constexpr unsigned int course_max = 9999;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int k, m, course;
    std::bitset<course_max + 1> chosen_courses;
    unsigned int c, r, category_courses_taken;
    bool can_graduate;
    while (std::cin >> k, k != 0) {
        std::cin >> m;
        for (unsigned int i = 0; i < k; ++i) {
            std::cin >> course;
            chosen_courses[course] = true;
        }
        can_graduate = true;
        for (unsigned int i = 0; i < m; ++i) {
            std::cin >> c >> r;
            category_courses_taken = 0;
            while (c-- > 0) {
                std::cin >> course;
                if (chosen_courses[course]) {
                    ++category_courses_taken;
                }
            }
            if (category_courses_taken < r) {
                can_graduate = false;
            }
        }
        std::cout << (can_graduate ? "yes\n" : "no\n");
        chosen_courses.reset();
    }
    return 0;
}
