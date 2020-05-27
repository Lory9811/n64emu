#include "N64.h"

N64::N64() : memory(), r4300(&memory) {
	memory.LoadFileAtAddress("./test.bin", 0);
}

N64::~N64() {
}

void N64::Update() {
	r4300.Run(1);
}
