#ifndef PYTHON_INTERPRETER_EVALVISITOR_H
#define PYTHON_INTERPRETER_EVALVISITOR_H

#include <cmath>
#include "Python3BaseVisitor.h"
#include "Program.h"
#include "exceptions.h"
class EvalVisitor: public Python3BaseVisitor {
private:
    using Any = antlrcpp::Any;
    using anyV_t = std::vector<Any>;
    Program program;
public:
    inline bool isList(const Any &it)
    {
        return (it.is<std::shared_ptr<anyV_t>>() || 
                it.is<std::shared_ptr<std::vector<Any*>>>()
                );
    }


    inline size_t getNodeIndex(antlr4::tree::TerminalNode* it)
    {
        return it->getSymbol()->getTokenIndex();
    }


    inline int toInt(const Any &it)
    {
        if (isList(it)) {
            //err
        }
        if (it.is<std::string>() || it.is<sjtu::none_t>()) {
            //err
        } else if (it.is<bool>()) {
            return it.as<bool>();
        } else if (it.is<int>()) {
            return it.as<int>();
        }
    }
    inline bool toBool(const Any &it)
    {
        if (isList(it)) {
            //err
        }
        if (it.is<std::string>()) {
            return it.as<std::string>() != "";
        } else if (it.is<sjtu::none_t>()) {
            return false;
        } else if (it.is<bool>()) {
            return it.as<bool>();
        } else return it.as<int>();
    }


    inline void checkType(const Any &a, const Any &b)
    {
        if (b.is<sjtu::none_t>()) {
            //err
        }
        if ((a.is<std::string>() && !b.is<std::string>()) ||
            !a.is<std::string>() && b.is<std::string>()) {
            //err
        }
        return;
    }


    inline bool lessThan(const Any &a, const Any &b)
    {
        checkType(a, b);
        if (a.is<std::string>()) {
            return a.as<std::string>() < b.as<std::string>();
        } else {
            return toInt(a) < toInt(b);
        }
    }
    inline bool greaterThan(const Any &a, const Any &b)
    {
        checkType(a, b);
        if (a.is<std::string>()) {
            return a.as<std::string>() > b.as<std::string>();
        } else {
            return toInt(a) > toInt(b);
        }
    }
    inline bool equals(const Any &a, const Any &b)
    {
        checkType(a, b);
        if (a.is<std::string>()) {
            return a.as<std::string>() == b.as<std::string>();
        } else {
            return toInt(a) == toInt(b);
        }
    }
    inline bool gtEq(const Any &a, const Any &b)
    {
        checkType(a, b);
        if (a.is<std::string>()) {
            return a.as<std::string>() >= b.as<std::string>();
        } else {
            return toInt(a) >= toInt(b);
        }
    }
    inline bool lsEq(const Any &a, const Any &b)
    {
        checkType(a, b);
        if (a.is<std::string>()) {
            return a.as<std::string>() <= b.as<std::string>();
        } else {
            return toInt(a) <= toInt(b);
        }
    }


    inline antlrcpp::Any judgeSuite(const Any &it) 
    {
        if (it.is<sjtu::flowRet>()) {
            if (it.as<sjtu::flowRet>().type == 3)
                return it;
        }
        return sjtu::none_t();
    }

    void printEle(const Any &it)
    {
        if (it.is<bool>()) {
            if (it.as<bool>()) {
                std::cout << "True";
            } else {
                std::cout << "False";
            }
        } else if (it.is<int>()) {
            std::cout << it.as<int>();
        } else if (it.is<std::string>()) {
            std::cout << it.as<std::string>();
        } else if (it.is<sjtu::none_t>()) {
            std::cout << "None";
        } else if (it.is<anyV_t>()) {
            std::cout << "(";
            printVector(it.as<anyV_t>());
            std::cout << ")";
        }
    }
    
    void printVector(const anyV_t &eles) 
    {
        for (size_t i = 0;i < eles.size();++i) {
            if (i) std::cout << ", ";
            if (eles[i].is<sjtu::funcArg>()) {
                if (eles[i].as<sjtu::funcArg>().type) {
                    //err
                } else {
                    printEle(eles[i].as<sjtu::funcArg>().value);
                }
            }
            else {
                printEle(eles[i]);
            }
        }
    }

