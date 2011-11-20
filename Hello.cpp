#include "SuperVector2f.hpp"
#include <iostream>

int main()
{
	SuperVector2f vec (10.0f, 50.0f);

	std::cout << vec << std::endl;

	vec.Normalize();

	std::cout << vec << std::endl;


	return 0;
}

