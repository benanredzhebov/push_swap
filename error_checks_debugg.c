#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t    ft_strlen(const char *s)
{
    size_t    i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

int    ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t    i;

    if (n == 0)
        return (0);
    i = 0;
    while (i < n - 1 && str1[i] != '\0' \
    && str2[i] != '\0' && str1[i] == str2[i])
        i++;
    return ((unsigned char)str1[i] - (unsigned char)str2[i]);
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

int    ft_isbound(char *str)
{
    int        i;
    int        isneg;
    long    nbr;

    i = 0;
    isneg = 0;
    nbr = 0;
    if (str[i] != '\0' && str[i] == '-')
    {
        isneg = 1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i])
    {
        nbr = (nbr * 10) + (str[i] - '0');
        i++;
    }
    if (isneg == 1)
        nbr *= -1;
    if (!(nbr >= -2147483648 && nbr <= 2147483647))
        return (0);
    return (1);
}

int    ft_isduplicate(char **str)
{
    int    i;
    int    j;

    i = 1;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if ((ft_strncmp(str[i], str[j], ft_strlen(str[j])) == 0)
                && (ft_strlen(str[i]) == ft_strlen(str[j])))
            {
                write(1, "Error: there are duplicates\n", 28);
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int    checks(char **str)
{
    int    i;

    i = 1;
    if (!ft_iscorrect(str))
    {
        write(1, "Error: some arguments aren't integers\n", 38);
        return (0);
    }
    if (ft_isduplicate(str))
        return (0);
    while (str[i])
    {
        if (!ft_isbound(str[i]))
        {
            write(1, "Error: some arguments are out of integer range\n", 47);
            return (0);
        }
        i++;
    }
    return (1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [integer1] [integer2] ...\n", argv[0]);
        return 1;
    }
    
    // Assuming argv[0] is the program name, skip it
    if (!checks(argv)) {
        // Input validation failed, exit program
        return 1;
    }

    // All input validation passed, proceed with program logic
    // For example, you can convert the strings to integers and perform some operations
    printf("Input validation passed!\n");
    
    return 0;
}
