// Prediction of CORONAVIRUS COVID-19 CASES in the USA JAN 22 - APRIL 26, 2020
#include <iostream>
#include <random>
#include <ctime>
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#define usa_population 3.306e8
#define DBL_MAX 1.79769e+308
#define RUNS 100000000

using namespace std;

// Initialize VAR
unsigned seed;
default_random_engine generator(seed);
uniform_real_distribution<double> spread(1, 96); // Creates a random number in the bounds of 1. and 96.
uniform_real_distribution<double> infected(1., usa_population);
uniform_real_distribution<double> mortality(0., 1.);


// Build  generators
double spread_time() {
    return spread(generator);
}
double predicted_cases() {
    return infected(generator);
}

double mortality_cases() {
    return mortality(generator);
}


int main(int argc, char** argv) {


        // SOURCE:  CDC- Number of COVID-19 Cases 
            double cdc_n_value = 957875;
            double error_cdc = sqrt(cdc_n_value);
            double avg_x = 61.81818182;
            double avg_y = 262134.2273;
            double x; double step_size = 1e6;
            double dead = 0., recovered = 0.; long int j = 0;
            double new_population = usa_population + 1.77e3; // Average daily birth rate us
      
            // QUARTIC REGRESSION EQ COMPARISON PARAM.
            double chisq = DBL_MAX;
            //double chisqe_min = chisq/n-m which is chisq / (n-#ofparameters)
            double n = 4;
            double dof = 3;
            double error = sqrt(n);
           for (double i = 1.; i < new_population; i++) {
                double infected = 1.;  double f1 = 4205.149 - 4525.719 * x + 329.6756 * pow(x, 2) - 8.189336 * pow(x, 3) + 0.06779979 * pow(x, 4);
                if ( i < f1) {
                    double new_cases = f1 * step_size;
                    double infected_tspread = new_cases * step_size;
                    cout << infected_tspread << "," << new_cases << endl;
                    if (chisq < cdc_n_value) // If smaller than current value stored in a variable  then increment 
                        chisq+=DBL_MAX;
                        i++;
                    
                }
            } 
        // EXPONENTIAL EQ COMP. PARAM.
            double chisq1 = DBL_MAX;
            double n1 = 3;
            double dof1 = 2;
            double error1 = sqrt(n1);
            double y0 = 39268.81;
            double v0 = .1189847764;
            double k = 10.9731324;
           
            double f2 = 39268.81 - (0.1189847764 / 10.9731324) * (1 - exp(10.9731324 * x));
            for (double i = 1.; i < new_population; i++) {
                double infected = 1.;
                if (i < f2) {
                    double new_cases = f2 * step_size;
                    double infected_tspread = new_cases * step_size;
                    cout << infected_tspread << "," << new_cases << endl;
                    if (chisq1 < cdc_n_value) // if smaller than current value stored in a variable
                    chisq1+=DBL_MAX;
                    i++;
                    //cout << chisq1 << endl;
                }
            }


            // 2 SIGMOIDS

            // SYMM SIGMOID COMPAR. PARAM
            double chisq2 = DBL_MAX;
            double n2 = 4;
            double dof2 = 3;
            double error2 = sqrt(4);
            double a = 0.9995678;
            double b = 16.41063;
            double c = 74.43508;
            double d = 789708.7;
            
            for (double i = 1.; i < new_population; i++) {
                double infected = 1.; double f3 = 789708.7 + (0.9995678 - 789708.7) / (1 + pow(x / 74.43508, 16.41063));
                if (i < f3) {
                    double new_cases = f3 * step_size;
                    double infected_tspread = new_cases * step_size;
                    cout << infected_tspread << "," << new_cases << endl;
                    if (chisq2 < cdc_n_value) // if smaller than current value stored in a variable 
                    chisq2+=DBL_MAX; 
                    i++;
                    cout << chisq2 << endl;
                }
            } 
    
            // ASYMMETRIC SIGMOID COMP. PARAM
            double chisq3 = DBL_MAX;
            double n3 = 6;
            double dof3;
            double error3 = sqrt(n3);
            double a1 = 1.000028;
            double b1 = 16.51944;
            double c1 = 69.19481;
            double d1 = 1576628;
            double m = 0.1583732;
            double f4 = 1576628 + (1.000028 - 1576628) / (1 + (pow((x / 69.19481, 16.51944),0.1583732)));
            
            for (double i = 1.; i < new_population; i++) {
                double infected = 1.; 
                if (i < f4) {
                    double new_cases = f4 * step_size;
                    double infected_tspread = new_cases * step_size;
                    cout << infected_tspread << "," << new_cases << endl;
                    if (chisq3 < cdc_n_value) // update if smaller than current value stored in a variable
                    chisq3+=DBL_MAX;
                    i++;
                    cout << chisq3 << endl;
                }
            }

            }
