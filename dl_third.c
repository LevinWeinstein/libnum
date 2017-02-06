/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_third.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:02:58 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 19:31:48 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

static int	dl_digits(int n)
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

static int	dl_abs(long n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

NUMBER		*dl_load(long n)
{
	int		digits;
	int		negative;
	NUMBER	tmp;
	NUMBER	*output;

	negative = 0;
	if (n < 0)
		negative += 1;
	output = NULL;
	tmp.next = NULL;
	digits = dl_digits((int)(n)) + negative;
	while (digits-- > negative)
	{
		tmp.digit = dl_abs((char)(n % 10));
		dl_add_front(&output, dl_store_loose(tmp));
		n /= 10;
	}
	tmp.digit = -1;
	if (negative)
		dl_add_front(&output, dl_store_loose(tmp));
	return (output);
}

void		dl_putchar(char c)
{
	write(1, &c, 1);
}

void		dl_putval(NUMBER *num)
{
	if (num == NULL)
		return ;
	if (num->digit == -3)
		dl_putchar('-');
	else if (num->digit == -5)
		;
	else if (num->digit >= 0 && num->digit <= 9)
		dl_putchar(num->digit + '0');
	else if (num->digit <= 15 && num->digit >= 10)
		dl_putchar((num->digit - 10) + 'A');
	else
		light_putnbr(num->digit);
	dl_putchar(' ');
	dl_putval(num->next);
}
