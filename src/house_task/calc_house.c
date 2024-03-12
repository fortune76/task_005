#include "calc_house.h"

void _input_values(House *house) {
    scanf("%d %d %d %d", &house->wall_width, &house->wall_long, &house->wall_height, &house->prepayment);
}

int _calc_total_price(const House *house) {
    int basement = house->wall_width * house->wall_long * 1000;
    int walls = ((house->wall_width + house->wall_long) * 2) * house->wall_height * 500;
    int roof = (house->wall_long * house->wall_width * 700) + house->wall_height * 100;
    return (basement + walls + roof);
}

void _output_answer(int mode, int diff) {
    if (mode) {
        printf("NO %d", diff);
    } else {
        printf("YES");
    }
}

void _decision(const House *house) {
    if (house->prepayment >= house->total_price) {
        _output_answer(0, 0);
    } else {
        int diff = house->total_price - house->prepayment;
        _output_answer(1, diff);
    }
}

void calc_house() {
    House house = {0, 0, 0, 0, 0};
    House *house_p = &house;
    _input_values(house_p);
    house_p->total_price = _calc_total_price(house_p);
    _decision(house_p);
}