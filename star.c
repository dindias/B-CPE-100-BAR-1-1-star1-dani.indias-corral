/*
// EPITECH PROJECT, 2021
// star.c
// File description:
// Write a function that displays a star, based on its given size.
If the size is 0, don’t display anything (but it is not an error).
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int top (int x)
{
    int i = 0;
    int j = 0;
    int margin = (x*3);

    while (i <= x-1) {
        while (j <= margin + i) {
            if (j == margin - i || j == margin + i) {
                my_putchar(42);
            } else {
                my_putchar(32);
            }
            j++;
        }
        my_putchar('\n');
        j = 0;
        i++;
    }
    return(x);
}

void star(int x)
{
    top(x);
}

int main()
{
    star(5);
}
