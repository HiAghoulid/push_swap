/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:46:46 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/12 16:59:35 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_stack
{
	int			content;
	int			index;
	struct s_stack	*next;
}	t_stack;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/************************ rules  ************************/
void swap(t_stack	**stack);
void swap_a(t_stack **stack);
void swap_b(t_stack **stack);
void swap_ab(t_stack **stack);

void push(t_stack **stack_a,t_stack **stack_b);
void push_a(t_stack **stack_a,t_stack **stack_b);
void push_b(t_stack **stack_a,t_stack **stack_b);

void rotate(t_stack **stack);
void rotate_a(t_stack **stack);
void rotate_b(t_stack **stack);
void rotate_ab(t_stack **stack_a, t_stack **stack_b);

void reverse_rotate(t_stack **stack);
void reverse_rotate_a(t_stack **stack);
void reverse_rotate_b(t_stack **stack);
void reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

/************************ sorts  ************************/
void    sort(int *t_stack, int end);
void    lthree_sort(t_stack **stack_a, t_stack **stack_b , char c);
void    lfive_sort();

/************************ lst  ************************/
t_stack	*ft_lstnew(int content);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstclear(t_stack **lst, void (*del)(void*));
void	ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));

/************************ utiles  ************************/
long    ft_atoi(const char *str);
int     is_dup(t_stack *stack);
int     is_sorted(t_stack *stack);
int     is_int(char *str);
void    ft_putstr(char *str);
int     *ft_cpy_and_get_middle(t_stack *stack);

int     find_max(t_stack *stack);
int     find_min(t_stack *stack);

int     is_error(t_stack *stack);
int     fill_stack(t_stack **stack, char **av, int ac);
int     is_sorted_dec(t_stack *stack);

void    index_lst(t_stack *stack);

#endif