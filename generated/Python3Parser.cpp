
// Generated from .\Python3.g4 by ANTLR 4.7.2


#include "Python3Listener.h"

#include "Python3Parser.h"


using namespace antlrcpp;
using namespace antlr4;

Python3Parser::Python3Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

Python3Parser::~Python3Parser() {
  delete _interpreter;
}

std::string Python3Parser::getGrammarFileName() const {
  return "Python3.g4";
}

const std::vector<std::string>& Python3Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& Python3Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- File_inputContext ------------------------------------------------------------------

Python3Parser::File_inputContext::File_inputContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::File_inputContext::EOF() {
  return getToken(Python3Parser::EOF, 0);
}

std::vector<tree::TerminalNode *> Python3Parser::File_inputContext::NEWLINE() {
  return getTokens(Python3Parser::NEWLINE);
}

tree::TerminalNode* Python3Parser::File_inputContext::NEWLINE(size_t i) {
  return getToken(Python3Parser::NEWLINE, i);
}

std::vector<Python3Parser::StmtContext *> Python3Parser::File_inputContext::stmt() {
  return getRuleContexts<Python3Parser::StmtContext>();
}

Python3Parser::StmtContext* Python3Parser::File_inputContext::stmt(size_t i) {
  return getRuleContext<Python3Parser::StmtContext>(i);
}


size_t Python3Parser::File_inputContext::getRuleIndex() const {
  return Python3Parser::RuleFile_input;
}

void Python3Parser::File_inputContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile_input(this);
}

void Python3Parser::File_inputContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile_input(this);
}

Python3Parser::File_inputContext* Python3Parser::file_input() {
  File_inputContext *_localctx = _tracker.createInstance<File_inputContext>(_ctx, getState());
  enterRule(_localctx, 0, Python3Parser::RuleFile_input);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Python3Parser::STRING)
      | (1ULL << Python3Parser::NUMBER)
      | (1ULL << Python3Parser::DEF)
      | (1ULL << Python3Parser::RETURN)
      | (1ULL << Python3Parser::IF)
      | (1ULL << Python3Parser::WHILE)
      | (1ULL << Python3Parser::FOR)
      | (1ULL << Python3Parser::NOT)
      | (1ULL << Python3Parser::NONE)
      | (1ULL << Python3Parser::TRUE)
      | (1ULL << Python3Parser::FALSE)
      | (1ULL << Python3Parser::CONTINUE)
      | (1ULL << Python3Parser::BREAK)
      | (1ULL << Python3Parser::NEWLINE)
      | (1ULL << Python3Parser::NAME)
      | (1ULL << Python3Parser::ADD)
      | (1ULL << Python3Parser::MINUS)
      | (1ULL << Python3Parser::NOT_OP))) != 0)) {
      setState(74);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case Python3Parser::NEWLINE: {
          setState(72);
          match(Python3Parser::NEWLINE);
          break;
        }

        case Python3Parser::STRING:
        case Python3Parser::NUMBER:
        case Python3Parser::DEF:
        case Python3Parser::RETURN:
        case Python3Parser::IF:
        case Python3Parser::WHILE:
        case Python3Parser::FOR:
        case Python3Parser::NOT:
        case Python3Parser::NONE:
        case Python3Parser::TRUE:
        case Python3Parser::FALSE:
        case Python3Parser::CONTINUE:
        case Python3Parser::BREAK:
        case Python3Parser::NAME:
        case Python3Parser::ADD:
        case Python3Parser::MINUS:
        case Python3Parser::NOT_OP: {
          setState(73);
          stmt();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(78);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(79);
    match(Python3Parser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncdefContext ------------------------------------------------------------------

Python3Parser::FuncdefContext::FuncdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::FuncdefContext::DEF() {
  return getToken(Python3Parser::DEF, 0);
}

tree::TerminalNode* Python3Parser::FuncdefContext::NAME() {
  return getToken(Python3Parser::NAME, 0);
}

Python3Parser::ParametersContext* Python3Parser::FuncdefContext::parameters() {
  return getRuleContext<Python3Parser::ParametersContext>(0);
}

tree::TerminalNode* Python3Parser::FuncdefContext::COLON() {
  return getToken(Python3Parser::COLON, 0);
}

Python3Parser::SuiteContext* Python3Parser::FuncdefContext::suite() {
  return getRuleContext<Python3Parser::SuiteContext>(0);
}


size_t Python3Parser::FuncdefContext::getRuleIndex() const {
  return Python3Parser::RuleFuncdef;
}

void Python3Parser::FuncdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncdef(this);
}

void Python3Parser::FuncdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncdef(this);
}

Python3Parser::FuncdefContext* Python3Parser::funcdef() {
  FuncdefContext *_localctx = _tracker.createInstance<FuncdefContext>(_ctx, getState());
  enterRule(_localctx, 2, Python3Parser::RuleFuncdef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(81);
    match(Python3Parser::DEF);
    setState(82);
    match(Python3Parser::NAME);
    setState(83);
    parameters();
    setState(84);
    match(Python3Parser::COLON);
    setState(85);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

Python3Parser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::ParametersContext::OPEN_PAREN() {
  return getToken(Python3Parser::OPEN_PAREN, 0);
}

tree::TerminalNode* Python3Parser::ParametersContext::CLOSE_PAREN() {
  return getToken(Python3Parser::CLOSE_PAREN, 0);
}

Python3Parser::TypedargslistContext* Python3Parser::ParametersContext::typedargslist() {
  return getRuleContext<Python3Parser::TypedargslistContext>(0);
}


size_t Python3Parser::ParametersContext::getRuleIndex() const {
  return Python3Parser::RuleParameters;
}

void Python3Parser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void Python3Parser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}

Python3Parser::ParametersContext* Python3Parser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 4, Python3Parser::RuleParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(Python3Parser::OPEN_PAREN);
    setState(89);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Python3Parser::NAME)
      | (1ULL << Python3Parser::STAR)
      | (1ULL << Python3Parser::POWER))) != 0)) {
      setState(88);
      typedargslist();
    }
    setState(91);
    match(Python3Parser::CLOSE_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedargslistContext ------------------------------------------------------------------

Python3Parser::TypedargslistContext::TypedargslistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::TfpdefContext *> Python3Parser::TypedargslistContext::tfpdef() {
  return getRuleContexts<Python3Parser::TfpdefContext>();
}

Python3Parser::TfpdefContext* Python3Parser::TypedargslistContext::tfpdef(size_t i) {
  return getRuleContext<Python3Parser::TfpdefContext>(i);
}

tree::TerminalNode* Python3Parser::TypedargslistContext::STAR() {
  return getToken(Python3Parser::STAR, 0);
}

tree::TerminalNode* Python3Parser::TypedargslistContext::POWER() {
  return getToken(Python3Parser::POWER, 0);
}

std::vector<tree::TerminalNode *> Python3Parser::TypedargslistContext::ASSIGN() {
  return getTokens(Python3Parser::ASSIGN);
}

tree::TerminalNode* Python3Parser::TypedargslistContext::ASSIGN(size_t i) {
  return getToken(Python3Parser::ASSIGN, i);
}

std::vector<Python3Parser::TestContext *> Python3Parser::TypedargslistContext::test() {
  return getRuleContexts<Python3Parser::TestContext>();
}

Python3Parser::TestContext* Python3Parser::TypedargslistContext::test(size_t i) {
  return getRuleContext<Python3Parser::TestContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::TypedargslistContext::COMMA() {
  return getTokens(Python3Parser::COMMA);
}

tree::TerminalNode* Python3Parser::TypedargslistContext::COMMA(size_t i) {
  return getToken(Python3Parser::COMMA, i);
}


size_t Python3Parser::TypedargslistContext::getRuleIndex() const {
  return Python3Parser::RuleTypedargslist;
}

void Python3Parser::TypedargslistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedargslist(this);
}

void Python3Parser::TypedargslistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedargslist(this);
}

Python3Parser::TypedargslistContext* Python3Parser::typedargslist() {
  TypedargslistContext *_localctx = _tracker.createInstance<TypedargslistContext>(_ctx, getState());
  enterRule(_localctx, 6, Python3Parser::RuleTypedargslist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(174);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::NAME: {
        setState(93);
        tfpdef();
        setState(96);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Python3Parser::ASSIGN) {
          setState(94);
          match(Python3Parser::ASSIGN);
          setState(95);
          test();
        }
        setState(106);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(98);
            match(Python3Parser::COMMA);
            setState(99);
            tfpdef();
            setState(102);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == Python3Parser::ASSIGN) {
              setState(100);
              match(Python3Parser::ASSIGN);
              setState(101);
              test();
            } 
          }
          setState(108);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
        }
        setState(142);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Python3Parser::COMMA) {
          setState(109);
          match(Python3Parser::COMMA);
          setState(140);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case Python3Parser::STAR: {
              setState(110);
              match(Python3Parser::STAR);
              setState(112);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == Python3Parser::NAME) {
                setState(111);
                tfpdef();
              }
              setState(122);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
              while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                if (alt == 1) {
                  setState(114);
                  match(Python3Parser::COMMA);
                  setState(115);
                  tfpdef();
                  setState(118);
                  _errHandler->sync(this);

                  _la = _input->LA(1);
                  if (_la == Python3Parser::ASSIGN) {
                    setState(116);
                    match(Python3Parser::ASSIGN);
                    setState(117);
                    test();
                  } 
                }
                setState(124);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
              }
              setState(133);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == Python3Parser::COMMA) {
                setState(125);
                match(Python3Parser::COMMA);
                setState(131);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == Python3Parser::POWER) {
                  setState(126);
                  match(Python3Parser::POWER);
                  setState(127);
                  tfpdef();
                  setState(129);
                  _errHandler->sync(this);

                  _la = _input->LA(1);
                  if (_la == Python3Parser::COMMA) {
                    setState(128);
                    match(Python3Parser::COMMA);
                  }
                }
              }
              break;
            }

            case Python3Parser::POWER: {
              setState(135);
              match(Python3Parser::POWER);
              setState(136);
              tfpdef();
              setState(138);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == Python3Parser::COMMA) {
                setState(137);
                match(Python3Parser::COMMA);
              }
              break;
            }

            case Python3Parser::CLOSE_PAREN: {
              break;
            }

          default:
            break;
          }
        }
        break;
      }

      case Python3Parser::STAR: {
        setState(144);
        match(Python3Parser::STAR);
        setState(146);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Python3Parser::NAME) {
          setState(145);
          tfpdef();
        }
        setState(156);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(148);
            match(Python3Parser::COMMA);
            setState(149);
            tfpdef();
            setState(152);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == Python3Parser::ASSIGN) {
              setState(150);
              match(Python3Parser::ASSIGN);
              setState(151);
              test();
            } 
          }
          setState(158);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
        }
        setState(167);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Python3Parser::COMMA) {
          setState(159);
          match(Python3Parser::COMMA);
          setState(165);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == Python3Parser::POWER) {
            setState(160);
            match(Python3Parser::POWER);
            setState(161);
            tfpdef();
            setState(163);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == Python3Parser::COMMA) {
              setState(162);
              match(Python3Parser::COMMA);
            }
          }
        }
        break;
      }

      case Python3Parser::POWER: {
        setState(169);
        match(Python3Parser::POWER);
        setState(170);
        tfpdef();
        setState(172);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == Python3Parser::COMMA) {
          setState(171);
          match(Python3Parser::COMMA);
        }
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

