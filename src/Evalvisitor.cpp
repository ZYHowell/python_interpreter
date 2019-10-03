#include "Evalvisitor.h"
virtual antlrcpp::Any EvalVisitor::visitFile_input(Python3Parser::File_inputContext *ctx) 
{
    for (auto current_stmt : ctx->stmt()) {
        visit(current_stmt).as<int>;
        //how to end a function or the program?
    }
    return antlr::Any();
}

virtual antlrcpp::Any EvalVisitor::visitFuncdef(Python3Parser::FuncdefContext *ctx) 
{
    auto params = visit(ctx->parameters());
    program.funcs.insert(std::make_pair(ctx->NAME()->toString(), Function(ctx->suite(), *params)));
    return Any();
}

virtual antlrcpp::Any EvalVisitor::visitParameters(Python3Parser::ParametersContext *ctx) 
{
    if (ctx->typedargslist() == nullptr) {
        return std::make_shared<std::vector<std::string>>(std::vector<std::string>());
    } else{
        return visit(ctx->typedargslist());
    }
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
    if (ctx->simple_stmt() != nullptr) {
        return visit(ctx->simple_stmt());
    } else{
        return visit(ctx->compound_stmt());
    }
}

virtual antlrcpp::Any EvalVisitor::visitSimple_stmt(Python3Parser::Simple_stmtContext *ctx) 
{
    return visit(ctx->small_stmt());
}

virtual antlrcpp::Any EvalVisitor::visitSmall_stmt(Python3Parser::Small_stmtContext *ctx) 
{
    if (ctx->flow_stmt() == nullptr) {
        return visit(ctx->expr_stmt());
    } else{
        return visit(ctx->flow_stmt());
    }
}

bool EvalVisitor::AreNames(antlrcpp::Any &list) 
{
    auto names = list.as<std::vector<antlrcpp::Any>>();
    for (auto name : names) {
        if (!name.is<antlrcpp::Any *>)
            return false;
    }
    return true;
}

virtual antlrcpp::Any EvalVisitor::visitExpr_stmt(Python3Parser::Expr_stmtContext *ctx) 
{
    antlrcpp::Any list;
    auto result = visit(ctx->testlist(ctx->testlist.size() - 1));
    if (ctx->augassign() == nullptr) {
        list = visit(ctx->testlist(0))
        if (!AreNames(list)) {
            //cerr
        } else {
            if (ctx->augassign()->ADD_ASSIGN != nullptr) {

            } else if (ctx->augassign()->SUB_ASSIGN() != nullptr) {

            } else if (ctx->augassign()->MULT_ASSIGN() != nullptr) {

            } else {

            }
        }
    } else {
        for (int i = ctx->testlist.size() - 2;i >= 0;i--) {
            list = visit(ctx->testlist(i))
            if (!AreNames(list)) {
                //cerr
            } else {

            }
        }
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
    Any ret;
    while(visit(ctx->test())) {
        ret = visit(ctx->suite());
        if (ret.as<> == ) break;
        else if (ret.as<> == ) continue;
        else if (ret.is<antlrcpp::Any *>) return ret;
        //another class is needed
    }
    return Any();
}

// virtual antlrcpp::Any EvalVisitor::visitFor_stmt(Python3Parser::For_stmtContext *ctx) 
// {
    
// }

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
    Any expre[2];
    int num = 0;
    bool fir = 0;
    expre[0] = visit(ctx->arith_expr(num));
    for (auto op : comp_op){
        expre[!fir] = visit(ctx->arith_expr(++num));
        //since STRING type, the comparison may need to be improved
        if (op->LESS_THAN() != nullptr){
            if (!expre[fir] < expre[!fir])
                return false;
        }
        else if (op->GREATER_THAN() != nullptr){
            if (!expre[fir] > expre[!fir])
                return false;
        }
        else if (op->EQUALS() != nullptr){
            if (!expre[fir] == expre[!fir])
                return false;
        }
        else if (op->GT_EQ() != nullptr){
            if (!expre[fir] >= expre[!fir])
                return false;
        }
        else{
            if (!expre[fir] <= expre[!fir])
                return false;
        }
        fir = !fir;
    }
    return true;
}

virtual antlrcpp::Any EvalVisitor::visitComp_op(Python3Parser::Comp_opContext *ctx) 
{
    //no need to override it, or in order to be safer, it is necessary to override?
    return visitChildren(ctx);
}

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
    if (ctx->trailer().size()) {
        if (ctx->atom().NAME() == nullptr) {
            //cerr
        } else {
            std::string funcName = ctx->atom()->NAME()->toString();
            Function func = program.funcs[funcName];
            //needs to be improved since it is slow.
            program.frames.push(Frame());
            std::map<std::string, antlrcpp::Any> *mem = program.frames.top.memory;
            for (auto i : func.params)
        }
    } else {
        Any ret = visit(ctx->atom());
        return ret;
    }
}

virtual antlrcpp::Any EvalVisitor::visitTrailer(Python3Parser::TrailerContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitAtom(Python3Parser::AtomContext *ctx) 
{
    if (ctx->NUMBER() != nullptr){
        //this version do not support superlong caculation

    } else if (ctx->NAME() != nullptr) {
        std::string name = ctx->NAME()->toString();
        return program.getValue(name);
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
    std::vector<antlrcpp::Any *> ret(ctx->NAME().size());


    return ret;
}

virtual antlrcpp::Any EvalVisitor::visitTestlist(Python3Parser::TestlistContext *ctx) 
{
    std::vector<antlrcpp::Any> ret(ctx->test().size());
    for (auto testEle : ctx->test()) {
        ret.push_back(visit(testEle));
        //can this be a pointer?
    }
    return ret;
}

virtual antlrcpp::Any EvalVisitor::visitArglist(Python3Parser::ArglistContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitArgument(Python3Parser::ArgumentContext *ctx) 
{
    
}