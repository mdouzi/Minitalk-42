/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouzi <mdouzi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:28:22 by mdouzi            #+#    #+#             */
/*   Updated: 2023/01/24 22:28:23 by mdouzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_atoi(const char *str);
int	ft_printf(const char *format, ...);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int nb);
int	ft_putchar(char c);
int	ft_puthex(unsigned long nb, char *base);
int	ft_putnbr(int nb);
int	ft_strlen(char *str);

#endif
