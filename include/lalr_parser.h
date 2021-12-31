
#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <fstream>

#include <lalr/GrammarCompiler.hpp>
#include <lalr/Parser.ipp>
#include <lalr/AddParserActionHandler.ipp>

#include "token.h"
#include "grammar.h"
#include "parsetree.h"
#include "language.h"


struct LALRGrammar {

	string grammar;

	lalr::GrammarCompiler compiler;

	LALRGrammar(string path) {
		std::ifstream file(path.str);
		std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		grammar = content.c_str();
		file.close();

		compiler.compile(getc(), getc() + strlen(getc()));
	}

	const char* getc() {
		return grammar.str;
	}
};

template <typename T1, typename T2>
struct LALRParser {
	lalr::Parser<T1, T2> ps;

	LALRParser(const LALRGrammar& gmammar) :
		ps(gmammar.compiler.parser_state_machine()) {

		ps.set_default_action_handler([](const int* data, const lalr::ParserNode<>* nodes, size_t length)
			{
				printf("\n node : \n ");
				for (int i = 0; i < length; i++) {
					printf("\n\t [ %i, %s, %s, %s ] ",
						nodes[i].column(),
						nodes[i].lexeme().c_str(),
						nodes[i].symbol()->identifier,
						nodes[i].symbol()->lexeme);
				}
				return 0;
			}
		);
	}

	bool parse(T1 in, size_t len) {
		ps.parse(in, &in[len]);
		return false;
	}

};