//----------------- TfpdefContext ------------------------------------------------------------------

Python3Parser::TfpdefContext::TfpdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::TfpdefContext::NAME() {
  return getToken(Python3Parser::NAME, 0);
}

tree::TerminalNode* Python3Parser::TfpdefContext::COLON() {
  return getToken(Python3Parser::COLON, 0);
}

Python3Parser::TestContext* Python3Parser::TfpdefContext::test() {
  return getRuleContext<Python3Parser::TestContext>(0);
}


size_t Python3Parser::TfpdefContext::getRuleIndex() const {
  return Python3Parser::RuleTfpdef;
}

void Python3Parser::TfpdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTfpdef(this);
}

void Python3Parser::TfpdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTfpdef(this);
}

Python3Parser::TfpdefContext* Python3Parser::tfpdef() {
  TfpdefContext *_localctx = _tracker.createInstance<TfpdefContext>(_ctx, getState());
  enterRule(_localctx, 8, Python3Parser::RuleTfpdef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
    match(Python3Parser::NAME);
    setState(179);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Python3Parser::COLON) {
      setState(177);
      match(Python3Parser::COLON);
      setState(178);
      test();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

Python3Parser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Python3Parser::Simple_stmtContext* Python3Parser::StmtContext::simple_stmt() {
  return getRuleContext<Python3Parser::Simple_stmtContext>(0);
}

Python3Parser::Compound_stmtContext* Python3Parser::StmtContext::compound_stmt() {
  return getRuleContext<Python3Parser::Compound_stmtContext>(0);
}


size_t Python3Parser::StmtContext::getRuleIndex() const {
  return Python3Parser::RuleStmt;
}

void Python3Parser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void Python3Parser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

Python3Parser::StmtContext* Python3Parser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 10, Python3Parser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::STRING:
      case Python3Parser::NUMBER:
      case Python3Parser::RETURN:
      case Python3Parser::NOT:
      case Python3Parser::NONE:
      case Python3Parser::TRUE:
      case Python3Parser::FALSE:
      case Python3Parser::CONTINUE:
      case Python3Parser::BREAK:
      case Python3Parser::NAME:
      case Python3Parser::ADD:
      case Python3Parser::MINUS:
      case Python3Parser::NOT_OP: {
        enterOuterAlt(_localctx, 1);
        setState(181);
        simple_stmt();
        break;
      }

      case Python3Parser::DEF:
      case Python3Parser::IF:
      case Python3Parser::WHILE:
      case Python3Parser::FOR: {
        enterOuterAlt(_localctx, 2);
        setState(182);
        compound_stmt();
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

//----------------- Simple_stmtContext ------------------------------------------------------------------

Python3Parser::Simple_stmtContext::Simple_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Python3Parser::Small_stmtContext* Python3Parser::Simple_stmtContext::small_stmt() {
  return getRuleContext<Python3Parser::Small_stmtContext>(0);
}

tree::TerminalNode* Python3Parser::Simple_stmtContext::NEWLINE() {
  return getToken(Python3Parser::NEWLINE, 0);
}


size_t Python3Parser::Simple_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleSimple_stmt;
}

void Python3Parser::Simple_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_stmt(this);
}

void Python3Parser::Simple_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_stmt(this);
}

Python3Parser::Simple_stmtContext* Python3Parser::simple_stmt() {
  Simple_stmtContext *_localctx = _tracker.createInstance<Simple_stmtContext>(_ctx, getState());
  enterRule(_localctx, 12, Python3Parser::RuleSimple_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    small_stmt();
    setState(186);
    match(Python3Parser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Small_stmtContext ------------------------------------------------------------------

Python3Parser::Small_stmtContext::Small_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Python3Parser::Expr_stmtContext* Python3Parser::Small_stmtContext::expr_stmt() {
  return getRuleContext<Python3Parser::Expr_stmtContext>(0);
}

Python3Parser::Flow_stmtContext* Python3Parser::Small_stmtContext::flow_stmt() {
  return getRuleContext<Python3Parser::Flow_stmtContext>(0);
}


size_t Python3Parser::Small_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleSmall_stmt;
}

void Python3Parser::Small_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSmall_stmt(this);
}

void Python3Parser::Small_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSmall_stmt(this);
}

Python3Parser::Small_stmtContext* Python3Parser::small_stmt() {
  Small_stmtContext *_localctx = _tracker.createInstance<Small_stmtContext>(_ctx, getState());
  enterRule(_localctx, 14, Python3Parser::RuleSmall_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(190);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::STRING:
      case Python3Parser::NUMBER:
      case Python3Parser::NOT:
      case Python3Parser::NONE:
      case Python3Parser::TRUE:
      case Python3Parser::FALSE:
      case Python3Parser::NAME:
      case Python3Parser::ADD:
      case Python3Parser::MINUS:
      case Python3Parser::NOT_OP: {
        enterOuterAlt(_localctx, 1);
        setState(188);
        expr_stmt();
        break;
      }

      case Python3Parser::RETURN:
      case Python3Parser::CONTINUE:
      case Python3Parser::BREAK: {
        enterOuterAlt(_localctx, 2);
        setState(189);
        flow_stmt();
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

//----------------- Expr_stmtContext ------------------------------------------------------------------

Python3Parser::Expr_stmtContext::Expr_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::TestlistContext *> Python3Parser::Expr_stmtContext::testlist() {
  return getRuleContexts<Python3Parser::TestlistContext>();
}

Python3Parser::TestlistContext* Python3Parser::Expr_stmtContext::testlist(size_t i) {
  return getRuleContext<Python3Parser::TestlistContext>(i);
}

Python3Parser::AugassignContext* Python3Parser::Expr_stmtContext::augassign() {
  return getRuleContext<Python3Parser::AugassignContext>(0);
}

std::vector<tree::TerminalNode *> Python3Parser::Expr_stmtContext::ASSIGN() {
  return getTokens(Python3Parser::ASSIGN);
}

tree::TerminalNode* Python3Parser::Expr_stmtContext::ASSIGN(size_t i) {
  return getToken(Python3Parser::ASSIGN, i);
}


size_t Python3Parser::Expr_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleExpr_stmt;
}

void Python3Parser::Expr_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_stmt(this);
}

void Python3Parser::Expr_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_stmt(this);
}

