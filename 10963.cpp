#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int t;
    std::cin >> t;
    unsigned int w;
    int y1, y2, landmass_size;
    bool can_be_closed;
    while (t-- > 0) {
        std::cin >> w >> y1 >> y2;
        landmass_size = y1 - y2;
        can_be_closed = true;
        while (--w > 0) {
            std::cin >> y1 >> y2;
            if (y1 - y2 != landmass_size) {
                can_be_closed = false;
            }
        }
        std::cout << (can_be_closed ? "yes\n" : "no\n");
        if (t > 0) {
            std::cout << '\n';
        }
    }
    return 0;
}
