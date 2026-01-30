#include "finance.h"
#include <math.h>
double calculate_yearly_balance(double current_balance, double rate, double monthly_contribution) {
    // Calcul lunar pentru precizie
    for (int m = 0; m < 12; m++) {
        current_balance = current_balance * (1.0 + rate / 12.0);
        current_balance += monthly_contribution;
    }
    return current_balance;
}
double adjust_for_inflation(double amount, double inflation_rate, int years) {
    if (inflation_rate == 0) return amount;
    return amount / pow(1.0 + inflation_rate, years);
}