Python3Parser::Expr_stmtContext* Python3Parser::expr_stmt() {
  Expr_stmtContext *_localctx = _tracker.createInstance<Expr_stmtContext>(_ctx, getState());
  enterRule(_localctx, 16, Python3Parser::RuleExpr_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    testlist();
    setState(203);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::ADD_ASSIGN:
      case Python3Parser::SUB_ASSIGN:
      case Python3Parser::MULT_ASSIGN:
      case Python3Parser::AT_ASSIGN:
      case Python3Parser::DIV_ASSIGN:
      case Python3Parser::MOD_ASSIGN:
      case Python3Parser::AND_ASSIGN:
      case Python3Parser::OR_ASSIGN:
      case Python3Parser::XOR_ASSIGN:
      case Python3Parser::LEFT_SHIFT_ASSIGN:
      case Python3Parser::RIGHT_SHIFT_ASSIGN:
      case Python3Parser::POWER_ASSIGN:
      case Python3Parser::IDIV_ASSIGN: {
        setState(193);
        augassign();
        setState(194);
        testlist();
        break;
      }

      case Python3Parser::NEWLINE:
      case Python3Parser::ASSIGN: {
        setState(200);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == Python3Parser::ASSIGN) {
          setState(196);
          match(Python3Parser::ASSIGN);
          setState(197);
          testlist();
          setState(202);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
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

//----------------- AugassignContext ------------------------------------------------------------------

Python3Parser::AugassignContext::AugassignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::AugassignContext::ADD_ASSIGN() {
  return getToken(Python3Parser::ADD_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::SUB_ASSIGN() {
  return getToken(Python3Parser::SUB_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::MULT_ASSIGN() {
  return getToken(Python3Parser::MULT_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::AT_ASSIGN() {
  return getToken(Python3Parser::AT_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::DIV_ASSIGN() {
  return getToken(Python3Parser::DIV_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::MOD_ASSIGN() {
  return getToken(Python3Parser::MOD_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::AND_ASSIGN() {
  return getToken(Python3Parser::AND_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::OR_ASSIGN() {
  return getToken(Python3Parser::OR_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::XOR_ASSIGN() {
  return getToken(Python3Parser::XOR_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::LEFT_SHIFT_ASSIGN() {
  return getToken(Python3Parser::LEFT_SHIFT_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::RIGHT_SHIFT_ASSIGN() {
  return getToken(Python3Parser::RIGHT_SHIFT_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::POWER_ASSIGN() {
  return getToken(Python3Parser::POWER_ASSIGN, 0);
}

tree::TerminalNode* Python3Parser::AugassignContext::IDIV_ASSIGN() {
  return getToken(Python3Parser::IDIV_ASSIGN, 0);
}


size_t Python3Parser::AugassignContext::getRuleIndex() const {
  return Python3Parser::RuleAugassign;
}

void Python3Parser::AugassignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAugassign(this);
}

void Python3Parser::AugassignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAugassign(this);
}

Python3Parser::AugassignContext* Python3Parser::augassign() {
  AugassignContext *_localctx = _tracker.createInstance<AugassignContext>(_ctx, getState());
  enterRule(_localctx, 18, Python3Parser::RuleAugassign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    _la = _input->LA(1);
    if (!(((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (Python3Parser::ADD_ASSIGN - 64))
      | (1ULL << (Python3Parser::SUB_ASSIGN - 64))
      | (1ULL << (Python3Parser::MULT_ASSIGN - 64))
      | (1ULL << (Python3Parser::AT_ASSIGN - 64))
      | (1ULL << (Python3Parser::DIV_ASSIGN - 64))
      | (1ULL << (Python3Parser::MOD_ASSIGN - 64))
      | (1ULL << (Python3Parser::AND_ASSIGN - 64))
      | (1ULL << (Python3Parser::OR_ASSIGN - 64))
      | (1ULL << (Python3Parser::XOR_ASSIGN - 64))
      | (1ULL << (Python3Parser::LEFT_SHIFT_ASSIGN - 64))
      | (1ULL << (Python3Parser::RIGHT_SHIFT_ASSIGN - 64))
      | (1ULL << (Python3Parser::POWER_ASSIGN - 64))
      | (1ULL << (Python3Parser::IDIV_ASSIGN - 64)))) != 0))) {
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

//----------------- Flow_stmtContext ------------------------------------------------------------------

Python3Parser::Flow_stmtContext::Flow_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Python3Parser::Break_stmtContext* Python3Parser::Flow_stmtContext::break_stmt() {
  return getRuleContext<Python3Parser::Break_stmtContext>(0);
}

Python3Parser::Continue_stmtContext* Python3Parser::Flow_stmtContext::continue_stmt() {
  return getRuleContext<Python3Parser::Continue_stmtContext>(0);
}

Python3Parser::Return_stmtContext* Python3Parser::Flow_stmtContext::return_stmt() {
  return getRuleContext<Python3Parser::Return_stmtContext>(0);
}


size_t Python3Parser::Flow_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleFlow_stmt;
}

void Python3Parser::Flow_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFlow_stmt(this);
}

void Python3Parser::Flow_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFlow_stmt(this);
}

Python3Parser::Flow_stmtContext* Python3Parser::flow_stmt() {
  Flow_stmtContext *_localctx = _tracker.createInstance<Flow_stmtContext>(_ctx, getState());
  enterRule(_localctx, 20, Python3Parser::RuleFlow_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(210);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::BREAK: {
        enterOuterAlt(_localctx, 1);
        setState(207);
        break_stmt();
        break;
      }

      case Python3Parser::CONTINUE: {
        enterOuterAlt(_localctx, 2);
        setState(208);
        continue_stmt();
        break;
      }

      case Python3Parser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(209);
        return_stmt();
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

//----------------- Break_stmtContext ------------------------------------------------------------------

Python3Parser::Break_stmtContext::Break_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::Break_stmtContext::BREAK() {
  return getToken(Python3Parser::BREAK, 0);
}


size_t Python3Parser::Break_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleBreak_stmt;
}

void Python3Parser::Break_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreak_stmt(this);
}

void Python3Parser::Break_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreak_stmt(this);
}

Python3Parser::Break_stmtContext* Python3Parser::break_stmt() {
  Break_stmtContext *_localctx = _tracker.createInstance<Break_stmtContext>(_ctx, getState());
  enterRule(_localctx, 22, Python3Parser::RuleBreak_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(Python3Parser::BREAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Continue_stmtContext ------------------------------------------------------------------

Python3Parser::Continue_stmtContext::Continue_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::Continue_stmtContext::CONTINUE() {
  return getToken(Python3Parser::CONTINUE, 0);
}


size_t Python3Parser::Continue_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleContinue_stmt;
}

void Python3Parser::Continue_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinue_stmt(this);
}

void Python3Parser::Continue_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinue_stmt(this);
}

Python3Parser::Continue_stmtContext* Python3Parser::continue_stmt() {
  Continue_stmtContext *_localctx = _tracker.createInstance<Continue_stmtContext>(_ctx, getState());
  enterRule(_localctx, 24, Python3Parser::RuleContinue_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    match(Python3Parser::CONTINUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

Python3Parser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::Return_stmtContext::RETURN() {
  return getToken(Python3Parser::RETURN, 0);
}

Python3Parser::TestlistContext* Python3Parser::Return_stmtContext::testlist() {
  return getRuleContext<Python3Parser::TestlistContext>(0);
}


size_t Python3Parser::Return_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleReturn_stmt;
}

void Python3Parser::Return_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_stmt(this);
}

void Python3Parser::Return_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_stmt(this);
}

Python3Parser::Return_stmtContext* Python3Parser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 26, Python3Parser::RuleReturn_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(Python3Parser::RETURN);
    setState(218);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Python3Parser::STRING)
      | (1ULL << Python3Parser::NUMBER)
      | (1ULL << Python3Parser::NOT)
      | (1ULL << Python3Parser::NONE)
      | (1ULL << Python3Parser::TRUE)
      | (1ULL << Python3Parser::FALSE)
      | (1ULL << Python3Parser::NAME)
      | (1ULL << Python3Parser::ADD)
      | (1ULL << Python3Parser::MINUS)
      | (1ULL << Python3Parser::NOT_OP))) != 0)) {
      setState(217);
      testlist();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_stmtContext ------------------------------------------------------------------

Python3Parser::Compound_stmtContext::Compound_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Python3Parser::If_stmtContext* Python3Parser::Compound_stmtContext::if_stmt() {
  return getRuleContext<Python3Parser::If_stmtContext>(0);
}

Python3Parser::While_stmtContext* Python3Parser::Compound_stmtContext::while_stmt() {
  return getRuleContext<Python3Parser::While_stmtContext>(0);
}

Python3Parser::For_stmtContext* Python3Parser::Compound_stmtContext::for_stmt() {
  return getRuleContext<Python3Parser::For_stmtContext>(0);
}

Python3Parser::FuncdefContext* Python3Parser::Compound_stmtContext::funcdef() {
  return getRuleContext<Python3Parser::FuncdefContext>(0);
}


size_t Python3Parser::Compound_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleCompound_stmt;
}

void Python3Parser::Compound_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_stmt(this);
}

void Python3Parser::Compound_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_stmt(this);
}

Python3Parser::Compound_stmtContext* Python3Parser::compound_stmt() {
  Compound_stmtContext *_localctx = _tracker.createInstance<Compound_stmtContext>(_ctx, getState());
  enterRule(_localctx, 28, Python3Parser::RuleCompound_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(224);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(220);
        if_stmt();
        break;
      }

      case Python3Parser::WHILE: {
        enterOuterAlt(_localctx, 2);
        setState(221);
        while_stmt();
        break;
      }

      case Python3Parser::FOR: {
        enterOuterAlt(_localctx, 3);
        setState(222);
        for_stmt();
        break;
      }

      case Python3Parser::DEF: {
        enterOuterAlt(_localctx, 4);
        setState(223);
        funcdef();
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

//----------------- If_stmtContext ------------------------------------------------------------------

Python3Parser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::If_stmtContext::IF() {
  return getToken(Python3Parser::IF, 0);
}

std::vector<Python3Parser::TestContext *> Python3Parser::If_stmtContext::test() {
  return getRuleContexts<Python3Parser::TestContext>();
}

Python3Parser::TestContext* Python3Parser::If_stmtContext::test(size_t i) {
  return getRuleContext<Python3Parser::TestContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::If_stmtContext::COLON() {
  return getTokens(Python3Parser::COLON);
}

tree::TerminalNode* Python3Parser::If_stmtContext::COLON(size_t i) {
  return getToken(Python3Parser::COLON, i);
}

std::vector<Python3Parser::SuiteContext *> Python3Parser::If_stmtContext::suite() {
  return getRuleContexts<Python3Parser::SuiteContext>();
}

Python3Parser::SuiteContext* Python3Parser::If_stmtContext::suite(size_t i) {
  return getRuleContext<Python3Parser::SuiteContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::If_stmtContext::ELIF() {
  return getTokens(Python3Parser::ELIF);
}

tree::TerminalNode* Python3Parser::If_stmtContext::ELIF(size_t i) {
  return getToken(Python3Parser::ELIF, i);
}

tree::TerminalNode* Python3Parser::If_stmtContext::ELSE() {
  return getToken(Python3Parser::ELSE, 0);
}


size_t Python3Parser::If_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleIf_stmt;
}

void Python3Parser::If_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIf_stmt(this);
}

void Python3Parser::If_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIf_stmt(this);
}

Python3Parser::If_stmtContext* Python3Parser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 30, Python3Parser::RuleIf_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    match(Python3Parser::IF);
    setState(227);
    test();
    setState(228);
    match(Python3Parser::COLON);
    setState(229);
    suite();
    setState(237);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Python3Parser::ELIF) {
      setState(230);
      match(Python3Parser::ELIF);
      setState(231);
      test();
      setState(232);
      match(Python3Parser::COLON);
      setState(233);
      suite();
      setState(239);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(243);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Python3Parser::ELSE) {
      setState(240);
      match(Python3Parser::ELSE);
      setState(241);
      match(Python3Parser::COLON);
      setState(242);
      suite();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_stmtContext ------------------------------------------------------------------

Python3Parser::While_stmtContext::While_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::While_stmtContext::WHILE() {
  return getToken(Python3Parser::WHILE, 0);
}

Python3Parser::TestContext* Python3Parser::While_stmtContext::test() {
  return getRuleContext<Python3Parser::TestContext>(0);
}

tree::TerminalNode* Python3Parser::While_stmtContext::COLON() {
  return getToken(Python3Parser::COLON, 0);
}

Python3Parser::SuiteContext* Python3Parser::While_stmtContext::suite() {
  return getRuleContext<Python3Parser::SuiteContext>(0);
}


size_t Python3Parser::While_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleWhile_stmt;
}

void Python3Parser::While_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhile_stmt(this);
}

void Python3Parser::While_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhile_stmt(this);
}

Python3Parser::While_stmtContext* Python3Parser::while_stmt() {
  While_stmtContext *_localctx = _tracker.createInstance<While_stmtContext>(_ctx, getState());
  enterRule(_localctx, 32, Python3Parser::RuleWhile_stmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(Python3Parser::WHILE);
    setState(246);
    test();
    setState(247);
    match(Python3Parser::COLON);
    setState(248);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_stmtContext ------------------------------------------------------------------

Python3Parser::For_stmtContext::For_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::For_stmtContext::FOR() {
  return getToken(Python3Parser::FOR, 0);
}

Python3Parser::ExprlistContext* Python3Parser::For_stmtContext::exprlist() {
  return getRuleContext<Python3Parser::ExprlistContext>(0);
}

tree::TerminalNode* Python3Parser::For_stmtContext::IN() {
  return getToken(Python3Parser::IN, 0);
}

Python3Parser::TestlistContext* Python3Parser::For_stmtContext::testlist() {
  return getRuleContext<Python3Parser::TestlistContext>(0);
}

std::vector<tree::TerminalNode *> Python3Parser::For_stmtContext::COLON() {
  return getTokens(Python3Parser::COLON);
}

tree::TerminalNode* Python3Parser::For_stmtContext::COLON(size_t i) {
  return getToken(Python3Parser::COLON, i);
}

std::vector<Python3Parser::SuiteContext *> Python3Parser::For_stmtContext::suite() {
  return getRuleContexts<Python3Parser::SuiteContext>();
}

Python3Parser::SuiteContext* Python3Parser::For_stmtContext::suite(size_t i) {
  return getRuleContext<Python3Parser::SuiteContext>(i);
}

tree::TerminalNode* Python3Parser::For_stmtContext::ELSE() {
  return getToken(Python3Parser::ELSE, 0);
}


size_t Python3Parser::For_stmtContext::getRuleIndex() const {
  return Python3Parser::RuleFor_stmt;
}

void Python3Parser::For_stmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_stmt(this);
}

void Python3Parser::For_stmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_stmt(this);
}

Python3Parser::For_stmtContext* Python3Parser::for_stmt() {
  For_stmtContext *_localctx = _tracker.createInstance<For_stmtContext>(_ctx, getState());
  enterRule(_localctx, 34, Python3Parser::RuleFor_stmt);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(Python3Parser::FOR);
    setState(251);
    exprlist();
    setState(252);
    match(Python3Parser::IN);
    setState(253);
    testlist();
    setState(254);
    match(Python3Parser::COLON);
    setState(255);
    suite();
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Python3Parser::ELSE) {
      setState(256);
      match(Python3Parser::ELSE);
      setState(257);
      match(Python3Parser::COLON);
      setState(258);
      suite();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuiteContext ------------------------------------------------------------------

Python3Parser::SuiteContext::SuiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Python3Parser::Simple_stmtContext* Python3Parser::SuiteContext::simple_stmt() {
  return getRuleContext<Python3Parser::Simple_stmtContext>(0);
}

tree::TerminalNode* Python3Parser::SuiteContext::NEWLINE() {
  return getToken(Python3Parser::NEWLINE, 0);
}

tree::TerminalNode* Python3Parser::SuiteContext::INDENT() {
  return getToken(Python3Parser::INDENT, 0);
}

tree::TerminalNode* Python3Parser::SuiteContext::DEDENT() {
  return getToken(Python3Parser::DEDENT, 0);
}

std::vector<Python3Parser::StmtContext *> Python3Parser::SuiteContext::stmt() {
  return getRuleContexts<Python3Parser::StmtContext>();
}

Python3Parser::StmtContext* Python3Parser::SuiteContext::stmt(size_t i) {
  return getRuleContext<Python3Parser::StmtContext>(i);
}


size_t Python3Parser::SuiteContext::getRuleIndex() const {
  return Python3Parser::RuleSuite;
}

void Python3Parser::SuiteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSuite(this);
}

void Python3Parser::SuiteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSuite(this);
}

Python3Parser::SuiteContext* Python3Parser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 36, Python3Parser::RuleSuite);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(271);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::STRING:
      case Python3Parser::NUMBER:
      case Python3Parser::RETURN:
      case Python3Parser::NOT:
      case Python3Parser::NONE:
      case Python3Parser::TRUE:
      case Python3Parser::FALSE:
      case Python3Parser::CONTINUE:
      case Python3Parser::BREAK:
      case Python3Parser::NAME:
      case Python3Parser::ADD:
      case Python3Parser::MINUS:
      case Python3Parser::NOT_OP: {
        enterOuterAlt(_localctx, 1);
        setState(261);
        simple_stmt();
        break;
      }

      case Python3Parser::NEWLINE: {
        enterOuterAlt(_localctx, 2);
        setState(262);
        match(Python3Parser::NEWLINE);
        setState(263);
        match(Python3Parser::INDENT);
        setState(265); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(264);
          stmt();
          setState(267); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Python3Parser::STRING)
          | (1ULL << Python3Parser::NUMBER)
          | (1ULL << Python3Parser::DEF)
          | (1ULL << Python3Parser::RETURN)
          | (1ULL << Python3Parser::IF)
          | (1ULL << Python3Parser::WHILE)
          | (1ULL << Python3Parser::FOR)
          | (1ULL << Python3Parser::NOT)
          | (1ULL << Python3Parser::NONE)
          | (1ULL << Python3Parser::TRUE)
          | (1ULL << Python3Parser::FALSE)
          | (1ULL << Python3Parser::CONTINUE)
          | (1ULL << Python3Parser::BREAK)
          | (1ULL << Python3Parser::NAME)
          | (1ULL << Python3Parser::ADD)
          | (1ULL << Python3Parser::MINUS)
          | (1ULL << Python3Parser::NOT_OP))) != 0));
        setState(269);
        match(Python3Parser::DEDENT);
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

//----------------- TestContext ------------------------------------------------------------------

Python3Parser::TestContext::TestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::Or_testContext *> Python3Parser::TestContext::or_test() {
  return getRuleContexts<Python3Parser::Or_testContext>();
}

Python3Parser::Or_testContext* Python3Parser::TestContext::or_test(size_t i) {
  return getRuleContext<Python3Parser::Or_testContext>(i);
}

tree::TerminalNode* Python3Parser::TestContext::IF() {
  return getToken(Python3Parser::IF, 0);
}

tree::TerminalNode* Python3Parser::TestContext::ELSE() {
  return getToken(Python3Parser::ELSE, 0);
}

Python3Parser::TestContext* Python3Parser::TestContext::test() {
  return getRuleContext<Python3Parser::TestContext>(0);
}


size_t Python3Parser::TestContext::getRuleIndex() const {
  return Python3Parser::RuleTest;
}

void Python3Parser::TestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTest(this);
}

void Python3Parser::TestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTest(this);
}

Python3Parser::TestContext* Python3Parser::test() {
  TestContext *_localctx = _tracker.createInstance<TestContext>(_ctx, getState());
  enterRule(_localctx, 38, Python3Parser::RuleTest);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(273);
    or_test();
    setState(279);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Python3Parser::IF) {
      setState(274);
      match(Python3Parser::IF);
      setState(275);
      or_test();
      setState(276);
      match(Python3Parser::ELSE);
      setState(277);
      test();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Or_testContext ------------------------------------------------------------------

Python3Parser::Or_testContext::Or_testContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::And_testContext *> Python3Parser::Or_testContext::and_test() {
  return getRuleContexts<Python3Parser::And_testContext>();
}

Python3Parser::And_testContext* Python3Parser::Or_testContext::and_test(size_t i) {
  return getRuleContext<Python3Parser::And_testContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::Or_testContext::OR() {
  return getTokens(Python3Parser::OR);
}

tree::TerminalNode* Python3Parser::Or_testContext::OR(size_t i) {
  return getToken(Python3Parser::OR, i);
}


size_t Python3Parser::Or_testContext::getRuleIndex() const {
  return Python3Parser::RuleOr_test;
}

void Python3Parser::Or_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOr_test(this);
}

void Python3Parser::Or_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOr_test(this);
}

Python3Parser::Or_testContext* Python3Parser::or_test() {
  Or_testContext *_localctx = _tracker.createInstance<Or_testContext>(_ctx, getState());
  enterRule(_localctx, 40, Python3Parser::RuleOr_test);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    and_test();
    setState(286);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Python3Parser::OR) {
      setState(282);
      match(Python3Parser::OR);
      setState(283);
      and_test();
      setState(288);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- And_testContext ------------------------------------------------------------------

Python3Parser::And_testContext::And_testContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::Not_testContext *> Python3Parser::And_testContext::not_test() {
  return getRuleContexts<Python3Parser::Not_testContext>();
}

Python3Parser::Not_testContext* Python3Parser::And_testContext::not_test(size_t i) {
  return getRuleContext<Python3Parser::Not_testContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::And_testContext::AND() {
  return getTokens(Python3Parser::AND);
}

tree::TerminalNode* Python3Parser::And_testContext::AND(size_t i) {
  return getToken(Python3Parser::AND, i);
}


size_t Python3Parser::And_testContext::getRuleIndex() const {
  return Python3Parser::RuleAnd_test;
}

void Python3Parser::And_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd_test(this);
}

void Python3Parser::And_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd_test(this);
}

Python3Parser::And_testContext* Python3Parser::and_test() {
  And_testContext *_localctx = _tracker.createInstance<And_testContext>(_ctx, getState());
  enterRule(_localctx, 42, Python3Parser::RuleAnd_test);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(289);
    not_test();
    setState(294);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Python3Parser::AND) {
      setState(290);
      match(Python3Parser::AND);
      setState(291);
      not_test();
      setState(296);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Not_testContext ------------------------------------------------------------------

Python3Parser::Not_testContext::Not_testContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::Not_testContext::NOT() {
  return getToken(Python3Parser::NOT, 0);
}

Python3Parser::Not_testContext* Python3Parser::Not_testContext::not_test() {
  return getRuleContext<Python3Parser::Not_testContext>(0);
}

Python3Parser::ComparisonContext* Python3Parser::Not_testContext::comparison() {
  return getRuleContext<Python3Parser::ComparisonContext>(0);
}


size_t Python3Parser::Not_testContext::getRuleIndex() const {
  return Python3Parser::RuleNot_test;
}

void Python3Parser::Not_testContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNot_test(this);
}

void Python3Parser::Not_testContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNot_test(this);
}

Python3Parser::Not_testContext* Python3Parser::not_test() {
  Not_testContext *_localctx = _tracker.createInstance<Not_testContext>(_ctx, getState());
  enterRule(_localctx, 44, Python3Parser::RuleNot_test);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(300);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(297);
        match(Python3Parser::NOT);
        setState(298);
        not_test();
        break;
      }

      case Python3Parser::STRING:
      case Python3Parser::NUMBER:
      case Python3Parser::NONE:
      case Python3Parser::TRUE:
      case Python3Parser::FALSE:
      case Python3Parser::NAME:
      case Python3Parser::ADD:
      case Python3Parser::MINUS:
      case Python3Parser::NOT_OP: {
        enterOuterAlt(_localctx, 2);
        setState(299);
        comparison();
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

//----------------- ComparisonContext ------------------------------------------------------------------

Python3Parser::ComparisonContext::ComparisonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::ExprContext *> Python3Parser::ComparisonContext::expr() {
  return getRuleContexts<Python3Parser::ExprContext>();
}

Python3Parser::ExprContext* Python3Parser::ComparisonContext::expr(size_t i) {
  return getRuleContext<Python3Parser::ExprContext>(i);
}

std::vector<Python3Parser::Comp_opContext *> Python3Parser::ComparisonContext::comp_op() {
  return getRuleContexts<Python3Parser::Comp_opContext>();
}

Python3Parser::Comp_opContext* Python3Parser::ComparisonContext::comp_op(size_t i) {
  return getRuleContext<Python3Parser::Comp_opContext>(i);
}


size_t Python3Parser::ComparisonContext::getRuleIndex() const {
  return Python3Parser::RuleComparison;
}

void Python3Parser::ComparisonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComparison(this);
}

void Python3Parser::ComparisonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComparison(this);
}

Python3Parser::ComparisonContext* Python3Parser::comparison() {
  ComparisonContext *_localctx = _tracker.createInstance<ComparisonContext>(_ctx, getState());
  enterRule(_localctx, 46, Python3Parser::RuleComparison);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    expr();
    setState(308);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Python3Parser::IN)
      | (1ULL << Python3Parser::NOT)
      | (1ULL << Python3Parser::LESS_THAN)
      | (1ULL << Python3Parser::GREATER_THAN)
      | (1ULL << Python3Parser::EQUALS)
      | (1ULL << Python3Parser::GT_EQ)
      | (1ULL << Python3Parser::LT_EQ)
      | (1ULL << Python3Parser::NOT_EQ_1)
      | (1ULL << Python3Parser::NOT_EQ_2))) != 0)) {
      setState(303);
      comp_op();
      setState(304);
      expr();
      setState(310);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Comp_opContext ------------------------------------------------------------------

Python3Parser::Comp_opContext::Comp_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::Comp_opContext::LESS_THAN() {
  return getToken(Python3Parser::LESS_THAN, 0);
}

tree::TerminalNode* Python3Parser::Comp_opContext::GREATER_THAN() {
  return getToken(Python3Parser::GREATER_THAN, 0);
}

tree::TerminalNode* Python3Parser::Comp_opContext::EQUALS() {
  return getToken(Python3Parser::EQUALS, 0);
}

tree::TerminalNode* Python3Parser::Comp_opContext::GT_EQ() {
  return getToken(Python3Parser::GT_EQ, 0);
}

tree::TerminalNode* Python3Parser::Comp_opContext::LT_EQ() {
  return getToken(Python3Parser::LT_EQ, 0);
}

tree::TerminalNode* Python3Parser::Comp_opContext::NOT_EQ_1() {
  return getToken(Python3Parser::NOT_EQ_1, 0);
}

tree::TerminalNode* Python3Parser::Comp_opContext::NOT_EQ_2() {
  return getToken(Python3Parser::NOT_EQ_2, 0);
}

tree::TerminalNode* Python3Parser::Comp_opContext::IN() {
  return getToken(Python3Parser::IN, 0);
}

tree::TerminalNode* Python3Parser::Comp_opContext::NOT() {
  return getToken(Python3Parser::NOT, 0);
}


size_t Python3Parser::Comp_opContext::getRuleIndex() const {
  return Python3Parser::RuleComp_op;
}

void Python3Parser::Comp_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComp_op(this);
}

