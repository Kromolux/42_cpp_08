/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 06:38:37 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/31 15:14:00 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void	print_text(std::string output);
static int	random_number(void);
static void	print(int & number);
static int	getListIndex(std::list<int> & list, std::list<int>::iterator & search);
static int	getDequeIndex(std::deque<int> & deque, std::deque<int>::iterator & search);

int	main(void)
{
	std::vector<int>	int_vector(100);
	std::list<int>		int_list(100);
	std::deque<int>		int_deque(100);
	srand(time(NULL));
	
	print_text("Populate int vector and list with random numbers.");
	
	std::generate(int_vector.begin(), int_vector.end(), random_number);
	std::generate(int_list.begin(), int_list.end(), random_number);
	std::generate(int_deque.begin(), int_deque.end(), random_number);
	
	print_text("Print int vector to terminal.");
	int_vector.push_back(42);
	for_each(int_vector.begin(), int_vector.end(), print);

	print_text("Try to find number 100 in int vector.");
	try
	{
		std::vector<int>::iterator it = easyFind(int_vector, 100);
		std::cout << "Found element at address: " << it.base() << " index: " << static_cast<int>(it.base() - int_vector.begin().base()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}
	
	print_text("Try to find number 42 in int vector.");
	try
	{
		std::vector<int>::iterator it = easyFind(int_vector, 42);
		std::cout << "Found element at address: " << it.base() << " index: " << static_cast<int>(it.base() - int_vector.begin().base()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}

	print_text("Print int list to terminal.");
	int_list.push_back(42);
	for_each(int_list.begin(), int_list.end(), print);
	
	print_text("Try to find number 100 in int list.");
	try
	{
		std::list<int>::iterator it = easyFind(int_list, 100);
		std::cout << "Found element at address: " << *it << " index: " << it.operator->() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}
	
	print_text("Try to find number 42 in int list.");
	try
	{
		std::list<int>::iterator it = easyFind(int_list, 42);
		std::cout << "Found element at address: " << it.operator->() << " index: " << getListIndex(int_list, it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}

	print_text("Print int deque to terminal.");
	int_deque.push_back(42);
	for_each(int_deque.begin(), int_deque.end(), print);

	print_text("Try to find number 100 in int deque.");
	try
	{
		std::deque<int>::iterator it = easyFind(int_deque, 100);
		std::cout << "Found element at address: " << it.operator->() << " index: " << getDequeIndex(int_deque, it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}
	
	print_text("Try to find number 42 in int vector.");
	try
	{
		std::deque<int>::iterator it = easyFind(int_deque, 42);
		std::cout << "Found element at address: " << it.operator->() << " index: " << getDequeIndex(int_deque, it) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << COLOR_RED << e.what() << '\n' << COLOR_DEFAULT;
	}
	return (0);
}

static void	print_text(std::string output)
{
	std::cout << COLOR_YELLOW << "\n" << output << "\n\n" << COLOR_DEFAULT;
}

static int	random_number(void)
{
	return (rand() % 100);
}

static void	print(int & number)
{
	std::cout << number << " ";
}

static int	getListIndex(std::list<int> & list, std::list<int>::iterator & search)
{
	std::list<int>::iterator it;
	int i = 0;
	for (it = list.begin(); it != list.end(); it++, i++)
	{
		if (it == search)
			return (i);
	}
	return (-1);
}

static int	getDequeIndex(std::deque<int> & deque, std::deque<int>::iterator & search)
{
	std::deque<int>::iterator it;
	int i = 0;
	for (it = deque.begin(); it != deque.end(); it++, i++)
	{
		if (it == search)
			return (i);
	}
	return (-1);
}
