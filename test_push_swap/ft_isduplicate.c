#include <string.h>
#include <stdio.h>

int	ft_isduplicate(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if ((strncmp(str[i], str[j], strlen(str[j])) == 0)
				&& (strlen(str[i]) == strlen(str[j])))
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


int main() {
    char *array[] = {"./program", "123", "456", "123", NULL};

    if (ft_isduplicate(array)) {
        printf("There are duplicate strings.\n");
    } else {
        printf("There are no duplicate strings.\n");
    }

    return 0;
}