void Python3Parser::Comp_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComp_op(this);
}

Python3Parser::Comp_opContext* Python3Parser::comp_op() {
  Comp_opContext *_localctx = _tracker.createInstance<Comp_opContext>(_ctx, getState());
  enterRule(_localctx, 48, Python3Parser::RuleComp_op);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::LESS_THAN: {
        enterOuterAlt(_localctx, 1);
        setState(311);
        match(Python3Parser::LESS_THAN);
        break;
      }

      case Python3Parser::GREATER_THAN: {
        enterOuterAlt(_localctx, 2);
        setState(312);
        match(Python3Parser::GREATER_THAN);
        break;
      }

      case Python3Parser::EQUALS: {
        enterOuterAlt(_localctx, 3);
        setState(313);
        match(Python3Parser::EQUALS);
        break;
      }

      case Python3Parser::GT_EQ: {
        enterOuterAlt(_localctx, 4);
        setState(314);
        match(Python3Parser::GT_EQ);
        break;
      }

      case Python3Parser::LT_EQ: {
        enterOuterAlt(_localctx, 5);
        setState(315);
        match(Python3Parser::LT_EQ);
        break;
      }

      case Python3Parser::NOT_EQ_1: {
        enterOuterAlt(_localctx, 6);
        setState(316);
        match(Python3Parser::NOT_EQ_1);
        break;
      }

      case Python3Parser::NOT_EQ_2: {
        enterOuterAlt(_localctx, 7);
        setState(317);
        match(Python3Parser::NOT_EQ_2);
        break;
      }

      case Python3Parser::IN: {
        enterOuterAlt(_localctx, 8);
        setState(318);
        match(Python3Parser::IN);
        break;
      }

      case Python3Parser::NOT: {
        enterOuterAlt(_localctx, 9);
        setState(319);
        match(Python3Parser::NOT);
        setState(320);
        match(Python3Parser::IN);
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

//----------------- ExprContext ------------------------------------------------------------------

Python3Parser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::Xor_exprContext *> Python3Parser::ExprContext::xor_expr() {
  return getRuleContexts<Python3Parser::Xor_exprContext>();
}

Python3Parser::Xor_exprContext* Python3Parser::ExprContext::xor_expr(size_t i) {
  return getRuleContext<Python3Parser::Xor_exprContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::ExprContext::OR_OP() {
  return getTokens(Python3Parser::OR_OP);
}

tree::TerminalNode* Python3Parser::ExprContext::OR_OP(size_t i) {
  return getToken(Python3Parser::OR_OP, i);
}


size_t Python3Parser::ExprContext::getRuleIndex() const {
  return Python3Parser::RuleExpr;
}

void Python3Parser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void Python3Parser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}

Python3Parser::ExprContext* Python3Parser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 50, Python3Parser::RuleExpr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    xor_expr();
    setState(328);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Python3Parser::OR_OP) {
      setState(324);
      match(Python3Parser::OR_OP);
      setState(325);
      xor_expr();
      setState(330);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Xor_exprContext ------------------------------------------------------------------

Python3Parser::Xor_exprContext::Xor_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::And_exprContext *> Python3Parser::Xor_exprContext::and_expr() {
  return getRuleContexts<Python3Parser::And_exprContext>();
}

Python3Parser::And_exprContext* Python3Parser::Xor_exprContext::and_expr(size_t i) {
  return getRuleContext<Python3Parser::And_exprContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::Xor_exprContext::XOR() {
  return getTokens(Python3Parser::XOR);
}

tree::TerminalNode* Python3Parser::Xor_exprContext::XOR(size_t i) {
  return getToken(Python3Parser::XOR, i);
}


size_t Python3Parser::Xor_exprContext::getRuleIndex() const {
  return Python3Parser::RuleXor_expr;
}

void Python3Parser::Xor_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterXor_expr(this);
}

void Python3Parser::Xor_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitXor_expr(this);
}

Python3Parser::Xor_exprContext* Python3Parser::xor_expr() {
  Xor_exprContext *_localctx = _tracker.createInstance<Xor_exprContext>(_ctx, getState());
  enterRule(_localctx, 52, Python3Parser::RuleXor_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    and_expr();
    setState(336);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Python3Parser::XOR) {
      setState(332);
      match(Python3Parser::XOR);
      setState(333);
      and_expr();
      setState(338);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- And_exprContext ------------------------------------------------------------------

Python3Parser::And_exprContext::And_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::Shift_exprContext *> Python3Parser::And_exprContext::shift_expr() {
  return getRuleContexts<Python3Parser::Shift_exprContext>();
}

Python3Parser::Shift_exprContext* Python3Parser::And_exprContext::shift_expr(size_t i) {
  return getRuleContext<Python3Parser::Shift_exprContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::And_exprContext::AND_OP() {
  return getTokens(Python3Parser::AND_OP);
}

tree::TerminalNode* Python3Parser::And_exprContext::AND_OP(size_t i) {
  return getToken(Python3Parser::AND_OP, i);
}


size_t Python3Parser::And_exprContext::getRuleIndex() const {
  return Python3Parser::RuleAnd_expr;
}

void Python3Parser::And_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAnd_expr(this);
}

void Python3Parser::And_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAnd_expr(this);
}

Python3Parser::And_exprContext* Python3Parser::and_expr() {
  And_exprContext *_localctx = _tracker.createInstance<And_exprContext>(_ctx, getState());
  enterRule(_localctx, 54, Python3Parser::RuleAnd_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    shift_expr();
    setState(344);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Python3Parser::AND_OP) {
      setState(340);
      match(Python3Parser::AND_OP);
      setState(341);
      shift_expr();
      setState(346);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Shift_exprContext ------------------------------------------------------------------

Python3Parser::Shift_exprContext::Shift_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::Arith_exprContext *> Python3Parser::Shift_exprContext::arith_expr() {
  return getRuleContexts<Python3Parser::Arith_exprContext>();
}

Python3Parser::Arith_exprContext* Python3Parser::Shift_exprContext::arith_expr(size_t i) {
  return getRuleContext<Python3Parser::Arith_exprContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::Shift_exprContext::LEFT_SHIFT() {
  return getTokens(Python3Parser::LEFT_SHIFT);
}

tree::TerminalNode* Python3Parser::Shift_exprContext::LEFT_SHIFT(size_t i) {
  return getToken(Python3Parser::LEFT_SHIFT, i);
}

std::vector<tree::TerminalNode *> Python3Parser::Shift_exprContext::RIGHT_SHIFT() {
  return getTokens(Python3Parser::RIGHT_SHIFT);
}

tree::TerminalNode* Python3Parser::Shift_exprContext::RIGHT_SHIFT(size_t i) {
  return getToken(Python3Parser::RIGHT_SHIFT, i);
}


size_t Python3Parser::Shift_exprContext::getRuleIndex() const {
  return Python3Parser::RuleShift_expr;
}

void Python3Parser::Shift_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShift_expr(this);
}

void Python3Parser::Shift_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShift_expr(this);
}

Python3Parser::Shift_exprContext* Python3Parser::shift_expr() {
  Shift_exprContext *_localctx = _tracker.createInstance<Shift_exprContext>(_ctx, getState());
  enterRule(_localctx, 56, Python3Parser::RuleShift_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(347);
    arith_expr();
    setState(352);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Python3Parser::LEFT_SHIFT

    || _la == Python3Parser::RIGHT_SHIFT) {
      setState(348);
      _la = _input->LA(1);
      if (!(_la == Python3Parser::LEFT_SHIFT

      || _la == Python3Parser::RIGHT_SHIFT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(349);
      arith_expr();
      setState(354);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arith_exprContext ------------------------------------------------------------------

Python3Parser::Arith_exprContext::Arith_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::TermContext *> Python3Parser::Arith_exprContext::term() {
  return getRuleContexts<Python3Parser::TermContext>();
}

Python3Parser::TermContext* Python3Parser::Arith_exprContext::term(size_t i) {
  return getRuleContext<Python3Parser::TermContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::Arith_exprContext::ADD() {
  return getTokens(Python3Parser::ADD);
}

tree::TerminalNode* Python3Parser::Arith_exprContext::ADD(size_t i) {
  return getToken(Python3Parser::ADD, i);
}

std::vector<tree::TerminalNode *> Python3Parser::Arith_exprContext::MINUS() {
  return getTokens(Python3Parser::MINUS);
}

tree::TerminalNode* Python3Parser::Arith_exprContext::MINUS(size_t i) {
  return getToken(Python3Parser::MINUS, i);
}


size_t Python3Parser::Arith_exprContext::getRuleIndex() const {
  return Python3Parser::RuleArith_expr;
}

void Python3Parser::Arith_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_expr(this);
}

void Python3Parser::Arith_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_expr(this);
}

Python3Parser::Arith_exprContext* Python3Parser::arith_expr() {
  Arith_exprContext *_localctx = _tracker.createInstance<Arith_exprContext>(_ctx, getState());
  enterRule(_localctx, 58, Python3Parser::RuleArith_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    term();
    setState(360);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == Python3Parser::ADD

    || _la == Python3Parser::MINUS) {
      setState(356);
      _la = _input->LA(1);
      if (!(_la == Python3Parser::ADD

      || _la == Python3Parser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(357);
      term();
      setState(362);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

Python3Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::FactorContext *> Python3Parser::TermContext::factor() {
  return getRuleContexts<Python3Parser::FactorContext>();
}

Python3Parser::FactorContext* Python3Parser::TermContext::factor(size_t i) {
  return getRuleContext<Python3Parser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::TermContext::STAR() {
  return getTokens(Python3Parser::STAR);
}

tree::TerminalNode* Python3Parser::TermContext::STAR(size_t i) {
  return getToken(Python3Parser::STAR, i);
}

std::vector<tree::TerminalNode *> Python3Parser::TermContext::AT() {
  return getTokens(Python3Parser::AT);
}

tree::TerminalNode* Python3Parser::TermContext::AT(size_t i) {
  return getToken(Python3Parser::AT, i);
}

std::vector<tree::TerminalNode *> Python3Parser::TermContext::DIV() {
  return getTokens(Python3Parser::DIV);
}

tree::TerminalNode* Python3Parser::TermContext::DIV(size_t i) {
  return getToken(Python3Parser::DIV, i);
}

std::vector<tree::TerminalNode *> Python3Parser::TermContext::MOD() {
  return getTokens(Python3Parser::MOD);
}

tree::TerminalNode* Python3Parser::TermContext::MOD(size_t i) {
  return getToken(Python3Parser::MOD, i);
}

std::vector<tree::TerminalNode *> Python3Parser::TermContext::IDIV() {
  return getTokens(Python3Parser::IDIV);
}

tree::TerminalNode* Python3Parser::TermContext::IDIV(size_t i) {
  return getToken(Python3Parser::IDIV, i);
}


size_t Python3Parser::TermContext::getRuleIndex() const {
  return Python3Parser::RuleTerm;
}

void Python3Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void Python3Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}

Python3Parser::TermContext* Python3Parser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 60, Python3Parser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    factor();
    setState(368);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << Python3Parser::STAR)
      | (1ULL << Python3Parser::DIV)
      | (1ULL << Python3Parser::MOD)
      | (1ULL << Python3Parser::IDIV)
      | (1ULL << Python3Parser::AT))) != 0)) {
      setState(364);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << Python3Parser::STAR)
        | (1ULL << Python3Parser::DIV)
        | (1ULL << Python3Parser::MOD)
        | (1ULL << Python3Parser::IDIV)
        | (1ULL << Python3Parser::AT))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(365);
      factor();
      setState(370);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

Python3Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Python3Parser::FactorContext* Python3Parser::FactorContext::factor() {
  return getRuleContext<Python3Parser::FactorContext>(0);
}

tree::TerminalNode* Python3Parser::FactorContext::ADD() {
  return getToken(Python3Parser::ADD, 0);
}

tree::TerminalNode* Python3Parser::FactorContext::MINUS() {
  return getToken(Python3Parser::MINUS, 0);
}

tree::TerminalNode* Python3Parser::FactorContext::NOT_OP() {
  return getToken(Python3Parser::NOT_OP, 0);
}

Python3Parser::PowerContext* Python3Parser::FactorContext::power() {
  return getRuleContext<Python3Parser::PowerContext>(0);
}


size_t Python3Parser::FactorContext::getRuleIndex() const {
  return Python3Parser::RuleFactor;
}

void Python3Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void Python3Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

Python3Parser::FactorContext* Python3Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 62, Python3Parser::RuleFactor);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(374);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::ADD:
      case Python3Parser::MINUS:
      case Python3Parser::NOT_OP: {
        enterOuterAlt(_localctx, 1);
        setState(371);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << Python3Parser::ADD)
          | (1ULL << Python3Parser::MINUS)
          | (1ULL << Python3Parser::NOT_OP))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(372);
        factor();
        break;
      }

      case Python3Parser::STRING:
      case Python3Parser::NUMBER:
      case Python3Parser::NONE:
      case Python3Parser::TRUE:
      case Python3Parser::FALSE:
      case Python3Parser::NAME: {
        enterOuterAlt(_localctx, 2);
        setState(373);
        power();
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

//----------------- PowerContext ------------------------------------------------------------------

Python3Parser::PowerContext::PowerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

Python3Parser::AtomContext* Python3Parser::PowerContext::atom() {
  return getRuleContext<Python3Parser::AtomContext>(0);
}

tree::TerminalNode* Python3Parser::PowerContext::POWER() {
  return getToken(Python3Parser::POWER, 0);
}

Python3Parser::FactorContext* Python3Parser::PowerContext::factor() {
  return getRuleContext<Python3Parser::FactorContext>(0);
}


size_t Python3Parser::PowerContext::getRuleIndex() const {
  return Python3Parser::RulePower;
}

void Python3Parser::PowerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPower(this);
}

void Python3Parser::PowerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPower(this);
}

