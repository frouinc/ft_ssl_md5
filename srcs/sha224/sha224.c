/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:12:25 by cfrouin           #+#    #+#             */
/*   Updated: 2020/09/01 11:17:18 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const uint32_t	g_k[] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void				calc_word2(t_words_calc *wc, uint32_t w, uint32_t ah[8],
	uint32_t kva)
{
	wc->s1 = right_rot(ah[4], 6) ^ right_rot(ah[4], 11) ^ right_rot(ah[4], 25);
	wc->ch = (ah[4] & ah[5]) ^ (~ah[4] & ah[6]);
	wc->temp1 = ah[7] + wc->s1 + wc->ch + kva + w;
	wc->s0 = right_rot(ah[0], 2) ^ right_rot(ah[0], 13) ^ right_rot(ah[0], 22);
	wc->maj = (ah[0] & ah[1]) ^ (ah[0] & ah[2]) ^ (ah[1] & ah[2]);
	wc->temp2 = wc->s0 + wc->maj;
	ah[7] = ah[6];
	ah[6] = ah[5];
	ah[5] = ah[4];
	ah[4] = ah[3] + wc->temp1;
	ah[3] = ah[2];
	ah[2] = ah[1];
	ah[1] = ah[0];
	ah[0] = wc->temp1 + wc->temp2;
}

static void				calc_word_rot(t_sha256 *se, t_words_calc *wc)
{
	wc->s0 = right_rot(se->w[(se->j + 1) & 0xf], 7)
	^ right_rot(se->w[(se->j + 1) & 0xf], 18)
	^ (se->w[(se->j + 1) & 0xf] >> 3);
	wc->s1 = right_rot(se->w[(se->j + 14) & 0xf], 17)
	^ right_rot(se->w[(se->j + 14) & 0xf], 19)
	^ (se->w[(se->j + 14) & 0xf] >> 10);
	se->w[se->j] = se->w[se->j] + wc->s0 + se->w[(se->j + 9) & 0xf]
	+ wc->s1;
}

static void				calc_word(t_sha256 *se, t_words_calc *wc)
{
	se->i = -1;
	while (++se->i < 4)
	{
		se->j = -1;
		while (++se->j < 16)
		{
			if (se->i == 0)
			{
				se->w[se->j] = (uint32_t)se->p[0] << 24
				| (uint32_t)se->p[1] << 16
				| (uint32_t)se->p[2] << 8 | (uint32_t)se->p[3];
				se->p += 4;
			}
			else
				calc_word_rot(se, wc);
			calc_word2(wc, se->w[se->j], se->ah, g_k[se->i << 4 | se->j]);
		}
	}
}

static void				init_h(uint32_t h[8])
{
	h[0] = 0xc1059ed8;
	h[1] = 0x367cd507;
	h[2] = 0x3070dd17;
	h[3] = 0xf70e5939;
	h[4] = 0xffc00b31;
	h[5] = 0x68581511;
	h[6] = 0x64f98fa7;
	h[7] = 0xbefa4fa4;
}

void					sha224(unsigned char *input)
{
	t_sha256		se;
	uint8_t			chunk[64];
	t_buffer_state	state;
	t_words_calc	wc;

	se.len = ft_strlen((char *)input);
	init_h(se.h);
	sha224_init_buf_state(&state, input, se.len);
	while (sha224_calc_chunk(chunk, &state))
	{
		se.p = chunk;
		se.i = -1;
		while (++se.i < 8)
			se.ah[se.i] = se.h[se.i];
		calc_word(&se, &wc);
		se.i = -1;
		while (++se.i < 8)
			se.h[se.i] += se.ah[se.i];
	}
	sha224_fill_hash(se.hash, se.h);
	print_hash(se.hash, 28);
}
