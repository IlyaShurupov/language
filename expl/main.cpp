
#include "parser.h"

#include <iostream>
#include <fstream>
#include <string>

int main() {

	LALRGrammar grammar("expl.grammar");
	LALRParser<const char*, int> parser(grammar);

	while (1) {
		std::string input;
		getline(std::cin, input);

		parser.parse(input.c_str(), input.length());
		printf(" = %d \n", parser.ps.user_data());
	}
}