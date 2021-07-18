/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 09:24:12 by aalcara-          #+#    #+#             */
/*   Updated: 2021/07/17 23:04:00 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	verify_isdigit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) != 1)
			{
				if (j != 0 || argv[i][j] != '-' || argv[i][j + 1] == '\0')
					error_exit();
			}
			j++;
		}
		i++;
		j = 0;
	}
}

static int	*verify_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	*numlist;

	i = -1;
	numlist = (int *)malloc(sizeof(int) * (argc - 1));
	while (i++ < argc - 2)
		numlist[i] = ft_atoi(argv[i + 1]);
	i = 0;
	j = 1;
	while (i < argc - 2)
	{
		while (j < argc - 1)
		{
			if (numlist[i] == numlist[j])
			{
				free(numlist);
				error_exit();
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (numlist);
}

static void	verify_intlimits(int argc, char **argv)
{
	int			i;
	long int	num;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11)
			error_exit();
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit();
		i++;
	}
}

int *verify_args(int argc, char **argv)
{
	int	*numlist;

	if (argc == 1)
		error_exit();
	verify_isdigit(argc, argv);
	verify_intlimits(argc, argv);
	numlist = verify_duplicates(argc, argv);
	return (numlist);
}
