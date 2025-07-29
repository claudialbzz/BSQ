#include <unistd.h>
#include "print.h"

void	print_map(char **map, int rows, int cols, int largest_square_row, int largest_square_col, int square_size)
{
    int	i;
    int	j;
    char	c;

    i = 0;

    while (i < rows)
    {
        j = 0;
        while (j < cols)
        {
            if (i >= largest_square_row && i < largest_square_row + square_size)
            {
                if (j >= largest_square_col && j < largest_square_col + square_size)
                    c = 'x';
                else
                    c = map[i][j];
            }
            else
                c = map[i][j];
            write(1, &c, 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void	print_error(void)
{
    write(2, "map error\n", 10);
}