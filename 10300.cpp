#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n;
    std::cin >> n;
    unsigned int f, farmyard_size, animal_count, env_friendliness, total_burden;
    while (n-- > 0) {
        std::cin >> f;
        total_burden = 0;
        while (f-- > 0) {
            std::cin >> farmyard_size >> animal_count >> env_friendliness;
            total_burden += farmyard_size * env_friendliness;
        }
        std::cout << total_burden << '\n';
    }
    return 0;
}
