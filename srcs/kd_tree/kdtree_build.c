/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kdtree_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:30:02 by jaguillo          #+#    #+#             */
/*   Updated: 2016/03/18 18:02:59 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"
#include "kd_tree.h"
#include "kd_tree_def.h"

static void		kdtree_build_child(t_kdtree_child **dst, t_kdtree_build *b,
					uint32_t *indexes, uint32_t count, bool force_leaf);

// TODO: sum only obj center
static float	kdtree_av(t_vector const *v, uint32_t k, uint32_t d)
{
	uint32_t		i;
	float			sum;

	i = d;
	sum = 0.f;
	while (i < v->length)
	{
		sum += VGET(float, *v, i);
		i += k;
	}
	return (sum / (float)v->length);
}

static uint32_t	kdtree_split(t_kdtree_def const *def,
					uint32_t const *indexes, uint32_t count, float p,
					uint32_t *dst, bool left)
{
	uint32_t		len;
	uint32_t		i;
	t_vec2u			pts;

	len = 0;
	i = 0;
	pts = VEC2U(0, 0);
	while (i < count)
	{
		pts.y += VGET(t_kdtree_def_data, def->datas, indexes[i]).pt_count;
		while (pts.x < pts.y)
		{
			if (BOOL_OF(VGET(float, def->pts, pts.x) < p) == left)
			{
				dst[len++] = indexes[i];
				pts.x = pts.y;
				break ;
			}
			pts.x++;
		}
		i++;
	}
	return (len);
}

static void		kdtree_build_split(t_kdtree_node *dst, t_kdtree_build *b,
					uint32_t *indexes, uint32_t count)
{
	uint32_t		tmp[count];
	uint32_t		tmp_len;

	dst->d = b->height % b->tree.k;
	dst->p = kdtree_av(&b->def->pts, b->tree.k, dst->d);
	tmp_len = kdtree_split(b->def, indexes, count, dst->p, tmp, true);
	kdtree_build_child(&dst->left, b, tmp, tmp_len,
		BOOL_OF(tmp_len == count));
	tmp_len = kdtree_split(b->def, indexes, count, dst->p, tmp, false);
	kdtree_build_child(&dst->right, b, tmp, tmp_len,
		BOOL_OF(tmp_len == count));
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
	b->tree.length = MAX(b->tree.length, b->height);
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
