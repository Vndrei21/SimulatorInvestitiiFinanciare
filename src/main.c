#include <stdio.h>
#include "finance.h"
int main() {
    printf("===Testare initiala===\n");
    double start = 1000;
    double end = calculate_yearly_balance(start, 0.05, 0);
    printf("Suma initiala: 1000, Dupa 1 an (5%%): %.2f\n", end);
    return 0;
}