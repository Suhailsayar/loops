#include<stdio.h>
#include<math.h>
double f(double x) {
    return x * x; 
}
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n; 
    double integral = 0.0;                                     //intergration 
    integral += f(a) / 2.0; 
    for (int i = 1; i < n; i++) {
        integral += f(a + i * h); 
    }
    integral += f(b) / 2.0; 
    integral *= h; 
    return integral;
}
int main() {
    double a, b; 
    int n;       
    printf("Enter the lower limit of integration (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration (b): ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);
    double result = trapezoidalRule(a, b, n);
    printf("The integral of the function from %.2lf to %.2lf is: %.6lf\n", a, b, result);

    return 0;
}