#pragma once
#include "Memory.h"
#include "R4300.h"

class N64 {
public:
	N64();
	~N64();
	void Update();
private:
	Memory memory;
	R4300 r4300;
};

