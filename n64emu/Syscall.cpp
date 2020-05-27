#include "InterpreterCPU.h"
#include <cstdio>

void InterpreterCPU::Syscall(Instruction instruction, R4300* cpu) {
	if (instruction.sa > 0) {
		char result = instruction.rt;
		printf("Test Result - ISA: %d Set: %d Test: %d Result: %c\n",
			   instruction.rs, instruction.rd, instruction.sa, (instruction.rt & 0x1F) + 64);
	} else {

	}
}