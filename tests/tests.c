/*
** EPITECH PROJECT, 2022
** MyDefender
** File description:
** tests
*/

#include <criterion/criterion.h>

// includes :

int my_getnbr(char const *str);
int my_atoi(char *str);
int my_strlen(char const *str);
int strcompare(char *str1, char *str2);
int check_file(char *str);
int error_args(void);
int usage(void);
int null_file(void);

// Tests :

Test(test_getnbr, test_simple)
{
    cr_assert_eq(my_getnbr("18"), 18);
}

Test(test_getnbr, test_meduim)
{
    cr_assert_neq(my_getnbr("18"), 19);
}

Test(test_atoi, test_simple)
{
    cr_assert_eq(my_atoi("18"), 18);
}

Test(test_atoi, test_meduim)
{
    cr_assert_neq(my_atoi   ("18"), 19);
}

Test(test_strlen, test_simple)
{
    cr_assert_eq(my_strlen("18"), 2);
}

Test(test_strlen, test_meduim)
{
    cr_assert_neq(my_strlen("18"), 3);
}

Test(test_comp, test_simple)
{
    cr_assert_eq(strcompare("aa", "aa"), 0);
}

Test(test_comp, test_meduim)
{
    cr_assert_neq(strcompare("aa", "aa"), 84);
}

Test(test_comp2, test_simple)
{
    cr_assert_eq(strcompare("aa", "ab"), 84);
}

Test(test_comp2, test_meduim)
{
    cr_assert_neq(strcompare("aa", "ab"), 0);
}

Test(test_check_file, test_medium)
{
    cr_assert_eq(check_file("maps/tuto2.txt"), 1);
}

Test(test_check_file2, test_medium)
{
    cr_assert_neq(check_file("maps/tuto2.txt"), 0);
}

Test(test_error, test_simple)
{
    cr_assert_eq(error_args(), 84);
}

Test(test_error, test_simple2)
{
    cr_assert_eq(usage(), 0);
}

Test(test_error, test_simple3)
{
    cr_assert_eq(null_file(), 84);
}

Test(test_error2, test_simple)
{
    cr_assert_neq(error_args(), 0);
}

Test(test_error2, test_simple2)
{
    cr_assert_neq(usage(), 84);
}

Test(test_error2, test_simple3)
{
    cr_assert_neq(null_file(), 0);
}
