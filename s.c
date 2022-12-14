    // else
    // {
    //     while (!is_sorted(stack_a))
    //     {
    //         int	i;
	//         int	size;

	//         size = ft_lstsize(stack_a);
	//         i = find_min(stack_a);
	//         if (i > size / 2)
	//         {
	// 	        while (i < size)
	// 	        {
	// 		        reverse_rotate_a(&stack_a);
	// 		    i++;
	// 	    }
	//         }
	//         else
	//         {
	// 	        while (i > 0)
	// 	        {
	// 		        rotate_a(&stack_a);
	// 		        i--;
	// 	        }
	//         }
    //         push_b(&stack_a, &stack_b);
    // }

    // while (stack_b)
    //     push_a(&stack_a, &stack_b);
    // }



/**********************************************************/
    // while (i < 3)
    // {
    //     int a = find_small_from_top(stack_a, ft_lstsize(stack_a));
    //     int b = find_small_from_bottom(stack_a, ft_lstsize(stack_a));

    //     printf("top == %d \n", a);
    //     printf("bot == %d \n", b);

    //     if(a < b)
    //     {
    //         if(a != 0)
    //         {
    //             while (a >= 0)
    //             {
    //                 rotate_a(&stack_a);
    //                 a--;
    //             }
    //         }
    //         push_b(&stack_a, &stack_b);
    //     }
    //     else
    //     {
    //         while (b >= 0)
    //         {
    //             reverse_rotate_a(&stack_a);
    //             b--;
    //         }
    //         push_b(&stack_a, &stack_b);
    //     }
    //     i++;
    //     printf("\nstack a :\n");
    //     tmp = stack_a;
    //     while (tmp != NULL)
    //     {
    //         printf("%d \n", tmp -> content);
    //         tmp = tmp -> next;
    //     }
    // }

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

int find_small_from_top(t_stack *stack, int range)
{
    int i;
    int *array;

    i = 0;
    array = cpy_to_array(stack);
    while (i <= range)
    {
        if(array[i] <= range)
            return (i);
        i++;
    }
    free(array);
    return (-1);
}

int find_small_from_bottom(t_stack *stack, int range)
{
    int i;
    int *array;

    i = 0;
    array = cpy_to_array(stack);
    swap_array(array, ft_lstsize(stack));
    while (i <= range)
    {
        if(array[i] <= range)
            return (i);
        i++;
    }
    free(array);
    return (-1);
}

// void    push_groups(t_stack **stack_a, t_stack **stack_b, int rs)
// {
//     while (rs >= 0)
//     {
//         int	i;
// 	    int	size;

// 	    size = ft_lstsize(stack_a);
// 	    i = find_min(stack_a);
// 	    if (i > size / 2)
// 	    {
// 		    while (i < size)
// 		    {
// 			    reverse_rotate_a(&stack_a);
// 			i++;
// 		}
// 	    }
// 	    else
// 	    {
// 		    while (i > 0)
// 		    {
// 			    rotate_a(&stack_a);
// 			    i--;
// 		    }
// 	    }
//         push_b(&stack_a, &stack_b);
//         rs--;
//     }
// }

while (i < 10)
    {
        int a = find_small_from_top(stack_a, size);
        int b = find_small_from_bottom(stack_a, size);

        printf("a == %d b = %d", a , b);

        if(a == 0)
            push_b(&stack_a, &stack_b);
        else if(a <= b && a != -1)
        {
            while (a > 0)
            {
                rotate_a(&stack_a);
                a--;
            }
            push_b(&stack_a, &stack_b);
        }
        else if(a < b && b != -1)
        {
            while (b > 0)
            {
                reverse_rotate_a(&stack_a);
                b--;
            }
            push_b(&stack_a, &stack_b);
        }
        i++;
    }