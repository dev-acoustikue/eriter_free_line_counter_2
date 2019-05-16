// [eriter_free] line counter advanced
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2017, VS Platform Tool 17
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.09
// 

#pragma once

#include <iostream>
#include <list>

#include <iterator>
#include <algorithm>
#include <sstream>

#ifndef CONSOLE_OUT_SERIES
#define CONSOLE_OUT_SERIES
#endif

// declaration
#include "ExtensionFinder.h"

// experimental? since C++17
// using namespace std::experimental::filesystem;
// namespace fs = std::experimental::filesystem;


// Exception class
_jcode::ExtensionFinder::ExtensionFinderException::ExtensionFinderException(const char* argExcptMsg)
	: ExceptionMessage(argExcptMsg) {
#ifdef CONSOLE_DEBUG_ON
	CONSOLE_OUT_SYSTEM("CTOR: ExtensionFinder::ExtensionFinderException::ExtensionFinderException(const char*)");
#endif

};

_jcode::ExtensionFinder::ExtensionFinderException::ExtensionFinderException(std::string& argExcptMsg)
	: ExceptionMessage(argExcptMsg) {
#ifdef CONSOLE_DEBUG_ON
	CONSOLE_OUT_SYSTEM("CTOR: ExtensionFinder::ExtensionFinderException::ExtensionFinderException(std::string&)");
#endif
};



// ctor
_jcode::ExtensionFinder::ExtensionFinder(const char* argDirName) : RootDirName(argDirName){
#ifdef CONSOLE_DEBUG_ON
	CONSOLE_OUT_SYSTEM("CTOR: ExtensionFinder::ExtensionFinder(const char*)");
#endif

	this->findUnderRootDirAddr();
};


_jcode::ExtensionFinder::ExtensionFinder(std::string& argDirName) : RootDirName(argDirName) {
#ifdef CONSOLE_DEBUG_ON
	CONSOLE_OUT_SYSTEM("CTOR: ExtensionFinder::ExtensionFinder(std::string&)");
#endif

	this->findUnderRootDirAddr();
};

// setter
void _jcode::ExtensionFinder::setRootDirName(const char* argDirName) noexcept {
	
	this->RootDirName = argDirName;
	this->findUnderRootDirAddr();
};

void _jcode::ExtensionFinder::setRootDirName(std::string& argDirName) noexcept {
	
	this->RootDirName = argDirName;
	this->findUnderRootDirAddr();
};

void _jcode::ExtensionFinder::setFileTargetExtension(const char* argExtensionStr) {
	
	std::string Wrapper(argExtensionStr);
	std::istringstream iss(Wrapper); // temporary wrapper

	try {

		// Tokenizing, and inserting to list<string>
		std::copy(
			std::istream_iterator<std::string>(iss),
			std::istream_iterator<std::string>(),
			std::back_inserter(TargetFileExtension));

	} catch (std::exception argException) {
		
		CONSOLE_OUT_SYSTEM("Problem occurred when tokenizing.");
	}

};

void _jcode::ExtensionFinder::setFileTargetExtension(std::string& argExtensionStr) {
	
	std::istringstream iss(argExtensionStr);

	try {

		// Tokenizing, and inserting to list<string>
		std::copy(
			std::istream_iterator<std::string>(iss),
			std::istream_iterator<std::string>(),
			std::back_inserter(TargetFileExtension));

	} catch (std::exception argException) {

		CONSOLE_OUT_SYSTEM("Problem occurred when tokenizing.");
	}
};

// getter
std::string _jcode::ExtensionFinder::getFileTargetExtension(const int& argIndex) const {
	
	return TargetFileExtension.at(argIndex);
};

// core
void _jcode::ExtensionFinder::findUnderRootDirAddr() {

#ifdef CONSOLE_DEBUG_ON
	CONSOLE_OUT_SYSTEM("ExtensionFinder::findUnderRootDirAddr()");
#endif

	DirUnderRootList.push_back(this->RootDirName); // Will start from here.
		// This variable contains itself. (root)

	for(auto& iterator : DirUnderRootList) {
		for (auto& dir_name : fs::directory_iterator(iterator)) {

			if (fs::is_directory(dir_name))
				DirUnderRootList.push_back(dir_name.path().string());

			else
				;
		}

	}

#ifdef CONSOLE_DEBUG_ON
	CONSOLE_OUT_SYSTEM("Done making a list of folder names.");
#endif
};

