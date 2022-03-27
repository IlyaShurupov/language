
#pragma once

#include "list.h"

class token {
	alni type;

	alni val_ref;
	alni val_len;
};

typedef list<token> TokStream;