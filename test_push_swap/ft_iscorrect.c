/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscorrect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:40:42 by beredzhe          #+#    #+#             */
/*   Updated: 2024/02/17 12:40:59 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int    ft_iscorrect(char **str)
{
    int        i;
    int        j;
    char    c;

    i = 1;
    while (str[i])
    {
        j = 0;
        while (str[i][j])
        {
            c = str[i][j];
            if ((c >= '0' && c <= '9') || c == '-' || c == '+')
            {
                if (((c == '+' || c == '-') && !ft_isdigit(str[i][j + 1]))
                    || ((c == '+' || c == '-') && ft_isdigit(str[i][j - 1])))
                    return (0);
                j++;
            }
            else
                return (0);
        }
        i++;
    }
    return (1);
}

int main() {
    char *array[] = {"./program", "123", "-456", "+789", NULL};

    if (ft_iscorrect(array)) {
        printf("All strings are correctly formatted numbers.\n");
    } else {
        printf("One or more strings are not correctly formatted numbers.\n");
    }

    return 0;
}