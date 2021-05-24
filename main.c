/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbroderi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 12:53:24 by sbroderi          #+#    #+#             */
/*   Updated: 2020/10/18 12:53:32 by sbroderi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t count);
ssize_t			ft_read(int fd, void *buf, size_t count);
char			*ft_strdup(const char *s);

static void		check_write(void)
{
	int fd;

	errno = 0;
	printf("%zd\n", ft_write(444, "ab", 2));
	printf("%d - %s\n\n", errno, strerror(errno));
	errno = 0;
	printf("%zd\n", ft_write(0, 0x0, 2));
	printf("%d - %s\n\n", errno, strerror(errno));
	fd = open("test.txt", O_RDONLY | O_WRONLY);
	errno = 0;
	printf("%zd\n", ft_write(fd, "hello", 5));
	printf("%d - %s\n\n", errno, strerror(errno));
	printf(" - %zd\n", ft_write(0, "hello_stdin", 11));
	printf(" - %zd\n", ft_write(1, "hello_stdout", 12));
}

static void		check_read(void)
{
	int		fd;
	char	buf[55];

	fd = open("src/ft_strlen.s", O_RDONLY);
	errno = 0;
	printf("size buf: %zd\n", ft_read(fd, buf, 55));
	printf("************buffer*************\n");
	printf("%s\n", buf);
	printf("*******************************\n");
	printf("%d - %s\n\n", errno, strerror(errno));
	printf("\n-----TEST BAD FILE-----\n");
	fd = open("bad_file.s", O_RDONLY);
	memset(buf, 0, 55);
	errno = 0;
	printf("%zd\n", ft_read(fd, buf, 55));
	printf("************buffer*************\n");
	printf("%s\n", buf);
	printf("*******************************\n");
	printf("%d - %s\n\n", errno, strerror(errno));
}

int				main(int ac, char **av)
{
	char	*str;
	char	*str2;

	if (ac < 2)
	{
		printf("Please, choose and write some func\n");
		return (1);
	}
	if ((strcmp(av[1], "ft_strlen")) == 0)
	{
		if (ac == 3)
		{
			printf("Standart  func: %zu\n", strlen(av[2]));
			printf("Libasm    func: %zu\n", ft_strlen(av[2]));
		}
		else
			printf("ft_strlen requires 1 param\n");
	}
	else if ((strcmp(av[1], "ft_strcpy")) == 0)
	{
		if (ac == 3)
		{
			str = (char *)malloc(sizeof(char) * (strlen(av[2]) + 1));
			printf("Standart  func: %s\n", strcpy(str, av[2]));
			printf("Libasm    func: %s\n", ft_strcpy(str, av[2]));
			free(str);
		}
		else
			printf("ft_strcpy requires 1 param\n");
	}
	else if ((strcmp(av[1], "ft_strcmp")) == 0)
	{
		if (ac == 4)
		{
			printf("Standart  func: %d\n", strcmp(av[2], av[3]));
			printf("Libasm    func: %d\n", ft_strcmp(av[2], av[3]));
		}
		else
			printf("ft_strlen requires 2 params\n");
	}
	else if ((strcmp(av[1], "ft_write")) == 0)
		check_write();
	else if ((strcmp(av[1], "ft_read")) == 0)
		check_read();
	else if ((strcmp(av[1], "ft_strdup")) == 0)
	{
		if (ac == 3)
		{
			errno = 0;
			str = strdup(av[2]);
			printf("Standart  func: %s\n", str);
			printf("%d - %s\n\n", errno, strerror(errno));
			errno = 0;
			str2 = ft_strdup(av[2]);
			printf("Libasm   func: %s\n", str2);
			printf("%d - %s\n", errno, strerror(errno));
			free(str);
			free(str2);
		}
		else
			printf("ft_strdup requires 1 param\n");
	}
	else
		printf("Please, choose and write some func of libasm\n");
	return (0);
}
