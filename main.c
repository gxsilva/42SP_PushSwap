/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:59:32 by lsilva-x          #+#    #+#             */
/*   Updated: 2025/02/11 12:16:16 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	main(int argc, char **argv)
{
	char	*str;
	s_node	*stack_a;
	int		*nbrs;

	stack_a = NULL;
	if (argc == 1)
		return (-1);
	str = init_str(argc, argv);
	if (!str)
		return (-1);
	nbrs = check_ints(str);
	check_nbrs(nbrs);
	init_stack(nbrs, &stack_a);
	print_list(stack_a);
	// printf ("List Size: %d\n", size_list(stack_a));
	if (!list_sorted(stack_a))
	{
		printf("Time to sort wp :P");
	}
	free_list(stack_a);
	return (0);
}

