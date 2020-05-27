#include "Memory.h"
#include <fstream>

Memory::Memory() {
	memory = new uint8_t[4194304];
}

Memory::~Memory() {
	delete[] memory;
}

void Memory::LoadFileAtAddress(std::string filename, uint64_t address) {
	std::ifstream file(filename, std::ios_base::binary);
	file.seekg(0, std::ios_base::end);
	int length = file.tellg();
	file.seekg(0, std::ios_base::beg);
	// TODO: check if file fits in memory
	
	file.read((char*)memory, length);

	file.close();
}
