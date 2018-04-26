
// Generated from .\VisualStudioAntlrProject\VisualStudioAntlrProject\swl.g4 by ANTLR 4.7.1


#include "swlListener.h"

#include "swlParser.h"


using namespace antlrcpp;
using namespace antlr4;

swlParser::swlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

swlParser::~swlParser() {
  delete _interpreter;
}

std::string swlParser::getGrammarFileName() const {
  return "swl.g4";
}

const std::vector<std::string>& swlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& swlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

swlParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<swlParser::StatementContext *> swlParser::ProgramContext::statement() {
  return getRuleContexts<swlParser::StatementContext>();
}

swlParser::StatementContext* swlParser::ProgramContext::statement(size_t i) {
  return getRuleContext<swlParser::StatementContext>(i);
}


size_t swlParser::ProgramContext::getRuleIndex() const {
  return swlParser::RuleProgram;
}

void swlParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void swlParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

swlParser::ProgramContext* swlParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, swlParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(10);
    match(swlParser::T__0);
    setState(12); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(11);
      statement();
      setState(14); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << swlParser::T__2)
      | (1ULL << swlParser::T__4)
      | (1ULL << swlParser::T__5))) != 0));
    setState(16);
    match(swlParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

swlParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

swlParser::AssignContext* swlParser::StatementContext::assign() {
  return getRuleContext<swlParser::AssignContext>(0);
}

swlParser::AddContext* swlParser::StatementContext::add() {
  return getRuleContext<swlParser::AddContext>(0);
}

swlParser::PrintContext* swlParser::StatementContext::print() {
  return getRuleContext<swlParser::PrintContext>(0);
}


size_t swlParser::StatementContext::getRuleIndex() const {
  return swlParser::RuleStatement;
}

void swlParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void swlParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

swlParser::StatementContext* swlParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 2, swlParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(21);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case swlParser::T__2: {
        enterOuterAlt(_localctx, 1);
        setState(18);
        assign();
        break;
      }

      case swlParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(19);
        add();
        break;
      }

      case swlParser::T__4: {
        enterOuterAlt(_localctx, 3);
        setState(20);
        print();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

swlParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> swlParser::AssignContext::ID() {
  return getTokens(swlParser::ID);
}

tree::TerminalNode* swlParser::AssignContext::ID(size_t i) {
  return getToken(swlParser::ID, i);
}

tree::TerminalNode* swlParser::AssignContext::NUMBER() {
  return getToken(swlParser::NUMBER, 0);
}


size_t swlParser::AssignContext::getRuleIndex() const {
  return swlParser::RuleAssign;
}

void swlParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void swlParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

swlParser::AssignContext* swlParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 4, swlParser::RuleAssign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(23);
    match(swlParser::T__2);
    setState(24);
    match(swlParser::ID);
    setState(25);
    match(swlParser::T__3);
    setState(26);
    _la = _input->LA(1);
    if (!(_la == swlParser::ID

    || _la == swlParser::NUMBER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

swlParser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* swlParser::PrintContext::NUMBER() {
  return getToken(swlParser::NUMBER, 0);
}

tree::TerminalNode* swlParser::PrintContext::ID() {
  return getToken(swlParser::ID, 0);
}


size_t swlParser::PrintContext::getRuleIndex() const {
  return swlParser::RulePrint;
}

void swlParser::PrintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrint(this);
}

void swlParser::PrintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrint(this);
}

swlParser::PrintContext* swlParser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 6, swlParser::RulePrint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(swlParser::T__4);
    setState(29);
    _la = _input->LA(1);
    if (!(_la == swlParser::ID

    || _la == swlParser::NUMBER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddContext ------------------------------------------------------------------

swlParser::AddContext::AddContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> swlParser::AddContext::ID() {
  return getTokens(swlParser::ID);
}

tree::TerminalNode* swlParser::AddContext::ID(size_t i) {
  return getToken(swlParser::ID, i);
}

tree::TerminalNode* swlParser::AddContext::NUMBER() {
  return getToken(swlParser::NUMBER, 0);
}


size_t swlParser::AddContext::getRuleIndex() const {
  return swlParser::RuleAdd;
}

void swlParser::AddContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd(this);
}

void swlParser::AddContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<swlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd(this);
}

swlParser::AddContext* swlParser::add() {
  AddContext *_localctx = _tracker.createInstance<AddContext>(_ctx, getState());
  enterRule(_localctx, 8, swlParser::RuleAdd);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(31);
    match(swlParser::T__5);
    setState(32);
    _la = _input->LA(1);
    if (!(_la == swlParser::ID

    || _la == swlParser::NUMBER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(33);
    match(swlParser::T__6);
    setState(34);
    match(swlParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> swlParser::_decisionToDFA;
atn::PredictionContextCache swlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN swlParser::_atn;
std::vector<uint16_t> swlParser::_serializedATN;

std::vector<std::string> swlParser::_ruleNames = {
  "program", "statement", "assign", "print", "add"
};

std::vector<std::string> swlParser::_literalNames = {
  "", "'begin'", "'end'", "'let'", "'be'", "'print'", "'add'", "'to'"
};

std::vector<std::string> swlParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "ID", "NUMBER", "WS", "ErrorChar"
};

dfa::Vocabulary swlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> swlParser::_tokenNames;

swlParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xd, 0x27, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x3, 0x2, 0x3, 0x2, 0x6, 
    0x2, 0xf, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x10, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x18, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x2, 0x2, 0x7, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0x2, 0x3, 0x3, 0x2, 0xa, 0xb, 0x2, 0x24, 0x2, 0xc, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x1e, 0x3, 0x2, 0x2, 0x2, 0xa, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0xe, 0x7, 0x3, 0x2, 0x2, 0xd, 0xf, 0x5, 0x4, 0x3, 0x2, 0xe, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0xf, 0x10, 0x3, 0x2, 0x2, 0x2, 0x10, 0xe, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x11, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x13, 0x7, 0x4, 0x2, 0x2, 0x13, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x14, 0x18, 0x5, 0x6, 0x4, 0x2, 0x15, 0x18, 0x5, 0xa, 0x6, 0x2, 0x16, 
    0x18, 0x5, 0x8, 0x5, 0x2, 0x17, 0x14, 0x3, 0x2, 0x2, 0x2, 0x17, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x5, 0x2, 0x2, 0x1a, 0x1b, 0x7, 0xa, 
    0x2, 0x2, 0x1b, 0x1c, 0x7, 0x6, 0x2, 0x2, 0x1c, 0x1d, 0x9, 0x2, 0x2, 
    0x2, 0x1d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x7, 0x2, 0x2, 
    0x1f, 0x20, 0x9, 0x2, 0x2, 0x2, 0x20, 0x9, 0x3, 0x2, 0x2, 0x2, 0x21, 
    0x22, 0x7, 0x8, 0x2, 0x2, 0x22, 0x23, 0x9, 0x2, 0x2, 0x2, 0x23, 0x24, 
    0x7, 0x9, 0x2, 0x2, 0x24, 0x25, 0x7, 0xa, 0x2, 0x2, 0x25, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x10, 0x17, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

swlParser::Initializer swlParser::_init;
