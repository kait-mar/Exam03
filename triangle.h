#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_zone
{
    int width;
    int height;
    char    back;
}       t_zone;

typedef struct s_rec
{
    char    c;
    int     x;
    int     y;
    int     width;
    int     height;
    char    back;
}       t_rec;

#endif