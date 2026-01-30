#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "finance.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    double initial = 0, rate = 0, monthly = 0, inflation = 0;
    int years = 0;
    char *csv_file = NULL;
    int scenarios = 0; 

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--initial") == 0 && i+1 < argc) initial = atof(argv[++i]);
        else if (strcmp(argv[i], "--rate") == 0 && i+1 < argc) rate = atof(argv[++i]);
        else if (strcmp(argv[i], "--years") == 0 && i+1 < argc) years = atoi(argv[++i]);
        else if (strcmp(argv[i], "--monthly") == 0 && i+1 < argc) monthly = atof(argv[++i]);
        else if (strcmp(argv[i], "--inflation") == 0 && i+1 < argc) inflation = atof(argv[++i]);
        else if (strcmp(argv[i], "--export") == 0 && i+1 < argc) csv_file = argv[++i];
        else if (strcmp(argv[i], "--scenarios") == 0) scenarios = 1;
    }

    if (initial <= 0 || years <= 0) {
        printf("Usage: ./investment_sim --initial <val> --rate <0.0x> --years <ani> ...\n");
        return 1;
    }

    FILE *fp = NULL;
    if (csv_file) {
        fp = fopen(csv_file, "w");
        if (fp) fprintf(fp, "An,Investit,Sold,Profit\n");
    }

    printf("\n***** Start Simulare ****\n");
    double balance = initial;
    double invested = initial;
    double est_max = initial * pow(1+rate, years) + (monthly * 12 * years);

    for (int y = 1; y <= years; y++) {
        balance = calculate_yearly_balance(balance, rate, monthly);
        invested += monthly * 12;

        double real_val = adjust_for_inflation(balance, inflation, y);
        print_bar_chart(y, real_val, est_max);
        export_to_csv(fp, y, invested, balance, balance - invested);
    }

    if (fp) { fclose(fp); printf("Exportat in %s\n", csv_file); }

    if (scenarios) {
        printf("\n**** Scenarii (Optimist/Pesimist) ****\n");
        double rates[] = {rate - 0.02, rate + 0.02};
        char *lbl[] = {"Pesimist", "Optimist"};

        for (int i=0; i<2; i++) {
            double s = initial;
            for (int y=1; y<=years; y++) s = calculate_yearly_balance(s, rates[i], monthly);
            printf("%s: %.2f\n", lbl[i], s);
        }
    }

    return 0;
}