Python3Parser::PowerContext* Python3Parser::power() {
  PowerContext *_localctx = _tracker.createInstance<PowerContext>(_ctx, getState());
  enterRule(_localctx, 64, Python3Parser::RulePower);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    atom();
    setState(379);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Python3Parser::POWER) {
      setState(377);
      match(Python3Parser::POWER);
      setState(378);
      factor();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

Python3Parser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* Python3Parser::AtomContext::NAME() {
  return getToken(Python3Parser::NAME, 0);
}

tree::TerminalNode* Python3Parser::AtomContext::NUMBER() {
  return getToken(Python3Parser::NUMBER, 0);
}

tree::TerminalNode* Python3Parser::AtomContext::NONE() {
  return getToken(Python3Parser::NONE, 0);
}

tree::TerminalNode* Python3Parser::AtomContext::TRUE() {
  return getToken(Python3Parser::TRUE, 0);
}

tree::TerminalNode* Python3Parser::AtomContext::FALSE() {
  return getToken(Python3Parser::FALSE, 0);
}

std::vector<tree::TerminalNode *> Python3Parser::AtomContext::STRING() {
  return getTokens(Python3Parser::STRING);
}

tree::TerminalNode* Python3Parser::AtomContext::STRING(size_t i) {
  return getToken(Python3Parser::STRING, i);
}


size_t Python3Parser::AtomContext::getRuleIndex() const {
  return Python3Parser::RuleAtom;
}

void Python3Parser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void Python3Parser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

Python3Parser::AtomContext* Python3Parser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 66, Python3Parser::RuleAtom);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case Python3Parser::NAME: {
        setState(381);
        match(Python3Parser::NAME);
        break;
      }

      case Python3Parser::NUMBER: {
        setState(382);
        match(Python3Parser::NUMBER);
        break;
      }

      case Python3Parser::STRING: {
        setState(384); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(383);
          match(Python3Parser::STRING);
          setState(386); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == Python3Parser::STRING);
        break;
      }

      case Python3Parser::NONE: {
        setState(388);
        match(Python3Parser::NONE);
        break;
      }

      case Python3Parser::TRUE: {
        setState(389);
        match(Python3Parser::TRUE);
        break;
      }

      case Python3Parser::FALSE: {
        setState(390);
        match(Python3Parser::FALSE);
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

//----------------- ExprlistContext ------------------------------------------------------------------

Python3Parser::ExprlistContext::ExprlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::ExprContext *> Python3Parser::ExprlistContext::expr() {
  return getRuleContexts<Python3Parser::ExprContext>();
}

Python3Parser::ExprContext* Python3Parser::ExprlistContext::expr(size_t i) {
  return getRuleContext<Python3Parser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::ExprlistContext::COMMA() {
  return getTokens(Python3Parser::COMMA);
}

tree::TerminalNode* Python3Parser::ExprlistContext::COMMA(size_t i) {
  return getToken(Python3Parser::COMMA, i);
}


size_t Python3Parser::ExprlistContext::getRuleIndex() const {
  return Python3Parser::RuleExprlist;
}

void Python3Parser::ExprlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprlist(this);
}

void Python3Parser::ExprlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprlist(this);
}

