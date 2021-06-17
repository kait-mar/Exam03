#include "triangle.h"

void    print_error_and_exit(void)
{
    write(2, "Error: argument\n", 16);
    exit(EXIT_FAILURE);
}

t_zone  get_zone(FILE *fd)
{
    t_zone  zone;

    if (fscanf(fd, "%d %d %c\n", &zone.width, &zone.height, &zone.back) != 3)
        print_error_and_exit();
    if ((zone.width <= 0 || zone.width > 300) || (zone.height <= 0 || zone.height > 300))
        print_error_and_exit();
    return (zone);
}

t_rec  get_rec(FILE *fd)
{
    t_rec   rec;

    if (fscanf(fd, "%c %f %f %d %d %c\n", &rec.c, &rec.x, &rec.y, &rec.width, &rec.height, &rec.back) != 6)
        print_error_and_exit();
    if (rec.height <= 0 || rec.width <= 0)
        print_error_and_exit();
    return (rec);
}

int     condition(t_zone zone, t_rec rec, int i, int j)
{
    return ((j == rec.y && (i >= rec.x && i <= rec.x + rec.width))
            || (j == rec.y + rec.height && (i >= rec.x && i <= rec.x + rec.width))
            || (i == rec.x && (j >= rec.y && j <= rec.y + rec.height))
            || (i == rec.x + rec.width && (j >= rec.y && j <= rec.y + rec.height)));
}

void    draw_zone_rec(t_zone zone, t_rec rec)
{
    int i;
    int j;

    i = 0;
    while (i < zone.width)
    {
        j = 0;
        while (j < zone.height)
        {
            if (rec.c == 'R')
            {
                if (i >= rec.x && i <= rec.x + rec.width && j >= rec.y && j <= rec.y + rec.height)
                    write(1, &rec.back, 1);
                else
                    write(1, &zone.back, 1);
            }
            else if (rec.c == 'r')
            {
                if (condition(zone, rec, i, j))
                    write(1, &rec.back, 1);
                else
                    write(1, &zone.back, 1);
            }
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int    main(int argc, char **argv)
{
    t_zone  zone;
    t_rec   rec;
    FILE    *fd;

    if (argc != 2)
        print_error_and_exit();
    fd = fopen(argv[1], "r");
    zone = get_zone(fd);
    rec = get_rec(fd);
    draw_zone_rec(zone, rec);
    return (0);
}