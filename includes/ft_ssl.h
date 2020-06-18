/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillefrouin <cyrillefrouin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:28:42 by cyrillefrou       #+#    #+#             */
/*   Updated: 2020/06/18 12:29:51 by cyrillefrou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>

# include "libft.h"

# define CHUNK_SIZE 64
# define TOTAL_LEN_LEN 8

typedef struct			s_operation
{
	char				*name;
	void				(*operation)(unsigned char *);
	struct s_operation	*next;
}						t_operation;

typedef struct			s_data
{
	t_operation			*c_op;
	t_operation			*op_list;
	int					quiet;
	int					print;
	int					reverse;
	int					hadFile;
}						t_data;

typedef struct			s_md5
{
	unsigned int		a0;
	unsigned int		b0;
	unsigned int		c0;
	unsigned int		d0;
	unsigned int		a;
	unsigned int		b;
	unsigned int		c;
	unsigned int		d;
	unsigned int		x;
	unsigned int		y;
	unsigned int		out_len;
	long long			len;
	unsigned int		f;
	unsigned int		g;
	unsigned char		*out;
	unsigned int		m[16];
}						t_md5;

typedef struct			s_sha256
{
	int					i;
	int					j;
	uint32_t			ah[8];
	uint8_t				*p;
	uint32_t			w[16];
	uint32_t			h[8];
	uint8_t				hash[32];
	char				hash_string[65];
	size_t				len;
}						t_sha256;

typedef struct			s_buffer_state
{
	const uint8_t		*p;
	size_t				len;
	size_t				total_len;
	int					single_one_delivered;
	int					total_len_delivered;
}						t_buffer_state;

typedef struct			s_words_calc
{
	uint32_t			s1;
	uint32_t			ch;
	uint32_t			temp1;
	uint32_t			s0;
	uint32_t			maj;
	uint32_t			temp2;
}						t_words_calc;

/*
** params.c
*/
int						params(int ac, char **av, t_data *data);

/*
** error.c
*/
void					md5_error(char *message, int errnoDisplay);

/*
** op.c
*/
void					call_operation_string(t_data *data, unsigned char *str);
void					call_operation_file(t_data *data, char *filename, unsigned char *str);

/*
** md5.c
*/
void					md5(unsigned char *input);

/*
** md5bis.c
*/
int						get_output_len(unsigned char *string);
int						reverse_int(int num);

/*
** sha256.c
*/
void					sha256(unsigned char *input);

/*
** sha256bis.c
*/
uint32_t				right_rot(uint32_t value, unsigned int count);
void					init_buf_state(t_buffer_state *state, const void *input,
	size_t len);
int						calc_chunk(uint8_t chunk[CHUNK_SIZE],
	t_buffer_state *state);
void					fill_hash(uint8_t hash[32], uint32_t h[8]);

/*
** sha256ter.c
*/

void					hash_to_string(char string[65], const uint8_t hash[32]);

#endif