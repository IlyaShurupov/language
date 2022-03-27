
#pragma once

#include  "tuple.h"
#include  "array.h"

class language {
	alni symb_len;
	Array<range> alphabet;
};

class text {
	const char* buff;
	language* lan;
};
