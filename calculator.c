// c program to do simple calculator operations
#include <stdio.h>
int main() {
    char operator;
    double first, second, result;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf", &first, &second);
    switch (operator) {
        case '+':
            result = first + second;
            printf("%.2lf + %.2lf = %.2lf\n", first, second, result);
            break;
        case '-':
            result = first - second;
            printf("%.2lf - %.2lf = %.2lf\n", first, second, result);
            break;
        case '*':
            result = first * second;
            printf("%.2lf * %.2lf = %.2lf\n", first, second, result);
            break;
        case '/':
            if (second != 0) {
                result = first / second;
                printf("%.2lf / %.2lf = %.2lf\n", first, second, result);
            } else {
                printf("Error! Division by zero.\n");
            }
            break;
        default:
            printf("Error! Operator is not correct.\n");
            break;
    }
    return 0;
}