    antlrcpp::Any visitFile_input(Python3Parser::File_inputContext *ctx) override 
    {
        Any ret;
        for (auto stmtEle : ctx->stmt()) {
            ret = judgeSuite(visit(stmtEle));
            if (ret.is<sjtu::none_t>()) continue;
            else {
                if (ret.as<sjtu::flowRet>().type != 3) {
                    //err
                }
                else {
                    ret = ret.as<sjtu::flowRet>().retValue;
                }
            }
        }
        return 0;
    }

    antlrcpp::Any visitFuncdef(Python3Parser::FuncdefContext *ctx) override 
    {
        auto params = visit(ctx->parameters()).as<std::shared_ptr<std::vector<sjtu::funcArg>>>();
        program.funcs.insert(std::make_pair(ctx->NAME()->toString(), Function(ctx->suite(), *params)));
        return sjtu::none_t();
    }

    antlrcpp::Any visitParameters(Python3Parser::ParametersContext *ctx) override 
    {
        if (ctx->typedargslist() == nullptr) {
            return std::make_shared<std::vector<sjtu::funcArg>>(std::vector<sjtu::funcArg>());
        } else{
            return visit(ctx->typedargslist());
        }
    }

    antlrcpp::Any visitTypedargslist(Python3Parser::TypedargslistContext *ctx) override 
    {
        auto tfps = ctx->tfpdef();
        auto tests = ctx->test();
        size_t i = 0;
        auto ret = std::make_shared<std::vector<sjtu::funcArg>>(std::vector<sjtu::funcArg>(tfps.size()));
        for (auto tfp : tfps) {
            ret->operator[](i) = sjtu::funcArg(visit(tests[i]), 1, visit(tfp));
        }
        return ret;
    }

    antlrcpp::Any visitTfpdef(Python3Parser::TfpdefContext *ctx) override 
    {
        return ctx->NAME()->toString();
    }

    antlrcpp::Any visitStmt(Python3Parser::StmtContext *ctx) override 
    {
        if (ctx->simple_stmt() != nullptr) {
            return visit(ctx->simple_stmt());
        } else{
            return visit(ctx->compound_stmt());
        }
    }

    antlrcpp::Any visitSimple_stmt(Python3Parser::Simple_stmtContext *ctx) override 
    {
        return visit(ctx->small_stmt());
    }

    antlrcpp::Any visitSmall_stmt(Python3Parser::Small_stmtContext *ctx) override 
    {
        if (ctx->flow_stmt() == nullptr) {
            return visit(ctx->expr_stmt());
        } else{
            return visit(ctx->flow_stmt());
        }
    }


    antlrcpp::Any visitExpr_stmt(Python3Parser::Expr_stmtContext *ctx) override 
    {
        
        auto result = *visit(ctx->testlist(ctx->testlist().size() - 1)).as<std::shared_ptr<anyV_t>>();
        
        if (ctx->augassign() != nullptr) {
            program.checkIsName = true;
            auto testEle = *visit(ctx->testlist(0)).as<std::shared_ptr<anyV_t>>();
            program.checkIsName = false;

            if (testEle.size() != 1 || result.size() != 1) {
                //err
            }
            auto content = testEle[0].as<Any*>();

            if (ctx->augassign()->ADD_ASSIGN() != nullptr) {
                //*content += result;
            } else if (ctx->augassign()->SUB_ASSIGN() != nullptr) {
                //*content -= result;
            } else if (ctx->augassign()->MULT_ASSIGN() != nullptr) {
                //*content *= result;
            } else {
                //*content /= result;
            }

        } else if (ctx->ASSIGN().size()){
            anyV_t contents;
            program.checkIsName = true;
            size_t m = ctx->testlist().size();
            for (size_t i = 0;i < ctx->testlist().size() - 1;++i) {

                contents = *visit(ctx->testlist(i)).as<std::shared_ptr<anyV_t>>();


                if (contents.size() != result.size()) {
                    //err
                } else {
                    for (size_t j = 0;j < contents.size();++j) {
                        *(contents.at(j).as<Any*>()) = result[j];
                    }
                }
            }
            program.checkIsName = false;
        }
        return sjtu::none_t();
    }

    antlrcpp::Any visitAugassign(Python3Parser::AugassignContext *ctx) override 
    {
        return visitChildren(ctx);
    }

