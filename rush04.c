/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:21:03 by dschwarz          #+#    #+#             */
/*   Updated: 2018/08/05 01:17:11 by dschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	print_rush04(int x, int y)
{
	int i;
	int j;

	i = x;
	j = y;
	if (i <= 0 || j <= 0)
	{
		ft_putchar(0);
		return ;
	}
	if (x == 1 && y == 1)
	{
		ft_putchar('A');
		return ;
	}
	if (x > 1 && y == 1)
	{
		ft_putchar('A');
		i--;
		while (i != x && i != 1)
		{
			ft_putchar('B');
			i--;
		}
		ft_putchar('C');
		return ;
	}
	if (i == 1 && j >= 2)
	{
		ft_putchar('A');
		ft_putchar('\n');
		while (j != 2)
		{
			ft_putchar('B');
			ft_putchar('\n');
			j--;
		}
		ft_putchar('C');
		return ;
	}
	while (i == x)
	{
		ft_putchar('A');
		i--;
		while (i != x && i != 1)
		{
			ft_putchar('B');
			i--;
		}
		ft_putchar('C');
	}
	while (j > 2)
	{
		ft_putchar('\n');
		ft_putchar('B');
		i = 0;
		while (i != x - 2)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('B');
		j--;
	}
	j = 1;
	while (j == 1)
	{
		ft_putchar('\n');
		ft_putchar('C');
		i = 0;
		while (i != x - 2)
		{
			ft_putchar('B');
			i++;
		}
		ft_putchar('A');
		j--;
	}
}

int		main(void)
{
	print_rush04(1, 1);
	return (0);
}
