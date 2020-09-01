/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:12:25 by cfrouin           #+#    #+#             */
/*   Updated: 2020/06/20 11:27:04 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void					sha224_init_buf_state(t_buffer_state *state,
	const void *input, size_t len)
{
	state->p = input;
	state->len = len;
	state->total_len = len;
	state->single_one_delivered = 0;
	state->total_len_delivered = 0;
}

void					calc_chunk2(size_t space_in_chunk,
	uint8_t chunk[CHUNK_SIZE], t_buffer_state *state)
{
	size_t				left;
	size_t				len;
	int					i;

	if (space_in_chunk >= TOTAL_LEN_LEN)
	{
		left = space_in_chunk - TOTAL_LEN_LEN;
		len = state->total_len;
		memset(chunk, 0x00, left);
		chunk += left;
		chunk[7] = (uint8_t)(len << 3);
		len >>= 5;
		i = 7;
		while (--i >= 0)
		{
			chunk[i] = (uint8_t)len;
			len >>= 8;
		}
		state->total_len_delivered = 1;
	}
	else
		memset(chunk, 0x00, space_in_chunk);
}

int						sha224_calc_chunk(uint8_t chunk[CHUNK_SIZE],
	t_buffer_state *state)
{
	size_t				space_in_chunk;

	if (state->total_len_delivered)
		return (0);
	if (state->len >= CHUNK_SIZE)
	{
		memcpy(chunk, state->p, CHUNK_SIZE);
		state->p += CHUNK_SIZE;
		state->len -= CHUNK_SIZE;
		return (1);
	}
	memcpy(chunk, state->p, state->len);
	chunk += state->len;
	space_in_chunk = CHUNK_SIZE - state->len;
	state->p += state->len;
	state->len = 0;
	if (!state->single_one_delivered)
	{
		*chunk++ = 0x80;
		space_in_chunk -= 1;
		state->single_one_delivered = 1;
	}
	calc_chunk2(space_in_chunk, chunk, state);
	return (1);
}

void					sha224_fill_hash(uint8_t hash[32], uint32_t h[8])
{
	int					i;
	int					j;

	i = -1;
	j = 0;
	while (++i < 8)
	{
		hash[j++] = (uint8_t)(h[i] >> 24);
		hash[j++] = (uint8_t)(h[i] >> 16);
		hash[j++] = (uint8_t)(h[i] >> 8);
		hash[j++] = (uint8_t)h[i];
	}
}
