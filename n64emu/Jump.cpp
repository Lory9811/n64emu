#include "InterpreterCPU.h"

void InterpreterCPU::Jump(Instruction instruction, R4300* cpu) {
	cpu->Jump(instruction.target);
	cpu->AddDelay(1);
}

void InterpreterCPU::Branch(Instruction instruction, R4300* cpu) {
	auto condition = [instruction, cpu]{
		uint64_t rs = cpu->GetGPRegister(instruction.rs);
		uint64_t rt = cpu->GetGPRegister(instruction.rt);
		switch (instruction.op) {
		case BEQ:
			return rs == rt;
			break;
		default:
			return false;
			break;
		}
	};

	if (condition()) {
		cpu->Branch(instruction.immediate);
		cpu->AddDelay(1);
	}
}
