/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:15:06 by yogun             #+#    #+#             */
/*   Updated: 2023/03/22 20:23:00 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base*	generate(void)
{
	int	i;

	i = rand() % 3;
	std::cout << "Generated case number " << i << std::endl;
	switch (i)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

/*
	Dynamic cast is executed at runtime, not compile time. Because this is a run-time cast, it is useful especially when combined with polymorphic classes. 
	In fact, in certain cases the classes must be polymorphic in order for the cast to be legal.
	Given a base class pointer or reference, dynamic_cast can be used to cast it to a derived class pointer or reference,
	which can be a more specific type than the original base class type. 
	When the cast fails, dynamic_cast returns a null pointer of the target type.

	This function takes a pointer to a Base class, and tries to cast it to A, B and C. If the cast is successful, it prints the class name.
	Unless the cast doesn't fail, it does nothing.
*/ 
void	identify(Base* p)
{
	A*	a = dynamic_cast<A *>(p);
	if (a != NULL)
		std::cout << "It's an 'A' class" << std::endl;

	B*	b = dynamic_cast<B *>(p);
	if (b != NULL)
		std::cout << "It's a 'B' class" << std::endl;

	C*	c = dynamic_cast<C *>(p);
	if (c != NULL)
		std::cout << "It's a 'C' class" << std::endl;
}

// This function takes a reference to a Base class, and tries to cast it to A, B and C. If the cast is successful, it prints the class name.
// If the cast fails, it catches the exception and does nothing.
void	identify(Base& p)
{
	try
	{
		A	a = dynamic_cast<A &>(p);
		std::cout << "It's an 'A' class!" << '\n';
	}
	catch(const std::exception& e) {}

	try
	{
		B	b = dynamic_cast<B &>(p);
		std::cout << "It's a 'B' class!" << '\n';
	}
	catch(const std::exception& e) {}

	try
	{
		C	c = dynamic_cast<C &>(p);
		std::cout << "It's a 'C' class!" << '\n';
	}
	catch(const std::exception& e) {}
}

int main()
{
	Base	*base;

	srand(time(NULL)); // thanks to this, the random number will be different each time
	
	std::cout << "* Generating value *" << std::endl;
	base = generate();	// generate a random pointer to Base class

	std::cout << std::endl << "* Pointer test *" << std::endl;
	identify(base);	//we send to indentify function the pointer to Base class

	std::cout << std::endl << "* Reference test *" << std::endl;
	identify(*base);	// we send to indentify function the reference to Base class

	delete base;
	return (0);
}