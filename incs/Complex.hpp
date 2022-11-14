/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Complex.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:08:47 by besellem          #+#    #+#             */
/*   Updated: 2022/11/14 23:30:24 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_HPP
# define COMPLEX_HPP

# include <iostream>
# include "_utils.hpp"

__BEGIN

class Complex
{
	public:
		typedef double											value_type;

	public:
		Complex(void) : _real(0.), _imag(0.)
		{}

		Complex(value_type const & real, value_type const & imag) : _real(real), _imag(imag)
		{}

		Complex(Complex const & src) : Complex()
		{
			*this = src;
		}

		~Complex()
		{}

		Complex &		operator=(Complex const & rhs)
		{
			if (this == &rhs)
				return *this;

			this->_real = rhs._real;
			this->_imag = rhs._imag;
			return *this;
		}

		Complex &		operator+=(Complex const & rhs)
		{
			this->_real += rhs._real;
			this->_imag += rhs._imag;
			return *this;
		}

		Complex &		operator-=(Complex const & rhs)
		{
			this->_real -= rhs._real;
			this->_imag -= rhs._imag;
			return *this;
		}

		Complex &		operator*=(Complex const & rhs)
		{
			const value_type	tmp = this->_real;

			this->_real = (tmp * rhs._real) - (this->_imag * rhs._imag);
			this->_imag = (tmp * rhs._imag) + (this->_imag * rhs._real);
			return *this;
		}

		Complex &		operator/=(Complex const & rhs)
		{
			const value_type	tmp = this->_real;

			this->_real = (tmp * rhs._real + this->_imag * rhs._imag) / (rhs._real * rhs._real + rhs._imag * rhs._imag);
			this->_imag = (this->_imag * rhs._real - tmp * rhs._imag) / (rhs._real * rhs._real + rhs._imag * rhs._imag);
			return *this;
		}

		Complex &		operator+=(value_type const & rhs)
		{
			this->_real += rhs;
			return *this;
		}

		Complex &		operator-=(value_type const & rhs)
		{
			this->_real -= rhs;
			return *this;
		}

		Complex &		operator*=(value_type const & rhs)
		{
			this->_real *= rhs;
			this->_imag *= rhs;
			return *this;
		}
		
		Complex &		operator/=(value_type const & rhs)
		{
			this->_real /= rhs;
			this->_imag /= rhs;
			return *this;
		}

		value_type		real(void) const
		{
			return this->_real;
		}

		value_type		imag(void) const
		{
			return this->_imag;
		}

	private:
		double													_real;
		double													_imag;
};

Complex			operator+(Complex const & lhs, Complex const & rhs)
{
	Complex		tmp(lhs);
	tmp += rhs;
	return tmp;
}

Complex			operator-(Complex const & lhs, Complex const & rhs)
{
	Complex		tmp(lhs);
	tmp -= rhs;
	return tmp;
}

Complex			operator*(Complex const & lhs, Complex const & rhs)
{
	Complex		tmp(lhs);
	tmp *= rhs;
	return tmp;
}

Complex			operator/(Complex const & lhs, Complex const & rhs)
{
	Complex		tmp(lhs);
	tmp /= rhs;
	return tmp;
}

Complex			operator+(Complex const & lhs, Complex::value_type const & rhs)
{
	Complex		tmp(lhs);
	tmp += rhs;
	return tmp;
}

Complex			operator-(Complex const & lhs, Complex::value_type const & rhs)
{
	Complex		tmp(lhs);
	tmp -= rhs;
	return tmp;
}

Complex			operator*(Complex const & lhs, Complex::value_type const & rhs)
{
	Complex		tmp(lhs);
	tmp *= rhs;
	return tmp;
}

Complex			operator/(Complex const & lhs, Complex::value_type const & rhs)
{
	Complex		tmp(lhs);
	tmp /= rhs;
	return tmp;
}

Complex			operator+(Complex::value_type const & lhs, Complex const & rhs)
{
	Complex		tmp(rhs);
	tmp += lhs;
	return tmp;
}

Complex			operator-(Complex::value_type const & lhs, Complex const & rhs)
{
	Complex		tmp(rhs);
	tmp -= lhs;
	return tmp;
}

Complex			operator*(Complex::value_type const & lhs, Complex const & rhs)
{
	Complex		tmp(rhs);
	tmp *= lhs;
	return tmp;
}

Complex			operator/(Complex::value_type const & lhs, Complex const & rhs)
{
	Complex		tmp(rhs);
	tmp /= lhs;
	return tmp;
}

bool			operator==(Complex const & lhs, Complex const & rhs)
{
	return (lhs.real() == rhs.real() && lhs.imag() == rhs.imag());
}

bool			operator!=(Complex const & lhs, Complex const & rhs)
{
	return !(lhs == rhs);
}

std::ostream &	operator<<(std::ostream & o, Complex const & rhs)
{
	if (rhs.imag() < 0)
		o << rhs.real() << " - " << -rhs.imag() << "i";
	else
		o << rhs.real() << " + " << rhs.imag() << "i";
	return o;
}

__END

#endif
