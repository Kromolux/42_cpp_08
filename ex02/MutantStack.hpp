/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 07:13:00 by rkaufman          #+#    #+#             */
/*   Updated: 2022/06/01 13:36:55 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack(void) {};
		MutantStack(MutantStack const & obj) { *this = obj; };
		virtual ~MutantStack(void) {};

		MutantStack & operator=(MutantStack const & obj)
		{
			std::stack<T>::operator=(obj);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		
		iterator begin(void) { return(std::stack<T>::c.begin()); }
		iterator end(void) { return(std::stack<T>::c.end()); }

		reverse_iterator rbegin(void) { return(std::stack<T>::c.rbegin()); }
		reverse_iterator rend(void) { return(std::stack<T>::c.rend()); }

	protected:

	private:
	
};

#endif

//https://en.cppreference.com/w/cpp/container/stack
//https://www.cplusplus.com/reference/stack/stack/?kw=stack
/*
Container
Type of the internal underlying container object where the elements are stored.
Its value_type shall be T.
Aliased as member type stack::container_type.
*/