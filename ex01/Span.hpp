/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:21:56 by rkaufman          #+#    #+#             */
/*   Updated: 2022/06/01 13:26:51 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <algorithm>
# include <iostream>
# include <stdexcept>
# include <numeric>
# include <climits>
# include <new>
# include "colors.h"

class Span
{
	public:

		Span(unsigned int N);
		Span(Span const & obj);
		Span & operator=(Span const & obj);
		~Span(void);

		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			printElements(void) const;
		void			randomFill(void);

	protected:

	private:

		Span(void);
		static int	randomNumber(void);
		static void	positiv(int & number);
		static void	printElement(int const & number);
		std::vector<int>	* _vector;
		unsigned int		_index;
		unsigned int		_size;

};

#endif