#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/cub.h"

// int ft_strlen(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

int	get_max_length(char **tab)
{
	int tmp;
	int i;

	tmp = 0;
	i = 0;
	while (tab[i])
	{
		if (ft_strlen(tab[i]) > (size_t)tmp)
			tmp = ft_strlen(tab[i]);
		i++;
	}
	return (tmp);
}

char *fill_string(char *str, int len)
{
	int i;
	int j;
	char *new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * len + 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			new[j] = 'V';
		else 
			new[j] = str[i];
		i++;
		j++;
	}
	while (j < len)
		new[j++] = 'V';
	new[j] = 0;
	return (new);
}

int	count_string(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_alll(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char **reform_map(char **tab)
{
	int i;
	int j;
	char **new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * (count_string(tab) + 1));
	if (!new)
		return (NULL);
	while (tab[i])
	{
		new[j] = fill_string(tab[i], get_max_length(tab));
		i++;
		j++;
	}
	new[j] = NULL;
	if (tab)
		free_alll(tab);
	return (new);
}

// int main (int ac, char **av)
// {
// 	char *str; 



// 	str = reform_map("111111111111111111\n10000000000     000000000   000001\n1111111111111111111");
// 	for (int i = 0; str[i];i++)
// 		printf("%s\n", str[i]);
// }