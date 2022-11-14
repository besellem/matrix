/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:44:39 by besellem          #+#    #+#             */
/*   Updated: 2022/11/14 16:07:36 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <iostream>
# include <vector>
# include <initializer_list>
# include "Vector.hpp"
# include "_utils.hpp"

__BEGIN

template <class T = double>
class Matrix
{
	public:
		typedef T													value_type;
		typedef T&													reference;
		typedef T*													pointer;
		typedef Vector<value_type>									vector_type;
		typedef typename vector_type::size_type						size_type;
		typedef std::vector<vector_type>							matrix_type;
		typedef std::initializer_list<vector_type>					list_type;
		typedef typename std::vector<vector_type>::iterator			iterator;
		typedef typename std::vector<vector_type>::const_iterator	const_iterator;

	public:
		Matrix(void) : _matrix(matrix_type())
		{}

		Matrix(list_type const & list) : Matrix()
		{
			this->assign(list);
		}

		Matrix(Matrix const & src) : Matrix()
		{
			*this = src;
		}

		~Matrix(void)
		{}

		Matrix &	operator=(Matrix const & rhs)
		{
			if (this == &rhs)
				return *this;

			this->_matrix = rhs._matrix;
			return *this;
		}

		void			assign(list_type const & list)
		{
			for (auto const & v : list)
				this->_matrix.push_back(v);
		}

		size_type		size(void) const  { return this->_matrix.size(); }

		iterator		begin(void)       { return this->_matrix.begin(); }
		const_iterator	begin(void) const { return this->_matrix.begin(); }
		iterator		end(void)         { return this->_matrix.end(); }
		const_iterator	end(void) const   { return this->_matrix.end(); }

	public:
		void	add(Matrix const & rhs)
		{
			if (this->size() != rhs.size())
				throw std::length_error("Matrix::add(): matrix sizes do not match");
			
			for (size_type i = 0; i < this->size(); ++i)
				this->_matrix[i].add(rhs._matrix[i]);
		}

		void	sub(Matrix const & rhs)
		{
			if (this->size() != rhs.size())
				throw std::length_error("Matrix::sub(): matrix sizes do not match");
			
			for (size_type i = 0; i < this->size(); ++i)
				this->_matrix[i].sub(rhs._matrix[i]);
		}

		template <class K>
		void	scl(K const & k)
		{
			for (size_type i = 0; i < this->size(); ++i)
				this->_matrix[i].scl(k);
		}

	private:
		matrix_type													_matrix;
};

template <class T>
std::ostream &	operator<<(std::ostream & o, Matrix<T> const & rhs)
{
	for (auto it = rhs.begin(); it != rhs.end(); ++it)
	{
		o << "[";
		for (typename Matrix<T>::size_type i = 0; i < it->size(); ++i)
		{
			o << (*it)[i];

			if (i + 1 < it->size())
				o << ", ";
		}
		o << "]";

		if (it + 1 != rhs.end())
			o << ",";
		o << std::endl;
	}
	return o;
}

__END

#endif
