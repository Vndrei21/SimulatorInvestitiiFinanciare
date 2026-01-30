#ifndef FINANCE_H
#define FINANCE_H

// Calculeaza soldul dupa un an (dobanda compusa)
double calculate_yearly_balance(double current_balance, double rate, double monthly_contribution);
double adjust_for_inflation(double amount, double inflation_rate, int years);

#endif