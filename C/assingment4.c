/*
the corresponding grammar of this expression parser is the following:
E → T | E + T | E - T
T → F | T * F | T / F
F → D | ( E )
D → 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
*/
#include <stdio.h>
#include <ctype.h>
char *input; // Pointer to input expression
char token;  // Current token
void nextToken()
{
    token = *input++;
    while (token == ' ')
        token = *input++; // Skip spaces
}
int expr(); // Forward declaration
int factor()
{
    if (isdigit(token))
    { // Handle single-digit numbers
        int num = token - '0';
        nextToken();
        return num;
    }
    else if (token == '(')
    { // Handle parentheses
        nextToken();
        int result = expr();
        nextToken(); // Skip ')'
        return result;
    }
    return 0; // Default case (should handle errors properly)
}
int term()
{
    int result = factor();
    while (token == '*' || token == '/')
    { // Handle mult and div
        char op = token;
        nextToken();
        result = (op == '*') ? result * factor() : result / factor();
    }
    return result;
}
int expr()
{
    int result = term();
    while (token == '+' || token == '-')
    { // Handle addition/subtraction
        char op = token;
        nextToken();
        result = (op == '+') ? result + term() : result - term();
    }
    return result;
}
int main()
{
    char expression[] = "5 + 2 * (4 - 1)";
    input = expression;
    nextToken();
    printf("Result: %d\n", expr()); // Evaluate and print result
    return 0;
}