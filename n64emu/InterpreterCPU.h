#pragma once
#include "Instruction.h"
#include "R4300.h"

#include <cstdint>
#include <functional>
#include <array>

class InterpreterCPU {
public:
	static void Init();
	static void ExecuteInstruction(uint32_t instruction, R4300* cpu);
private:
	typedef std::function<void(Instruction, R4300* cpu)> Handler;
	static std::array<Handler, 64> handlers;
	static std::array<Handler, 64> specialHandlers;

	/* start instruction handlers */
	static void Special(Instruction instruction, R4300* cpu);
	static void AddImmediate(Instruction instruction, R4300* cpu);
	static void Jump(Instruction instruction, R4300* cpu);
	static void Branch(Instruction instruction, R4300* cpu);
	/* end instruction handlers */

	/* start special instructions handlers */
	static void Shift(Instruction instruction, R4300* cpu);
	static void Syscall(Instruction instruction, R4300* cpu);
	/* end special instructions handlers */
	
	/* start opcode constants */
	static const uint8_t SPECIAL = 000;
	static const uint8_t ADDI = 010;
	static const uint8_t ADDIU = 011;
	static const uint8_t ANDI = 014;
	static const uint8_t COP0 = 020;
	static const uint8_t COP1 = 021;
	static const uint8_t COP2 = 022;
	static const uint8_t BEQ = 004;
	static const uint8_t BEQL = 024;
	static const uint8_t REGIMM = 001;
	static const uint8_t BGTZ = 007;
	static const uint8_t BGTZL = 027;
	static const uint8_t BLEZ = 006;
	static const uint8_t BLEZL = 016;
	static const uint8_t BNE = 005;
	static const uint8_t BNEL = 025;
	static const uint8_t CACHE = 057;
	static const uint8_t DADDI = 030;
	static const uint8_t DADDIU = 031;
	static const uint8_t J = 002;
	static const uint8_t JAL = 003;
	static const uint8_t LB = 040;
	static const uint8_t LBU = 044;
	static const uint8_t LD = 067;
	static const uint8_t LDC1 = 065;
	static const uint8_t LDC2 = 066;
	static const uint8_t LDL = 032;
	static const uint8_t LDR = 033;
	static const uint8_t LH = 041;
	static const uint8_t LHU = 045;
	static const uint8_t LL = 060;
	static const uint8_t LLD = 064;
	static const uint8_t LUI = 017;
	static const uint8_t LW = 063;
	static const uint8_t LWC1 = 061;
	static const uint8_t LWC2 = 062;
	static const uint8_t LWL = 042;
	static const uint8_t LWR = 046;
	static const uint8_t LWU = 047;
	static const uint8_t ORI = 015;
	static const uint8_t SB = 050;
	static const uint8_t SC = 070;
	static const uint8_t SCD = 074;
	static const uint8_t SD = 077;
	static const uint8_t SDC1 = 074;
	static const uint8_t SDC2 = 075;
	static const uint8_t SDL = 054;
	static const uint8_t SDR = 055;
	static const uint8_t SH = 051;
	static const uint8_t SLTI = 012;
	static const uint8_t SLTIU = 013;
	static const uint8_t SW = 053;
	static const uint8_t SWC1 = 071;
	static const uint8_t SWC2 = 072;
	static const uint8_t SWL = 052;
	static const uint8_t SWR = 056;
	static const uint8_t XORI = 016;
	/* end opcode static constants */

	/* start funct static constants */
	static const uint8_t ADDU = 041;
	static const uint8_t AND = 044;
	static const uint8_t BREAK = 015;
	static const uint8_t DADD = 054;
	static const uint8_t DADDU = 055;
	static const uint8_t DDIV = 036;
	static const uint8_t DDIVU = 037;
	static const uint8_t DIV = 032;
	static const uint8_t DIVU = 033;
	static const uint8_t DMULT = 034;
	static const uint8_t DMULTU = 035;
	static const uint8_t DSLL = 070;
	static const uint8_t DSLLV = 050;
	static const uint8_t DSLL32 = 074;
	static const uint8_t DSRA = 073;
	static const uint8_t DSRAV = 027;
	static const uint8_t DSRA32 = 077;
	static const uint8_t DSRL = 072;
	static const uint8_t DSRLV = 026;
	static const uint8_t DSRL32 = 076;
	static const uint8_t DSUB = 056;
	static const uint8_t DSUBU = 057;
	static const uint8_t JALR = 011;
	static const uint8_t JR = 010;
	static const uint8_t MFHI = 020;
	static const uint8_t MFLO = 022;
	static const uint8_t MTHI = 021;
	static const uint8_t MTLO = 023;
	static const uint8_t MULT = 020;
	static const uint8_t MULTU = 021;
	static const uint8_t NOR = 047;
	static const uint8_t OR = 045;
	static const uint8_t SLL = 000;
	static const uint8_t SLLV = 004;
	static const uint8_t SLT = 052;
	static const uint8_t SLTU = 053;
	static const uint8_t SRA = 003;
	static const uint8_t SRAV = 007;
	static const uint8_t SRL = 002;
	static const uint8_t SRLV = 006;
	static const uint8_t SUB = 042;
	static const uint8_t SUBU = 043;
	static const uint8_t SYNC = 017;
	static const uint8_t SYSCALL = 014;
	static const uint8_t TEQ = 064;
	static const uint8_t TGE = 060;
	static const uint8_t TGEU = 061;
	static const uint8_t TLT = 062;
	static const uint8_t TLTU = 063;
	static const uint8_t TNE = 066;
	static const uint8_t XOR = 046;
	/* end funct static constants */

	/* start COP static constats */
	static const uint8_t MF = 0;
	static const uint8_t MT = 004;
	static const uint8_t TLBP = 010;
	static const uint8_t TLBR = 001;
	static const uint8_t TLBWI = 002;
	static const uint8_t TLBWR = 006;
	static const uint8_t ERET = 030; /* move somwhere else? */
	/* end COP static constants */

	/* start REGIMM static consts */
	static const uint8_t TEQI = 014;
	static const uint8_t TGEI = 010;
	static const uint8_t TGEIU = 011;
	static const uint8_t TLTI = 012;
	static const uint8_t TLTIU = 013;
	static const uint8_t TNEI = 016;
	/* end REGIMM static consts */

};

