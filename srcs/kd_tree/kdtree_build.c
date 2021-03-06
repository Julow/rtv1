/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:30:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/05/02 16:54:34 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kd_tree.h"
#include "kd_tree_builder.h"
#include "math_utils.h"

#include <math.h>

#define MAX_HEIGHT			10 // TODO: improve

static void		kdtree_build_child(t_kdtree_child **dst, t_kdtree_builder *b,
					uint32_t *indexes, uint32_t count, bool force_leaf);

static float	kdtree_median(t_kdtree_builder const *b, uint32_t const *indexes,
					uint32_t index_count, uint32_t d)
{
	uint32_t		i;
	float			min;
	float			max;
	float			tmp;
	t_vec2u			pts;

	pts = VGETC(t_vec2u, b->pts_indexes, indexes[0]);
	min = VGETC(float, b->pts, pts.x + d);
	max = min;
	i = 0;
	while (i < index_count)
	{
		pts = VGETC(t_vec2u, b->pts_indexes, indexes[i]);
		while (pts.x < pts.y)
		{
			tmp = VGETC(float, b->pts, pts.x + d);
			if (min > tmp)
				min = tmp;
			else if (max < tmp)
				max = tmp;
			pts.x += b->k;
		}
		i++;
	}
	return (LERP(min, max, 0.5f));
}

static uint32_t	kdtree_split(t_kdtree_builder const *b,
					uint32_t const *indexes, uint32_t index_count,
					uint32_t d, float p, uint32_t *dst, bool left)
{
	uint32_t		i;
	uint32_t		len;
	t_vec2u			pts;

	len = 0;
	i = 0;
	while (i < index_count)
	{
		pts = VGETC(t_vec2u, b->pts_indexes, indexes[i]);
		while (pts.x < pts.y)
		{
			if (BOOL_OF(VGET(float, b->pts, pts.x + d) < p) == left)
			{
				dst[len++] = indexes[i];
				break ;
			}
			pts.x += b->k;
		}
		i++;
	}
	return (len);
}

static void		kdtree_build_split(t_kdtree_node *dst, t_kdtree_builder *b,
					uint32_t *indexes, uint32_t count)
{
	uint32_t		split[count];
	uint32_t		d;
	uint32_t		tmp_len;
	float			tmp_p;
	t_vec2u			tmp;

	d = 0;
	while (d < b->k)
	{
		tmp_p = kdtree_median(b, indexes, count, d);
		tmp.x = kdtree_split(b, indexes, count, d, tmp_p, split, true);
		tmp.y = kdtree_split(b, indexes, count, d, tmp_p, split, false);
		tmp.x = DIFF(tmp.x, tmp.y) + tmp.x + tmp.y;
		// tmp.x = DIFF(tmp.x, tmp.y) + MAX(tmp.x, tmp.y);
		if (d == 0 || tmp.x < tmp_len)
		{
			dst->d = d;
			dst->p = tmp_p;
			tmp_len = tmp.x;
		}
		d++;
	}
	tmp_len = kdtree_split(b, indexes, count, dst->d, dst->p, split, true);
	kdtree_build_child(&dst->left, b, split, tmp_len, BOOL_OF(tmp_len == count));
	tmp_len = kdtree_split(b, indexes, count, dst->d, dst->p, split, false);
	kdtree_build_child(&dst->right, b, split, tmp_len, BOOL_OF(tmp_len == count));
}

static void		kdtree_build_leaf(t_vector *dst, t_kdtree_builder *b,
					uint32_t *indexes, uint32_t count)
{
	*dst = VECTOR(void const*);
	ft_vreserve(dst, count);
	dst->length = count;
	while (count > 0)
	{
		--count;
		VGET(void const*, *dst, count) =
			VGETC(void const*, b->datas, indexes[count]);
	}
	b->max_height = MAX(b->max_height, b->height);
}

static void		kdtree_build_child(t_kdtree_child **dst, t_kdtree_builder *b,
					uint32_t *indexes, uint32_t count, bool force_leaf)
{
	*dst = NEW(t_kdtree_child);
	if (count <= 3 || b->height >= MAX_HEIGHT || force_leaf) // TODO: improve
	{
		(*dst)->type = KDTREE_LEAF;
		return (kdtree_build_leaf(&(*dst)->v.leaf, b, indexes, count));
	}
	(*dst)->type = KDTREE_SPLIT;
	b->height++;
	kdtree_build_split(&(*dst)->v.split, b, indexes, count);
	b->height--;
}

t_kdtree		kdtree_build(t_kdtree_builder *b)
{
	uint32_t		indexes[b->datas.length];
	uint32_t		i;
	t_kdtree		tree;

	i = 0;
	while (i < b->datas.length)
	{
		indexes[i] = i;
		i++;
	}
	kdtree_build_child(&tree.root, b, indexes, b->datas.length, false);
	tree.k = b->k;
	tree.height = b->max_height;
	tree.length = b->datas.length;
	kdtree_builder_destroy(b);
	return (tree);
}
