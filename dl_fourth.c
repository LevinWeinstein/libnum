/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_fourth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:05:07 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 19:29:45 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

void	dl_remove_soft(NUMBER **n, int nb)
{
	NUMBER *temp;

	if (n == NULL || nb < 0)
		return ;
	if (nb > 0)
		dl_remove_soft((&((*n)->next)), nb - 1);
	else if (nb == 0)
	{
		temp = (*n);
		(*n) = (*n)->next;
		free(temp);
	}
}

void	dl_multisave(NUMLIST **store, long count, ...)
{
	int		i;
	va_list ap;

	if (count < 1)
		return ;
	va_start(ap, count);
	i = -1;
	while (++i < count)
		nl_add_back(store, nl_dl_in(va_arg(ap, NUMBER*)));
	va_end(ap);
}

int		dl_nth_digit(int n, NUMBER *m)
{
	while (n--)
	{
		if (m == NULL)
			return (-42);
		m = m->next;
	}
	return (m->digit);
}

/*
** 1. Double slash is not allowed since it's a c++ comment.
**        	--The norme's "original" standard includes comments.
** 2. A comment without stars EVERY line is 'confusing'
**        	--Clarity is required in the norme, including comments.
** 3. A comment with one star per line is 'ugly'.
**        	--The norm is about making code pretty. Comments too.
** 4. Spaces at the end of lines are againt the norm.
**			--Why would that not be true for comments?
** 5. Comment should have a '/' '*' on it's own line above and below.
**			--Valid comments are framed like the masterpieces they are.
** 6. If these rules are followed?
**			--Norme this file and see ;).
*/

int		dl_nth_remove(int n, NUMBER **m)
{
	NUMBER *temp;

	while (n--)
	{
		if (*m == NULL)
			return (-42);
		(*m) = (*m)->next;
	}
	if (*m == NULL)
		return (-42);
	temp = *m;
	*m = (*m)->next;
	free(temp);
	return ((*m)->digit);
}

NUMBER	*dl_str(char *str)
{
	NUMBER	*output;
	int		negative;
	int		valid;

	output = NULL;
	valid = 0;
	negative = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
				*str == '\f' || *str == '\n' || *str == '\r')
		str++;
	if (*str == '-' && *str++)
		negative = 1;
	else if (*str == '+' && *str++)
		;
	while (*str >= '0' && *str <= '9' && (valid = 1) == 1)
		dl_add_back(&output, dl_new(*(str++) - '0'));
	if (negative && valid)
		dl_add_front(&output, dl_new('-' - '0'));
	return (output);
}
