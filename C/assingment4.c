/*
the corresponding grammar of this expression parser is the following:
E → T | E + T | E - T
T → F | T * F | T / F
F → D | ( E )
D → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
char *input; // Pointer to input expression
char token;  // Current token
void nextToken()
{
    token = *input++;
    while (token == ' ')
        token = *input++; // Skip spaces
}
float expr(); // Forward declaration
float factor()
{
    if (token == '-')
    {
        nextToken();
        return -factor();
    }
    else if (token == '.')
    {
        nextToken();
        float fraction = 0.0;
        float divisor = 10.0;
        while (isdigit(token))
        {
            fraction += (token - '0') / divisor;
            divisor *= 10;
            nextToken();
        }
        return fraction;
    }
    else if (isdigit(token))
    {
        float num = 0;
        while (isdigit(token))
        { // Problem 1 complete.
            num = (num * 10) + token - '0';
            nextToken();
        }
        float fraction = 0.0;
        if (token == '.')
        {
            nextToken();
            float divisor = 10.0;
            while (isdigit(token))
            {
                fraction += (token - '0') / divisor;
                divisor *= 10;
                nextToken();
            }
        }
        return num + fraction;
    }
    else if (token == '(')
    { // Handle parentheses
        nextToken();
        float result = expr();
        nextToken(); // Skip ')'
        return result;
    }
    return 0; // Default case (should handle errors properly)
}
float power();
float term()
{
    float result = power();
    while (token == '*' || token == '/')
    { // Handle mult and div
        char op = token;
        nextToken();
        if (op == '*')
        {
            result = result * power();
        }
        else if (op == '/')
        {
            float divisor = power();
            if (divisor == 0.0f)
            {
                printf("Cannot divide by 0.\n");
                exit(1);
            }
            else
            {
                result = result / divisor;
            }
        }
    }
    return result;
}
float expr()
{
    float result = term();
    while (token == '+' || token == '-')
    { // Handle addition/subtraction
        char op = token;
        nextToken();
        result = (op == '+') ? result + term() : result - term();
    }
    return result;
}
float power(){
    float base = factor();
    if (token == '^'){
        nextToken();
        float exponent = power();
        return powf(base,exponent);
    }
    return base;

}

int main()
{
    char expression[] = "-2 ^ 3 + (40.5 - 1.5) * (3 ^ 2) / 1.5";
    input = expression;
    nextToken();
    printf("Result: %.2f\n", expr()); // Evaluate and print result
    return 0;
}