    antlrcpp::Any visitFlow_stmt(Python3Parser::Flow_stmtContext *ctx) override 
    {
        if (ctx->break_stmt() != nullptr) {
            return visit(ctx->break_stmt());
        } else if (ctx->continue_stmt() != nullptr) {
            return visit(ctx->continue_stmt());
        } else {
            return visit(ctx->return_stmt());
        }
    }

    antlrcpp::Any visitBreak_stmt(Python3Parser::Break_stmtContext *ctx) override 
    {
        return sjtu::flowRet(1);
    }

    antlrcpp::Any visitContinue_stmt(Python3Parser::Continue_stmtContext *ctx) override 
    {
        return sjtu::flowRet(2);
    }

    antlrcpp::Any visitReturn_stmt(Python3Parser::Return_stmtContext *ctx) override 
    {
        return sjtu::flowRet(3, visit(ctx->testlist()));
    }

    antlrcpp::Any visitCompound_stmt(Python3Parser::Compound_stmtContext *ctx) override 
    {
        if (ctx->if_stmt() != nullptr) {
            return visit(ctx->if_stmt());
        } else if (ctx->while_stmt() != nullptr) {
            return visit(ctx->while_stmt());
        } else {
            return visit(ctx->funcdef());
        }
    }

    antlrcpp::Any visitIf_stmt(Python3Parser::If_stmtContext *ctx) override 
    {
        bool ret = toBool(visit(ctx->test(0)));
        if (ret) {
            return visit(ctx->suite(0));
        } else {
            for (size_t i = 0;i < ctx->ELIF().size();++i) {
                if ( toBool( visit(ctx->test(1 + i)) ) ) {
                    return visit(ctx->suite(1 + i));
                }
            }
            if (ctx->ELSE() != nullptr) {
                return visit(ctx->suite(ctx->ELIF().size() + 1));
            }
        }
        return sjtu::none_t();
    }

    antlrcpp::Any visitWhile_stmt(Python3Parser::While_stmtContext *ctx) override 
    {
        Any ret;
        while(toBool(visit(ctx->test()))) {
            ret = visit(ctx->suite());
            if (ret.is<sjtu::flowRet>()) {
                auto result = ret.as<sjtu::flowRet>();
                if (result.type == 1) break;
                else if (result.type == 3) return ret;
            }
        }
        return sjtu::none_t();
    }

    antlrcpp::Any visitSuite(Python3Parser::SuiteContext *ctx) override 
    {
        if (ctx->simple_stmt() != nullptr) {
            return judgeSuite(visit(ctx->simple_stmt()));
        } else {
            size_t num = ctx->stmt().size();
            size_t current = 0;
            while (current < num) {
                auto stmtRet = visit(ctx->stmt(current));
                if (stmtRet.is<sjtu::flowRet>()) {
                    return stmtRet;
    /*
        a judgement is needed there since such a situation is avaliable in grammar:
        in a function, there is no while but a break/continue is found.
        i hope it can be found and throw here. 
        e.g.: def a(): break
        Maybe a stack to record avaliable while_stmt in this function?
        Or, solve it in higher level? like where to use suite?
    */ 
                } else ++current;
            }
        }
        return sjtu::none_t();
    }

    antlrcpp::Any visitTest(Python3Parser::TestContext *ctx) override 
    {
        return visit(ctx->or_test());
    }
    antlrcpp::Any visitOr_test(Python3Parser::Or_testContext *ctx) override 
    {
        if (ctx->and_test().size() == 1) {
            return visit(ctx->and_test(0));
        } else {
            if (program.checkIsName) {
                //err
            }
            if (toBool(visit(ctx->and_test(0)))) {
                return true;
            } else {
                return toBool(visit(ctx->and_test(1)));
            }
        }
    }

    antlrcpp::Any visitAnd_test(Python3Parser::And_testContext *ctx) override 
    {
        if (ctx->not_test().size() == 1) {
            // auto ret = visit(ctx->not_test(0));
            // bool b = ret.is<std::string>();
            // auto it = ret.as<std::string>();
            // return ret;
            return visit(ctx->not_test(0));
        } else {
            if (program.checkIsName) {
                //err
            }
            if (!toBool(visit(ctx->not_test(0)))) {
                return false;
            } else {
                return toBool(visit(ctx->not_test(1)));
            }
        }
    }

