#include <ios>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    unsigned int n, b, h, w, p, a, cost, best;
    while (std::cin >> n >> b >> h >> w) {
        best = b + 1;
        while (h-- > 0) {
            std::cin >> p;
            cost = n * p;
            for (unsigned int i = 0; i < w; ++i) {
                std::cin >> a;
                if (a >= n && cost < best) {
                    best = cost;
                }
            }
        }
        if (best > b) {
            std::cout << "stay home\n";
        } else {
            std::cout << best << '\n';
        }
    }
    return 0;
}
