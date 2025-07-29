
#include "solve.h"
#include "map.h"
#include <stdlib.h>

int find_largest_square(char **map, int rows, int cols) {
    int **dp = malloc(rows * sizeof(int *));
    int max_square = 0;

    for (int i = 0; i < rows; i++) {
        dp[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + (dp[i-1][j] < dp[i][j-1] ? 
                                    (dp[i-1][j] < dp[i-1][j-1] ? 
                                    dp[i-1][j] : dp[i-1][j-1]) : 
                                    (dp[i][j-1] < dp[i-1][j-1] ? 
                                    dp[i][j-1] : dp[i-1][j-1]));
                }
                if (dp[i][j] > max_square) {
                    max_square = dp[i][j];
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        free(dp[i]);
    }
    free(dp);

    return max_square;
}