Python3Parser::ExprlistContext* Python3Parser::exprlist() {
  ExprlistContext *_localctx = _tracker.createInstance<ExprlistContext>(_ctx, getState());
  enterRule(_localctx, 68, Python3Parser::RuleExprlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(393);
    expr();
    setState(398);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(394);
        match(Python3Parser::COMMA);

        setState(395);
        expr(); 
      }
      setState(400);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx);
    }
    setState(402);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Python3Parser::COMMA) {
      setState(401);
      match(Python3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TestlistContext ------------------------------------------------------------------

Python3Parser::TestlistContext::TestlistContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<Python3Parser::TestContext *> Python3Parser::TestlistContext::test() {
  return getRuleContexts<Python3Parser::TestContext>();
}

Python3Parser::TestContext* Python3Parser::TestlistContext::test(size_t i) {
  return getRuleContext<Python3Parser::TestContext>(i);
}

std::vector<tree::TerminalNode *> Python3Parser::TestlistContext::COMMA() {
  return getTokens(Python3Parser::COMMA);
}

tree::TerminalNode* Python3Parser::TestlistContext::COMMA(size_t i) {
  return getToken(Python3Parser::COMMA, i);
}


size_t Python3Parser::TestlistContext::getRuleIndex() const {
  return Python3Parser::RuleTestlist;
}

void Python3Parser::TestlistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTestlist(this);
}

void Python3Parser::TestlistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<Python3Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTestlist(this);
}

