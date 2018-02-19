/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/11 11:11:02 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 12:25:03 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_ftprintf_params
{
	char			*flags;
	int				width;
	int				precision;
	char			*size;
	char			*size2;
	char			type;
	int				valid;
	int				*scount;
	int				diese_f;
	int				zero_f;
	int				moins_f;
	int				plus_f;
	int				space_f;
	int				h_s;
	int				hh_s;
	int				l_s;
	int				ll_s;
	int				j_s;
	int				z_s;
	char			*str_lst;
	int				len;
	int				cumul_size;
	int				wchar_size;
	int				wchar_len;
}				t_params;

int				ft_printf(const char *format, ...);
int				ft_search_arguments(const char *format);
void			ft_sf_isstring(t_params *f, char *str);
void			ft_sf_isint(t_params *f, int long long nb);
void			ft_sf_isunsint(t_params *f, uintmax_t nb);
void			ft_sf_islongint(t_params *f, long int nb);
void			ft_sf_isvoid(t_params *f, void *p);
void			ft_sf_iswchar(t_params *f, wchar_t nb);
int				ft_sf_iswchar_str(t_params *f, wchar_t *str);
void			ft_unicode_limit(wchar_t n, int size, int *count, t_params *f);
void			ft_check_unicode(wchar_t n, int *count, t_params *f);
void			ft_check_unicode_str(wchar_t *str, int *count, t_params *f);
int				ft_is_valid_type(char c);
int				ft_is_flags(char c);
int				ft_check_after_is_type_exist(const char *format, int i);
int				ft_is_size(char c);
int				ft_check_arg_continuation(const char *format, int i);
int				ft_check_format(const char *format, va_list ap, int *count);
int				ft_check_format2(const char *format, va_list ap, int *c, int i);
int				ft_fill_fields(char *stock, va_list ap, int *count);
int				ft_repartition_after_parse(t_params *f, va_list ap);
int				ft_parse_stock_f_w(char *stock, t_params *fields, int i);
int				ft_parse_stock_p_s_t_1(t_params *fields, char *stock, int i);
int				ft_parse_stock_p_s_t(t_params *fields, char *stock, int i);
void			ft_fill_size_operator(t_params *f, char *str_size);
void			ft_va_arg_parse_int1(t_params *f, va_list ap);
void			ft_va_arg_parse_int2(t_params *f, va_list ap);
void			ft_va_arg_parse_char(t_params *f, va_list ap);
int				ft_va_arg_parse_wcharstr(t_params *f, va_list ap);
void			ft_hexa(t_params *f, uintmax_t nb);
void			ft_analyze_hexa(t_params *f);
void			ft_width_hexa(t_params *f, int i, int l, int j);
void			ft_wp_hexa(t_params *f, int i, int l, int j);
void			ft_wp_minus(t_params *f, int i, int l, int j);
void			ft_diese_hexa(t_params *f);
int				ft_minus_hexa(t_params *f, int k);
int				ft_v(t_params *f);
int				ft_apply_diese_hexa(t_params *f, int j, int *i);
void			ft_string(t_params *f, char *str);
void			ft_char(t_params *f, int c);
void			ft_iam_d_i(t_params *f, long long nb);
void			ft_all_di(t_params *f, long long nb, int len, long long n);
void			ft_iam_u(t_params *f, uintmax_t nb);
int				ft_count_nb(long long nb);
void			ft_wchar(t_params *f, wchar_t *str, char *trans);
int				ft_analyze_wchar(wchar_t *str, int *count, t_params *f);
int				ft_check_wchar_isnot_valid(wchar_t *str, t_params *f);
void			ft_wcsolo(t_params *f, wchar_t nb);

#endif
