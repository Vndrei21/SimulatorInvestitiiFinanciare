#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
void print_bar_chart(int year, double amount, double max_ref);
void export_to_csv(FILE *fp, int year, double invested, double balance, double profit);
#endif