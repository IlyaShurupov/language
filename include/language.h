
#pragma once

#include  "types.h"

struct range : pair<alni, alni> {};

class language {
	alni symb_len;
	Array<range> alphabet;
};

class text {
	const char* buff;
	language* lan;
};
