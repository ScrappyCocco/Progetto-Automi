// Generated from swl.g4 by ANTLR 4.7
#include <iostream>
#include "MyListener.h"

using namespace std;

void MyListener::enterProgram(swlParser::ProgramContext *ctx) {
    cout << "#include <iostream>" << endl << endl
         << "using namespace std;" << endl << endl
         << "int main() {" << endl;
    indent += 4;
}

void MyListener::exitProgram(swlParser::ProgramContext *ctx) {
    cout << "}" << endl;
}

void MyListener::exitAssign(swlParser::AssignContext *ctx) {
    string name = ctx->ID(0)->getText();
    string val;
    if(ctx->ID().size() > 1) {
        val = ctx->ID(1)->getText();
    } else {
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << "int " << name << " = " << val << ";" << endl;
}


void MyListener::exitPrint(swlParser::PrintContext *ctx) {
    string val;
    if(ctx->ID() != NULL) {
        val = ctx->ID()->getText();
    } else {
	if(ctx->NUMBER() != NULL) {
        	val = ctx->NUMBER()->getText();
	}else{
		val = ctx->comparison()->getText();
	}
    }
    cout << string(indent, ' ') << "cout << " << val << " << endl;" << endl;    
}

void MyListener::exitMeno(swlParser::MenoContext *ctx)
{
	string name;
    string val;
    if(ctx->ID().size() > 1) {
        name = ctx->ID(1)->getText();
        val = ctx->ID(0)->getText();
    } else {
        name = ctx->ID(0)->getText();
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << name << " -= " << val << ";" << endl;
}

void MyListener::exitAdd(swlParser::AddContext *ctx) {
    string name;
    string val;
    if(ctx->ID().size() > 1) {
        name = ctx->ID(1)->getText();
        val = ctx->ID(0)->getText();
    } else {
        name = ctx->ID(0)->getText();
        val = ctx->NUMBER()->getText();
    }
    cout << string(indent, ' ') << name << " += " << val << ";" << endl;
}
void MyListener::enterIfoperator(swlParser::IfoperatorContext *ctx)
{
	string boolexp = "";
	if(ctx->booloperator() != NULL) {
		boolexp = "(" + ctx->booloperator()->getText() + ")";
	}else{
		if(ctx->comparison()->NOTOPERATOR() != NULL) {
			boolexp = "!";
		}
		boolexp += "(" + ctx->comparison()->getText() + ")";
	}
	cout << string(indent, ' ') << "if " << boolexp << "{" << endl;
	indent += 4;
}

void MyListener::exitIfoperator(swlParser::IfoperatorContext *ctx){
	indent -= 4;
	cout << string(indent, ' ') << "}" << endl;
}


