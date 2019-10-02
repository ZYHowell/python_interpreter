//
// Created by jinho on 9/28/2019.
//

#include "Evalvisitor.h"
virtual antlrcpp::Any EvalVisitor::visitFile_input(Python3Parser::File_inputContext *ctx) 
{
    for (auto current_stmt : ctx->stmt()) {
        visit(current_stmt);
    }
    return antlr::Any();
}

virtual antlrcpp::Any EvalVisitor::visitFuncdef(Python3Parser::FuncdefContext *ctx) 
{
    auto params = visit(ctx->parameters());
    program.funcs.insert()
}

virtual antlrcpp::Any EvalVisitor::visitParameters(Python3Parser::ParametersContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitTypedargslist(Python3Parser::TypedargslistContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitTfpdef(Python3Parser::TfpdefContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitStmt(Python3Parser::StmtContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitSimple_stmt(Python3Parser::Simple_stmtContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitSmall_stmt(Python3Parser::Small_stmtContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitExpr_stmt(Python3Parser::Expr_stmtContext *ctx) 
{
    auto objnames = visit(ctx->testlist(0));
    if (ctx->augassign() == nullptr) {
        if (ctx->testlist().size())
    }
}

virtual antlrcpp::Any EvalVisitor::visitAugassign(Python3Parser::AugassignContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitFlow_stmt(Python3Parser::Flow_stmtContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitBreak_stmt(Python3Parser::Break_stmtContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitContinue_stmt(Python3Parser::Continue_stmtContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitReturn_stmt(Python3Parser::Return_stmtContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitCompound_stmt(Python3Parser::Compound_stmtContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitIf_stmt(Python3Parser::If_stmtContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitWhile_stmt(Python3Parser::While_stmtContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitFor_stmt(Python3Parser::For_stmtContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitSuite(Python3Parser::SuiteContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitTest(Python3Parser::TestContext *ctx) 
{
    return visit(ctx->or_test());
}

virtual antlrcpp::Any EvalVisitor::visitOr_test(Python3Parser::Or_testContext *ctx) 
{
    if (ctx->and_test().size() == 1) {
        return visit(ctx->and_test(0));
    } else {
        return visit(ctx->and_test(0)).as<int>() || visit(ctx->and_test(1)).as<int>();
    }
}

virtual antlrcpp::Any EvalVisitor::visitAnd_test(Python3Parser::And_testContext *ctx) 
{
    if (ctx->not_test().size() == 1) {
        return visit(ctx->not_test(0));
    } else {
        return visit(ctx->not_test(0)).as<int>() && visit(ctx->not_test(1)).as<int>();
    }
}

virtual antlrcpp::Any EvalVisitor::visitNot_test(Python3Parser::Not_testContext *ctx) 
{
    if (ctx->NOT() != nullptr){
        return !visit(ctx->not_test());
    } else {
        return visit(ctx->comparison());
    }
}

virtual antlrcpp::Any EvalVisitor::visitComparison(Python3Parser::ComparisonContext *ctx) 
{
    Any first = visit(ctx->arith_expr(0));
    int num = 0;
    Any second;
    for (auto op : comp_op){
        second = visit(ctx->arith_expr(++i));
        if (op->LESS_THAN() != nullptr){

        }
        else if (op->GREATER_THAN() != nullptr){

        }
        else if (op->EQUALS() != nullptr){

        }
        else if (op->GT_EQ() != nullptr){

        }
        else{

        }
    }
}

// virtual antlrcpp::Any EvalVisitor::visitComp_op(Python3Parser::Comp_opContext *ctx) 
// {
//     return visitChildren(ctx);
// }

virtual antlrcpp::Any EvalVisitor::visitArith_expr(Python3Parser::Arith_exprContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitTerm(Python3Parser::TermContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitFactor(Python3Parser::FactorContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitAtom_expr(Python3Parser::Atom_exprContext *ctx) 
{
    Any ret = visit(ctx->atom());
    if (ctx->trailer().size()) {

    } else {

    }
}

virtual antlrcpp::Any EvalVisitor::visitTrailer(Python3Parser::TrailerContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitAtom(Python3Parser::AtomContext *ctx) 
{
    if (ctx->NUMBER() != nullptr){
        
    } else if (ctx->NAME() != nullptr) {
        
    } else if (ctx->STRING().size() != 0) {
        std::string ret = "";
        for (auto &str : ctx->STRING()) {
            ret += str->toString();
        }
        return ret;
    } else if (ctx->NONE() != nullptr) {
        return nullptr;
    } else if (ctx->TRUE() != nullptr) {
        return true;
    } else if (ctx->FALSE() != nullptr) {
        return false;
    }
}

virtual antlrcpp::Any EvalVisitor::visitNamelist(Python3Parser::NamelistContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitTestlist(Python3Parser::TestlistContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitArglist(Python3Parser::ArglistContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitArgument(Python3Parser::ArgumentContext *ctx) 
{
    
}