#include <stdio.h>
#include <stdlib.h>

int plus(int a, int b) { return a + b; }
int minus(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divided(int a, int b) { return a / b; }

int (*get_math_function(char key, char *keys, int (*funcs[])(int, int), size_t n))(int, int)
{
    for (int i = 0; i < n; i++) {
        if (key == keys[i]) {
            return funcs[i];
        }
    }

    return funcs[0];
}


int main()
{
    int a, c;
    char b;
    int (*fptr[4])(int, int) = {plus, minus, multiply, divided};
    char keys[4] = {'+', '-', '*', '/'};

    printf("key a Function \nEX: 1 + 1\n");
    scanf("%i %c %i", &a, &b, &c);
    printf("%d %c %d = %d\n", a, b, c, get_math_function(b, keys, fptr, 4)(a, c));
}
