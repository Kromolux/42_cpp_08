/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:20:42 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/31 20:38:07 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include "Span.hpp"

static void	print_text(std::string output);
static void	try_catch(Span const & obj, unsigned int (Span::*f)(void) const);
static void	try_catch_number(Span & obj, int number);

int	main(void)
{
	{
		print_text("TEST 1 - Creating Span object[1] with one element.");
		
		Span sp = Span(1);
		
		sp.addNumber(INT_MAX);
		
		print_text("Printing Span object.");
		sp.printElements();

		print_text("Try to get Span.");
		try_catch(sp, &Span::shortestSpan);
		try_catch(sp, &Span::longestSpan);

		print_text("Try to add new element.");
		try_catch_number(sp, INT_MIN);
	}
	{
		print_text("TEST 2 - Creating Span object[3] with one element.");
		
		Span sp = Span(3);
		
		sp.addNumber(INT_MAX);
		
		print_text("Printing Span object.");
		sp.printElements();

		print_text("Try to get Span.");
		try_catch(sp, &Span::shortestSpan);
		try_catch(sp, &Span::longestSpan);

		print_text("Try to add new element.");
		try_catch_number(sp, 0);

		print_text("Try to add new element.");
		try_catch_number(sp, INT_MIN);
	
		print_text("Try to get Span.");
		try_catch(sp, &Span::shortestSpan);
		try_catch(sp, &Span::longestSpan);
	}
	{
		print_text("TEST 3 - Creating Span object[4] with three elements.");
		
		Span sp = Span(4);
		
		try_catch_number(sp, 42);
		try_catch_number(sp, 0);
		try_catch_number(sp, 4);
		try_catch_number(sp, 2);

		print_text("Printing Span object.");
		sp.printElements();

		print_text("Try to get Span.");
		try_catch(sp, &Span::shortestSpan);
		try_catch(sp, &Span::longestSpan);	
	}
	{
		print_text("TEST 4 - Creating Span object[4] with four elements.");
		
		Span sp = Span(4);
		
		sp.addNumber(-42);
		sp.addNumber(0);
		sp.addNumber(-4);
		sp.addNumber(-2);
		
		print_text("Printing Span object.");
		sp.printElements();

		print_text("Try to get Span.");
		try_catch(sp, &Span::shortestSpan);
		try_catch(sp, &Span::longestSpan);	
	}
	{
		print_text("TEST 5 - Creating Span object[3] with three elements.");
		
		Span sp = Span(3);
		
		sp.addNumber(42);
		sp.addNumber(0);
		sp.addNumber(-4);
		
		print_text("Printing Span object.");
		sp.printElements();

		print_text("Try to get Span.");
		try_catch(sp, &Span::shortestSpan);
		try_catch(sp, &Span::longestSpan);
	}
	{
		print_text("TEST 6 - Creating Span object[100].");
		
		Span sp = Span(100);
		sp.randomFill();
		
		print_text("Printing Span object.");
		sp.printElements();

		print_text("Try to get Span.");
		try_catch(sp, &Span::shortestSpan);
		try_catch(sp, &Span::longestSpan);
	}
}

static void	print_text(std::string output)
{
	std::cout << COLOR_YELLOW << "\n" << output << "\n\n" << COLOR_DEFAULT;
}

static void	try_catch(Span const & obj, unsigned int (Span::*f)(void) const)
{
	try
	{
		std::cout << "Span: " << (obj.*f)() << "\n";
	}
	catch (std::exception & error)
	{
		std::cerr << COLOR_RED << error.what() << COLOR_DEFAULT << std::endl;
	}
}

static void	try_catch_number(Span & obj, int number)
{
	try
	{
		obj.addNumber(number);
		std::cout << "Number: " << number << " added to container\n";
	}
	catch (std::exception & error)
	{
		std::cerr << COLOR_RED << error.what() << COLOR_DEFAULT << std::endl;
	}
}