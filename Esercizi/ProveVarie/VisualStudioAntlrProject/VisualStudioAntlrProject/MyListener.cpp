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
	if (ctx->ID().size() > 1) {
		val = ctx->ID(1)->getText();
	}
	else {
		val = ctx->NUMBER()->getText();
	}
	cout << string(indent, ' ') << "int " << name << " = " << val << ";" << endl;
}


void MyListener::exitPrint(swlParser::PrintContext *ctx) {
	string val;
	if (ctx->ID() != NULL) {
		val = ctx->ID()->getText();
	}
	else {
		if (ctx->NUMBER() != NULL) {
			val = ctx->NUMBER()->getText();
		}
	}
	cout << string(indent, ' ') << "cout << " << val << " << endl;" << endl;
}

void MyListener::exitSub(swlParser::SubContext *ctx)
{
	string name;
	string val;
	if (ctx->ID().size() > 1) {
		name = ctx->ID(1)->getText();
		val = ctx->ID(0)->getText();
	}
	else {
		name = ctx->ID(0)->getText();
		val = ctx->NUMBER()->getText();
	}
	cout << string(indent, ' ') << name << " -= " << val << ";" << endl;
}

void MyListener::exitAdd(swlParser::AddContext *ctx) {
	string name;
	string val;
	if (ctx->ID().size() > 1) {
		name = ctx->ID(1)->getText();
		val = ctx->ID(0)->getText();
	}
	else {
		name = ctx->ID(0)->getText();
		val = ctx->NUMBER()->getText();
	}
	cout << string(indent, ' ') << name << " += " << val << ";" << endl;
}

void MyListener::exitMul(swlParser::MulContext *ctx)
{
	string name;
	string val;
	if (ctx->ID().size() > 1) {
		name = ctx->ID(1)->getText();
		val = ctx->ID(0)->getText();
	}
	else {
		name = ctx->ID(0)->getText();
		val = ctx->NUMBER()->getText();
	}
	cout << string(indent, ' ') << name << " *= " << val << ";" << endl;
}
void MyListener::exitDiv(swlParser::DivContext *ctx)
{
	string name;
	string val;
	if (ctx->ID().size() > 1) {
		name = ctx->ID(1)->getText();
		val = ctx->ID(0)->getText();
	}
	else {
		name = ctx->ID(0)->getText();
		val = ctx->NUMBER()->getText();
	}
	cout << string(indent, ' ') << name << " /= " << val << ";" << endl;
}

//FUNZIONE UTILIZZATA PER CONVERTIRE IL TESTO DELL'OPERATORE IN OPERATORE CPP
string convertBooleanOperatorToCppOperator(string bool_operator) {
	if (bool_operator == "equal") {
		return "==";
	}
	if (bool_operator == "lower") {
		return "<";
	}
	if (bool_operator == "greater") {
		return ">";
	}
	if (bool_operator == "different") {
		return "!=";
	}
	if (bool_operator == "and") {
		return "&&";
	}
	if (bool_operator == "or") {
		return "||";
	}
	if (bool_operator == "not") {
		return "!";
	}
}

//FUNZIONE USATA PER CONVERTIRE UN ComparisonContext NELLA STRINGA CHE LO RAPPRESENTA (Ex. a greater b --> a > b)
string generateComparisonExpression(swlParser::ComparisonContext* ctx) {
	string val1, val2, bool_operator;
	if (ctx->ID().size() > 1) {
		val1 = ctx->ID(0)->getText();
		val2 = ctx->ID(1)->getText();
	}
	else {
		val1 = ctx->ID(0)->getText();
		val2 = ctx->NUMBER()->getText();
	}
	bool_operator = convertBooleanOperatorToCppOperator(ctx->bool_compare_operators()->getText());
	string not_string = "";
	if (ctx->not_operator().size() > 0) {
		for (int i = 0;i < ctx->not_operator().size();i++) {
			not_string += convertBooleanOperatorToCppOperator(ctx->not_operator(i)->getText());
		}
	}
	string final_string;
	if (not_string != "") {
		final_string = not_string + "(" + val1 + " " + bool_operator + " " + val2 + ")";
	}
	else {
		final_string = val1 + " " + bool_operator + " " + val2;
	}
	return final_string;
}

string generateBooleanExpression(swlParser::BooloperatorContext* ctx);

string generateBracketsBooleanExpression(swlParser::BoolbracketsContext* ctx) {
	string final_string = "(";
	if (ctx->comparison() != NULL) {
		final_string += generateComparisonExpression(ctx->comparison());
	}
	else {
		final_string += generateBooleanExpression(ctx->booloperator());
	}
	final_string += ")";
	return final_string;
}

string generateBooleanExpressionNew(swlParser::BooloperatorContext* ctx) {
	cout << "---PRINTING---" << endl;
	string final_string = "";
	for (int i = 0;i < ctx->children.size();i++) {
		cout << ctx->children[i]->getText() << endl;
	}
	cout << "---END PRINTING---" << endl;
	return final_string;
}

//FUNZIONE USATA PER CONVERTIRE UN BooloperatorContext NELLA STRINGA CHE LO RAPPRESENTA
//VIENE UTILIZZATO UN FOR PER LE OPERAZIONI CONCATENATE (a > b && b > c) DA DUE POTREBBERO ESSERE INFINITE
string generateBooleanExpression(swlParser::BooloperatorContext* ctx) {
	string final_string = "";
	//LISTA DI PARENTESI
	/*if (ctx->boolbrackets().size > 2) {
		for (int i = 1;i < ctx->boolbrackets().size();i++) {
			string other_expr = generateComparisonExpression(ctx->comparison(i));
			string bool_operator = convertBooleanOperatorToCppOperator(ctx->operator_list(i - 1)->getText());
			final_string += bool_operator + " " + other_expr + " ";
		}
	}
	//LSITA DI COMPARE SEMPLICI
	if (ctx->comparison().size() > 2) {
		string expr1 = generateComparisonExpression(ctx->comparison(0));
		final_string += expr1 + " ";
		for (int i = 1;i < ctx->comparison().size();i++) {
			string other_expr = generateComparisonExpression(ctx->comparison(i));
			string bool_operator = convertBooleanOperatorToCppOperator(ctx->operator_list(i-1)->getText());
			final_string += bool_operator + " " + other_expr + " ";
		}
		return final_string;
	}
	else if (ctx->comparison().size() == 2) { //SOLO 2 COMPARE SEMPLICI IN TUTTO IL BooloperatorContext
		string expr1 = generateComparisonExpression(ctx->comparison(0));
		string expr2 = generateComparisonExpression(ctx->comparison(1));
		string bool_operator = convertBooleanOperatorToCppOperator(ctx->operator_list(0)->getText());
		return expr1 + " " + bool_operator + " " + expr2;
	}*/
	return final_string;
}

void MyListener::enterIfoperator(swlParser::IfoperatorContext *ctx)
{
	string boolexp = "";
	if (ctx->booloperator() != NULL) {
		//boolexp = generateBooleanExpression(ctx->booloperator());
		boolexp = generateBooleanExpressionNew(ctx->booloperator());
	}
	else {
		if (ctx->comparison() != NULL) {
			boolexp = generateComparisonExpression(ctx->comparison());
		}
	}
	cout << string(indent, ' ') << "if (" << boolexp << ") {" << endl;
	indent += 4;
}

void MyListener::exitIfoperator(swlParser::IfoperatorContext *ctx) {
	indent -= 4;
	cout << string(indent, ' ') << "}" << endl;
}


