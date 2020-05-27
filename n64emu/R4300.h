#pragma once
#include "Memory.h"
#include <cstdint>

class R4300 {
public:
	enum class Register {
		PC, MUL_HI, MUL_LO, LL,
		FP_CR0, FP_CR31
	};
	R4300(Memory* memory);
	void SetGPRegister(int number, uint64_t value);
	uint64_t GetGPRegister(int number);
	void SetSpecialRegister(Register reg, uint64_t value);
	uint64_t GetSpecialRegister(Register reg);
	void Jump(uint64_t address);
	void Branch(int16_t offset);
	void AddDelay(int delay) { this->delay = delay; };
	void Run(int cycles);
private:
	int64_t delay;

	uint64_t registers[32];
	uint64_t fpRegisters[32];
	uint64_t mulHi;
	uint64_t mulLo;
	uint64_t PC;
	uint64_t LLbit;

	uint32_t fpCR0;
	uint32_t fpCR31;

	Memory* memory;
};

