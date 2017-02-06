/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nl_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:07:49 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 21:38:56 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

NUMLIST	*nl_null_dl(void)
{
	NUMLIST *output;

	if ((output = (NUMLIST*)malloc(sizeof(NUMLIST))) == NULL)
		return (NULL);
	output->number = NULL;
	output->next = NULL;
	return (output);
}

NUMLIST	*nl_empty_dl(void)
{
	NUMLIST *output;

	if ((output = (NUMLIST*)malloc(sizeof(NUMLIST))) == NULL)
		return (NULL);
	output->next = NULL;
	output->number = dl_empty();
	return (output);
}

NUMLIST	*nl_new_dl(long n)
{
	NUMLIST *output;

	if ((output = (NUMLIST*)malloc(sizeof(NUMLIST))) == NULL)
		return (NULL);
	output->next = NULL;
	output->number = dl_new(n);
	return (output);
}

NUMLIST	*nl_dl_in(NUMBER *dlist)
{
	NUMLIST *output;

	if ((output = (NUMLIST*)malloc(sizeof(NUMLIST))) == NULL)
		return (NULL);
	output->number = dlist;
	output->next = NULL;
	return (output);
}

NUMLIST	*nl_copydl(NUMBER *dlist)
{
	NUMLIST *output;

	if ((output = (NUMLIST*)malloc(sizeof(NUMLIST))) == NULL)
		return (NULL);
	output->number = dl_store_loose(*dlist);
	output->next = NULL;
	return (output);
}
