/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzabrots <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:46:06 by dzabrots          #+#    #+#             */
/*   Updated: 2017/12/18 18:10:45 by dzabrots         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	func(int num, ...)
{
	va_list	ptr;
	int		res = 0;

	va_start(ptr, num);
	while (num > 0)
	{
		res += va_arg(ptr, int);
		num--;
	}
	return (res);
}

int main(void)
{
	printf("res: %i\n", func(6, 1, 1, 1, 1, 1, 5));
}
