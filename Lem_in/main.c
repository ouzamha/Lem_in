/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:35:36 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 12:58:43 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_lines(t_mem *mem)
{
	t_hold	*hold;

	while (mem->line)
	{
		hold = mem->line;
		ft_putstr(hold->adr);
		ft_putstr("\n");
		mem->line = mem->line->next;
		free(hold->adr);
		free(hold);
	}
	ft_putstr("\n");
}

void	free_lem_in(t_mem *mem)
{
	t_hold	*hold;

	while (mem->hld)
	{
		hold = mem->hld;
		mem->hld = mem->hld->next;
		free(hold->adr);
		free(hold);
	}
}

void	init_lem_in(t_farm *farm, t_mem *mem)
{
	mem->hld = NULL;
	farm->node = NULL;
	farm->end = NULL;
	farm->start = NULL;
	mem->line = NULL;
	farm->size = 0;
}

int		main(void)
{
	t_farm	farm;
	t_mem	mem;

	init_lem_in(&farm, &mem);
	read_farm(&farm, &mem);
	find_sol(&farm, &mem);
	print_lines(&mem);
	share_ants(&farm);
	printing(&farm);
	free_lem_in(&mem);
	return (0);
}
