#include "finance.h"

double calculate_yearly_balance(double current_balance, double rate, double monthly_contribution) {
    // Calcul lunar pentru precizie
    for (int m = 0; m < 12; m++) {
        current_balance = current_balance * (1.0 + rate / 12.0);
        current_balance += monthly_contribution;
    }
    return current_balance;
}