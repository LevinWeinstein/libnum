/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nl_third.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:11:21 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 21:39:14 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

void	nl_undo_back(NUMLIST **n)
{
	if (n == NULL || *n == NULL)
		return ;
	if ((*n)->next == NULL)
		nl_kill(n);
	else
		nl_undo_back(&((*n)->next));
}

void	nl_undo_front(NUMLIST **n)
{
	NUMLIST *temp;

	temp = *n;
	if (n == NULL)
		return ;
	(*n) = (*n)->next;
	free(temp);
}

void	nl_remove_soft(NUMLIST **n, int nb)
{
	NUMLIST *temp;

	if (n == NULL || nb < 0)
		return ;
	if (nb > 0)
		nl_remove_soft((&((*n)->next)), nb - 1);
	else if (nb == 0)
	{
		temp = (*n);
		(*n) = (*n)->next;
		free(temp);
	}
}
