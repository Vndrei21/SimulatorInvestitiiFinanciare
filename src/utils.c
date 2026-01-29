#include "utils.h"
void print_bar_chart(int year, double amount, double max_ref) {
    const int MAX_WIDTH = 50;
    if (max_ref <= 0) max_ref = 1;
    int width = (int)((amount / max_ref) * MAX_WIDTH);
    if (width > MAX_WIDTH) width = MAX_WIDTH;
    printf("An %2d | ", year);
    for (int i = 0; i < width; i++) printf("#");
    printf(" (%.0f RON)\n", amount);
}