#include <fcntl.h>
#include <unistd.h>
#include "../include/map.h"
#include "../include/solve.h"
#include "../include/print.h"
#include "../include/error.h"

int main(int ac, char **av)
{
    int i = 1;
    while (i < ac || (ac == 1 && i == 1)) {
        t_map map = {0};
        int fd = (ac == 1) ? 0 : open(av[i], O_RDONLY);
        
        if (fd == -1 || !parse_map(fd, &map)) {
            print_error();
        } else {
            find_square(&map);
            print_map(&map);
            free_map(&map);
        }
        if (fd > 0) close(fd);
        if (++i < ac) write(1, "\n", 1);
    }
    return 0;
}