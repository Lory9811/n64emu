#include "InterpreterCPU.h"

void InterpreterCPU::AddImmediate(Instruction instruction, R4300* cpu) {
	switch (instruction.op) {
	case ADDI:
		// TODO: throw overflow exception if there is an overflow
		break;
	case ADDIU:
		break;
	default:
		break;
	}

	cpu->SetGPRegister(instruction.rt, cpu->GetGPRegister(instruction.rs) + instruction.immediate);
}