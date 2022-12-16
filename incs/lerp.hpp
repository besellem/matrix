/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:58:20 by besellem          #+#    #+#             */
/*   Updated: 2022/12/16 15:35:57 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LERP_HPP
# define LERP_HPP

# include "_utils.hpp"
# include "Vector.hpp"
# include "Matrix.hpp"

__BEGIN


template <class K = double>
K		lerp(K const & u, K const & v, double const & t)
{
	if (t < 0. || t > 1.)
		throw std::out_of_range("lerp: t must be between 0 and 1");

	return (1. - t) * u + (t * v);
}

template <class K = double>
Vector<K>	lerp(Vector<K> const & u, Vector<K> const & v, double const & t)
{
	Vector<K>	u_cpy(u);
	Vector<K>	v_cpy(v);

	if (t < 0. || t > 1.)
		throw std::out_of_range("lerp: t must be between 0 and 1");

	u_cpy.scl(1. - t);
	v_cpy.scl(t);
	u_cpy.add(v_cpy);
	return u_cpy;
}

template <class K = double>
Matrix<K>	lerp(Matrix<K> const & u, Matrix<K> const & v, double const & t)
{
	Matrix<K>	u_cpy(u);
	Matrix<K>	v_cpy(v);

	if (t < 0. || t > 1.)
		throw std::out_of_range("lerp: t must be between 0 and 1");

	u_cpy.scl(1. - t);
	v_cpy.scl(t);
	u_cpy.add(v_cpy);
	return u_cpy;
}

__END

#endif /* define(LERP_HPP) */
