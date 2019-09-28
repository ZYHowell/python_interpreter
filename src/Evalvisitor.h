//
// Created by jinho on 9/28/2019.
//

#ifndef PYTHON_INTERPRETER_EVALVISITOR_H
#define PYTHON_INTERPRETER_EVALVISITOR_H

#include <cmath>
#include "Python3BaseVisitor.h"
#include "Program.h"
using antlrcpp::Any;
class EvalVisitor: public Python3BaseVisitor {
private:
    Program program;
public:
    Any visitFile_input(Python3Parser::File_inputContext *ctx) override{
        for (int i = 0; i < ctx->stmt().size(); i++) {
            visit(ctx->stmt()[i]);
        }
        return antlrcpp::Any();
    }
    Any visitFuncdef (Python3Parser::FuncdefContext *ctx) override{
        auto params=visit(ctx->parameters());
        program.funcs.insert(std::make_pair(ctx->NAME()->toString(),Function(ctx->suite(),params)));
        return Any();
    }
    antlrcpp::Any visitParameters (Python3Parser::ParametersContext *ctx) override{
        if (ctx->typedargslist() == nullptr) {
            return std::make_shared<std::vector<std::string>>(std::vector<std::string>());
        } else{
            return visit(ctx->typedargslist());
        }
    }
    antlrcpp::Any visitTypedargslist(Python3Parser::TypedargslistContext *ctx) override {
        std::vector<std::string> params;
        //todo:
    }
    antlrcpp::Any visitStmt(Python3Parser::StmtContext *ctx) override {
        if (ctx->simple_stmt() != nullptr) {
            return visit(ctx->simple_stmt());
        } else{
            return visit(ctx->compound_stmt());
        }
    }
    antlrcpp::Any visitSimple_stmt(Python3Parser::Simple_stmtContext *ctx) override {
        return visit(ctx->small_stmt());
    }
    antlrcpp::Any visitSmall_stmt(Python3Parser::Small_stmtContext *ctx) override {
        if (ctx->flow_stmt() == nullptr) {
            return visit(ctx->expr_stmt());
        } else{
            return visit(ctx->flow_stmt());
        }
    }
    antlrcpp::Any visitExpr_stmt(Python3Parser::Expr_stmtContext *ctx) override {
        auto objnames=visit(ctx->testlist(0));
        if(ctx->augassign()== nullptr) {
            if(ctx->testlist().size()>1) {
                auto result = visit(ctx->testlist(ctx->ASSIGN().size()));
    
                program.frames.top().memory[objnames] = result;
                for (auto &i : *objnames.as<std::shared_ptr<std::vector<Any>>>()) {
                    program.frames.top().memory[i] = (*result.as<std::shared_ptr<std::vector<Any>>>())[i];
                }
                for (int i = 1; i < ctx->ASSIGN().size(); i++) {
                    auto otherobj = visit(ctx->testlist(i));
                    for (auto &j : *otherobj.as<std::shared_ptr<std::vector<Any>>>()) {
                        program.frames.top().memory[j] = (*result.as<std::shared_ptr<std::vector<Any>>>())[i];
                    }
                }
            }
        } else {
            auto result=visit(ctx->testlist(1));
            auto& cur_val=program.frames.top().memory[objnames];
            if(cur_val.is<int>()) {
                if (ctx->augassign()->toString() == "+=") {
                    cur_val.as<int>()+=result.as<int>();
                } else if(ctx->augassign()->toString()=="-=") {
                    cur_val.as<int>()-=result.as<int>();
                } else if (ctx->augassign()->toString() == "*=") {
                    cur_val.as<int>()*=result.as<int>();
                } else if (ctx->augassign()->toString() == "//=") {
                    cur_val.as<int>()/=result.as<int>();
                } else if (ctx->augassign()->toString() == "%=") {
                    cur_val.as<int>()%=result.as<int>();
                } else if(ctx->augassign()->toString()=="**="){
                    //todo:都需要类型转换什么的
                }
            }
        }
        return Any();
    }
    /**
     * @return  std::vector<Any>
     */
    antlrcpp::Any visitTestlist(Python3Parser::TestlistContext *ctx) override {
        auto tests=std::make_shared<std::vector<Any>>(std::vector<Any>());
        for (int i = 0; i < ctx->test().size(); i++) {
            tests->push_back(visit(ctx->test(i)));
        }
        return tests;
    }
    antlrcpp::Any visitTest(Python3Parser::TestContext *ctx) override {
        if (ctx->test() == nullptr) {
            return visit(ctx->or_test(0));
        } else{
            std::cout<<"unsupported"<<std::endl;
            return Any();
        }
    }
    antlrcpp::Any visitOr_test(Python3Parser::Or_testContext *ctx) override {
        if (ctx->and_test().size() == 1) {
            return visit(ctx->and_test(0));
        } else{
            return visit(ctx->and_test(0)).as<int>()||visit(ctx->and_test(1)).as<int>();
        }
    }
    antlrcpp::Any visitAnd_test(Python3Parser::And_testContext *ctx) override {
        if (ctx->not_test().size() == 1) {
            return visit(ctx->not_test(0));
        } else{
            return visit(ctx->not_test(0)).as<int>()&&visit(ctx->not_test(1)).as<int>();
        }
    }
    antlrcpp::Any visitNot_test(Python3Parser::Not_testContext *ctx) override {
        if (ctx->NOT() != nullptr) {
            return !visit(ctx->not_test());
        } else{
            return visit(ctx->comparison());
        }
    }
    /**
     *
     * @return Any
     */
    antlrcpp::Any visitComparison(Python3Parser::ComparisonContext *ctx) override {
        Any result=visit(ctx->expr(0));
        for (int i = 0; i < ctx->expr().size(); i++) {
            //todo:deal with comparison
        }
        return result;
    }
    antlrcpp::Any visitExpr(Python3Parser::ExprContext *ctx) override {
        auto result=visit(ctx->xor_expr(0));
        if (ctx->xor_expr().size() > 1) {
            for (int i = 1; i < ctx->xor_expr().size(); i++) {
                result.as<int>()|=visit(ctx->xor_expr(i)).as<int>();
            }
        }
        return result;
    }
    antlrcpp::Any visitXor_expr(Python3Parser::Xor_exprContext *ctx) override {
        auto result=visit(ctx->and_expr(0));
        if (ctx->and_expr().size() > 1) {
            for (int i = 1; i < ctx->and_expr().size(); i++) {
                result.as<int>()^=visit(ctx->and_expr(i)).as<int>();
            }
        }
        return result;
    }
    antlrcpp::Any visitAnd_expr(Python3Parser::And_exprContext *ctx) override {
        auto result=visit(ctx->shift_expr(0));
        if (ctx->shift_expr().size() > 1) {
            for (int i = 1; i < ctx->shift_expr().size(); i++) {
                result.as<int>()&=visit(ctx->shift_expr(i)).as<int>();
            }
        }
        return result;
    }
    antlrcpp::Any visitShift_expr(Python3Parser::Shift_exprContext *ctx) override {
        auto result=visit(ctx->arith_expr(0));
        if (ctx->arith_expr().size() > 1) {
            //todo:
        }
        return result;
    }
    antlrcpp::Any visitArith_expr(Python3Parser::Arith_exprContext *ctx) override {
        auto result=visit(ctx->term(0));
        if (ctx->term().size() > 1) {
            //todo:
        }
        return result;
    }
    antlrcpp::Any visitTerm(Python3Parser::TermContext *ctx) override {
        auto result = visit(ctx->factor(0));
        if (ctx->factor().size() > 1) {
            //todo:
        }
        return result;
    }
    antlrcpp::Any visitFactor(Python3Parser::FactorContext *ctx) override {
        if (ctx->power() == nullptr) {
            if (ctx->ADD() != nullptr) {
                return visit(ctx->factor());
            } else if (ctx->MINUS() != nullptr) {
                auto tmp=visit(ctx->factor());
                if (tmp.is<int>()) {
                    return -tmp.as<int>();
                } else if (tmp.is<double>()){
                    return -tmp.as<double>();
                } else{
                    std::cout<<"unsupported"<<std::endl;
                }
            } else if (ctx->NOT_OP() != nullptr) {
                return ~visit(ctx->factor()).as<int>();
            }
        } else{
            return visit(ctx->power());
        }
    }
    antlrcpp::Any visitPower(Python3Parser::PowerContext *ctx) override {
        auto result=visit(ctx->atom_expr());
        if (ctx->factor() != nullptr) {
            int factor=visit(ctx->factor());
            result.as<int>()=pow(result.as<int>(),factor);
        }
        return result;
    }
    antlrcpp::Any visitAtom_expr(Python3Parser::Atom_exprContext *ctx) override {
        if (ctx->atom()->NAME() && ctx->atom()->NAME()->toString()=="print") {
            auto tmp=visit(ctx->trailer(0)).as<std::shared_ptr<std::vector<Any>>>();//tostring是打印出结构
            for(auto& str:*tmp) {
                if (str.is<double>()) {
                    std::cout<<str.as<double>();
                } else if (str.is<int>()) {
                    std::cout<<str.as<int>();
                } else{
                    std::cout<<str.as<std::string>();
                }
            }
            std::cout<<std::endl;
            return Any();
        } else{
            if (ctx->trailer().size() == 0) {
                return visit(ctx->atom());
            } else{
                //todo:func
            }
        }
    }
    antlrcpp::Any visitAtom(Python3Parser::AtomContext *ctx) override {
        if (ctx->NUMBER() != nullptr) {
            return std::atoi(ctx->NUMBER()->toString().c_str());
        } else if (ctx->NAME() != nullptr) {
            return ctx->NAME()->toString();//todo:wrong
        } else if (ctx->STRING().size() != 0) {
            std::string tmp="";
            for (auto &str:ctx->STRING()) {
                tmp+=str->toString();
            }
            return tmp;
        } else {
            //todo:
        }
    }
    /**
 *
 * @param ctx
 * @return std::vector<Any>
 */
    antlrcpp::Any visitTrailer(Python3Parser::TrailerContext *ctx) override {
        return visit(ctx->arglist());
    }
    
    antlrcpp::Any visitArglist(Python3Parser::ArglistContext *ctx) override {
        auto  arglist=std::shared_ptr<std::vector<Any>>(new std::vector<Any>());
        for (auto &i:ctx->argument()) {
            arglist->push_back(visit(i));
        }
        return arglist;
    }
    antlrcpp::Any visitArgument(Python3Parser::ArgumentContext *ctx) override {
        return visit(ctx->test(0));
        //todo:
    }
};


#endif //PYTHON_INTERPRETER_EVALVISITOR_H
