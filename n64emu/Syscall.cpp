#include "InterpreterCPU.h"
#include <cstdio>

void InterpreterCPU::Syscall(Instruction instruction, R4300* cpu) {
	if (instruction.sa > 0) {
		printf("Test Result - ISA: %d Set: %d Test: %d Result: %c\n",
			   instruction.rs, instruction.rd, instruction.sa, ((char)instruction.rt + 64));
	} else {

	}
}