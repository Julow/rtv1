/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:30:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/21 13:20:06 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "kd_tree.h"
#include "kd_tree_def.h"

#include <math.h>

static void		kdtree_build_child(t_kdtree_child **dst, t_kdtree_build *b,
					uint32_t *indexes, uint32_t count, bool force_leaf);

// static float	kdtree_av(t_kdtree_def const *def, uint32_t k, uint32_t d)
// {
// 	float					sum;
// 	t_kdtree_def_data const	*data;
// 	float					tmp_sum;
// 	t_vec2u					pt;

// 	pt = VEC2U(0, 0);
// 	sum = 0.f;
// 	data = VECTOR_IT(def->datas);
// 	while (VECTOR_NEXT(def->datas, data))
// 	{
// 		tmp_sum = 0.f;
// 		pt.y += data->pt_count * k;
// 		while (pt.x < pt.y)
// 		{
// 			tmp_sum += VGETC(float, def->pts, pt.x + d);
// 			pt.x += k;
// 		}
// 		sum += tmp_sum / data->pt_count;
// 	};
// 	return (sum / def->datas.length);
// }

// static float	kdtree_av(t_kdtree_def const *def, uint32_t k, uint32_t d)
// {
// 	float			min;
// 	float			max;
// 	float			tmp;
// 	uint32_t		i;

// 	min = VGETC(float, def->pts, d);
// 	max = min;
// 	i = k;
// 	while (i < def->pts.length)
// 	{
// 		tmp = VGETC(float, def->pts, i + d);
// 		if (tmp < min)
// 			min = tmp;
// 		if (tmp > max)
// 			max = tmp;
// 		i += k;
// 	}
// 	return ((min * 0.5f) + (max * (1.f - 0.5f)));
// }

// static t_vec2u	kdtree_split_count(t_kdtree_def const *def,
// 					uint32_t const *indexes, uint32_t index_count,
// 					uint32_t k, uint32_t d, float p)
// {
// 	uint32_t		i;
// 	t_vec2u			tmp;
// 	t_vec2u			count;
// 	t_vec2u			pts;

// 	count = VEC2U(0, 0);
// 	i = 0;
// 	while (i < index_count)
// 	{
// 		tmp = VEC2U(0, 0);
// 		pts = VGETC(t_kdtree_def_data, def->datas, indexes[i]).pts;
// 		pts = VEC2U(pts.x * k + d, pts.y * k);
// 		while (pts.x < pts.y)
// 		{
// 			if (VGETC(float, def->pts, pts.x) < p)
// 				tmp.x++;
// 			else
// 				tmp.y++;
// 			pts.x += k;
// 		}
// 		if (tmp.x > 0)
// 			count.x++;
// 		if (tmp.y > 0)
// 			count.y++;
// 		i++;
// 	}
// 	return (count);
// }

static float	kdtree_av(t_kdtree_def const *def, uint32_t const *indexes,
					uint32_t index_count, uint32_t k, uint32_t d)
{
	uint32_t		i;
	float			min;
	float			max;
	float			tmp;
	t_vec2u			pts;

	pts = VGETC(t_kdtree_def_data, def->datas, indexes[0]).pts;
	min = VGETC(float, def->pts, pts.x * k + d);
	max = min;
	i = 0;
	while (i < index_count)
	{
		pts = VGETC(t_kdtree_def_data, def->datas, indexes[i]).pts;
		pts = VEC2U(pts.x * k + d, pts.y * k);
		while (pts.x < pts.y)
		{
			tmp = VGETC(float, def->pts, pts.x);
			if (tmp < min)
				min = tmp;
			if (tmp > max)
				max = tmp;
			pts.x += k;
		}
		i++;
	}
	return (min * 0.5f + (max * (1.f - 0.5f)));
}

