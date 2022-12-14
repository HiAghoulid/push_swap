/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghouli <haghouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:48:31 by haghouli          #+#    #+#             */
/*   Updated: 2022/12/13 16:50:35 by haghouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/push_swap.h"

void    swap_array(int *array, int len)
{
    int i;
    int l;
    int tmp;

    i = 0;
    l = len - 1;
    while (i < len / 2)
    {
        tmp = array[i];
        array[i] = array[l - i];
        array[l - i] = tmp;
        i++;
    }    
}

int   *cpy_to_array(t_stack *stack)
{
    int *array;
    int i;

    i = 0;
    array = malloc(ft_lstsize(stack) * sizeof(int));
    while (stack != NULL)
    {
        array[i++] = stack -> index;
        stack = stack -> next;
    }
    return (array);
}

int find_small_from_top(t_stack *stack, int range, int chunck_size)
{
    int i;
    int *array;

    i = 0;
    array = cpy_to_array(stack);
    while (i <= range)
    {
        if(array[i] <= chunck_size)
            return (i);
        i++;
    }
    free(array);
    return (-1);
}

int find_small_from_bottom(t_stack *stack, int range, int chunck_size)
{
    int i;
    int *array;

    i = 0;
    array = cpy_to_array(stack);
    swap_array(array, ft_lstsize(stack));
    while (i < range)
    {
        if(array[i] < chunck_size)
            return (i);
        i++;
    }
    free(array);
    return (-1);
}

void push_chunckes(t_stack **stack_a,t_stack **stack_b, int div)
{
    int i = 0;
    int size = ft_lstsize(*stack_a) / 2;
    int chunck_size = ft_lstsize(*stack_a) / div;
    int counter = chunck_size;
    int j = 0;
    while (j < div)
    {
        i = 0;
        while (i < chunck_size)
        {
            int a = find_small_from_top(*stack_a, size, counter);
            int b = find_small_from_bottom(*stack_a, size, counter);

            if(a == 0)
                push_b(stack_a, stack_b);
            else if(b == -1)
            {
                while (a > 0)
                {
                    rotate_a(stack_a);
                    a--;
                }
                push_b(stack_a, stack_b);
            }
            else if(a == -1)
            {
                while (b >= 0)
                {
                    reverse_rotate_a(stack_a);
                    b--;
                }
                push_b(stack_a, stack_b);
            }
            else if(a <= b)
            {
                while (a > 0)
                {
                    rotate_a(stack_a);
                    a--;
                }
                push_b(stack_a, stack_b);
            }
            else if(a > b)
            {
                while (b >= 0)
                {
                    reverse_rotate_a(stack_a);
                    b--;
                }
                push_b(stack_a, stack_b);
            }
            i++;
        }
        j++;
        counter += chunck_size;
    }
}

void    push_groups(t_stack **stack_a, t_stack **stack_b)
{
    while (*stack_b)
    {
        int	i;
	    int	size;

	    size = ft_lstsize(*stack_b);
	    i = find_max(*stack_b);
	    if (i > size / 2)
	    {
		    while (i < size)
		    {
			    reverse_rotate_b(stack_b);
			i++;
		}
	    }
	    else
	    {
		    while (i > 0)
		    {
			    rotate_b(stack_b);
			    i--;
		    }
	    }
        push_a(stack_a, stack_b);
    }
}

int main(int ac, char *av[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    t_stack *tmp;
    int div = 10;
    int i = 0;
    if (ac < 2)
        return (0);
    if(!fill_stack(&stack_a, av, ac) || is_error(stack_a))
        return (0);
    int t = ft_lstsize(stack_a) / div;
    index_lst(stack_a);
    push_chunckes(&stack_a, &stack_b, div);
    // int max = find_max(stack_b);
    // while (max > 0)
    // {
    //     rotate_b(&stack_b);
    //     max--;
    // }
    // push_a(&stack_a, &stack_b);
    push_groups(&stack_a, &stack_b);

    // if(is_sorted(stack_a))
    //     printf("OK");
    // else
    //     printf("KO");
    // printf("\nstack a :\n");
    // tmp = stack_a;
    // while (tmp != NULL)
    // {
    //     printf("%d ", tmp -> content);
    //     tmp = tmp -> next;
    // }
    // printf("\nstack b :\n");
    // tmp = stack_b;
    // i = 0;
    // while (tmp != NULL)
    // {
    //     if(i % t == 0)
    //         printf("\n");
    //     printf("%d ", tmp -> content);
    //     i++;
    //     tmp = tmp -> next;
    // } 
}
