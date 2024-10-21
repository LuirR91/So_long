/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiribei <luiribei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:01:40 by luiribei          #+#    #+#             */
/*   Updated: 2024/05/27 15:26:04 by luiribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	i;

	i = 0;
	while (num)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_print_char(num + '0');
		else
			ft_print_char(num - 10 + 'a');
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
	{
		i += write (1, "0x0", 3);
		return (3);
	}		
	else
	{

		i += write(1, "0x", 2);
		ft_put_ptr(ptr);
		i += ft_ptr_len(ptr);
	}
	return (i);
}
