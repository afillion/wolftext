#include "wolf.h"
#include "fcntl.h"
#include <stdio.h>


static char			*ft_join(char const *s1, char const *s2)
{
	char	*new;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(new = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	new[len] = '\0';
	free((void*)s1);
	return (new);
}

int		count_word(const char *s, char c)
{
	int nb;
	int	i;
	int check;

	i = 0;
	check = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && check)
			check = !check;
		else if (s[i] != c && !check)
		{
			nb++;
			check = !check;
		}
		i++;
	}
	return (nb);
}

void	split_map(t_env *e, char *map)
{
	int		i;
	int		j;
	char	**split;
	char	**new;

	i = 0;
	j = 0;
	split = ft_strsplit(map, '\n');
	e->world_map = (int**)malloc(sizeof(int*) * e->line);
	while (split[i])
	{
		j = 0;
		e->world_map[i] = (int*)malloc(sizeof(int) * count_word(split[i], ' '));
		if (e->col < count_word(split[i], ' '))
			e->col = count_word(split[i], ' ');
		new = ft_strsplit(split[i], ' ');
		while (new[j])
		{
			printf("new[j] :[%p]\n", new[j]);
			e->world_map[i][j] = ft_atoi(new[j]);
			free(new[j]);
			j++;
		}
		free(split[i]);
		i++;
	}
	free(new);
	free(split);
}

void	parse_map(t_env *e)
{
	int		fd;
	char	*line;
	char	*map;
	char	*line_end;

	line = NULL;
	map = ft_strnew(0);
	fd = open(e->filename, O_RDONLY);
	//if fd < 1 go ft_exit
	while (get_next_line(fd, &line) > 0)
	{
		line_end = ft_join(line, "\n");
		map = ft_join(map, line_end);
		free(line_end);
		e->line++;
	}
	close(fd);
	split_map(e, map);
	free(map);
}
