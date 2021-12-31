
#pragma once

#include "token.h"
#include "grammar.h"
#include "parsetree.h"
#include "language.h"


class Parser {

public:

	Parser(Grammar& grammar) {}

	virtual ParseTree parse(TokStream& tokstream) {
		return ParseTree();
	}

};