/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:32:24 by alfreire          #+#    #+#             */
/*   Updated: 2024/04/27 16:10:02 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*extract_line(char *memory)
{
	char	*line;
	size_t	len;

	if (!memory[0])
		return (NULL);
	len = ft_strclen(memory, '\n');
	if (memory[len] == '\n')
		len++;
	line = ft_strldup(memory, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*remove_extracted_line(char *memory)
{
	size_t	len;
	size_t	jump;
	char	*remaining_content;

	len = ft_strclen(memory, '\0');
	jump = ft_strclen(memory, '\n');
	if (memory[jump] == '\n')
		jump++;
	remaining_content = ft_strldup(memory + jump, len - jump + 1);
	if (!remaining_content)
		return (NULL);
	free (memory);
	return (remaining_content);
}

char	*store_memblocks(int fd, char *memory)
{
	char	*memblock;
	ssize_t	bytes;

	bytes = 1;
	memblock = malloc(BUFFER_SIZE + 1);
	if (!memblock)
		return (NULL);
	while (bytes > 0 && !ft_strchr(memory, '\n'))
	{
		bytes = read(fd, memblock, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (memblock);
			free (memory);
			return (NULL);
		}
		memblock[bytes] = '\0';
		if (!memblock)
			return (NULL);
		memory = ft_strjoingnl(memory, memblock);
	}
	free (memblock);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	memory = store_memblocks(fd, memory);
	if (!memory)
		return (NULL);
	line = extract_line(memory);
	memory = remove_extracted_line(memory);
	if (!memory[0])
	{
		free (memory);
		memory = NULL;
	}
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("get_next_line.c", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     // Lê as linhas do arquivo até chegar ao final
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }

//     // Fecha o arquivo
//     close(fd);

//     return (0);
// }