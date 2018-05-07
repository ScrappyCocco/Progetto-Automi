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

	/**
	Funzioni IF
	*/
	void enterIfoperator(swlParser::IfoperatorContext *ctx);
	void exitIfoperator(swlParser::IfoperatorContext *ctx);

	/*COSE DA DISCUTERE:
		-COME IMPLEMENTARE IL NOT RISPETTO A COM'E' ORA
		-SE TENERE GLI SPAZI OBBLIGATORI
		-COME SI IMPLEMENTA IF/ELSE
		-DISCUTERE IL CODICE IMPLEMENTATO
		-IMPLEMENTARE LE COSE SOTTO (+ IL WHILE CHE E' COME L'IF GIA' IMPLEMENTATO)
	*/
	//LISTA FUNZIONI PRONTE DA IMPLEMENTARE
	void exitIncrementExpression(swlParser::IncrementExpressionContext *ctx)  { }
	void exitDecrementExpression(swlParser::DecrementExpressionContext *ctx)  { }
	void enterIfelseoperator(swlParser::IfelseoperatorContext *ctx)  { }
	void exitIfelseoperator(swlParser::IfelseoperatorContext *ctx)  { }
};

