/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:37:58 by sleung            #+#    #+#             */
/*   Updated: 2017/03/15 14:36:02 by sleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE	"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN	"\x1B[36m"
# define WHITE	"\x1B[37m"
# define RESET	"\x1B[0m"

typedef struct	s_format
{
	char	*fo;
	int		i;
}				t_format;

typedef struct	s_struct
{
	int		null;
	int		flag;
	int		sharp;
	char	conv;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		mw;
	int		p;
	char	lm;
}				t_struct;

int				ft_printf(const char *format, ...);
int				ft_printf_c(unsigned char c, t_struct *d);
int				ft_printf_wc(wchar_t c, t_struct *d);
int				ft_printf_s(char *str, t_struct *d);
int				ft_printf_ws(wchar_t *c, t_struct *d, int len, int ti);
int				ft_printf_i(intmax_t n, t_struct *d);
int				ft_printf_cd(intmax_t n, t_struct *d);
int				ft_printf_x(uintmax_t n, t_struct *d);
int				ft_printf_cx(uintmax_t n, t_struct *d);
int				ft_printf_o(uintmax_t n, t_struct *d);
int				ft_printf_co(uintmax_t n, t_struct *d);
int				ft_printf_pcnt(t_struct *d);
int				ft_printf_u(uintmax_t n, t_struct *d);
int				ft_printf_cu(unsigned long n, t_struct *d);
int				ft_printf_p(void *ptr, t_struct *d);
int				get_size(t_struct *d);
void			check_flags(t_struct *d, t_format *f, va_list ap);
int				check_conv(t_struct *d, t_format *f);
int				read_data(va_list ap, t_struct *d, t_format *f);
intmax_t		extract_id(va_list ap, t_struct *d);
uintmax_t		extract_oxu(va_list ap, t_struct *d);
void			handle_sign(t_struct *d, char **tmp, char **str, int *ti);
void			handle_flags(t_struct *d, int *space, int *zero, intmax_t n);
int				handle_wildcard(t_struct *d, t_format *f, va_list ap, int prec);
char			*handle_sharp(t_struct *d, char **tmp, int *ti, intmax_t n);
int				count_spaces(t_struct *d, int len);
int				count_zeros(t_struct *d, int len, intmax_t n);
int				count_sp_int(t_struct *d, int len, intmax_t n);
int				write_spaces(int spaces, char *tmp, int ti);
int				write_zeros(int zeros, char *tmp, int ti);
int				write_null(t_struct *d);
int				ft_tonarrow(wchar_t *str, char *dst, int dlen, t_struct *d);
char			*ft_itoa_base(intmax_t value, int base);
char			*ft_itoa_base_uns_long(uintmax_t value, int base);
char			*ft_stricpy(char *dst, int *i, const char *src);
int				ft_putstrcount(char *tmp);
int				ft_putstrdel(char **as, int ti);

#endif
