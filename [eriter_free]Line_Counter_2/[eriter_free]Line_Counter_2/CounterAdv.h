#pragma once
// [eriter_free] line counter advanced
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2017, VS Platform Tool 17
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.09 Happpy new year!!
// 

#define __CXX_LEGACY
#define _WINDOWS_

#include <string>

#ifndef CONSOLE_OUT_SERIES
#define CONSOLE_OUT_SERIES
#endif

#ifdef CONSOLE_OUT_SERIES

#define CONSOLE_OUT(MSG) \
	do { COUT << MSG << ENDL; } while (0)
#define CONSOLE_OUT_SYSTEM(SYS_MSG) \
	do { COUT << "SYSTEM: " << SYS_MSG << ENDL; } while (0)
#define CONSOLE_OUT_MESSAGE(MSG) \
	do { COUT << "MESSAGE: " << MSG << ENDL; } while (0)

#endif

namespace _jcode {

	// Again!! Another useless wrapping system. My god!!
	class CounterAdv final {
	private:

	public:
		static long long countListOf(const std::vector<std::vector<std::string>>&);
	};
};

#undef __CXX_LEGACY
#undef _WINDOWS_