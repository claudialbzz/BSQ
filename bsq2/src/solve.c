#include <stdlib.h>
#include "../include/map.h"
#include "../include/solve.h"

static int min(int a, int b, int c)
{
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

void find_square(t_map *map)
{
    int **dp = malloc(map->rows * sizeof(int *));
    int max = 0, mi = 0, mj = 0;
    int i = 0;
    while (i < map->rows) {
        dp[i] = malloc(map->cols * sizeof(int));
        int j = 0;
        while (j < map->cols) {
            if (map->grid[i][j] == map->obst) dp[i][j] = 0;
            else {
                dp[i][j] = 1;
                if (i && j) dp[i][j] += min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
                if (dp[i][j] > max) { max = dp[i][j]; mi = i; mj = j; }
            }
            j++;
        }
        i++;
    }
    i = 0;
    while (i < max) {
        int j = 0;
        while (j < max) {
            map->grid[mi-i][mj-j] = map->full;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < map->rows) free(dp[i++]);
    free(dp);
}