static uint32_t	kdtree_split(t_kdtree_def const *def,
					uint32_t const *indexes, uint32_t index_count,
					uint32_t k, uint32_t d, float p, uint32_t *dst, bool left)
{
	uint32_t		i;
	uint32_t		len;
	t_vec2u			pts;

	len = 0;
	i = 0;
	while (i < index_count)
	{
		pts = VGETC(t_kdtree_def_data, def->datas, indexes[i]).pts;
		pts = VEC2U(pts.x * k + d, pts.y * k);
		while (pts.x < pts.y)
		{
			if (BOOL_OF(VGET(float, def->pts, pts.x) < p) == left)
			{
				dst[len++] = indexes[i];
				break ;
			}
			pts.x += k;
		}
		i++;
	}
	return (len);
}

static void		kdtree_build_split(t_kdtree_node *dst, t_kdtree_build *b,
					uint32_t *indexes, uint32_t count)
{
	uint32_t		split[count];
	uint32_t		d;
	uint32_t		tmp_len;
	float			tmp_p;
	t_vec2u			tmp;

	d = 0;
	dst->d = b->tree.k;
	while (d < b->tree.k)
	{
		tmp_p = kdtree_av(b->def, indexes, count, b->tree.k, d);
		// tmp = kdtree_split_count(b->def, indexes, count, b->tree.k, d, tmp_p);
		tmp.x = kdtree_split(b->def, indexes, count, b->tree.k, dst->d, dst->p, split, true);
		tmp.y = kdtree_split(b->def, indexes, count, b->tree.k, dst->d, dst->p, split, false);
		ft_printf("D %d P %f V [%u, %u] C %u%n", d, tmp_p, tmp.x, tmp.y, count);
		if (dst->d >= b->tree.k || (tmp.x + tmp.y) < tmp_len)
		{
			dst->d = d;
			dst->p = tmp_p;
			tmp_len = tmp.x + tmp.y;
		}
		d++;
	}
	ft_printf("	D %d P %f%n", dst->d, dst->p);

	tmp_len = kdtree_split(b->def, indexes, count, b->tree.k, dst->d, dst->p, split, true);
	kdtree_build_child(&dst->left, b, split, tmp_len, BOOL_OF(tmp_len == count));
	tmp_len = kdtree_split(b->def, indexes, count, b->tree.k, dst->d, dst->p, split, false);
	kdtree_build_child(&dst->right, b, split, tmp_len, BOOL_OF(tmp_len == count));
}

static void		kdtree_build_leaf(t_vector *dst, t_kdtree_build *b,
					uint32_t *indexes, uint32_t count)
{
	*dst = VECTOR(void const*);
	ft_vreserve(dst, count);
	dst->length = count;
	while (count > 0)
	{
		--count;
		VGET(void const*, *dst, count) =
			VGET(t_kdtree_def_data, b->def->datas, indexes[count]).data;
	}
	b->tree.height = MAX(b->tree.height, b->height);
}

static void		kdtree_build_child(t_kdtree_child **dst, t_kdtree_build *b,
					uint32_t *indexes, uint32_t count, bool force_leaf)
{
	*dst = NEW(t_kdtree_child);
	if (count <= 3 || b->height > MAX_HEIGHT || force_leaf) // TODO: improve
	{
		(*dst)->type = KDTREE_LEAF;
		return (kdtree_build_leaf(&(*dst)->v.leaf, b, indexes, count));
	}
	(*dst)->type = KDTREE_SPLIT;
	b->height++;
	kdtree_build_split(&(*dst)->v.split, b, indexes, count);
	b->height--;
}

t_kdtree		kdtree_build(uint32_t k, t_kdtree_def const *def)
{
	uint32_t		indexes[def->datas.length];
	uint32_t		i;
	t_kdtree_build	b;

	b = (t_kdtree_build){(t_kdtree){k, 0, def->datas.length, NULL}, def, 0};
	i = 0;
	while (i < def->datas.length)
	{
		indexes[i] = i;
		i++;
	}
	kdtree_build_child(&b.tree.root, &b, indexes, def->datas.length, false);
	return (b.tree);
}
