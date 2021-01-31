/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:36:12 by aybouras          #+#    #+#             */
/*   Updated: 2020/11/05 10:36:14 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_surg	*creat_surg(t_part *part, t_mem *mem)
{
	t_surg	*surg;

	surg = ft_malloc(sizeof(t_surg), mem);
	surg->prev = part;
	surg->adj = part->adj;
	surg->next = NULL;
	return (surg);
}

int		enqueue(t_queue *q, t_part *part, t_mem *mem)
{
	t_surg	*surg;

	surg = creat_surg(part, mem);
	if (q->first)
	{
		q->end->next = surg;
		q->end = surg;
	}
	else
	{
		q->first = surg;
		q->end = surg;
	}
	return (0);
}

t_surg	*dequeue(t_queue *q)
{
	t_surg	*hld;

	hld = NULL;
	if (q->first)
	{
		hld = q->first;
		q->first = q->first->next;
	}
	return (hld);
}
