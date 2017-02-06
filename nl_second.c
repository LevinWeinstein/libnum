/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nl_second.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:09:33 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 21:39:03 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

void	nl_add_back(NUMLIST **list, NUMLIST *add)
{
	NUMLIST *temp;

	if (*list != NULL && (*list)->number != NULL)
		nl_add_back(&(*list)->next, add);
	else if (*list == NULL)
		*list = add;
	else if ((*list)->number == NULL)
	{
		temp = *list;
		*list = add;
		free(temp);
	}
}

void	nl_add_front(NUMLIST **list, NUMLIST *add)
{
	if ((*list) == NULL)
		*list = add;
	else if ((*list)->number == NULL)
	{
		free(*list);
		*list = add;
	}
	else
	{
		add->next = *list;
		*list = add;
	}
}

int		nl_count(const NUMLIST *read)
{
	int		i;

	i = 0;
	while (read != NULL && ++i)
		read = read->next;
	return (i);
}

int		nl_bugprint(NUMLIST *read)
{
	if (read == NULL || read->number == NULL)
		return (1);
	if ((read->next == NULL) || (nl_bugprint(read->next) == 0))
	{
		dl_putval(read->number);
		dl_putchar('\n');
		return (0);
	}
	return (0);
}

void	nl_kill(NUMLIST **del)
{
	if (del == NULL || *del == NULL)
		return ;
	while (*del != NULL)
	{
		if ((*del)->next == NULL)
		{
			dl_kill(&(*del)->number);
			free((*del));
			(*del) = NULL;
			return ;
		}
		else
			nl_kill(&(*del)->next);
	}
}
