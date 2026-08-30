#include <ios>
#include <iostream>

unsigned int f(unsigned int n) {
    unsigned int result = 0;
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

unsigned int g(unsigned int n) {
    while (n >= 10) {
        n = f(n);
    }
    return n;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned int n;
    while (std::cin >> n, n != 0) {
        std::cout << g(n) << '\n';
    }
    return 0;
}
