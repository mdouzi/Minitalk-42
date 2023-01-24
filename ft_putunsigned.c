/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:31:26 by mdouzi            #+#    #+#             */
/*   Updated: 2023/01/24 21:16:19 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	count(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		++i;
	while (nb)
	{
		++i;
		nb /= 10;
	}
	return (i);
}

int	ft_putunsigned(unsigned int nb)
{
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else
	{
		ft_putunsigned(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	return (count(nb));
}
