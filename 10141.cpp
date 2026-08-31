#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int rfp = 0, n, p;
    std::string requirement, proposal;
    double d;
    unsigned int r;
    std::string best_proposal;
    double best_d;
    unsigned int best_r;
    while (std::cin >> n >> p, n != 0) {
        std::cin >> std::ws;
        for (unsigned int i = 0; i < n; ++i) {
            std::getline(std::cin, requirement);
        }
        best_d = std::numeric_limits<double>::max();
        best_r = 0;
        while (p-- > 0) {
            std::getline(std::cin, proposal);
            std::cin >> d >> r >> std::ws;
            if (r > best_r || (r == best_r && d < best_d)) {
                best_proposal = proposal;
                best_d = d;
                best_r = r;
            }
            while (r-- > 0) {
                std::getline(std::cin, requirement);
            }
        }
        if (rfp > 0) {
            std::cout << '\n';
        }
        std::cout << "RFP #" << ++rfp << '\n' << best_proposal << '\n';
    }
    return 0;
}
