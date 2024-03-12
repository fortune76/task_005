#include "calc_travel.h"

void _input_file_path(char *path) { scanf("%1024s", path); }
void _exception() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}

void _output_cities(char *cities) { printf("%s\n", cities); }

void _output_hours(int hours) { printf("%d", hours); }

/* Чтение из файла */
void _read_way(City *way, char *file_path) {
    FILE *f = fopen(file_path, "r");
    char line[BUFFER];
    int counter = 0;
    City tmp = {"", 0, 0};
    while (fgets(line, BUFFER - 1, f) != NULL) {
        if ((line[0] >= 65 && line[0] <= 90) || (line[0] >= 97 && line[0] <= 122)) {
            sscanf(line, "%1024s %10d %10d", tmp.name, &tmp.x, &tmp.y);
            way[counter] = tmp;
            counter++;
        }
    }
    fclose(f);
}

/* Целочисленное деление с округлением */
int ceil_divide(int x0, int y0, int dest_x, int dest_y) {
    int result = (abs(dest_x - x0) + abs(dest_y - y0)) / SPEED;
    float result_f = ((float)abs(dest_x - x0) + (float)abs(dest_y - y0)) / SPEED;
    if (result < result_f) {
        result += 1;
    }
    return result;
}

/* Вычисление общей длительности и точек остановки */
void _calc_way(City *way, int size) {
    int total_hours = 0, travel_hours = 0;
    int x0 = way[0].x, y0 = way[0].y;
    int time_to_dest = 0;
    char result[MAX_LENGHT] = {0};
    strcat(result, way[0].name);
    for (int i = 1; i < size; i++) {
        time_to_dest = ceil_divide(x0, y0, way[i].x, way[i].y);
        if (time_to_dest > 8) {
            printf("Travel is impossible!");
            exit(EXIT_SUCCESS);
        } else if ((time_to_dest + travel_hours) <= WORK_AND_RELAX) {
            travel_hours += time_to_dest;
        } else {
            total_hours += travel_hours + WORK_AND_RELAX;
            travel_hours = 0;
            strcat(result, "\n");
            strcat(result, way[i - 1].name);
        }
        x0 = way[i].x, y0 = way[i].y;
    }
    strcat(result, "\n");
    strcat(result, way[size - 1].name);
    _output_cities(result);
    if (total_hours != 0) {
        total_hours += time_to_dest;
    } else {
        total_hours += travel_hours;
    }

    _output_hours(total_hours);
}

/* Вычисление размера файла */
int calc_file_size(char *path) {
    FILE *f = fopen(path, "r");
    if (f == NULL) {
        _exception();
    }
    int counter = 0;
    char line[BUFFER];
    while (fgets(line, BUFFER - 1, f) != NULL) {
        if (strcmp(line, "\n") != 0) {
            counter++;
        }
    }
    fclose(f);
    return counter;
}

/* Основная функция */
void calc_travel() {
    char path[BUFFER] = {0};
    _input_file_path(path);
    int file_size = calc_file_size(path);
    City *way = calloc(file_size * sizeof(City), sizeof(City));
    _read_way(way, path);
    _calc_way(way, file_size);
    free(way);
}