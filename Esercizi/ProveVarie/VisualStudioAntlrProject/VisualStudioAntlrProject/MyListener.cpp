// Generated from swl.g4 by ANTLR 4.7
#include <iostream>
#include "MyListener.h"
#include "ParserRuleContext.h"

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

void MyListener::exitIncrementExpression(swlParser::IncrementExpressionContext *ctx)
{
	string name = ctx->ID()->getText();
	cout << string(indent, ' ') << "++" << name << ";" << endl;
}

void MyListener::exitDecrementExpression(swlParser::DecrementExpressionContext *ctx)
{
	string name = ctx->ID()->getText();
	cout << string(indent, ' ') << "--" << name << ";" << endl;
}

//FUNZIONE UTILIZZATA PER CONVERTIRE IL TESTO DELL'OPERATORE IN OPERATORE CPP
string convertBooleanOperatorToCppOperator(string bool_operator) {
	if (bool_operator == "equal") {
		return " == ";
	}
	if (bool_operator == "lower") {
		return " < ";
	}
	if (bool_operator == "greater") {
		return " > ";
	}
	if (bool_operator == "different") {
		return " != ";
	}
	if (bool_operator == "grequal") {
		return " >= ";
	}
	if (bool_operator == "lwequal") {
		return " <= ";
	}
	if (bool_operator == "and") {
		return " && ";
	}
	if (bool_operator == "or") {
		return " || ";
	}
	if (bool_operator == "not") {
		return "!";
	}
}

string generateOperatorList(swlParser::Operator_listContext* ctx) {
	return convertBooleanOperatorToCppOperator(ctx->getText());
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

string generateBooleanExpression(swlParser::BooloperatorContext* ctx) {
	string final_string = "";
	for (int i = 0; i < ctx->getRuleContexts<antlr4::ParserRuleContext>().size(); i++) {
		if (typeid(*ctx->getRuleContexts<antlr4::ParserRuleContext>()[i]) == typeid(swlParser::ComparisonContext)) {
			final_string += generateComparisonExpression(static_cast<swlParser::ComparisonContext*>(ctx->getRuleContexts<antlr4::ParserRuleContext>()[i]));
		}
		if (typeid(*ctx->getRuleContexts<antlr4::ParserRuleContext>()[i]) == typeid(swlParser::BooloperatorContext)) {
			final_string += generateBooleanExpression(static_cast<swlParser::BooloperatorContext*>(ctx->getRuleContexts<antlr4::ParserRuleContext>()[i]));
		}
		if (typeid(*ctx->getRuleContexts<antlr4::ParserRuleContext>()[i]) == typeid(swlParser::BoolbracketsContext)) {
			final_string += generateBracketsBooleanExpression(static_cast<swlParser::BoolbracketsContext*>(ctx->getRuleContexts<antlr4::ParserRuleContext>()[i]));
		}
		if (typeid(*ctx->getRuleContexts<antlr4::ParserRuleContext>()[i]) == typeid(swlParser::Operator_listContext)) {
			final_string += generateOperatorList(static_cast<swlParser::Operator_listContext*>(ctx->getRuleContexts<antlr4::ParserRuleContext>()[i]));
		}
	}
	return final_string;
}

void MyListener::enterIfoperator(swlParser::IfoperatorContext *ctx)
{
	string boolexp = "";
	if (ctx->booloperator() != NULL) {
		boolexp = generateBooleanExpression(ctx->booloperator());
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

void MyListener::enterIfelseoperator(swlParser::IfelseoperatorContext *ctx)
{
	string boolexp = "";
	if (ctx->booloperator() != NULL) {
		boolexp = generateBooleanExpression(ctx->booloperator());
	}
	else {
		if (ctx->comparison() != NULL) {
			boolexp = generateComparisonExpression(ctx->comparison());
		}
	}
	cout << string(indent, ' ') << "if (" << boolexp << ") {" << endl;
	indent += 4;
}

void MyListener::exitElse_word(swlParser::Else_wordContext *ctx)
{
	indent -= 4;
	cout << string(indent, ' ') << "} else {" << endl;
	indent += 4;
}

void MyListener::exitIfelseoperator(swlParser::IfelseoperatorContext *ctx)
{
	indent -= 4;
	cout << string(indent, ' ') << "}" << endl;
}

void MyListener::enterWhilecycle(swlParser::WhilecycleContext *ctx)
{
	string boolexp = "";
	if (ctx->booloperator() != NULL) {
		boolexp = generateBooleanExpression(ctx->booloperator());
	}
	else {
		if (ctx->comparison() != NULL) {
			boolexp = generateComparisonExpression(ctx->comparison());
		}
	}
	cout << string(indent, ' ') << "while (" << boolexp << ") {" << endl;
	indent += 4;
}

void MyListener::exitWhilecycle(swlParser::WhilecycleContext *ctx)
{
	indent -= 4;
	cout << string(indent, ' ') << "}" << endl;
}

void MyListener::enterDowhilecycle(swlParser::DowhilecycleContext *ctx)
{
	cout << string(indent, ' ') << "do {" << endl;
	indent += 4;
}

void MyListener::exitDowhilecycle(swlParser::DowhilecycleContext *ctx)
{
	string boolexp = "";
	if (ctx->booloperator() != NULL) {
		boolexp = generateBooleanExpression(ctx->booloperator());
	}
	else {
		if (ctx->comparison() != NULL) {
			boolexp = generateComparisonExpression(ctx->comparison());
		}
	}
	indent -= 4;
	cout << string(indent, ' ') << "} while (" << boolexp << ");" << endl;
	
}

void MyListener::enterForcycle(swlParser::ForcycleContext *ctx)
{
	string name = ctx->ID()->getText();
	string number1 = ctx->NUMBER(0)->getText();
	string number2 = ctx->NUMBER(1)->getText();
	string nameString = name;
	string cond = "";
	if (number1 > number2)
	{
		nameString = "--" + nameString;
		cond = name + " > " + number2;
	}
	else
	{
		nameString = "++" + nameString;
		cond = name + " < " + number2;
	}
	cout << string(indent, ' ') << "for (int " + name + " = " + number1 + "; " 
		+ cond + "; " + nameString << ") {" << endl;
	indent += 4;
}
void MyListener::exitForcycle(swlParser::ForcycleContext *ctx)
{
	indent -= 4;
	cout << string(indent, ' ') << "}" << endl;
}

void MyListener::enterFunction(swlParser::FunctionContext *ctx)
{
	cout << "lol" << endl;
	indent += 4;
	string finalString = ctx->ID->getText() + "(";
	for (int i = 0; i < ctx->ID().size(); i++)
	{
		if (i < ctx->ID.size() - 1)
		{
			finalString += ctx->ID(i)->getText() + ",";
		}
		else
		{
			finalString += ctx->ID(i)->getText();
		}
	}
	finalString += ")";
	cout << finalString << "{" << endl;

}
void MyListener::exitFunction(swlParser::FunctionContext *ctx)
{
	indent -= 4;
	cout << "}" << endl;
}
