/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_second.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:01:21 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 19:32:24 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

NUMBER			*dl_store_loose(NUMBER loose)
{
	NUMBER	*output;

	output = (NUMBER*)malloc(sizeof(NUMBER));
	*output = loose;
	return (output);
}

void			dl_add_back(NUMBER **dlist, NUMBER *new)
{
	if (dlist == NULL)
		return ;
	else if (*dlist == NULL)
		*dlist = new;
	else
		dl_add_back(&(*dlist)->next, new);
}

void			dl_add_front(NUMBER **dlist, NUMBER *new)
{
	if (dlist == NULL)
		return ;
	else if (*dlist == NULL)
		*dlist = new;
	else
	{
		new->next = *dlist;
		*dlist = new;
	}
}

int				dl_digits(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void			light_putnbr(long n)
{
	if (n < 0 && (n *= -1) > 0)
		dl_putchar('-');
	if (n >= 10)
		light_putnbr(n / 10);
	dl_putchar((n % 10) + '0');
}
