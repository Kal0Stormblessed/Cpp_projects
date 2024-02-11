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
	int frinputHandler (std::string frinputColor)
	{
		int number {};
		
		//supported colors: Black, Red, Green, Yellow, Blue, Magenta, Cyan, GrayWhite, GrayBlack.
		std::vector<std::string> colorList = { "Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "GrayWhite" };

		std::unordered_map<std::string, int> supColors;
		int counter = 30;
		for (const auto& color : colorList)
		{
			supColors.emplace(color, counter);
			counter++;
		}

		auto aux = supColors.find(frinputColor);
		if (aux != supColors.end()) {
			number = aux->second;
		}
		else {
			std::cerr << "Color not found: " << frinputColor << std::endl;

			std::cout << "Enter valid color: ";
			std::cin >> frinputColor;
		}
		//std::cout << number<<std :: endl;
		return number;
	}
	int bginputHandler(std::string bginputColor)
	{
		int number{};

		std::vector<std::string> colorList = { "Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "GrayWhite" };

		std::unordered_map<std::string, int> supColors;
		int counter = 40;
		for (const auto& color : colorList)
		{
			supColors.emplace(color, counter);
			counter++;
		}

		auto aux = supColors.find(bginputColor);
		if (aux != supColors.end()) {
			number = aux->second;
		}
		else {
			std::cerr << "Color not found: " << bginputColor << std::endl;

			std::cout << "Enter valid color: ";
			std::cin >> bginputColor;
		}
		//std::cout << number << std::endl;
		return number;
	}
	void colorText(std::string text)
	{
		int frCases{}, bgCases;
		std::string frinputColor, bginputColor;

		std::cout << "Specify foreground color: ";
		std::cin >> frinputColor;
		
		std::cout << "Specify background color: ";
		std::cin >> bginputColor;

		frCases = frinputHandler(frinputColor);
		bgCases = bginputHandler(bginputColor);

		std::cout << "\033["<< frCases <<";"<< bgCases << "m" << text <<"\033[0m" << std::endl;	 
	}
}
#endif