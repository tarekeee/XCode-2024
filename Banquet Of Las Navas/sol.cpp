#include <iostream>
#include <vector>

int main() {
    int T;
    std::cin >> T;

    for (int t = 1; t <= T; ++t) {
        long long P, L;
        std::cin >> P >> L;

        std::vector<long long> divisors;

        for (long long i = 1; i * i <= (P - L); ++i) {
            if ((P - L) % i == 0) {
                if (i > L) {
                    divisors.push_back(i);
                }
                if (i != (P - L) / i && (P - L) / i > L) {
                    divisors.push_back((P - L) / i);
                }
            }
        }

        std::cout << "Case " << t << ":";
        if (divisors.empty()) {
            std::cout << " impossible" << std::endl;
        } else {
            std::sort(divisors.begin(), divisors.end());
            for (long long divisor : divisors) {
                std::cout << " " << divisor;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}