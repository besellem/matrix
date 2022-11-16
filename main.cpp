/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:41:06 by besellem          #+#    #+#             */
/*   Updated: 2022/11/16 16:17:01 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/Matrix.hpp"
#include "incs/Vector.hpp"
#include "incs/Complex.hpp"
#include <iostream>

// int		main(void)
// {
// 	ft::Vector<>		vec = {1., 2., 3.};
// 	ft::Vector<>		vec4({4., 5., 6.});

// 	ft::Vector<>		vec2 = vec;
// 	ft::Vector<>		vec3;

// 	vec3 = vec2;
// 	vec3 = {7., 8., 9.};

// 	std::cout << "vec:" << std::endl;
// 	std::cout << vec << std::endl;

// 	vec.add({7., 8., 9.});

// 	std::cout << "vec:" << std::endl;
// 	std::cout << vec << std::endl;

// 	vec.scl(-3.25);

// 	std::cout << "vec:" << std::endl;
// 	std::cout << vec << std::endl;

// 	return 0;
// }


// int		main(void)
// {
// 	ft::Matrix<>		m1;
// 	ft::Matrix<>		m2 = m1;
// 	ft::Matrix<>		m3({
// 		{1., 2., 3.},
// 		{4., 5., 6.}
// 	});

// 	ft::Matrix<>		m4({
// 		{-13., 0., -3.},
// 		{42., -2., 5.}
// 	});

// 	std::cout << m3 << std::endl;
// 	std::cout << m4 << std::endl;

// 	m4.add(m3);
// 	std::cout << m4 << std::endl;

// 	m4.sub(m3);
// 	std::cout << m4 << std::endl;

// 	m4.scl(2.);
// 	std::cout << m4 << std::endl;

// 	m2 = m4;
// 	std::cout << m2 << std::endl;

// 	m1 = {
// 		{-13134.467, 34.46767, -334.45},
// 		{42434.234, -234., 513.45}
// 	};
// 	std::cout << m1 << std::endl;

// 	return 0;
// }

int		main(void)
{
	ft::Vector<ft::Complex>		vec1 = {
		ft::Complex(1., 1.),
		ft::Complex(2., 2.),
		ft::Complex(3., 3.)
	};

	ft::Vector<ft::Complex>		vec2 = {
		ft::Complex(-1., -1.),
		ft::Complex(-2., -2.),
		ft::Complex(-3., -3.)
	};

	ft::Vector<>				vec3 = {1., 2., 3.};
	ft::Vector<>				vec4 = {-1., -2., -3.};
	
	ft::Complex					c1(-1, -2);
	ft::Complex					c2(3, 4);

	ft::Matrix<ft::Complex>		m1 = {
		{
			ft::Complex(1., 1.),
			ft::Complex(2., 2.),
			ft::Complex(3., 3.)
		},
		{
			ft::Complex(1., 1.),
			ft::Complex(2., 2.),
			ft::Complex(3., 3.)
		},
		{
			ft::Complex(1., 1.),
			ft::Complex(2., 2.),
			ft::Complex(3., 3.)
		},
		{
			ft::Complex(1., 1.),
			ft::Complex(2., 2.),
			ft::Complex(3., 3.)
		},
	};

	ft::Matrix<ft::Complex>		m2 = {
		{
			ft::Complex(1., 1.),
			ft::Complex(2., 2.),
			ft::Complex(3., 3.)
		},
		{
			ft::Complex(1., 1.),
			ft::Complex(2., 2.),
			ft::Complex(3., 3.)
		},
		{
			ft::Complex(1., 1.),
			ft::Complex(2., 2.),
			ft::Complex(3., 3.)
		},
		{
			ft::Complex(1., 1.),
			ft::Complex(2., 2.),
			ft::Complex(3., 3.)
		},
	};

	std::cout << c1 + c2 << std::endl;
	std::cout << vec1 << std::endl;

	std::cout << vec3 - vec4 << std::endl;

	std::cout << m1 << std::endl;

	std::cout << (m1 == m2) << std::endl;

	m1.add(m2);
	std::cout << m1 << std::endl;


	ft::Vector<>	e1 = {1., 0., 0.};
	ft::Vector<>	e2 = {0., 1., 0.};
	ft::Vector<>	e3 = {0., 0., 1.};
	ft::Vector<>	v1 = {1., 2., 3.};
	ft::Vector<>	v2 = {0., 10., -100.};


	std::cout << "linear_combination:\n" << ft::linear_combination<>({e1, e2, e3}, {10., -2., 0.5}) << std::endl;

	return 0;
}
