/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:44:18 by besellem          #+#    #+#             */
/*   Updated: 2022/11/17 19:09:21 by besellem         ###   ########.fr       */
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

		Vector(size_type const & size, value_type const & val = value_type())
		{
			this->_size = size;
			this->_vector = new value_type[size];

			// copy
			for (size_type i = 0; i < size; ++i)
				this->_vector[i] = val;
		}

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

		Vector			operator+(Vector const & rhs) const
		{
			if (this->size() != rhs.size())
				throw std::length_error("Vector::operator+: vectors must have the same size");

			Vector	ret(*this);
			for (size_type i = 0; i < this->size(); ++i)
				ret[i] += rhs[i];
			return ret;
		}

		Vector &		operator+=(Vector const & rhs)
		{
			if (this->size() != rhs.size())
				throw std::length_error("Vector::operator+=: vectors must have the same size");
			for (size_type i = 0; i < this->size(); ++i)
				this->_vector[i] += rhs[i];
			return *this;
		}

		Vector			operator-(Vector const & rhs) const
		{
			if (this->size() != rhs.size())
				throw std::length_error("Vector::operator-: vectors must have the same size");

			Vector	ret(*this);
			for (size_type i = 0; i < this->size(); ++i)
				ret[i] -= rhs[i];
			return ret;
		}

		Vector &		operator-=(Vector const & rhs)
		{
			if (this->size() != rhs.size())
				throw std::length_error("Vector::operator-=: vectors must have the same size");
			for (size_type i = 0; i < this->size(); ++i)
				this->_vector[i] -= rhs[i];
			return *this;
		}

		Vector			operator*(Vector const & rhs) const
		{
			if (this->size() != rhs.size())
				throw std::length_error("Vector::operator*: vectors must have the same size");

			Vector	ret(*this);
			for (size_type i = 0; i < this->size(); ++i)
				ret[i] *= rhs[i];
			return ret;
		}

		Vector &		operator*=(Vector const & rhs)
		{
			if (this->size() != rhs.size())
				throw std::length_error("Vector::operator*=: vectors must have the same size");
			for (size_type i = 0; i < this->size(); ++i)
				this->_vector[i] *= rhs[i];
			return *this;
		}

		Vector			operator/(Vector const & rhs) const
		{
			if (this->size() != rhs.size())
				throw std::length_error("Vector::operator/: vectors must have the same size");

			Vector	ret(*this);
			for (size_type i = 0; i < this->size(); ++i)
				ret[i] /= rhs[i];
			return ret;
		}
		
		Vector &		operator/=(Vector const & rhs)
		{
			if (this->size() != rhs.size())
				throw std::length_error("Vector::operator/=: vectors must have the same size");
			for (size_type i = 0; i < this->size(); ++i)
				this->_vector[i] /= rhs[i];
			return *this;
		}

		reference		operator[](size_type const & i) const
		{
			if (i >= this->size())
				throw std::out_of_range("Vector::operator[]: index out of range");
			return this->_vector[i];
		}

		reference		at(size_type const & i) const
		{
			if (i >= this->size())
				throw std::out_of_range("Vector::at: index out of range");
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
			void		add(Vector const & rhs)
			{
				if (this->size() != rhs.size())
					throw std::length_error("Vector::add: vectors must have the same size");

				for (size_type i = 0; i < this->size(); ++i)
					this->_vector[i] += rhs[i];
			}

			void		sub(Vector const & rhs)
			{
				if (this->size() != rhs.size())
					throw std::length_error("Vector::sub: vectors must have the same size");

				for (size_type i = 0; i < this->size(); ++i)
					this->_vector[i] -= rhs[i];
			}

			template <class K>
			void		scl(K const & k)
			{
				for (size_type i = 0; i < this->size(); ++i)
					this->_vector[i] *= k;
			}

		private:
			pointer													_vector;
			size_type												_size;
};

template <class T1, class T2>
bool			operator==(Vector<T1> const & lhs, Vector<T2> const & rhs)
{
	if (lhs.size() != rhs.size())
		return false;

	for (typename Vector<T1>::size_type i = 0; i < lhs.size(); ++i)
	{
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

template <class T1, class T2>
bool			operator!=(Vector<T1> const & lhs, Vector<T2> const & rhs)
{
	return !(lhs == rhs);
}

template <class T>
std::ostream &	operator<<(std::ostream & o, Vector<T> const & rhs)
{
	for (size_t i = 0; i < rhs.size(); ++i)
	{
		o << "[" << rhs[i] << "]" << std::endl;
	}
	return o;
}

template <class T = double>
Vector<T>	linear_combination(std::initializer_list<Vector<T>> const & vecs, std::initializer_list<T> const & coefs)
{
	if (vecs.size() == 0)
		return Vector<T>();

	// check if the number of vectors and coefficients are the same
	if (vecs.size() != coefs.size())
		throw std::length_error("linear_combination: initializer lists must have the same size");

	const typename Vector<T>::size_type	single_vector_size = vecs.begin()->size();

	// check if all vectors have the same size
	for (auto it = vecs.begin(); it != vecs.end(); ++it)
	{
		if (it->size() != single_vector_size)
			throw std::length_error("linear_combination: all vectors must have the same size");
	}

	Vector<T>	ret(single_vector_size, T());
	Vector<T>	tmp;
	auto		it_vec = vecs.begin();
	auto		it_coef = coefs.begin();

	for (; it_vec != vecs.end() && it_coef != coefs.end(); ++it_vec, ++it_coef)
	{
		// create a copy of the current vector
		tmp = *it_vec;
	
		// scale it by the current coefficient
		tmp.scl(*it_coef);

		// add it to the return vector
		ret.add(tmp);
	}

	return ret;
}

__END

#endif
