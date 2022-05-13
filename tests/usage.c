/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-anthony.faure
** File description:
** usage
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int my_putstr(char const *str);

int usage(void)
{
    my_putstr("USAGE :\n\t./my_rpg\n\nDESCRIPTION\n");
    my_putstr("\tMyRPG is a RPG like game\n");
    return 0;
}

int error_args(void)
{
    write(2, "This programm need 1 arg\n", 32);
    return 84;
}

int check_file(char *str)
{
    int fd = open(str, O_RDONLY);
    if (fd == -1) {
        close(fd);
        return 1;
    }
    close(fd);
    return 0;
}

int null_file(void)
{
    write(2, "Your entry file doesn't exist !\n", 33);
    return 84;
}
