/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:27:29 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/18 12:38:16 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** https://en.wikipedia.org/wiki/MD5
*/

unsigned int g_k[64];
unsigned int g_s[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7,
	12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static void			init_gk(void)
{
	static int		calculated = 0;
	int				i;

	if (calculated == 1)
		return ;
	i = 0;
	while (i < 64)
	{
		g_k[i] = pow(2, 32) * fabs(sin(i + 1));
		i++;
	}
	calculated = 1;
}

void				md5_init(unsigned char *string, t_md5 *t)
{
	int				i;

	t->a0 = 0x67452301;
	t->b0 = 0xefcdab89;
	t->c0 = 0x98badcfe;
	t->d0 = 0x10325476;
	init_gk();
	t->out_len = get_output_len(string);
	t->out = (unsigned char *)ft_strnew(t->out_len);
	ft_strcpy((char *)t->out, (char *)string);
	t->len = ft_strlen((char *)string) * 8;
	t->out[ft_strlen((char *)string)] = 1 << 7;
	i = -1;
	while (++i < 8)
		t->out[t->out_len - 8 + i] = ((char *)&(t->len))[i];
}

void				md5_set_m(t_md5 *t, int i)
{
	t->x = 0;
	while (t->x < 16)
	{
		t->m[t->x] = 0;
		t->m[t->x] += t->out[i * 64 + t->x * 4 + 0];
		t->m[t->x] += t->out[i * 64 + t->x * 4 + 1] << 8;
		t->m[t->x] += t->out[i * 64 + t->x * 4 + 2] << 16;
		t->m[t->x] += t->out[i * 64 + t->x * 4 + 3] << 24;
		t->x++;
	}
	t->a = t->a0;
	t->b = t->b0;
	t->c = t->c0;
	t->d = t->d0;
}

void				md5_loop(t_md5 *t, int j)
{
	if (j < 16)
	{
		t->f = (t->b & t->c) | ((~t->b) & t->d);
		t->g = j;
	}
	else if (j < 32)
	{
		t->f = (t->d & t->b) | ((~t->d) & t->c);
		t->g = (5 * j + 1) & 15;
	}
	else if (j < 48)
	{
		t->f = t->b ^ t->c ^ t->d;
		t->g = (3 * j + 5) & 15;
	}
	else
	{
		t->f = t->c ^ (t->b | (~t->d));
		t->g = (7 * j) & 15;
	}
	t->f = t->f + t->a + g_k[j] + t->m[t->g];
	t->a = t->d;
	t->d = t->c;
	t->c = t->b;
	t->b += ((t->f << g_s[j]) | (t->f >> (32 - g_s[j])));
}

void				md5(unsigned char *string)
{
	t_md5			t;
	unsigned int	i;
	unsigned int	j;

	i = -1;
	md5_init(string, &t);
	while (++i < (t.out_len * 8) / 512)
	{
		md5_set_m(&t, i);
		j = 0;
		while (j < 64)
			md5_loop(&t, j++);
		t.a0 += t.a;
		t.b0 += t.b;
		t.c0 += t.c;
		t.d0 += t.d;
	}
	t.a0 = reverse_int(t.a0);
	t.b0 = reverse_int(t.b0);
	t.c0 = reverse_int(t.c0);
	t.d0 = reverse_int(t.d0);
	ft_printf("%.8x%.8x%.8x%.8x", t.a0, t.b0, t.c0, t.d0);
	free(t.out);
}
