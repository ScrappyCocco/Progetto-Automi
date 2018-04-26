#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "swlLexer.h"
#include "swlParser.h"

using namespace std;
using namespace antlr4;

int main() {
	cout << "Started" << endl;
	string filename = "example.swl";
	ifstream swlFile(filename);
	ANTLRInputStream input(swlFile);
	swlLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	swlParser parser(&tokens);
	tree::ParseTree *tree = parser.program();
	int errors = parser.getNumberOfSyntaxErrors();
	if (errors > 0) {
		cout << errors << " syntax errors found." << endl;
		return 1;
	}
	cout << "No syntax errors found." << endl;
	return 0;
}
