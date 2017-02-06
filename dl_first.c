/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_first.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:59:00 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 19:33:52 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libnum.h"

double			dl_highest(const NUMBER *list)
{
	int		out;
	NUMBER	*temp;

	temp = (NUMBER*)list;
	out = -200000;
	while (temp != NULL)
	{
		if (temp->digit > out)
			out = temp->digit;
		temp = temp->next;
	}
	return (out);
}

double			dl_lowest(const NUMBER *list)
{
	int		out;
	NUMBER	*temp;

	temp = (NUMBER*)list;
	out = 200000;
	while (temp != NULL)
	{
		if (temp->digit < out)
			out = temp->digit;
		temp = temp->next;
	}
	return (out);
}

NUMBER			*dl_empty(void)
{
	NUMBER		*output;

	output = (NUMBER*)malloc(sizeof(NUMBER));
	output->digit = 0;
	output->next = NULL;
	return (output);
}

NUMBER			*dl_new(long n)
{
	NUMBER		*output;

	output = (NUMBER*)malloc(sizeof(NUMBER));
	output->digit = n;
	output->next = NULL;
	return (output);
}
