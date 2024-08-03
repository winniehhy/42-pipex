/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hheng <hheng@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:46:13 by hheng             #+#    #+#             */
/*   Updated: 2024/07/13 11:05:55 by hheng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_newlst(t_list *new_lst, t_list *lst, void *(*f)(void *)
							, void (*del)(void *))
{
	t_list	*add;

	add = ft_lstnew(f(lst->content));
	if (add == NULL)
	{
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	ft_lstadd_back(&new_lst, add);
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (lst == NULL)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (new_lst == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		ft_newlst(new_lst, lst, f, del);
		lst = lst->next;
	}
	return (new_lst);
}
