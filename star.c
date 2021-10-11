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
    int margin = (x*3)-1;

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

void decreasing_spaces(int x,int i, int j)
{
    int total_margin = ((x*3)*2)-1;

    
    /*if (i == j || j == total_margin -1 - i || j == total_margin + i) {
        printf("%d",i);
        my_putchar(42);
    } else {
        my_putchar(32);
        }*/
}

void dec_vertical_interior(int x, int i, int j, int margin)
{
    int medium_margin = (x * 3) + (x - 2);
    int total_margin = ((x * 3)*2) - 1;
    
    while (i <= x) {
        while (j < total_margin){
            if ((i == 0 && j >= 0 && j < margin) || (i == 0 && j >= medium_margin && j <= total_margin)) {
                my_putchar(42);
            } else {
                decreasing_spaces(x,i,j);
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

void dec_vertical_exterior(int x, int i, int j, int margin)
{
    i = 0;
    j = x;
    while (i <= x) {
        while (j > 0){
            if (i == x /*&& j == x + 1*/){
                my_putchar(42);
            } else {
                decreasing_spaces(x,i,j);
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
    while (j < margin-1){
        my_putchar(42);
        j++;
    }
}

int vertical_side (int x)
{
    int i = 0;
    int j = 0;
    int margin = (x*2)+1;

    dec_vertical_interior(x,i,j,margin);
    dec_vertical_exterior(x,i,j,margin);
    return(x);
}

int bottom(int x)
{
    int i = 0;
    int j = 0;
    int margin = (x*3);
    int hor_margin = (x*2);

    my_putchar('\n');
    while (i <= x-1) {
        while (j < (margin + x)) {
            if (j == margin + (x - i)-2 || j == hor_margin + i) {
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
    vertical_side(x);
    bottom(x);
}

int main()
{
    star(5);
}
