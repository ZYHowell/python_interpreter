
// Generated from .\Python3.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "Python3Visitor.h"


/**
 * This class provides an empty implementation of Python3Visitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  Python3BaseVisitor : public Python3Visitor {
public:

  virtual antlrcpp::Any visitSingle_input(Python3Parser::Single_inputContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFile_input(Python3Parser::File_inputContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEval_input(Python3Parser::Eval_inputContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecorator(Python3Parser::DecoratorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecorators(Python3Parser::DecoratorsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecorated(Python3Parser::DecoratedContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAsync_funcdef(Python3Parser::Async_funcdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncdef(Python3Parser::FuncdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(Python3Parser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypedargslist(Python3Parser::TypedargslistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTfpdef(Python3Parser::TfpdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarargslist(Python3Parser::VarargslistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVfpdef(Python3Parser::VfpdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(Python3Parser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_stmt(Python3Parser::Simple_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSmall_stmt(Python3Parser::Small_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_stmt(Python3Parser::Expr_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnnassign(Python3Parser::AnnassignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTestlist_star_expr(Python3Parser::Testlist_star_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAugassign(Python3Parser::AugassignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDel_stmt(Python3Parser::Del_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPass_stmt(Python3Parser::Pass_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFlow_stmt(Python3Parser::Flow_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBreak_stmt(Python3Parser::Break_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitContinue_stmt(Python3Parser::Continue_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn_stmt(Python3Parser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYield_stmt(Python3Parser::Yield_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRaise_stmt(Python3Parser::Raise_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_stmt(Python3Parser::Import_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_name(Python3Parser::Import_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_from(Python3Parser::Import_fromContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_as_name(Python3Parser::Import_as_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDotted_as_name(Python3Parser::Dotted_as_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImport_as_names(Python3Parser::Import_as_namesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDotted_as_names(Python3Parser::Dotted_as_namesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDotted_name(Python3Parser::Dotted_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobal_stmt(Python3Parser::Global_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonlocal_stmt(Python3Parser::Nonlocal_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssert_stmt(Python3Parser::Assert_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_stmt(Python3Parser::Compound_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAsync_stmt(Python3Parser::Async_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_stmt(Python3Parser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_stmt(Python3Parser::While_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_stmt(Python3Parser::For_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTry_stmt(Python3Parser::Try_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWith_stmt(Python3Parser::With_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWith_item(Python3Parser::With_itemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExcept_clause(Python3Parser::Except_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSuite(Python3Parser::SuiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTest(Python3Parser::TestContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTest_nocond(Python3Parser::Test_nocondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLambdef(Python3Parser::LambdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLambdef_nocond(Python3Parser::Lambdef_nocondContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOr_test(Python3Parser::Or_testContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnd_test(Python3Parser::And_testContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNot_test(Python3Parser::Not_testContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComparison(Python3Parser::ComparisonContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComp_op(Python3Parser::Comp_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStar_expr(Python3Parser::Star_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(Python3Parser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitXor_expr(Python3Parser::Xor_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAnd_expr(Python3Parser::And_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitShift_expr(Python3Parser::Shift_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArith_expr(Python3Parser::Arith_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(Python3Parser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(Python3Parser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPower(Python3Parser::PowerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtom_expr(Python3Parser::Atom_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAtom(Python3Parser::AtomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTestlist_comp(Python3Parser::Testlist_compContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrailer(Python3Parser::TrailerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubscriptlist(Python3Parser::SubscriptlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubscript(Python3Parser::SubscriptContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSliceop(Python3Parser::SliceopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprlist(Python3Parser::ExprlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTestlist(Python3Parser::TestlistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDictorsetmaker(Python3Parser::DictorsetmakerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitClassdef(Python3Parser::ClassdefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArglist(Python3Parser::ArglistContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgument(Python3Parser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComp_iter(Python3Parser::Comp_iterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComp_for(Python3Parser::Comp_forContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComp_if(Python3Parser::Comp_ifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEncoding_decl(Python3Parser::Encoding_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYield_expr(Python3Parser::Yield_exprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitYield_arg(Python3Parser::Yield_argContext *ctx) override {
    return visitChildren(ctx);
  }


};

