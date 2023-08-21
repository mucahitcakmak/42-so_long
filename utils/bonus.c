/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:17:59 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/21 19:08:04 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_refresh(t_struct_control *stc, int i)
{
	static int	step = 0;
	char		*str;

	if (i == 1)
		++step;
	str = ft_itoa(step);
	mlx_string_put(stc->mlx, stc->win, 8, 20, 255, "STEP:");
	mlx_string_put(stc->mlx, stc->win, 18, 35, 255, str);
	free(str);
}

int	enemy_control(t_struct_control *stc)
{
	int	a;

	a = rand() % 4;
	if (a == 0)
		enemy_move(stc, 0, -1);
	else if (a == 1)
		enemy_move(stc, 0, 1);
	else if (a == 2)
		enemy_move(stc, -1, 0);
	else
		enemy_move(stc, 1, 0);
	return (0);
}

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_nbrlen(n);
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[--len] = '8';
			n /= 10;
		}
		n = -n;
	}
	while (len-- && n != 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