    antlrcpp::Any visitNot_test(Python3Parser::Not_testContext *ctx) override 
    {
        if (ctx->NOT() != nullptr){
            if (program.checkIsName) {
                //err
            }
            return !toBool(visit(ctx->not_test()));
        } else {
            // auto ret = visit(ctx->comparison());
            // bool b = ret.is<std::string>();
            // auto it = ret.as<std::string>();
            // return ret;
            return visit(ctx->comparison());
        }
    }


    antlrcpp::Any visitComparison(Python3Parser::ComparisonContext *ctx) override 
    {
        Any expre[2];
        size_t num = 0;
        bool fir = 0;
        expre[0] = visit(ctx->arith_expr(num));
        auto comp_op = ctx->comp_op();
        if (!comp_op.size()){
            // bool b = expre[0].is<std::string>();
            // auto it = expre[0].as<std::string>();
            return expre[0];
        }
        if (program.checkIsName) {
            //err
        }
        for (auto op : comp_op){
            expre[!fir] = visit(ctx->arith_expr(++num));
            //since NONE and STRING type, the comparisons are improved and packed
            if (op->LESS_THAN() != nullptr){
                if (!lessThan(expre[fir], expre[!fir]))
                    return false;
            }
            else if (op->GREATER_THAN() != nullptr) {
                if (!greaterThan(expre[fir], expre[!fir]))
                    return false;
            }
            else if (op->EQUALS() != nullptr) {
                if (!equals(expre[fir], expre[!fir]))
                    return false;
            }
            else if (op->GT_EQ() != nullptr) {
                if (!gtEq(expre[fir], expre[!fir]))
                    return false;
            }
            else{
                if (!lsEq(expre[fir], expre[!fir]))
                    return false;
            }
            fir = !fir;
        }
        return true;
    }

    antlrcpp::Any visitComp_op(Python3Parser::Comp_opContext *ctx) override 
    {
        //no need to override it, or in order to be safer, it is necessary to override?
        return visitChildren(ctx);
    }

    antlrcpp::Any visitArith_expr(Python3Parser::Arith_exprContext *ctx) override 
    {
        //waiting to check validity
        auto ret = visit(ctx->term(0));
        size_t num = ctx->term().size();
        size_t addN = 0, minusN = 0, addMax = ctx->ADD().size(), minusMax = ctx->MINUS().size();
        
        if (num == 1) {
            return ret;
        }
        
        if (program.checkIsName || ret.is<sjtu::none_t>()) {
            //err
        }
        if (isList(ret)) {
            //err
        }
        if (ret.is<std::string>()) {
            if (minusMax) {
                //err
            }
            std::string result = ret.as<std::string>();
            Any tmp;
            for (size_t i = 1;i < num;++i) {
                tmp = visit(ctx->term(i));
                if (!tmp.is<std::string>()) {
                    //err
                }
                result = result + tmp.as<std::string>();
            }
            return result;
        }
        
        int result = toInt(ret);
        int nex;
        for (size_t i = 1;i < num;++i) {
            nex = toInt(visit(ctx->term(i)));
            if (addN >= addMax) {
                result -= nex;
                ++minusN;
            } else if (minusN >= minusMax) {
                result += nex;
                ++addN;
            } else if (getNodeIndex(ctx->ADD(addN)) > getNodeIndex(ctx->MINUS(minusN))) {
                result -= nex;
                ++minusN;
            } else {
                result += nex;
                ++addN;
            }
        }
        return result;
    }

