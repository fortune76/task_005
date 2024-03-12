#ifndef CALC_TRAVEL_H
#define CALC_TRAVEL_H

#define SPEED 60
#define WORK_AND_RELAX 8
#define BUFFER 1025
#define MAX_LENGHT 8193

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[BUFFER];
    int x;
    int y;
} City;

typedef struct {
    char name[BUFFER];
} Route;

void calc_travel();

#endif