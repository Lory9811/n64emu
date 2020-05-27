#pragma once
#include <string>
#include <immintrin.h>


class Memory {
public:
	Memory();
	~Memory();

	void LoadFileAtAddress(std::string filename, uint64_t address);
	uint32_t ReadHW(uint64_t address) {
		return _bswap(Read<uint32_t>(address));
	}

	template<class T>
	T Read(uint64_t address) {
		return ((T*)memory)[address / sizeof(T)];
	}

	template<class T>
	void Write(uint64_t address, T value) {

	}
private:
	uint32_t _bswap(uint32_t a) {
		return (((uint8_t*)&a)[0] << 24) | (((uint8_t*)&a)[1] << 16) |
			(((uint8_t*)&a)[2] << 8) | (((uint8_t*)&a)[3]);
	}
	uint8_t* memory;
};