Python3Parser::TestlistContext* Python3Parser::testlist() {
  TestlistContext *_localctx = _tracker.createInstance<TestlistContext>(_ctx, getState());
  enterRule(_localctx, 70, Python3Parser::RuleTestlist);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(404);
    test();
    setState(409);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(405);
        match(Python3Parser::COMMA);
        setState(406);
        test(); 
      }
      setState(411);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx);
    }
    setState(413);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == Python3Parser::COMMA) {
      setState(412);
      match(Python3Parser::COMMA);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> Python3Parser::_decisionToDFA;
atn::PredictionContextCache Python3Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN Python3Parser::_atn;
std::vector<uint16_t> Python3Parser::_serializedATN;

std::vector<std::string> Python3Parser::_ruleNames = {
  "file_input", "funcdef", "parameters", "typedargslist", "tfpdef", "stmt", 
  "simple_stmt", "small_stmt", "expr_stmt", "augassign", "flow_stmt", "break_stmt", 
  "continue_stmt", "return_stmt", "compound_stmt", "if_stmt", "while_stmt", 
  "for_stmt", "suite", "test", "or_test", "and_test", "not_test", "comparison", 
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr", "arith_expr", 
  "term", "factor", "power", "atom", "exprlist", "testlist"
};

std::vector<std::string> Python3Parser::_literalNames = {
  "", "", "", "", "'def'", "'return'", "'if'", "'elif'", "'else'", "'while'", 
  "'for'", "'in'", "'or'", "'and'", "'not'", "'None'", "'True'", "'False'", 
  "'continue'", "'break'", "", "", "", "", "", "", "", "", "", "", "'.'", 
  "'...'", "'*'", "'('", "')'", "','", "':'", "';'", "'**'", "'='", "'['", 
  "']'", "'|'", "'^'", "'&'", "'<<'", "'>>'", "'+'", "'-'", "'/'", "'%'", 
  "'//'", "'~'", "'{'", "'}'", "'<'", "'>'", "'=='", "'>='", "'<='", "'<>'", 
  "'!='", "'@'", "'->'", "'+='", "'-='", "'*='", "'@='", "'/='", "'%='", 
  "'&='", "'|='", "'^='", "'<<='", "'>>='", "'**='", "'//='"
};

std::vector<std::string> Python3Parser::_symbolicNames = {
  "", "STRING", "NUMBER", "INTEGER", "DEF", "RETURN", "IF", "ELIF", "ELSE", 
  "WHILE", "FOR", "IN", "OR", "AND", "NOT", "NONE", "TRUE", "FALSE", "CONTINUE", 
  "BREAK", "NEWLINE", "NAME", "STRING_LITERAL", "BYTES_LITERAL", "DECIMAL_INTEGER", 
  "OCT_INTEGER", "HEX_INTEGER", "BIN_INTEGER", "FLOAT_NUMBER", "IMAG_NUMBER", 
  "DOT", "ELLIPSIS", "STAR", "OPEN_PAREN", "CLOSE_PAREN", "COMMA", "COLON", 
  "SEMI_COLON", "POWER", "ASSIGN", "OPEN_BRACK", "CLOSE_BRACK", "OR_OP", 
  "XOR", "AND_OP", "LEFT_SHIFT", "RIGHT_SHIFT", "ADD", "MINUS", "DIV", "MOD", 
  "IDIV", "NOT_OP", "OPEN_BRACE", "CLOSE_BRACE", "LESS_THAN", "GREATER_THAN", 
  "EQUALS", "GT_EQ", "LT_EQ", "NOT_EQ_1", "NOT_EQ_2", "AT", "ARROW", "ADD_ASSIGN", 
  "SUB_ASSIGN", "MULT_ASSIGN", "AT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", 
  "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN", 
  "POWER_ASSIGN", "IDIV_ASSIGN", "SKIP_", "UNKNOWN_CHAR", "INDENT", "DEDENT"
};

dfa::Vocabulary Python3Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> Python3Parser::_tokenNames;

Python3Parser::Initializer::Initializer() {
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
    0x3, 0x52, 0x1a2, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x4d, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x50, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5c, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x63, 0xa, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x69, 0xa, 0x5, 
    0x7, 0x5, 0x6b, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x6e, 0xb, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x73, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0x79, 0xa, 0x5, 0x7, 0x5, 0x7b, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x7e, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x84, 0xa, 0x5, 0x5, 0x5, 0x86, 0xa, 0x5, 0x5, 0x5, 0x88, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x8d, 0xa, 0x5, 0x5, 
    0x5, 0x8f, 0xa, 0x5, 0x5, 0x5, 0x91, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x95, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x9b, 0xa, 0x5, 0x7, 0x5, 0x9d, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xa0, 
    0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xa6, 0xa, 
    0x5, 0x5, 0x5, 0xa8, 0xa, 0x5, 0x5, 0x5, 0xaa, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0xaf, 0xa, 0x5, 0x5, 0x5, 0xb1, 0xa, 0x5, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xb6, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0xba, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0xc1, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xc9, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xcc, 
    0xb, 0xa, 0x5, 0xa, 0xce, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0xd5, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xdd, 0xa, 0xf, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xe3, 0xa, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0xee, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xf1, 0xb, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xf6, 0xa, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x13, 0x5, 0x13, 0x106, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x6, 0x14, 0x10c, 0xa, 0x14, 0xd, 0x14, 0xe, 0x14, 0x10d, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x112, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0x11a, 0xa, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x11f, 0xa, 0x16, 0xc, 0x16, 
    0xe, 0x16, 0x122, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 
    0x127, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x12a, 0xb, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x12f, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x135, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
    0x138, 0xb, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x144, 
    0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x149, 0xa, 0x1b, 
    0xc, 0x1b, 0xe, 0x1b, 0x14c, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x7, 0x1c, 0x151, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x154, 0xb, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x159, 0xa, 0x1d, 0xc, 0x1d, 
    0xe, 0x1d, 0x15c, 0xb, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 
    0x161, 0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x164, 0xb, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x7, 0x1f, 0x169, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 
    0x16c, 0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x171, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x174, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 
    0x3, 0x21, 0x5, 0x21, 0x179, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x5, 0x22, 0x17e, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x6, 0x23, 
    0x183, 0xa, 0x23, 0xd, 0x23, 0xe, 0x23, 0x184, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x18a, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x7, 0x24, 0x18f, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x192, 0xb, 0x24, 
    0x3, 0x24, 0x5, 0x24, 0x195, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
    0x7, 0x25, 0x19a, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x19d, 0xb, 0x25, 
    0x3, 0x25, 0x5, 0x25, 0x1a0, 0xa, 0x25, 0x3, 0x25, 0x2, 0x2, 0x26, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x2, 0x7, 
    0x3, 0x2, 0x42, 0x4e, 0x3, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x31, 0x32, 0x5, 
    0x2, 0x22, 0x22, 0x33, 0x35, 0x40, 0x40, 0x4, 0x2, 0x31, 0x32, 0x36, 
    0x36, 0x2, 0x1c5, 0x2, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x53, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x59, 0x3, 0x2, 0x2, 0x2, 0x8, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xc, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xe, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x12, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x16, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xd6, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xda, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe2, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x22, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xfc, 0x3, 0x2, 0x2, 0x2, 0x26, 0x111, 0x3, 0x2, 0x2, 0x2, 0x28, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x123, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x130, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x143, 0x3, 0x2, 0x2, 0x2, 0x34, 0x145, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x38, 0x155, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x165, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x16d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x178, 0x3, 0x2, 0x2, 0x2, 0x42, 0x17a, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x189, 0x3, 0x2, 0x2, 0x2, 0x46, 0x18b, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x196, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x7, 0x16, 
    0x2, 0x2, 0x4b, 0x4d, 0x5, 0xc, 0x7, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x7, 0x2, 0x2, 0x3, 0x52, 0x3, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 
    0x6, 0x2, 0x2, 0x54, 0x55, 0x7, 0x17, 0x2, 0x2, 0x55, 0x56, 0x5, 0x6, 
    0x4, 0x2, 0x56, 0x57, 0x7, 0x26, 0x2, 0x2, 0x57, 0x58, 0x5, 0x26, 0x14, 
    0x2, 0x58, 0x5, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5b, 0x7, 0x23, 0x2, 0x2, 
    0x5a, 0x5c, 0x5, 0x8, 0x5, 0x2, 0x5b, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 
    0x7, 0x24, 0x2, 0x2, 0x5e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 0x5, 
    0xa, 0x6, 0x2, 0x60, 0x61, 0x7, 0x29, 0x2, 0x2, 0x61, 0x63, 0x5, 0x28, 
    0x15, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x25, 0x2, 0x2, 
    0x65, 0x68, 0x5, 0xa, 0x6, 0x2, 0x66, 0x67, 0x7, 0x29, 0x2, 0x2, 0x67, 
    0x69, 0x5, 0x28, 0x15, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x8e, 0x7, 0x25, 0x2, 0x2, 
    0x70, 0x72, 0x7, 0x22, 0x2, 0x2, 0x71, 0x73, 0x5, 0xa, 0x6, 0x2, 0x72, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0x25, 0x2, 0x2, 0x75, 0x78, 0x5, 
    0xa, 0x6, 0x2, 0x76, 0x77, 0x7, 0x29, 0x2, 0x2, 0x77, 0x79, 0x5, 0x28, 
    0x15, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x87, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x85, 0x7, 0x25, 0x2, 0x2, 0x80, 0x81, 0x7, 
    0x28, 0x2, 0x2, 0x81, 0x83, 0x5, 0xa, 0x6, 0x2, 0x82, 0x84, 0x7, 0x25, 
    0x2, 0x2, 0x83, 0x82, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x86, 0x3, 0x2, 0x2, 0x2, 0x85, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8f, 
    0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x28, 0x2, 0x2, 0x8a, 0x8c, 0x5, 
    0xa, 0x6, 0x2, 0x8b, 0x8d, 0x7, 0x25, 0x2, 0x2, 0x8c, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x70, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x89, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x91, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0xb1, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x94, 0x7, 0x22, 0x2, 0x2, 0x93, 0x95, 0x5, 
    0xa, 0x6, 0x2, 0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 
    0x2, 0x2, 0x95, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x25, 0x2, 
    0x2, 0x97, 0x9a, 0x5, 0xa, 0x6, 0x2, 0x98, 0x99, 0x7, 0x29, 0x2, 0x2, 
    0x99, 0x9b, 0x5, 0x28, 0x15, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x96, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa7, 0x7, 0x25, 0x2, 
    0x2, 0xa2, 0xa3, 0x7, 0x28, 0x2, 0x2, 0xa3, 0xa5, 0x5, 0xa, 0x6, 0x2, 
    0xa4, 0xa6, 0x7, 0x25, 0x2, 0x2, 0xa5, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xaa, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0xaa, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0x28, 0x2, 
    0x2, 0xac, 0xae, 0x5, 0xa, 0x6, 0x2, 0xad, 0xaf, 0x7, 0x25, 0x2, 0x2, 
    0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x5f, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x92, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xab, 0x3, 0x2, 0x2, 0x2, 0xb1, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xb5, 0x7, 0x17, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x26, 
    0x2, 0x2, 0xb4, 0xb6, 0x5, 0x28, 0x15, 0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0xba, 0x5, 0xe, 0x8, 0x2, 0xb8, 0xba, 0x5, 0x1e, 0x10, 0x2, 0xb9, 
    0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x10, 0x9, 0x2, 0xbc, 0xbd, 0x7, 
    0x16, 0x2, 0x2, 0xbd, 0xf, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x5, 0x12, 
    0xa, 0x2, 0xbf, 0xc1, 0x5, 0x16, 0xc, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0xc0, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc1, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xcd, 0x5, 0x48, 0x25, 0x2, 0xc3, 0xc4, 0x5, 0x14, 0xb, 0x2, 0xc4, 
    0xc5, 0x5, 0x48, 0x25, 0x2, 0xc5, 0xce, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 
    0x7, 0x29, 0x2, 0x2, 0xc7, 0xc9, 0x5, 0x48, 0x25, 0x2, 0xc8, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xc9, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xca, 0x3, 0x2, 0x2, 0x2, 0xce, 0x13, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd0, 0x9, 0x2, 0x2, 0x2, 0xd0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd5, 
    0x5, 0x18, 0xd, 0x2, 0xd2, 0xd5, 0x5, 0x1a, 0xe, 0x2, 0xd3, 0xd5, 0x5, 
    0x1c, 0xf, 0x2, 0xd4, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0x17, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd7, 0x7, 0x15, 0x2, 0x2, 0xd7, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0xd8, 0xd9, 0x7, 0x14, 0x2, 0x2, 0xd9, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xda, 
    0xdc, 0x7, 0x7, 0x2, 0x2, 0xdb, 0xdd, 0x5, 0x48, 0x25, 0x2, 0xdc, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdd, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xe3, 0x5, 0x20, 0x11, 0x2, 0xdf, 0xe3, 0x5, 0x22, 
    0x12, 0x2, 0xe0, 0xe3, 0x5, 0x24, 0x13, 0x2, 0xe1, 0xe3, 0x5, 0x4, 0x3, 
    0x2, 0xe2, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xe2, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x8, 0x2, 0x2, 0xe5, 0xe6, 
    0x5, 0x28, 0x15, 0x2, 0xe6, 0xe7, 0x7, 0x26, 0x2, 0x2, 0xe7, 0xef, 0x5, 
    0x26, 0x14, 0x2, 0xe8, 0xe9, 0x7, 0x9, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x28, 
    0x15, 0x2, 0xea, 0xeb, 0x7, 0x26, 0x2, 0x2, 0xeb, 0xec, 0x5, 0x26, 0x14, 
    0x2, 0xec, 0xee, 0x3, 0x2, 0x2, 0x2, 0xed, 0xe8, 0x3, 0x2, 0x2, 0x2, 
    0xee, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x7, 0xa, 0x2, 0x2, 0xf3, 0xf4, 0x7, 
    0x26, 0x2, 0x2, 0xf4, 0xf6, 0x5, 0x26, 0x14, 0x2, 0xf5, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0xf8, 0x7, 0xb, 0x2, 0x2, 0xf8, 0xf9, 0x5, 0x28, 0x15, 0x2, 
    0xf9, 0xfa, 0x7, 0x26, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x26, 0x14, 0x2, 0xfb, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0xc, 0x2, 0x2, 0xfd, 0xfe, 
    0x5, 0x46, 0x24, 0x2, 0xfe, 0xff, 0x7, 0xd, 0x2, 0x2, 0xff, 0x100, 0x5, 
    0x48, 0x25, 0x2, 0x100, 0x101, 0x7, 0x26, 0x2, 0x2, 0x101, 0x105, 0x5, 
    0x26, 0x14, 0x2, 0x102, 0x103, 0x7, 0xa, 0x2, 0x2, 0x103, 0x104, 0x7, 
    0x26, 0x2, 0x2, 0x104, 0x106, 0x5, 0x26, 0x14, 0x2, 0x105, 0x102, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0x107, 0x112, 0x5, 0xe, 0x8, 0x2, 0x108, 0x109, 0x7, 0x16, 
    0x2, 0x2, 0x109, 0x10b, 0x7, 0x51, 0x2, 0x2, 0x10a, 0x10c, 0x5, 0xc, 
    0x7, 0x2, 0x10b, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x7, 0x52, 
    0x2, 0x2, 0x110, 0x112, 0x3, 0x2, 0x2, 0x2, 0x111, 0x107, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x108, 0x3, 0x2, 0x2, 0x2, 0x112, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0x113, 0x119, 0x5, 0x2a, 0x16, 0x2, 0x114, 0x115, 0x7, 0x8, 0x2, 
    0x2, 0x115, 0x116, 0x5, 0x2a, 0x16, 0x2, 0x116, 0x117, 0x7, 0xa, 0x2, 
    0x2, 0x117, 0x118, 0x5, 0x28, 0x15, 0x2, 0x118, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x114, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x11a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x120, 0x5, 0x2c, 0x17, 
    0x2, 0x11c, 0x11d, 0x7, 0xe, 0x2, 0x2, 0x11d, 0x11f, 0x5, 0x2c, 0x17, 
    0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x122, 0x3, 0x2, 0x2, 
    0x2, 0x120, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x120, 0x121, 0x3, 0x2, 0x2, 
    0x2, 0x121, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x123, 0x128, 0x5, 0x2e, 0x18, 0x2, 0x124, 0x125, 0x7, 0xf, 0x2, 0x2, 
    0x125, 0x127, 0x5, 0x2e, 0x18, 0x2, 0x126, 0x124, 0x3, 0x2, 0x2, 0x2, 
    0x127, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x12a, 
    0x128, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x7, 0x10, 0x2, 0x2, 0x12c, 
    0x12f, 0x5, 0x2e, 0x18, 0x2, 0x12d, 0x12f, 0x5, 0x30, 0x19, 0x2, 0x12e, 
    0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0x130, 0x136, 0x5, 0x34, 0x1b, 0x2, 0x131, 
    0x132, 0x5, 0x32, 0x1a, 0x2, 0x132, 0x133, 0x5, 0x34, 0x1b, 0x2, 0x133, 
    0x135, 0x3, 0x2, 0x2, 0x2, 0x134, 0x131, 0x3, 0x2, 0x2, 0x2, 0x135, 
    0x138, 0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 0x136, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x31, 0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x144, 0x7, 0x39, 0x2, 0x2, 0x13a, 0x144, 
    0x7, 0x3a, 0x2, 0x2, 0x13b, 0x144, 0x7, 0x3b, 0x2, 0x2, 0x13c, 0x144, 
    0x7, 0x3c, 0x2, 0x2, 0x13d, 0x144, 0x7, 0x3d, 0x2, 0x2, 0x13e, 0x144, 
    0x7, 0x3e, 0x2, 0x2, 0x13f, 0x144, 0x7, 0x3f, 0x2, 0x2, 0x140, 0x144, 
    0x7, 0xd, 0x2, 0x2, 0x141, 0x142, 0x7, 0x10, 0x2, 0x2, 0x142, 0x144, 
    0x7, 0xd, 0x2, 0x2, 0x143, 0x139, 0x3, 0x2, 0x2, 0x2, 0x143, 0x13a, 
    0x3, 0x2, 0x2, 0x2, 0x143, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x143, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x143, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x143, 0x13e, 
    0x3, 0x2, 0x2, 0x2, 0x143, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x143, 0x140, 
    0x3, 0x2, 0x2, 0x2, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x144, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x145, 0x14a, 0x5, 0x36, 0x1c, 0x2, 0x146, 0x147, 0x7, 
    0x2c, 0x2, 0x2, 0x147, 0x149, 0x5, 0x36, 0x1c, 0x2, 0x148, 0x146, 0x3, 
    0x2, 0x2, 0x2, 0x149, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 
    0x2, 0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x152, 0x5, 0x38, 
    0x1d, 0x2, 0x14e, 0x14f, 0x7, 0x2d, 0x2, 0x2, 0x14f, 0x151, 0x5, 0x38, 
    0x1d, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x151, 0x154, 0x3, 0x2, 
    0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 
    0x2, 0x2, 0x153, 0x37, 0x3, 0x2, 0x2, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 
    0x2, 0x155, 0x15a, 0x5, 0x3a, 0x1e, 0x2, 0x156, 0x157, 0x7, 0x2e, 0x2, 
    0x2, 0x157, 0x159, 0x5, 0x3a, 0x1e, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x159, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x15c, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x162, 0x5, 0x3c, 0x1f, 0x2, 
    0x15e, 0x15f, 0x9, 0x3, 0x2, 0x2, 0x15f, 0x161, 0x5, 0x3c, 0x1f, 0x2, 
    0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 
    0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 
    0x163, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 0x2, 0x165, 
    0x16a, 0x5, 0x3e, 0x20, 0x2, 0x166, 0x167, 0x9, 0x4, 0x2, 0x2, 0x167, 
    0x169, 0x5, 0x3e, 0x20, 0x2, 0x168, 0x166, 0x3, 0x2, 0x2, 0x2, 0x169, 
    0x16c, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16a, 
    0x16b, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16a, 
    0x3, 0x2, 0x2, 0x2, 0x16d, 0x172, 0x5, 0x40, 0x21, 0x2, 0x16e, 0x16f, 
    0x9, 0x5, 0x2, 0x2, 0x16f, 0x171, 0x5, 0x40, 0x21, 0x2, 0x170, 0x16e, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x174, 0x3, 0x2, 0x2, 0x2, 0x172, 0x170, 
    0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x174, 0x172, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x9, 
    0x6, 0x2, 0x2, 0x176, 0x179, 0x5, 0x40, 0x21, 0x2, 0x177, 0x179, 0x5, 
    0x42, 0x22, 0x2, 0x178, 0x175, 0x3, 0x2, 0x2, 0x2, 0x178, 0x177, 0x3, 
    0x2, 0x2, 0x2, 0x179, 0x41, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17d, 0x5, 0x44, 
    0x23, 0x2, 0x17b, 0x17c, 0x7, 0x28, 0x2, 0x2, 0x17c, 0x17e, 0x5, 0x40, 
    0x21, 0x2, 0x17d, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 
    0x2, 0x2, 0x17e, 0x43, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x18a, 0x7, 0x17, 
    0x2, 0x2, 0x180, 0x18a, 0x7, 0x4, 0x2, 0x2, 0x181, 0x183, 0x7, 0x3, 
    0x2, 0x2, 0x182, 0x181, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x184, 0x185, 0x3, 0x2, 
    0x2, 0x2, 0x185, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x186, 0x18a, 0x7, 0x11, 
    0x2, 0x2, 0x187, 0x18a, 0x7, 0x12, 0x2, 0x2, 0x188, 0x18a, 0x7, 0x13, 
    0x2, 0x2, 0x189, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x189, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x182, 0x3, 0x2, 0x2, 0x2, 0x189, 0x186, 0x3, 0x2, 
    0x2, 0x2, 0x189, 0x187, 0x3, 0x2, 0x2, 0x2, 0x189, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x18a, 0x45, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x190, 0x5, 0x34, 
    0x1b, 0x2, 0x18c, 0x18d, 0x7, 0x25, 0x2, 0x2, 0x18d, 0x18f, 0x5, 0x34, 
    0x1b, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x191, 0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x193, 0x195, 0x7, 0x25, 0x2, 0x2, 0x194, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x194, 0x195, 0x3, 0x2, 0x2, 0x2, 0x195, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x196, 0x19b, 0x5, 0x28, 0x15, 0x2, 0x197, 0x198, 0x7, 0x25, 0x2, 
    0x2, 0x198, 0x19a, 0x5, 0x28, 0x15, 0x2, 0x199, 0x197, 0x3, 0x2, 0x2, 
    0x2, 0x19a, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 
    0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a0, 0x7, 0x25, 0x2, 
    0x2, 0x19f, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x1a0, 0x49, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x4c, 0x4e, 0x5b, 0x62, 
    0x68, 0x6c, 0x72, 0x78, 0x7c, 0x83, 0x85, 0x87, 0x8c, 0x8e, 0x90, 0x94, 
    0x9a, 0x9e, 0xa5, 0xa7, 0xa9, 0xae, 0xb0, 0xb5, 0xb9, 0xc0, 0xca, 0xcd, 
    0xd4, 0xdc, 0xe2, 0xef, 0xf5, 0x105, 0x10d, 0x111, 0x119, 0x120, 0x128, 
    0x12e, 0x136, 0x143, 0x14a, 0x152, 0x15a, 0x162, 0x16a, 0x172, 0x178, 
    0x17d, 0x184, 0x189, 0x190, 0x194, 0x19b, 0x19f, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

Python3Parser::Initializer Python3Parser::_init;
