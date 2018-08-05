/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dschwarz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 13:21:03 by dschwarz          #+#    #+#             */
/*   Updated: 2018/08/05 20:12:27 by dschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	print_body1(int x, int y, int i)
{
	while ((i == x && y > 1) || (x > 1 && y == 1))
	{
		i--;
		while (i != x && i != 1)
		{
			ft_putchar('B');
			i--;
		}
		ft_putchar('C');
		if (y == 1)
		{
			return ;
		}
	}
}

void	print_body2(int x, int i, int j)
{
	while (x > 1 && j > 2)
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
	if (x == 1 && j >= 2)
	{
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
}

void	print_foot(int x, int i, int j)
{
	j = 1;
	while (x > 1 && j == 1)
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

void	print_rush04(int x, int y)
{
	int i;

	i = x;
	if (x <= 0 || y <= 0)
	{
		ft_putchar(0);
		return ;
	}
	if (x >= 1 && y >= 1)
	{
		ft_putchar('A');
	}
	if ((x == 1 && y == 1) || (x == 1 && y >= 2))
		print_body2(x, x, y);
	if (x > 1 && y == 1)
		print_body1(x, y, x);
	if (x > 1 && y >= 2)
	{
		print_body1(x, y, x);
		print_body2(x, x, y);
		print_foot(x, x, y);
	}
	ft_putchar('\n');
}

int		main(void)
{
	print_rush04(4, 4);
	return (0);
}
