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
    int margin = x*3;

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

void decreasing_spaces(int i, int j)
{
    if (i == j) {
        my_putchar(42);
    } else {
        my_putchar(32);
    }
}

void dec_vertical_right(int x, int i, int j, int margin)
{
    while (i <= x) {
        while (j <= margin){
            if (i == 0){
                my_putchar(42);
            } else {
                decreasing_spaces(i,j);
            }
            j++;
        }
        if (i != x) {
            my_putchar('\n');
        }
        j = 0;
	i++;
    }
}

void dec_vertical_left(int x, int i, int j, int margin)
{
    i = 0;
    j = x;
    while (i <= x) {
        while (j > 0){
            if (i == x /*&& j == x + 1*/){
                my_putchar(42);
            } else {
                decreasing_spaces(i,j);
            }
            j--;
        }
        if (i != x) {
            my_putchar('\n');
        } else {
            my_putchar(42);
        }
        j = x;
        i++;
    }
    while (j < margin){
        my_putchar(42);
        j++;
    }
}

int vertical_side (int x)
{
    int i = 0;
    int j = 0;
    int margin = (x*2)+1;

    dec_vertical_right(x,i,j,margin);
    dec_vertical_left(x,i,j,margin);
    return(x);
}

void star(int x)
{
    top(x);
    vertical_side(x);
}

int main()
{
    star(5);
}
