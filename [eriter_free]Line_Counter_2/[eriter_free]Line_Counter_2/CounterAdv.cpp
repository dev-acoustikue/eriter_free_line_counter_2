// [eriterfree] line counter advanced
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2017, VS Platform Tool 17
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.09 Happpy new year!!
// 

#pragma once

#include <fstream>
#include <iostream>

#include <vector>

#ifndef CONSOLE_OUT_SERIES
#define CONSOLE_OUT_SERIES
#endif

#include "CounterAdv.h"

long long _jcode::CounterAdv::countListOf(const std::vector<std::vector<std::string>>& argAddrList) {

	std::ifstream Target_File;
	std::string _T;
	
	long long Lines = 0;
	
	for (auto& extension_itor : argAddrList) {
		for (auto& addr_itor : extension_itor) {

			Target_File.open(addr_itor); // open it up!

			if (Target_File)
				while (std::getline(Target_File, _T)) Lines++; // Counting..

			Target_File.close(); // must be closed.
		}
	};

	return Lines;
};