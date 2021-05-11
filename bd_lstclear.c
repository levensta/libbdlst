#include "bidirectional_list.h"

void		bd_lstdelone(t_bd_lst **head, t_bd_lst *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		if (lst->prev == NULL)
			*head = lst->next;
		else
			lst->prev->next = lst->next;
		if (lst->next)
			lst->next->prev = lst->prev;
		free(lst);
	}
}

void		bd_lstclear(t_bd_lst **lst, void (*del)(void*))
{
	t_bd_lst *last;

	if (lst && *lst && del)
	{
		last = bd_lstlast(*lst);
		while (last->prev != NULL)
		{
			last = last->prev;
			bd_lstdelone(lst, last->next, (*del));
		}
		*lst = NULL;
	}
}
