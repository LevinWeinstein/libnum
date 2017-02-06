/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_nldl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweinste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:12:05 by lweinste          #+#    #+#             */
/*   Updated: 2017/01/30 23:45:30 by lweinste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBNUM_H
# define LIBNUM_H

# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

/*
** NUMBER & NUMLIST DATA STRUCTURES
** LAST EDIT: JANUARY 30th, 2017 by lweinste
*/

/*
** [v STRUCTURE DEFINITIONS v]
*/
typedef struct s_digit_list	t_digit_list;
struct						s_digit_list{
	long					digit;
	long					color_defined;
	t_digit_list			*next;
};
# define NUMBER t_digit_list

typedef struct s_numlist	t_numlist;
struct						s_numlist{
	NUMBER					*number;
	struct s_numlist		*next;
};
# define NUMLIST t_numlist

/*
** *************************** TEST FUNCTIONS: *************************
** ******************* [Struct Printing. For debug only] *********************
*/
void						dl_putchar(char c);
void						light_putnbr(long n);
void						dl_putval(NUMBER *num);
int							nl_bugprint(NUMLIST *read);

/*
** ******************* "NUMBER" FUNCTION PROTOTYPES ***********************
** *********************** [prepended with "dl_"] *************************
**
** dl_[A]:	DL LINK FINDING [Index by Value | Value by Index]
*/
int							dl_nth_digit(int n, NUMBER *m);
double						dl_highest(const NUMBER *list);
double						dl_lowest(const NUMBER *list);
/*
** 	dl_[B]:	DL MODIFY/USE  [Used for action, not return. 1 for success if ret]
*/
int							dl_nth_remove(int n, NUMBER **m);
void						dl_add_back(NUMBER **dlist, NUMBER *new);
void						dl_add_front(NUMBER **dlist, NUMBER *new);
void						dl_kill(NUMBER **del);
void						dl_kill(NUMBER **del);
void						dl_remove_soft(NUMBER **n, int nb);
void						dl_multisave(NUMLIST **store, long count, ...);
/*
** 	dl_[C]:	DL NEW CREATION [Return New Alloced NUMBER*]
*/
NUMBER						*dl_empty(void);
NUMBER						*dl_new(long n);
NUMBER						*dl_store_loose(NUMBER loose);
NUMBER						*dl_load(long n);
NUMBER						*dl_str(char *str);
/*
** *******************  NUMLIST FUNCTION PROTOTYPES **********************
** *********************** [prepended with "dl_"] *************************
**
** NL_[A]: 	NL ANALYZE		[Return Quantity || Index]
*/
int							nl_count(const NUMLIST *read);
/*
** NL_[B]:	NL MODIFY/USE   [Used for action, not return ]
*/
void						nl_kill(NUMLIST **del);
void						nl_undo_front(NUMLIST **n);
void						nl_undo_back(NUMLIST **n);
void						nl_remove_soft(NUMLIST **n, int nb);
void						nl_kill(NUMLIST **del);
void						nl_add_back(NUMLIST **list, NUMLIST *add);
void						nl_add_front(NUMLIST **list, NUMLIST *add);
/*
** dl_[C]:	NL CREATE [Return New Alloced NUMBER*]
** [!!][nl_dl_in VS nl_copydl : copydl COPIES INPUT VALUES, dl_in USES &input.
*/
NUMLIST						*nl_null_dl(void);
NUMLIST						*nl_empty_dl(void);
NUMLIST						*nl_new_dl(long n);
NUMLIST						*nl_dl_in(NUMBER *dlist);
NUMLIST						*nl_copydl(NUMBER *dlist);

#endif
