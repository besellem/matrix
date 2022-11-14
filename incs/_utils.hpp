/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _utils.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besellem <besellem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:16:07 by besellem          #+#    #+#             */
/*   Updated: 2022/11/13 22:10:50 by besellem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _UTILS_HPP
# define _UTILS_HPP

# define __BEGIN  namespace ft {
# define __END    }

# define LOG      std::cout << "\e[1;33m" << __FILE__ << ":" << __LINE__ << ": " << __func__ << "()\e[0m" << std::endl;

#endif
