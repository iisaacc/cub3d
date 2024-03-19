#include "../../includes/cub3d.h"

char	*ft_strjoin_gnl(char *s1, char const *s2, size_t len)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = len;
	join = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, s1_len + 1);
	ft_strlcpy((join + s1_len), s2, s2_len + 1);
	free(s1);
	return (join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			countread;
	int			to_copy;

	line = ft_strdup(buf);
	while (!(ft_strchr(line, '\n')) && (countread = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[countread] = '\0';
		line = ft_strjoin_gnl(line, buf, countread);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);

	newline = ft_strchr(line, '\n');
	if (newline != NULL)
	{
		to_copy = newline - line + 1;
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}