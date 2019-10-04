#ifndef PYTHON_INTERPRETER_EVALVISITOR_H
#define PYTHON_INTERPRETER_EVALVISITOR_H

#include <cmath>
#include "Python3BaseVisitor.h"
#include "Program.h"
#include "exceptions.h"
class EvalVisitor: public Python3BaseVisitor {
private:
    using Any = antlrcpp::Any;
    Program program;
public:
    virtual antlrcpp::Any visitFile_input(Python3Parser::File_inputContext *ctx);
    virtual antlrcpp::Any visitFuncdef(Python3Parser::FuncdefContext *ctx);
    virtual antlrcpp::Any visitParameters(Python3Parser::ParametersContext *ctx);
    virtual antlrcpp::Any visitTypedargslist(Python3Parser::TypedargslistContext *ctx);
    virtual antlrcpp::Any visitTfpdef(Python3Parser::TfpdefContext *ctx);
    virtual antlrcpp::Any visitStmt(Python3Parser::StmtContext *ctx);
    virtual antlrcpp::Any visitSimple_stmt(Python3Parser::Simple_stmtContext *ctx);
    virtual antlrcpp::Any visitSmall_stmt(Python3Parser::Small_stmtContext *ctx);
    virtual antlrcpp::Any visitExpr_stmt(Python3Parser::Expr_stmtContext *ctx);
    virtual antlrcpp::Any visitAugassign(Python3Parser::AugassignContext *ctx);
    virtual antlrcpp::Any visitFlow_stmt(Python3Parser::Flow_stmtContext *ctx);
    virtual antlrcpp::Any visitBreak_stmt(Python3Parser::Break_stmtContext *ctx);
    virtual antlrcpp::Any visitContinue_stmt(Python3Parser::Continue_stmtContext *ctx);
    virtual antlrcpp::Any visitReturn_stmt(Python3Parser::Return_stmtContext *ctx);
    virtual antlrcpp::Any visitCompound_stmt(Python3Parser::Compound_stmtContext *ctx);
    virtual antlrcpp::Any visitIf_stmt(Python3Parser::If_stmtContext *ctx);
    virtual antlrcpp::Any visitWhile_stmt(Python3Parser::While_stmtContext *ctx);
    virtual antlrcpp::Any visitFor_stmt(Python3Parser::For_stmtContext *ctx);
    virtual antlrcpp::Any visitSuite(Python3Parser::SuiteContext *ctx);
    virtual antlrcpp::Any visitTest(Python3Parser::TestContext *ctx);
    virtual antlrcpp::Any visitOr_test(Python3Parser::Or_testContext *ctx);
    virtual antlrcpp::Any visitAnd_test(Python3Parser::And_testContext *ctx);
    virtual antlrcpp::Any visitNot_test(Python3Parser::Not_testContext *ctx);
    virtual antlrcpp::Any visitComparison(Python3Parser::ComparisonContext *ctx);
    virtual antlrcpp::Any visitComp_op(Python3Parser::Comp_opContext *ctx);
    virtual antlrcpp::Any visitArith_expr(Python3Parser::Arith_exprContext *ctx);
    virtual antlrcpp::Any visitTerm(Python3Parser::TermContext *ctx);
    virtual antlrcpp::Any visitFactor(Python3Parser::FactorContext *ctx);
    virtual antlrcpp::Any visitAtom_expr(Python3Parser::Atom_exprContext *ctx);
    virtual antlrcpp::Any visitTrailer(Python3Parser::TrailerContext *ctx);
    virtual antlrcpp::Any visitAtom(Python3Parser::AtomContext *ctx);
    virtual antlrcpp::Any visitNamelist(Python3Parser::NamelistContext *ctx);
    virtual antlrcpp::Any visitTestlist(Python3Parser::TestlistContext *ctx);
    virtual antlrcpp::Any visitArglist(Python3Parser::ArglistContext *ctx);
    virtual antlrcpp::Any visitArgument(Python3Parser::ArgumentContext *ctx);
    inline size_t AreNames(antlrcpp::Any list);
    inline bool IsName(antlrcpp::Any &ele);
    inline size_t getNodeIndex(antlr4::tree::TerminalNode* it);
    inline bool isList(antlrcpp::Any &it);
    inline int toInt(antlrcpp::Any &it);
    inline void checkType(Any &a, Any &b);
    inline bool lessThan(Any &a, Any &b);
    inline bool greaterThan(Any &a, Any &b);
    inline bool equals(Any &a, Any &b);
    inline bool gtEq(Any &a, Any &b);
    inline bool lsEq(Any &a, Any &b);
};


#endif //PYTHON_INTERPRETER_EVALVISITOR_H
