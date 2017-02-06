/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_fifth.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:06:32 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 19:15:16 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

void		dl_undo_back(NUMBER **n)
{
	if (n == NULL || *n == NULL)
		return ;
	if ((*n)->next == NULL)
		dl_kill(n);
	else
		dl_undo_back(&((*n)->next));
}

void		dl_undo_front(NUMBER **n)
{
	NUMBER *temp;

	temp = *n;
	if (n == NULL || *n == NULL)
		return ;
	*n = (*n)->next;
	free(temp);
}

void		dl_kill(NUMBER **del)
{
	if (del == NULL || *del == NULL)
		return ;
	while (*del != NULL)
	{
		if ((*del)->next == NULL)
		{
			free((*del));
			(*del) = NULL;
			return ;
		}
		else
			dl_kill(&(*del)->next);
	}
}
