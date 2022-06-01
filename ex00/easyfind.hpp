/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:39:20 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/31 12:38:34 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <algorithm>
# include <stdexcept>
# include <iostream>
# include "colors.h"

template <typename T>
typename T::iterator	easyFind(T & container, int target)
{
	typename T::iterator it = std::find(container.begin(), container.end(), target);

	if (it == container.end())
		throw std::invalid_argument("easyFind::Container does not contain the target element!");
	return (it);
}

#endif