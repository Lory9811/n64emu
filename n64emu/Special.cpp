#include "InterpreterCPU.h"

void InterpreterCPU::Special(Instruction instruction, R4300* cpu) {
	specialHandlers[instruction.funct](instruction, cpu);
}
