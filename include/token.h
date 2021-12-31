
#pragma once

#include "types.h"

class token {
	alni type;

	alni val_ref;
	alni val_len;
};

typedef List<token> TokStream;