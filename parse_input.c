/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:43:16 by joonhlee          #+#    #+#             */
/*   Updated: 2023/04/12 11:09:24 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int			valid_check(int argc, char **argv);
static char			**arg_to_strs(int argc, char **argv);
static char			*ft_strjoin_all(int argc, char **argv, char sep);
static t_ps_deck	*error_parse_input(void);

t_ps_deck	*parse_input(int argc, char **argv)
{
	char		**nbrs;
	t_ps_deck	*a;

	if (valid_check(argc, argv) < 0)
		return (error_parse_input());
	nbrs = arg_to_strs(argc, argv);
	if (nbrs == 0)
		return (error_parse_input());
	a = strs_to_deck(nbrs);
	if (a == 0 || have_duplicate(a) > 0)
		return (error_parse_input());

	return (a);
}

static int	valid_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] == ' ' || (argv[i][j] >= '0' && argv[i][j] <= '9')
				|| argv[i][j] == '-' || argv[i][j] == '+'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static char	**arg_to_strs(int argc, char **argv)
{
	char	*all_in_one;
	char	**nbrs;

	all_in_one = ft_strjoin_all(argc, argv, ' ');
	if (all_in_one == 0)
		return (0);
	nbrs = ft_split(all_in_one, ' ');
	free(all_in_one);
	if (nbrs == 0)
		return (0);
	return (nbrs);
}

static char	*ft_strjoin_all(int argc, char **argv, char sep)
{
	size_t	len;
	int		i;
	char	*result;
	int		j;

	i = 1;
	len = 0;
	while (i < argc)
		len += ft_strlen(argv[i++]);
	len += argc - 1;
	result = (char *) malloc (len + 1);
	if (result == 0)
		return (0);
	i = 1;
	j = 0;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		ft_memmove((result + j), argv[i++], len);
		j += len;
		result[j++] = sep;
	}
	result[j] = '\0';
	return (result);
}

t_ps_deck	*error_parse_input(void)
{
	ft_putstr_fd("Error\n", 1);
	return (0);
}
