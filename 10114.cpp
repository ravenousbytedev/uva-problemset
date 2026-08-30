#include <array>
#include <ios>
#include <iostream>

constexpr int loan_dur_max = 100;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int loan_dur;
    double down_payment, loan_amount;
    unsigned int depreciation_record_count, month_no;
    std::array<double, loan_dur_max + 1> depreciation_percentages;
    double debt, car_val;
    while (
        std::cin
            >> loan_dur
            >> down_payment
            >> loan_amount
            >> depreciation_record_count,
        loan_dur >= 0
    ) {
        std::cin >> month_no >> depreciation_percentages[0];
        std::fill(
            depreciation_percentages.begin() + 1,
            depreciation_percentages.begin() + loan_dur + 1,
            depreciation_percentages[0]
        );
        while (--depreciation_record_count > 0) {
            std::cin >> month_no >> depreciation_percentages[month_no];
            std::fill(
                depreciation_percentages.begin() + month_no + 1,
                depreciation_percentages.begin() + loan_dur + 1,
                depreciation_percentages[month_no]
            );
        }
        debt = loan_amount + loan_amount / loan_dur;
        car_val = loan_amount + down_payment;
        for (int i = 0; i <= loan_dur; ++i) {
            debt -= loan_amount / loan_dur;
            car_val *= 1 - depreciation_percentages[i];
            if (debt < car_val) {
                std::cout << i << " month" << (i == 1 ? "" : "s") << '\n';
                break;
            }
        }
    }
    return 0;
}
