// [eriter_free] line counter advanced
// Windows 7 Enterprise 32-bit, Visual Studio Professional 2017, VS Platform Tool 17
// Operations Information & Communication Wing, Air-Defense Guided Missile System Team, 
// KTMO-CELL S/W Support, SukJoon Oh(17-70010114)
// 2019.01.09
// 

#pragma once

#define CONSOLE_DEBUG_ON // option


#include <string>
#include <list>
#include <vector>
#include <exception>

#include <iostream>

#ifndef CONSOLE_OUT_SERIES
#define CONSOLE_OUT_SERIES
#endif

#define COUT std::cout
#define CIN std::cin
#define ENDL std::endl

#ifdef CONSOLE_OUT_SERIES

#define CONSOLE_OUT(MSG) \
	do { COUT << MSG << ENDL; } while (0)
#define CONSOLE_OUT_SYSTEM(SYS_MSG) \
	do { COUT << "SYSTEM: " << SYS_MSG << ENDL; } while (0)
#define CONSOLE_OUT_MESSAGE(MSG) \
	do { COUT << "MESSAGE: " << MSG << ENDL; } while (0)

#endif

#include <filesystem> // experimental since C++17, VS2017

// experimental? since C++17
// using namespace std::experimental::filesystem;
namespace fs = std::experimental::filesystem;
// path filePath;


namespace _jcode {

	class ExtensionFinder final {
		// This code is tested in Windows 7 32-bit system.
	private:
		std::string RootDirName; // Must be initialized.
		std::list<std::string> DirUnderRootList;

		std::vector<std::string> TargetFileExtension; // used when finding a specific extension of files.
		
		// Exception catcher
		// class!!
		class ExtensionFinderException final {
		private:
			std::string ExceptionMessage;

		public:
			// ctor
			// ExtensionFinderException() = default;
			ExtensionFinderException(const char*);
			ExtensionFinderException(std::string&);

			// dtor
			virtual ~ExtensionFinderException() = default;

			// interface
			inline const std::string isError() {
				
				return ExceptionMessage;
			};

			inline const std::string isError(std::exception& argExcpt) {
				
				return argExcpt.what();
			};
		};

		// core
		void findUnderRootDirAddr();
		bool isTargetExtension(const std::string&, const std::string&);


	public:
		// ctor
		ExtensionFinder() = default;
		ExtensionFinder(const char*);
		ExtensionFinder(std::string&);

		// dtor
		virtual ~ExtensionFinder() = default;

		// setter
		void setRootDirName(const char*) noexcept;
		void setRootDirName(std::string&) noexcept;

		void setFileTargetExtension(const char*);
		void setFileTargetExtension(std::string&);

		// getter
		std::string getFileTargetExtension(const int&) const; // deprecated


		// interface
			// debug
		void showConsoleRootFolderList() const;
		void showConsoleRootFolderFileList() const;
		void showConsoleRootFolderFolderList() const;

		void showConsoleTokenizedList() const;
		void showConsoleDirUnderRootList() const;

			// toss the lists
		std::vector<std::string> getFileAddressListExtensionOf(const char*) const = delete;
		std::vector<std::string> getFileAddressListExtensionOf(std::string&) const = delete;

		std::vector<std::vector<std::string>> getFileAddrListExtension();

		void clearData() noexcept;
	};
};
