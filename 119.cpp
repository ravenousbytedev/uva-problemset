#include <array>
#include <ios>
#include <iostream>
#include <string>
#include <unordered_map>

constexpr unsigned int person_count_max = 10;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int person_count;
    std::array<std::string, person_count_max> person_names;
    unsigned int money_spent, gift_count, money_spent_per_gift;
    std::string person_name;
    std::unordered_map<std::string, int> net_worths;
    net_worths.reserve(person_count_max);
    bool is_first = true;
    while (std::cin >> person_count) {
        for (unsigned int i = 0; i < person_count; ++i) {
            std::cin >> person_names[i];
            net_worths[person_names[i]] = 0;
        }
        for (unsigned int i = 0; i < person_count; ++i) {
            std::cin >> person_name >> money_spent >> gift_count;
            if (gift_count == 0) {
                continue;
            }
            money_spent_per_gift = money_spent / gift_count;
            net_worths[person_name] -= money_spent_per_gift * gift_count;
            for (unsigned int j = 0; j < gift_count; ++j) {
                std::cin >> person_name;
                net_worths[person_name] += money_spent_per_gift;
            }
        }
        if (is_first) {
            is_first = false;
        } else {
            std::cout << '\n';
        }
        for (unsigned int i = 0; i < person_count; ++i) {
            std::cout << person_names[i] << ' ' << net_worths[person_names[i]] << '\n';
        }
        net_worths.clear();
    }
    return 0;
}
