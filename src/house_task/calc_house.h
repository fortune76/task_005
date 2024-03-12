#ifndef CALC_HOUSE_H
#define CALC_HOUSE_H

#include <stdio.h>

typedef struct {
    int wall_long;
    int wall_width;
    int wall_height;
    int prepayment;
    int total_price;
} House;

void calc_house();

#endif