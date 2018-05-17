#pragma once

#include <iostream>
#include "antlr4-runtime.h"
#include "swlParser.h"
#include "swlBaseListener.h"


/**
* This class defines a concrete listener for a parse tree produced by swlParser.
*/
class  MyListener : public swlBaseListener {
private:
	int indent = 0;
	
public:
	/**
	Funzioni di gestione inizio e fine programma
	*/
	void enterProgram(swlParser::ProgramContext *ctx);
	void exitProgram(swlParser::ProgramContext *ctx);

	/**
	Funzione di assegnazione
	*/
	void exitAssign(swlParser::AssignContext *ctx);

	/**
	Funzione di stampa
	*/
	void exitPrint(swlParser::PrintContext *ctx);

	/**
	Funzioni matematiche
	*/
	void exitAdd(swlParser::AddContext *ctx);
	void exitSub(swlParser::SubContext *ctx);
	void exitMul(swlParser::MulContext *ctx);
	void exitDiv(swlParser::DivContext *ctx);
	void exitIncrementExpression(swlParser::IncrementExpressionContext *ctx);
	void exitDecrementExpression(swlParser::DecrementExpressionContext *ctx);

	/**
	Funzioni IF
	*/
	void enterIfoperator(swlParser::IfoperatorContext *ctx);
	void exitIfoperator(swlParser::IfoperatorContext *ctx);
	void enterIfelseoperator(swlParser::IfelseoperatorContext *ctx);
	void exitIfelseoperator(swlParser::IfelseoperatorContext *ctx);
	void exitElse_word(swlParser::Else_wordContext *ctx);

	/**
	Cicli
	*/
	void enterForcycle(swlParser::ForcycleContext *ctx);
	void exitForcycle(swlParser::ForcycleContext *ctx);
	void enterDowhilecycle(swlParser::DowhilecycleContext *ctx);
	void exitDowhilecycle(swlParser::DowhilecycleContext *ctx);
	void enterWhilecycle(swlParser::WhilecycleContext *ctx);
	void exitWhilecycle(swlParser::WhilecycleContext *ctx);

	/**
	Funzioni
	*/

	void enterFunction(swlParser::FunctionContext *ctx);
	void exitFunction(swlParser::FunctionContext *ctx);
	
	/*TODO
	-Il not boolbrackets? Avrebbe senso
	-Discutere se il codice presente ha senso o se si poteva fare in tutt'altro modo
	*/
};

