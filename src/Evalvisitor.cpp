#include "Evalvisitor.h"
inline bool EvalVisitor::isList(antlrcpp::Any &it)
{
    return (it.is<std::vector<Any>>() || 
            it.is<std::vector<Any *>>()
            )
}
inline size_t EvalVisitor::AreNames(antlrcpp::Any &list) 
{
    if (!list.is<std::vector<antlrcpp::Any>>()) {
        //err
    }
    auto names = list.as<std::vector<antlrcpp::Any>>();
    for (auto name : names) {
        if (!name.is<antlrcpp::Any *>)
            return 0;
    }
    return names.size();
}
inline bool EvalVisitor::IsName(antlrcpp:: Any &ele)
{
    return ele.is<antlrcpp::Any *>;
}


inline size_t EvalVisitor::getNodeIndex(antlr4::tree::TerminalNode* it)
{
    return it->getSymbol()->getTokenIndex();
}


inline int EvalVisitor::toInt(antlrcpp::Any &it)
{
    if (it.is<std::string>() || it.is<void *>) {
        //err
    } else if (it.is<bool>()){
        return it.as<bool>();
    } else if (it.is<int>()) {
        return it.as<int>();
    }
}


inline void EvalVisitor::checkType(Any &a, Any &b)
{
    if (b.is<void *>) {
        //err
    }
    if ((a.is<std::string> && !b.is<std::string>) ||
         !a.is<std::string && b.is<std::string>>) {
        //err
    }
    return;
}


inline bool EvalVisitor::lessThan(Any &a, Any &b)
{
    checkType(a, b);
    if (a.is<std::string>) {
        return a.as<std::string> < b.as<std::string>;
    } else {
        return toInt(a) < toInt(b);
    }
}
inline bool EvalVisitor::greaterThan(Any &a, Any &b)
{
    checkType(a, b);
    if (a.is<std::string>) {
        return a.as<std::string> > b.as<std::string>;
    } else {
        return toInt(a) > toInt(b);
    }
}
inline bool EvalVisitor::equals(Any &a, Any &b)
{
    checkType(a, b);
    if (a.is<std::string>) {
        return a.as<std::string> == b.as<std::string>;
    } else {
        return toInt(a) == toInt(b);
    }
}
inline bool EvalVisitor::gtEq(Any &a, Any &b)
{
    checkType(a, b);
    if (a.is<std::string>) {
        return a.as<std::string> >= b.as<std::string>;
    } else {
        return toInt(a) >= toInt(b);
    }
}
inline bool EvalVisitor::lsEq(Any &a, Any &b)
{
    checkType(a, b);
    if (a.is<std::string>) {
        return a.as<std::string> <= b.as<std::string>;
    } else {
        return toInt(a) <= toInt(b);
    }
}


