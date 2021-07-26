/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smenna <smenna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 15:12:20 by smenna            #+#    #+#             */
/*   Updated: 2021/07/24 15:23:41 by smenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int args_count, char **args)
{
	t_table	table;

	print_header();
	if (args_count < 5 || args_count > 6)
		return (return_error(INVALID_ARGS));
	if (parse_argument(args_count, args, &table))
		return (return_error(PARSE_ERROR));
	if (thread_start(&table))
		return (return_error(THREAD));
	if (args_count == 6)
		printf(GREEN"Philosophers have eaten"RED" %d "GREEN"times.\n",
			table.eat_count);
	return (0);
}
