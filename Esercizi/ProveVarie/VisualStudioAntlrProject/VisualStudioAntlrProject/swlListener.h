
// Generated from .\VisualStudioAntlrProject\VisualStudioAntlrProject\swl.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "swlParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by swlParser.
 */
class  swlListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(swlParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(swlParser::ProgramContext *ctx) = 0;

  virtual void enterStatement(swlParser::StatementContext *ctx) = 0;
  virtual void exitStatement(swlParser::StatementContext *ctx) = 0;

  virtual void enterAssign(swlParser::AssignContext *ctx) = 0;
  virtual void exitAssign(swlParser::AssignContext *ctx) = 0;

  virtual void enterPrint(swlParser::PrintContext *ctx) = 0;
  virtual void exitPrint(swlParser::PrintContext *ctx) = 0;

  virtual void enterAdd(swlParser::AddContext *ctx) = 0;
  virtual void exitAdd(swlParser::AddContext *ctx) = 0;


};

