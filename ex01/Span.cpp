/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkaufman <rkaufman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:22:28 by rkaufman          #+#    #+#             */
/*   Updated: 2022/05/31 20:42:53 by rkaufman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Span] default constructor called." << std::endl << COLOR_DEFAULT;
}

Span::Span(unsigned int N) : _size(N)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Span] argument constructor called." << std::endl << COLOR_DEFAULT;
	_vector = new std::vector<int>(N);
	_index = 0;
}

Span::Span(Span const & obj)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Span] copy constructor called." << std::endl << COLOR_DEFAULT;
	this->_size = 0;
	*this = obj;
}
		
Span::~Span(void)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Span] deconstructor called." << std::endl << COLOR_DEFAULT;
	delete this->_vector;
}

Span & Span::operator=(Span const & obj)
{
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "[Span] assignement operator called." << std::endl << COLOR_DEFAULT;
	if (this == &obj)
		return (*this);
	if (this->_size > 0)
		delete this->_vector;
	this->_size = obj._size;
	this->_index = obj._index;
	this->_vector = new std::vector<int>(this->_size);
	for (unsigned int i = 0; i < this->_size; i++)
		this->_vector[i] = obj._vector[i];
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_index == this->_size)
		throw std::out_of_range("Span::Maximum size reached!");
	this->_vector->at(this->_index) =  number;
	this->_index++;
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_size < 2)
		throw std::logic_error("Span::Not enough elements to create shortest span!");
	std::vector<int> vector_copy = *this->_vector;

	std::adjacent_difference(vector_copy.begin(), vector_copy.end(), vector_copy.begin());
	for_each(vector_copy.begin(), vector_copy.end(), Span::positiv);
	return (static_cast<unsigned int>(*std::min_element(vector_copy.begin(), vector_copy.end())));
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_size < 2)
		throw std::logic_error("Span::Not enough elements to create longest span!");
	int	min = *std::min_element(this->_vector->begin(), this->_vector->end());
	int	max = *std::max_element(this->_vector->begin(), this->_vector->end());
	if (DEBUG)
		std::cout << COLOR_MAGENTA << "min: " << min << " max: " << max << std::endl << COLOR_DEFAULT;
	return (static_cast<unsigned int>(max - min));
}

void	Span::positiv(int & number)
{
	if (number < 0)
		number = number * (-1);
}

void	Span::printElements(void) const
{
	for_each(this->_vector->begin(), this->_vector->end(), printElement);
	std::cout << std::endl;
}

void	Span::printElement(int const & number)
{
	std::cout << number << " ";
}

void	Span::randomFill(void)
{
	std::srand(time(NULL));
	std::generate(this->_vector->begin(), this->_vector->end(), Span::randomNumber);
	this->_index = this->_size;
}

int	Span::randomNumber(void)
{
	int	newNumber = 0;

	newNumber = (std::rand() % INT_MAX);
	if (std::rand() % 2 == 1)
		newNumber = newNumber << 1;
	return (newNumber);
}
