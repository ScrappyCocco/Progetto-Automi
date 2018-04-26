#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "swlLexer.h"
#include "swlParser.h"
#include <windows.h>

using namespace antlr4;

inline bool exists_file(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

std::string workingdir()
{
	char buf[256];
	GetCurrentDirectoryA(256, buf);
	return std::string(buf) + '\\';
}

int main() {
	std::cout << "Started" << std::endl;
	std::string filename = "example.swl";
	if (!exists_file(filename)) {
		std::cout << "File "<< filename <<" not found in directory:"<< std::endl << (workingdir()) << std::endl;
		fflush(stdin);
		getchar();
		return 1;
	}
	else {
		std::cout << "File " << filename << " exist and is begin checked" << std::endl;
	}
	std::ifstream swlFile(filename);
	ANTLRInputStream input(swlFile);
	swlLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	swlParser parser(&tokens);
	tree::ParseTree *tree = parser.program();
	int errors = parser.getNumberOfSyntaxErrors();
	if (errors > 0) {
		std::cout << errors << " syntax errors found." << std::endl;
		fflush(stdin);
		getchar();
		return 1;
	}
	std::cout << "No syntax errors found." << std::endl;
	fflush(stdin);
	getchar();
}
