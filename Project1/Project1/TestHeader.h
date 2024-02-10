#ifndef COLORHEADER_H_
#include <iostream>
#include<vector>
#include<unordered_map>

#define COLORHEADER_H_

namespace coloring {
	void test( )
	{
		std::cout << "\033[31;107;1;3mHello\033[0m" << std::endl;

	}
	int inputHandler (std::string inputColor)
	{
		int number {};

		//supported colors: Black, Red, Green, Yellow, Blue, Magenta, Cyan, GrayWhite, GrayBlack.
		//supported colorc: 1    , 2  , 3    , 4     , 5   , 6      , 7   , 8        , 9
		std::vector<std::string> colorList = { "Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "GrayWhite", "GrayBlack" };

		std::unordered_map<std::string, int> supColors;
		int counter = 1;
		for (const auto& color : colorList)
		{
			supColors.emplace(color, counter);
			counter++;
		}

		auto aux = supColors.find(inputColor);
		if (aux != supColors.end()) {
			number = aux->second;
		}
		else {
			std::cerr << "Color not found: " << inputColor << std::endl;

			std::cout << "Enter valid color: ";
			std::cin >> inputColor;
		}
		std::cout << number<<std :: endl;
		return number;
	}
	void colorText(std::string text)
	{
		int cases;
		std::string inputColor;

		std::cout << "Specify color: ";
		std::cin >> inputColor;

		cases = inputHandler(inputColor);

		switch (cases)
		{
			case 1:
				std::cout << "\033[30;40m"<< text <<"\033[0m" << std::endl;
				break;

			case 2:
				std::cout << "\033[31;40m" << text << "\033[0m" << std::endl;
				break;

			case 3:
				std::cout << "\033[32;40m" << text << "\033[0m" << std::endl;
				break;

			case 4:
				std::cout << "\033[33;40m" << text << "\033[0m" << std::endl;
				break;
			case 5:
				std::cout << "\033[34;40m" << text << "\033[0m" << std::endl;
				break;
			case 6:
				std::cout << "\033[35;40m" << text << "\033[0m" << std::endl;
				break;
			case 7:
				std::cout << "\033[36;40m" << text << "\033[0m" << std::endl;
				break;
			case 8:
				std::cout << "\033[37;40m" << text << "\033[0m" << std::endl;
				break;
			case 9:
				std::cout << "\033[90;40m" << text << "\033[0m" << std::endl;
				break;
			
		}
					 
	}
}
#endif