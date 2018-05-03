#pragma once

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

  void enterProgram(swlParser::ProgramContext *ctx);
  void exitProgram(swlParser::ProgramContext *ctx);

  void exitAssign(swlParser::AssignContext *ctx);

  void exitPrint(swlParser::PrintContext *ctx);

  void exitAdd(swlParser::AddContext *ctx);

void exitMeno(swlParser::MenoContext *ctx);


void enterIfoperator(swlParser::IfoperatorContext *ctx);
void exitIfoperator(swlParser::IfoperatorContext *ctx);

};

