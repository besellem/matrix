/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:44:18 by besellem          #+#    #+#             */
/*   Updated: 2022/11/14 00:41:41 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <initializer_list>
# include "_utils.hpp"

__BEGIN

template <class T = double>
class Vector
{
	public:
		typedef T													value_type;
		typedef T&													reference;
		typedef T*													pointer;
		typedef size_t												size_type;
		typedef std::initializer_list<value_type>					list_type;

	public:
		Vector(void) : _vector(nullptr), _size(0)
		{}

		Vector(list_type const & list) : Vector()
		{
			this->assign(list);
		}

		Vector(Vector const & src) : Vector()
		{
			*this = src;
		}

		~Vector(void)
		{
			this->clear();
		}

		Vector &		operator=(Vector const & rhs)
		{
			if (this == &rhs)
				return *this;

			this->clear();
			this->assign(rhs._vector, rhs._size);
			return *this;
		}

		Vector &		operator=(list_type const & list)
		{
			this->clear();
			this->assign(list);
			return *this;
		}

		reference		operator[](size_type const & i) const
		{
			if (i >= this->size())
				throw std::out_of_range("Vector::operator[]: index out of range");
			return this->_vector[i];
		}

		size_type		size(void) const
		{
			return this->_size;
		}

		void			clear(void)
		{
			if (this->_vector != nullptr)
				delete [] this->_vector;
			this->_vector = nullptr;
			this->_size = 0;
		}

		void			assign(list_type const & list)
		{
			this->_size = list.size();
			this->_vector = new value_type[this->_size];

			// copy
			size_type	i = 0;
			for (auto it = list.begin(); it != list.end(); ++it, ++i)
				this->_vector[i] = *it;
		}

		void			assign(pointer const & ptr, size_type const & size)
		{
			this->_size = size;
			this->_vector = new value_type[this->_size];

			// copy
			for (size_type i = 0; i < this->_size; ++i)
				this->_vector[i] = ptr[i];
		}

		public:
			void	add(Vector const & rhs)
			{
				if (this->size() != rhs.size())
					throw std::length_error("Vector::add: vectors must have the same size");

				for (size_type i = 0; i < this->size(); ++i)
					this->_vector[i] += rhs[i];
			}

			void	sub(Vector const & rhs)
			{
				if (this->size() != rhs.size())
					throw std::length_error("Vector::sub: vectors must have the same size");

				for (size_type i = 0; i < this->size(); ++i)
					this->_vector[i] -= rhs[i];
			}

			template <class K>
			void	scl(K const & k)
			{
				for (size_type i = 0; i < this->size(); ++i)
					this->_vector[i] *= k;
			}

		private:
			pointer													_vector;
			size_type												_size;
};

template <class T>
std::ostream &	operator<<(std::ostream & o, Vector<T> const & rhs)
{
	for (size_t i = 0; i < rhs.size(); ++i)
	{
		o << "[" << rhs[i] << "]" << std::endl;
	}
	return o;
}

__END

#endif