virtual antlrcpp::Any EvalVisitor::visitFile_input(Python3Parser::File_inputContext *ctx) 
{
    for (auto current_stmt : ctx->stmt()) {
        visit(current_stmt).as<size_t>();
        //how to end a function or the whole program?
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


virtual antlrcpp::Any EvalVisitor::visitExpr_stmt(Python3Parser::Expr_stmtContext *ctx) 
{
    antlrcpp::Any testEle;
    auto result = visit(ctx->testlist(ctx->testlist.size() - 1));
    if (ctx->augassign() == nullptr) {
        program.checkIsName = true;
        testEle = visit(ctx->testlist(0));
        program.checkIsName = false;
        if (isList(testEle)) {
            //err
        }
        if (ctx->augassign()->ADD_ASSIGN != nullptr) {

        } else if (ctx->augassign()->SUB_ASSIGN() != nullptr) {

        } else if (ctx->augassign()->MULT_ASSIGN() != nullptr) {

        } else {

        }
    } else {
        program.checkIsName = true;
        for (size_t i = ctx->testlist.size() - 2;i >= 0;--i) {
            list = testEle(ctx->testlist(i))
        }
        program.checkIsName = false;
    }
    return Any();
}

virtual antlrcpp::Any EvalVisitor::visitAugassign(Python3Parser::AugassignContext *ctx) 
{
    return visitChildren(ctx);
}

virtual antlrcpp::Any EvalVisitor::visitFlow_stmt(Python3Parser::Flow_stmtContext *ctx) 
{
    if (ctx->break_stmt() != nullptr) {
        return visit(ctx->break_stmt());
    } else if (ctx->continue_stmt() != nullptr) {
        return visit(ctx->continue_stmt());
    } else {
        return visit(ctx->return_stmt());
    }
}

virtual antlrcpp::Any EvalVisitor::visitBreak_stmt(Python3Parser::Break_stmtContext *ctx) 
{
    return sjtu::flowRet(1);
}

virtual antlrcpp::Any EvalVisitor::visitContinue_stmt(Python3Parser::Continue_stmtContext *ctx) 
{
    return sjtu::flowRet(2);
}

virtual antlrcpp::Any EvalVisitor::visitReturn_stmt(Python3Parser::Return_stmtContext *ctx) 
{
    return sjtu::flowRet(3, visit(ctx->testlist()))
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
    if (ctx->simple_stmt() != nullptr) {
        auto ret = visit(ctx->simple_stmt());
    } else {
        size_t num = ctx->stmt().size();
        size_t current = 0;
        while (current < num) {
            auto stmtRet = visit(ctx->stmt(current));
            if (stmtRet.is<>()) {
                //deal with return/break/continue
            } else ++current;
        }
    }
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
        if (program.checkIsName) {
            //err
        }
        return visit(ctx->and_test(0)).as<int>() || visit(ctx->and_test(1)).as<int>();
    }
}

virtual antlrcpp::Any EvalVisitor::visitAnd_test(Python3Parser::And_testContext *ctx) 
{
    if (ctx->not_test().size() == 1) {
        return visit(ctx->not_test(0));
    } else {
        if (program.checkIsName) {
            //err
        }
        return visit(ctx->not_test(0)).as<int>() && visit(ctx->not_test(1)).as<int>();
    }
}

virtual antlrcpp::Any EvalVisitor::visitNot_test(Python3Parser::Not_testContext *ctx) 
{
    if (ctx->NOT() != nullptr){
        if (program.checkIsName) {
            //err
        }
        return !visit(ctx->not_test());
    } else {
        return visit(ctx->comparison());
    }
}


virtual antlrcpp::Any EvalVisitor::visitComparison(Python3Parser::ComparisonContext *ctx) 
{
    Any expre[2];
    size_t num = 0;
    bool fir = 0;
    expre[0] = visit(ctx->arith_expr(num));
    auto comp_op = ctx->comp_op();
    if (!comp_op.size())
        return expre[0];
    if (program.checkIsName || expre[0].is<void *>) {
        //err
    }
    for (auto op : comp_op){
        expre[!fir] = visit(ctx->arith_expr(++num));
        //since STRING type, the comparison may need to be improved
        if (op->LESS_THAN() != nullptr){
            if lessThan(!expre[fir], expre[!fir])
                return false;
        }
        else if (op->GREATER_THAN() != nullptr) {
            if greaterThan(!expre[fir], expre[!fir])
                return false;
        }
        else if (op->EQUALS() != nullptr) {
            if equals(!expre[fir], expre[!fir])
                return false;
        }
        else if (op->GT_EQ() != nullptr) {
            if gtEq(!expre[fir], expre[!fir])
                return false;
        }
        else{
            if lsEq(!expre[fir], expre[!fir])
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
    //waiting to check validity
    auto ret = visit(ctx->term(0));
    Any nex;
    size_t num = visit(ctx->term().size());
    size_t addN = 0, minusN = 0, addMax = ctx->ADD().size(), minusMax = ctx->MINUS().size();
    
    if (num == 1) {
        return ret;
    }
    
    if (program.checkIsName || ret.is<void *>()) {
        //err
    }
    
    if (ret.is<std::string>) {
        if (minusMax) {
            //err
        }
        std::string result = ret.as<std::string>();
        for (size_t i = 1;i < num;++i) {
            result = result + visit(ctx->term(i)).as<std::string>();
        }
        return result;
    }
    
    int result = toInt(ret);
    for (size_t i = 1;i < num;++i) {
        nex = toInt(visit(ctx->term(i)));
        if (addN >= addMax) {
            ret -= nex;
            ++minusN;
        } else if (minusN >= minusMax) {
            ret += nex;
            ++addN;
        } else if (getNodeIndex(ctx->ADD(addN)) > getNodeIndex(ctx->MINUS(minusN))) {
            ret -= nex;
            ++minusN;
        } else {
            ret += nex;
            ++addN;
        }
    }
    return ret;
}

virtual antlrcpp::Any EvalVisitor::visitTerm(Python3Parser::TermContext *ctx) 
{
    auto ret = visit(ctx->term(0));
    size_t num = visit(ctx->term().size());
    size_t starN = 0, divN = 0, starMax = ctx->STAR().size(), divMax = ctx->DIV().size();
    
    if (num == 1) return ret;
    
    if (program.checkIsName) {
        //err
    }

    int result = toInt(ret);
    int nex;
    for (size_t i = 1;i < num;++i) {
        nex = toInt(visit(ctx->term(i)));
        if (starN >= starMax) {
            result /= nex;
            ++divN;
        } else if (divN >= divMax) {
            result *= nex;
            ++starN;
        } else if (getNodeIndex(ctx->STAR(starN)) > getNodeIndex(ctx->DIV(divN))) {
            result /= nex;
            ++divN;
        } else {
            result *= nex;
            ++starN;
        }
    }
    return result;
}

virtual antlrcpp::Any EvalVisitor::visitFactor(Python3Parser::FactorContext *ctx) 
{
    //waiting to check validity
    if (ctx->atom_expr() != nullptr) {
        return visit(ctx->atom_expr());
    } else {
        if (program.checkIsName) {
            //err
        }
        Any ret = visit(ctx->factor());
        if (ctx->ADD() != nullptr) {
            if (ret.is<std::string>() || (ret.is<void *>())) {
                //err
            } else {
                if (ret.is<bool>) {
                    return (int)ret.as<bool>();
                }
                else return ret;
            }
        }
        else if (ret.is<std::string>() || (ret.is<void *>())) {
            //cerr
        } else {
            if (ret.is<bool>) {
                return -1 * (int)ret.as<bool>();
            }
            else return -1 * ret.as<int>(;)
        }
    }
}

virtual antlrcpp::Any EvalVisitor::visitAtom_expr(Python3Parser::Atom_exprContext *ctx) 
{
    if (ctx->trailer().size()) {
        if (ctx->atom().NAME() == nullptr) {
            //err
        } else {
            std::string funcName = ctx->atom()->NAME()->toString();
            if (funcName == "print") {
                //deal with Print
            }
            if (!program.funcs.count(funcName)) {
                //err
            }
            auto paraNum = visit(ctx->trailer()).as<std::vector<antlrcpp::Any>>;
            Function func = program.funcs[funcName];
            //needs to be improved since it is slow.
            program.frames.push(Frame());
            std::map<std::string, antlrcpp::Any> *mem = program.frames.top.memory;
            size_t num = func.params.size();
            for (size_t i = 0;i < num;++i) {
                (*mem)[func.params[i]] = paraNum[i];
            }
            auto ret = visit(func.suite);
            program.frames.pop();
        }
    } else {
        Any ret = visit(ctx->atom());
        return ret;
    }
}

virtual antlrcpp::Any EvalVisitor::visitTrailer(Python3Parser::TrailerContext *ctx) 
{
    return visit(ctx->arglist());
}

virtual antlrcpp::Any EvalVisitor::visitAtom(Python3Parser::AtomContext *ctx) 
{
    if (program.checkIsName) {
        if (ctx->NAME() != nullptr) {
            return program.getValue(ctx->NAME()->toString());
        }
        else {
            //err
        }
    }
    if (ctx->NUMBER() != nullptr){
        //this version do not support superlong caculation

    } else if (ctx->NAME() != nullptr) {
        std::string name = ctx->NAME()->toString();
        return *program.getValue(name);
    } else if (ctx->STRING().size() != 0) {
        std::string ret = "";
        for (auto &str : ctx->STRING()) {
            ret += str->toString();
        }
        return ret;
    } else if (ctx->NONE() != nullptr) {
        return (void *)nullptr;
    } else if (ctx->TRUE() != nullptr) {
        return true;
    } else if (ctx->FALSE() != nullptr) {
        return false;
    }
}

virtual antlrcpp::Any EvalVisitor::visitNamelist(Python3Parser::NamelistContext *ctx) 
{
    std::vector<antlrcpp::Any *> ret(ctx->NAME().size());
    size_t i = 0;
    for (auto nameEle : ctx->NAME()) {
        ret[i++] = visit(nameEle);
    }
    return ret;
}

virtual antlrcpp::Any EvalVisitor::visitTestlist(Python3Parser::TestlistContext *ctx) 
{
    std::vector<antlrcpp::Any> ret(ctx->test().size());
    size_t i = 0;
    for (auto testEle : ctx->test()) {
        ret[i++] = visit(testEle);
    }
    return ret;
}

virtual antlrcpp::Any EvalVisitor::visitArglist(Python3Parser::ArglistContext *ctx) 
{
    
}

virtual antlrcpp::Any EvalVisitor::visitArgument(Python3Parser::ArgumentContext *ctx) 
{
    
}