bool _jcode::ExtensionFinder::isTargetExtension(const std::string& argAddr, const std::string& argExtension) {
	
	// 'is this the right extension??' function.
	// std::string Address(argAddr), Extension(argExtension);

	if (!argAddr.substr(argAddr.length() - argExtension.length(),
		argExtension.length()).compare(argExtension))
		return true;

	else
		return false;
};



// interface
void _jcode::ExtensionFinder::showConsoleRootFolderList() const {
	
	// This function shows all regardless of types.
	// Thus, 

	try {
		this->showConsoleRootFolderFolderList(); // show folders first, 
		this->showConsoleRootFolderFileList(); // and then print the files.
	
	} catch (std::exception& argException) {
		CONSOLE_OUT_SYSTEM(argException.what());
	};
};

void _jcode::ExtensionFinder::showConsoleRootFolderFileList() const {

	try {

		for (auto& file_name : fs::directory_iterator(RootDirName)) {

			if (fs::is_regular_file(file_name))
				COUT << "\t(REG)FILE: " << file_name << ENDL;

			else if (fs::is_other(file_name))
				COUT << "\t(OTH)FILE: " << file_name << ENDL;

			else if (fs::is_directory(file_name))
				; // should be filtered at showConsoleRootFolderList() function.

			else
				CONSOLE_OUT_SYSTEM("Unknown case detected.");
		}
	
	} catch (std::exception& argException) {
		CONSOLE_OUT_SYSTEM(argException.what());
	};

};

void _jcode::ExtensionFinder::showConsoleRootFolderFolderList() const{

	try {
		for (auto& file_name : fs::directory_iterator(RootDirName)) {

			if (fs::is_directory(file_name)) 			
				COUT << "\t(DIR)DIR: " << file_name << ENDL;
		}

	} catch (std::exception& argException) {
		CONSOLE_OUT_SYSTEM(argException.what());
	};
};

void _jcode::ExtensionFinder::showConsoleTokenizedList() const {
		
	try {
		for (auto& tokenizedWord : TargetFileExtension)
				COUT << "\tTOKEN: " << tokenizedWord << ENDL;
	}
	catch (std::exception& argException) {
		CONSOLE_OUT_SYSTEM(argException.what());
	};
};

void _jcode::ExtensionFinder::showConsoleDirUnderRootList() const {
	
	try {

		for (auto& folderList : this->DirUnderRootList)
			COUT << "\tLIST(DIR): " << folderList << ENDL;
	}
	catch (std::exception& argException) {
		CONSOLE_OUT_SYSTEM(argException.what());
	};
};




// getFileAddressListExtensionOf
std::vector<std::vector<std::string>> _jcode::ExtensionFinder::getFileAddrListExtension() {
	
	std::vector<std::vector<std::string>> AddrList;
	int _x = 0x00;
	
	CONSOLE_OUT_SYSTEM("Filtered file lists.");

	for (auto& extensionItor : TargetFileExtension) { // first reiterates with extension list.

		AddrList.push_back(std::vector<std::string>()); // make some space!

		for (auto& folderItor : DirUnderRootList) {
			for (auto& item_name : fs::directory_iterator(folderItor)) {

				if (isTargetExtension(item_name.path().string(), extensionItor)
					&& !fs::is_directory(item_name)
					) {
				
					AddrList.at(_x).push_back(item_name.path().string());
					CONSOLE_OUT("\t" + item_name.path().string()); // shows what have been pushed.
				}
			}
		}

		_x++;
	};

	return AddrList;
};


// clearData()
void _jcode::ExtensionFinder::clearData() noexcept {
	
	// Clears the members
	RootDirName = "";
	DirUnderRootList.clear();
	TargetFileExtension.clear();

	// Done.
#ifdef CONSOLE_DEBUG_ON
	CONSOLE_OUT_SYSTEM("Done clearing lists.");
#endif
};
