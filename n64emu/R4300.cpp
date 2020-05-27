#include "R4300.h"
#include "InterpreterCPU.h"
#include <cstdio>

R4300::R4300(Memory* memory) {
	registers[0] = 0;
	PC = 0;
	delay = 0;

	this->memory = memory;
}

void R4300::SetGPRegister(int number, uint64_t value) {
	if (number == 0) return;
	registers[number] = value;
}

uint64_t R4300::GetGPRegister(int number) {
	return registers[number];
}

void R4300::SetSpecialRegister(Register reg, uint64_t value) {
}

uint64_t R4300::GetSpecialRegister(Register reg) {
	return uint64_t();
}

void R4300::Jump(uint64_t address) {
	PC = (PC & ((uint64_t)0xFFFFFFFF << 32)) | (address << 2);
	printf("Jumped to 0x%llx\n", PC);
}

void R4300::Branch(int16_t offset) {
	PC += ((int64_t)offset << 2);
	printf("Branched to 0x%llx with offset 0x%x\n", PC, offset << 2);
}

void R4300::Run(int cycles) {
	for (int i = 0; i != cycles; i++) {
		if (delay < 0) {
			delay++;
			continue;
		}

		//uint32_t instruction = memory->Read<uint32_t>(PC);
		uint32_t instruction = memory->ReadHW(PC);
		printf("[0x%llx]: %lx\n", PC, instruction);
		PC += 4;
		
		InterpreterCPU::ExecuteInstruction(instruction, this);
	}
}
