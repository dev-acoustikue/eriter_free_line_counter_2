#pragma once
// [eriter_free] line counter advanced
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2017, VS Platform Tool 17
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.09 Happpy new year!!
// 

// #define CONSOLE_DEBUG_ON // option

#include <cstdlib>

// #include <iostream>
#include <string>
// #include <functional>

#ifndef CONSOLE_OUT_SERIES
#define CONSOLE_OUT_SERIES
#endif

#include "ExtensionFinder.h"
#include "CounterAdv.h"


// another wrapper.
// I love wrapping. It gives me a great comfort. Dunno why, it does.
auto MenuFunction = [](std::string& argDirName, 
	std::string& argFileExtensions) -> void {

	CONSOLE_OUT_MESSAGE("Set the root directory.");
	COUT << "> ";
	std::getline(CIN, argDirName);

	CONSOLE_OUT_MESSAGE("Set file extensions which will be target.");
	COUT << "> ";
	std::getline(CIN, argFileExtensions);

};



// 
int main() try {

	// Showing project boilerplate
	CONSOLE_OUT("[eriter_free] line counter advanced");
	CONSOLE_OUT("Windows 7 Enterprise 32-bit, Visual Studio Professional 2017, VS Platform Tool 17");
	CONSOLE_OUT("Operations Information & Communication Wing, Air-Defense Guided Missile System Team, ");
	CONSOLE_OUT("KTMO-CELL S/W Support, SukJoon Oh(17-70010114)\n");


	std::string DirectoryName = "";
	std::string FileExtensions = "";

	_jcode::ExtensionFinder Wrapper;

#ifndef ITEM_FINDER_VERSION

	long long Lines = 0x00;
#endif



	while (1) { // For once

		CONSOLE_OUT_SYSTEM("Starting procedure...");
		// Console input menu
		MenuFunction(DirectoryName, FileExtensions);

		// FileSystemWrapper instance, setting the root directory.
		Wrapper.setRootDirName(DirectoryName);

		{ // debug, temporary scope

			CONSOLE_OUT_MESSAGE("Printing list of members below.");
			Wrapper.showConsoleRootFolderList();

			CONSOLE_OUT_MESSAGE("Printing saved list of directories.");
			Wrapper.showConsoleDirUnderRootList();
		}

		// Setting the extensions
		Wrapper.setFileTargetExtension(FileExtensions);


		{ // debug, temporary scope
			CONSOLE_OUT_SYSTEM("Printing list of tokenized words.");
			Wrapper.showConsoleTokenizedList();
		}

#ifdef ITEM_FINDER_VERSION
		// Getting 
		Wrapper.getFileAddrListExtension(); // Main operation!!!
			// No need for showConsole function. 
			// This function automatically shows when listing.
		
		// Until here, it will be an item-finder
		// if line counter is needed, set the option on.

#endif
#ifndef ITEM_FINDER_VERSION
		
		Lines = _jcode::CounterAdv::countListOf(
			Wrapper.getFileAddrListExtension()
		);
#endif

		CONSOLE_OUT_SYSTEM("Counted " + std::to_string(Lines) + " lines");

		Wrapper.clearData();
		CONSOLE_OUT_SYSTEM("Done...\n");
		// system("pause");
			// not neccessary


	}


	return 0;

} catch (std::exception& argException) {

	CONSOLE_OUT_SYSTEM(argException.what());

} catch (...) {

	CONSOLE_OUT_SYSTEM("Unknown exception catched. Shutting down the program.");
};