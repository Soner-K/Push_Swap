/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:58:17 by sokaraku          #+#    #+#             */
/*   Updated: 2024/01/27 20:40:27 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Allocate nmemb * size bytes and returns a void pointer
 * to the allocated memory.
 * @param nmemb The number of bytes to allocate.
 * @param size The bytes' size of the data type to be allocated.
 * @returns A void pointer to the newly allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if ((size != 0) && nmemb >= __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	if (nmemb == 0 || !size)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
