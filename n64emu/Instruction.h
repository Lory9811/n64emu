#pragma once

struct Instruction {
	union {
		struct {
			int target : 26;
			int op : 6;
		};
		struct {
			int funct : 6;
			int sa : 5;
			int rd : 5;
			int rt : 5;
			int rs : 5;
		};
		struct {
			int immediate : 16;
		};
	};
};
