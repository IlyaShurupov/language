
#pragma once

#include "list.h"
#include "array.h"
#include "strings.h"

#include "token.h"

class definition {
	list<definition*> source;

	token* tok;
};


class Grammar {
	Array<definition*> rulles;
};


// WIP

struct def_as_string {
	string target;
	list<string*> source;
};

struct grammar_as_rulles {
	list<def_as_string*> rulles;

	grammar_as_rulles& add_rulle(string target, alni toktype) {
		return *this;
	}

	grammar_as_rulles& add_rulle(string target, string src, ...) {
		return *this;
	}

	Grammar* generate() {
		return NULL;
	}
};