    antlrcpp::Any visitTerm(Python3Parser::TermContext *ctx) override 
    {
        auto ret = visit(ctx->factor(0));
        size_t num = ctx->factor().size();
        size_t starN = 0, divN = 0, starMax = ctx->STAR().size(), divMax = ctx->DIV().size();
        
        if (num == 1) return ret;
        
        if (program.checkIsName) {
            //err
        }
        int result = toInt(ret);
        int nex;
        for (size_t i = 1;i < num;++i) {
            nex = toInt(visit(ctx->factor(i)));
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

    antlrcpp::Any visitFactor(Python3Parser::FactorContext *ctx) override 
    {
        //waiting to check validity
        if (ctx->atom_expr() != nullptr) {
            return visit(ctx->atom_expr());
        } else {
            if (program.checkIsName) {
                //err
            }
            Any ret = visit(ctx->factor());
            if (isList(ret)) {
                //err
            }
            if (ret.is<std::string>() || (ret.is<sjtu::none_t>())) {
                //err
            }
            if (ctx->ADD() != nullptr) {
                if (ret.is<bool>()) {
                    return (int)ret.as<bool>();
                }
                else return ret;
            }
            else {
                if (ret.is<bool>()) {
                    return -1 * (int)ret.as<bool>();
                }
                else return -1 * ret.as<int>();
            }
        }
    }

    antlrcpp::Any visitAtom_expr(Python3Parser::Atom_exprContext *ctx) override 
    {
        if (ctx->trailer() != nullptr) {
            if (program.checkIsName) {
                //err
            }
            if (ctx->atom()->NAME() == nullptr) {
                //err
            } else {
                std::string funcName = ctx->atom()->NAME()->toString();
                auto paraNum = visit(ctx->trailer()).as<std::shared_ptr<anyV_t>>();
                //bool b = paraNum->operator[](0).is<sjtu::funcArg>();
                if (funcName == "print") {
                    printVector(*paraNum);
                    std::cout << std::endl;
                    return sjtu::none_t();
                }
                if (!program.funcs.count(funcName)) {
                    //err
                }
                Function *func = &program.funcs[funcName];
                //needs to be improved since it is slow.
                program.frames.push(Frame());
                std::map<std::string, antlrcpp::Any> *mem = program.frames.top().memory;
                size_t num = func->params.size();
                for (size_t i = 0;i < num;++i) {
                    //mem->at((func->params[i]).name) = paraNum->operator[]();
                    //needs to be improved
                }
                
                auto ret = visit(func->suite);
                if (ret.is<sjtu::flowRet>() && ret.as<sjtu::flowRet>().type != 3) {
                    //err like: def a(): break/continue
                }
                program.frames.pop();

                return judgeSuite(ret);
            }
        } else {
            Any ret = visit(ctx->atom());
            return ret;
        }
    }

    antlrcpp::Any visitTrailer(Python3Parser::TrailerContext *ctx) override 
    {
        auto ret = visit(ctx->arglist()).as<std::shared_ptr<anyV_t>>();
        return ret;
    }

    antlrcpp::Any visitAtom(Python3Parser::AtomContext *ctx) override 
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
            //this version do not support superlong caculation and double
            int ret = std::atoi(ctx->NUMBER()->toString().c_str());
            return ret;
        } else if (ctx->NAME() != nullptr) {
            std::string name = ctx->NAME()->toString();
            return *program.getValue(name);
            //no need to return name if checkIsName=false
        } else if (ctx->STRING().size() != 0) {
            std::string ret = "";
            for (auto &str : ctx->STRING()) {
                ret += str->toString();
            }
            return ret;
        } else if (ctx->NONE() != nullptr) {
            return sjtu::none_t();
        } else if (ctx->TRUE() != nullptr) {
            return true;
        } else if (ctx->FALSE() != nullptr) {
            return false;
        }
    }

    antlrcpp::Any visitTestlist(Python3Parser::TestlistContext *ctx) override 
    {
        auto ret = std::make_shared<anyV_t>(anyV_t(ctx->test().size()));
        size_t i = 0;
        Any result;
        for (auto testEle : ctx->test()) {
            ret->operator[](i++) = visit(testEle);
        }
        return ret;
    }

    antlrcpp::Any visitArglist(Python3Parser::ArglistContext *ctx) override 
    {
        auto args = ctx->argument();
        size_t i = 0;
        bool isPositional = false;
        auto ret = std::make_shared<anyV_t>(anyV_t(args.size()));
        for (auto arg : args) {
            ret->at(i) = visit(arg);
            if (ret->at(i).as<sjtu::funcArg>().type) isPositional = true;
            else if (isPositional) {
                //err
            }
            ++i;

        }
        return ret;
    }

    antlrcpp::Any visitArgument(Python3Parser::ArgumentContext *ctx) override 
    {
        auto tests = ctx->test();
        if (tests.size() == 1) {
            return sjtu::funcArg(visit(tests[0]));
        } else {
            return sjtu::funcArg(visit(tests[1]), 1, visit(tests[0]).as<std::string>());
        }
    }
};


#endif //PYTHON_INTERPRETER_EVALVISITOR_H
