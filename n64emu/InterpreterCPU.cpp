#include "InterpreterCPU.h"

std::array<InterpreterCPU::Handler, 64> InterpreterCPU::handlers = {};
std::array<InterpreterCPU::Handler, 64> InterpreterCPU::specialHandlers = {};

void InterpreterCPU::Init() {
	auto addInst = [](uint8_t opcode, Handler handler) {
		handlers[opcode] = handler;
	};
	auto addSpecial = [](uint8_t opcode, Handler handler) {
		specialHandlers[opcode] = handler;
	};

	addInst(SPECIAL, Special);
	addInst(ADDI, AddImmediate);
	addInst(ADDIU, AddImmediate);

	addInst(BEQ, Branch);

	addInst(J, Jump);

	addSpecial(SLL, Shift);
	addSpecial(SYSCALL, Syscall);
}

void InterpreterCPU::ExecuteInstruction(uint32_t instruction, R4300* cpu) {
	handlers[((Instruction*)&instruction)->op](*(Instruction*)&instruction, cpu);
}

//void InterpreterCPU::RegisterInstructionHandler(uint8_t opcode, Handler handler) {
//	handlers[opcode] = handler;
//}
