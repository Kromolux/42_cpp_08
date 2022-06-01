/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 07:10:51 by rkaufman          #+#    #+#             */
/*   Updated: 2022/06/01 11:03:04 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"
#include "colors.h"

static void	print_text(std::string output);

int main()
{
	{
		print_text("TEST 1 - MutantStack.");
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		
		std::cout << "first element "<< mstack.top() << std::endl;

		mstack.pop();
		
		std::cout << "size of Stack " << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...] mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		
		print_text("Printing elements in order.");
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		MutantStack<int>::reverse_iterator it_r = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite_r = mstack.rend();

		++it_r;
		--it_r;

		print_text("Printing elements in reverse order.");
		while (it_r != ite_r)
		{
			std::cout << *it_r << std::endl;
			++it_r;
		}
		std::stack<int> s(mstack);
	}
	{
		print_text("TEST 2 - List.");
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_front(17);
		
		std::cout << "first element "<< mstack.front() << std::endl;

		mstack.pop_front();
		
		std::cout << "size of Stack " << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...] mstack.push(0);
		
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;

		print_text("Printing elements in order.");
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		
		std::list<int>::reverse_iterator it_r = mstack.rbegin();
		std::list<int>::reverse_iterator ite_r = mstack.rend();

		++it_r;
		--it_r;

		print_text("Printing elements in reverse order.");
		while (it_r != ite_r)
		{
			std::cout << *it_r << std::endl;
			++it_r;
		}
	}
	{
		print_text("TEST 3 - Vector.");
		std::vector<int> mstack;

		mstack.push_back(5);
		mstack.front() = 17;
		
		std::cout << "first element "<< mstack.front() << std::endl;

		mstack.front() = 5;
		
		std::cout << "size of Stack " << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...] mstack.push(0);
		
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();

		++it;
		--it;

		print_text("Printing elements in order.");
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::vector<int>::reverse_iterator it_r = mstack.rbegin();
		std::vector<int>::reverse_iterator ite_r = mstack.rend();

		++it_r;
		--it_r;

		print_text("Printing elements in reverse order.");
		while (it_r != ite_r)
		{
			std::cout << *it_r << std::endl;
			++it_r;
		}
	}
	return (0);
}

static void	print_text(std::string output)
{
	std::cout << COLOR_YELLOW << "\n" << output << "\n\n" << COLOR_DEFAULT;
}
