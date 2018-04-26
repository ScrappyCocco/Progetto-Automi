#include <iostream>
#include <fstream>
#include <string>
#include "antlr4-runtime.h"
#include "swlLexer.h"
#include "swlParser.h"
#include "MyListener.h"

using namespace std;
using namespace antlr4;

int main(int argc, char* argv[]) {
    if(argc != 2) {
        cout << "Usage: translate filename.swl" << endl;
        return 1;
    }
    ifstream swlFile(argv[1]);
    ANTLRInputStream input(swlFile);
    swlLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    swlParser parser(&tokens);
    tree::ParseTree *tree = parser.program();
    int errors = parser.getNumberOfSyntaxErrors();
    if(errors > 0) {
        cout << errors << " syntax errors found, aborting." << endl;
        return 1;
    } 
    MyListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
    return 0;
}
