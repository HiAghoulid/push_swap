/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:48:31 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/22 12:01:57 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

char check_bigest_value(t_stack *p, int nb)
{
	while (p != NULL)
	{
		if (p -> content == nb)
			return (1);
		p = p -> next;
	}
	return (0);
}

int bing_indice(t_stack *p, int num)
{
	while (p != NULL)
	{
		if (num == p -> content)
			return(p -> index);
		p = p -> next;
	}
	return(0);
}

int content_location(t_stack *p, int content)
{
  int i;
  
  i = 0;
  while (content != p -> content)
  {
    i++;
    p = p -> next;
  }
  return (i);
}

int get_moves_first_num(t_stack *p, int nb)
{
	int start = 0;
	int i = content_location(p, nb) - start;
	return (i);
}

int get_moves_second_num(t_stack *p, int nb)
{
	int end = ft_lstsize(p) - 1;
	int i = end - content_location(p, nb) + 1;
	return (i);
}

void back_to_stack_a(t_stack **stack_a, t_stack **stack_b, int *arr)
{
	int count;
	int i;

	count = 0;
	i = ft_lstsize(*stack_b) - 1;
	while (*stack_b)
	{
		if (check_bigest_value((*stack_b), arr[i]))
		{ 
			if ((*stack_b) -> content == arr[i])
			{
				push_a(stack_a, stack_b);
				i--;
			}
			else
			{
				if (bing_indice(*stack_b, arr[i]) <= (ft_lstsize(*stack_b) - 1) / 2
				&& get_moves_first_num(*stack_b, arr[i]) <= get_moves_second_num(*stack_b, arr[i]))
				{
					if (count == 0 || (*stack_b) -> content >  ft_lstlast(*stack_a)->content)
					{
						push_a(stack_a, stack_b);
						if (ft_lstsize((*stack_a)) > 1)
							rotate_a(stack_a);
						count++;
					}
					else if (get_moves_first_num(*stack_b, arr[i]) <= get_moves_second_num(*stack_b, arr[i]))
						rotate_b(stack_b);
					else
						reverse_rotate_b(stack_b);
				}
				else
				{
					if (count == 0 || (*stack_b) -> content >  ft_lstlast(*stack_a)->content)
					{
						push_a(stack_a, stack_b);
						if (ft_lstsize((*stack_a)) > 1)
							rotate_a(stack_a);
						count++;
					}
					else if (get_moves_first_num(*stack_b, arr[i]) > get_moves_second_num(*stack_b, arr[i]))
						reverse_rotate_b(stack_b);
					else
						rotate_b(stack_b);
				}
			}
		}
		else 
		{
			reverse_rotate_a(stack_a);
			count--;
			i--;
		}
	}
	while(count > 0)
	{
		reverse_rotate_a(stack_a);
		count--;
	}
}

int main(int ac, char *av[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac < 2)
        return (0);
    if(!fill_stack(&stack_a, av, ac) || is_error(stack_a))
        return (0);
	index_lst(stack_a);
	if(ft_lstsize(stack_a) && is_sorted_dec(stack_a))
		swap_a(&stack_a);
	else if(ft_lstsize(stack_a) == 3)
		lthree_sort(&stack_a);
	else if(ft_lstsize(stack_a) <= 5)
		lfive_sort(&stack_a, &stack_b);
	else if(ft_lstsize(stack_a) <= 100)
	{
    	push_shunckes(&stack_a, &stack_b, 4);
        int *arr =  cpy_to_array(stack_b);
		back_to_stack_a(&stack_a, &stack_b, arr);
	}
	else
	{
    	push_shunckes(&stack_a, &stack_b, 10);
		int *arr =  cpy_to_array(stack_b);
		back_to_stack_a(&stack_a, &stack_b, arr);
	}
	t_stack *tmp; 
    // if(is_sorted(stack_a))
    //     printf("OK\n");
    // else
    //     printf("KO\n");
	// printf("\nstack a :\n");
    // tmp = stack_a;
    // while (tmp != NULL)
    // {
    //     printf("%d ", tmp -> content);
    //     tmp = tmp -> next;
    // }
    // printf("\nstack b :\n");
    // tmp = stack_b;
    // while (tmp != NULL)
    // {
    //     printf("%d ", tmp -> content);
    //     tmp = tmp -> next;
    // }
}