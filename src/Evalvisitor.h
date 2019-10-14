#ifndef PYTHON_INTERPRETER_EVALVISITOR_H
#define PYTHON_INTERPRETER_EVALVISITOR_H

#include <cmath>
#include "Python3BaseVisitor.h"
#include "Program.h"
#include "exceptions.h"
#include "bigint.h"

class EvalVisitor: public Python3BaseVisitor {

private:
    using Any = antlrcpp::Any;
    using anyV_t = std::vector<Any>;
    Program program;

public:

    /*
     * Judge if it is a list.
     * Always followed by an exception.
    */
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

	/* opcode
	 * 0 +
	 * 1 -
	 * 2 *
	 * 3 /
	 */
	antlrcpp::Any op(antlrcpp::Any a, antlrcpp::Any b, int opcode) {
		if (a.is<std::string>() && b.is<std::string>()) {
			if (opcode == 0)
				return a.as<std::string>() + b.as<std::string>();
			else {
				//err
			}
			assert(opcode == 0);
		}
		else if ((a.is<double>() || a.is<BigInt>() || a.is<bool>()) &&
				 (b.is<double>() || b.is<BigInt>() || b.is<bool>())) {
			if (a.is<double>() || b.is<double>()) {
				double da, db;
				if (a.is<double>())
					da = a.as<double>();
				else if (a.is<BigInt>())
					da = (a.as<BigInt>()).to_double();
				else
					da = a.as<bool>() * 1.0;
				if (b.is<double>())
					db = b.as<double>();
				else if (b.is<BigInt>())
					db = b.as<BigInt>().to_double();
				else
					db = b.as<bool>() * 1.0;
				if (opcode == 0)
					return da + db;
				else if (opcode == 1)
					return da - db;
				else if (opcode == 2)
					return da * db;
				else if (opcode == 3)
					return da / db;
			}
			else {
				BigInt da, db;
				if (a.is<BigInt>())
					da = a.as<BigInt>();
				else
					da = int(a.as<bool>());
				if (b.is<BigInt>())
					db = b.as<BigInt>();
				else
					db = int(b.as<bool>());
				if (opcode == 0)
					return da + db;
				else if (opcode == 1)
					return da - db;
				else if (opcode == 2)
					return da * db;
				else if (opcode == 3)
					return da.to_double() / db.to_double();
			}
		}
		else {
			// err
		}
	}

    /*
     * A tramsformation.
    */
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
        } else if (it.is<BigInt>()) {
			return it.as<BigInt>() == BigInt();
		} else if (it.is<double>())
			return it.as<double>() == 0.0;
    }

    /*
     * Comparisons(include string comparison)
    */
    inline bool lessThan(const Any &a, const Any &b)
    {
        if (a.is<std::string>() && b.is<std::string>()) {
            return a.as<std::string>() < b.as<std::string>();
        }
        else if ((a.is<double>() || a.is<BigInt>() || a.is<bool>()) &&
        		 (b.is<double>() || b.is<BigInt>() || b.is<bool>())) {
			if (a.is<double>() || b.is<double>()) {
				double da, db;
				if (a.is<double>())
					da = a.as<double>();
				else if (a.is<BigInt>())
					da = (a.as<BigInt>()).to_double();
				else
					da = a.as<bool>() * 1.0;
				if (b.is<double>())
					db = b.as<double>();
				else if (b.is<BigInt>())
					db = b.as<BigInt>().to_double();
				else
					db = b.as<bool>() * 1.0;
				return da < db;
			}
			else {
				BigInt da, db;
				if (a.is<BigInt>())
					da = a.as<BigInt>();
				else
					da = int(a.as<bool>());
				if (b.is<BigInt>())
					db = b.as<BigInt>();
				else
					db = int(b.as<bool>());
				return da < db;
			}
        }
        else {
        	// err
        }
    }
    inline bool greaterThan(const Any &a, const Any &b)
    {
		if (a.is<std::string>() && b.is<std::string>()) {
			return a.as<std::string>() > b.as<std::string>();
		}
		else if ((a.is<double>() || a.is<BigInt>() || a.is<bool>()) &&
				 (b.is<double>() || b.is<BigInt>() || b.is<bool>())) {
			if (a.is<double>() || b.is<double>()) {
				double da, db;
				if (a.is<double>())
					da = a.as<double>();
				else if (a.is<BigInt>())
					da = (a.as<BigInt>()).to_double();
				else
					da = a.as<bool>() * 1.0;
				if (b.is<double>())
					db = b.as<double>();
				else if (b.is<BigInt>())
					db = b.as<BigInt>().to_double();
				else
					db = b.as<bool>() * 1.0;
				return da > db;
			}
			else {
				BigInt da, db;
				if (a.is<BigInt>())
					da = a.as<BigInt>();
				else
					da = int(a.as<bool>());
				if (b.is<BigInt>())
					db = b.as<BigInt>();
				else
					db = int(b.as<bool>());
				return da > db;
			}
		}
		else {
			// err
		}
    }
    inline bool equals(const Any &a, const Any &b)
    {
		if (a.is<std::string>() && b.is<std::string>()) {
			return a.as<std::string>() == b.as<std::string>();
		}
		else if ((a.is<double>() || a.is<BigInt>() || a.is<bool>()) &&
				 (b.is<double>() || b.is<BigInt>() || b.is<bool>())) {
			if (a.is<double>() || b.is<double>()) {
				double da, db;
				if (a.is<double>())
					da = a.as<double>();
				else if (a.is<BigInt>())
					da = (a.as<BigInt>()).to_double();
				else
					da = a.as<bool>() * 1.0;
				if (b.is<double>())
					db = b.as<double>();
				else if (b.is<BigInt>())
					db = b.as<BigInt>().to_double();
				else
					db = b.as<bool>() * 1.0;
				return da == db;
			}
			else {
				BigInt da, db;
				if (a.is<BigInt>())
					da = a.as<BigInt>();
				else
					da = int(a.as<bool>());
				if (b.is<BigInt>())
					db = b.as<BigInt>();
				else
					db = int(b.as<bool>());
				return da == db;
			}
		}
		else {
			// err
		}
    }
    inline bool gtEq(const Any &a, const Any &b)
    {
		if (a.is<std::string>() && b.is<std::string>()) {
			return a.as<std::string>() >= b.as<std::string>();
		}
		else if ((a.is<double>() || a.is<BigInt>() || a.is<bool>()) &&
				 (b.is<double>() || b.is<BigInt>() || b.is<bool>())) {
			if (a.is<double>() || b.is<double>()) {
				double da, db;
				if (a.is<double>())
					da = a.as<double>();
				else if (a.is<BigInt>())
					da = (a.as<BigInt>()).to_double();
				else
					da = a.as<bool>() * 1.0;
				if (b.is<double>())
					db = b.as<double>();
				else if (b.is<BigInt>())
					db = b.as<BigInt>().to_double();
				else
					db = b.as<bool>() * 1.0;
				return da >= db;
			}
			else {
				BigInt da, db;
				if (a.is<BigInt>())
					da = a.as<BigInt>();
				else
					da = int(a.as<bool>());
				if (b.is<BigInt>())
					db = b.as<BigInt>();
				else
					db = int(b.as<bool>());
				return da >= db;
			}
		}
		else {
			// err
		}
    }
    inline bool lsEq(const Any &a, const Any &b)
    {
		if (a.is<std::string>() && b.is<std::string>()) {
			return a.as<std::string>() <= b.as<std::string>();
		}
		else if ((a.is<double>() || a.is<BigInt>() || a.is<bool>()) &&
				 (b.is<double>() || b.is<BigInt>() || b.is<bool>())) {
			if (a.is<double>() || b.is<double>()) {
				double da, db;
				if (a.is<double>())
					da = a.as<double>();
				else if (a.is<BigInt>())
					da = (a.as<BigInt>()).to_double();
				else
					da = a.as<bool>() * 1.0;
				if (b.is<double>())
					db = b.as<double>();
				else if (b.is<BigInt>())
					db = b.as<BigInt>().to_double();
				else
					db = b.as<bool>() * 1.0;
				return da <= db;
			}
			else {
				BigInt da, db;
				if (a.is<BigInt>())
					da = a.as<BigInt>();
				else
					da = int(a.as<bool>());
				if (b.is<BigInt>())
					db = b.as<BigInt>();
				else
					db = int(b.as<bool>());
				return da <= db;
			}
		}
		else {
			// err
		}
    }

    /*
     * Make the return of a suite clear
     * (mainly for a return of a break_stmt and continue_stmt)
    */
    inline antlrcpp::Any judgeSuite(const Any &it) 
    {
        if (it.is<sjtu::flowRet>()) {
            if (it.as<sjtu::flowRet>().type == 3)
                return it;
        }
        return sjtu::none_t();
    }

    /*
     * The following two functions are used to deal with the print function, 
     * which supports printing a turple of turples and other elements.
    */
    void printEle(const Any &it)
    {
        if (it.is<bool>()) {
            if (it.as<bool>()) {
                std::cout << "True";
            } else {
                std::cout << "False";
            }
        } else if (it.is<double>()) {
			std::cout << it.as<double>();
		} else if (it.is<BigInt>()) {
        	std::cout << it.as<BigInt>();
        } else if (it.is<std::string>()) {
            std::cout << it.as<std::string>();
        } else if (it.is<sjtu::none_t>()) {
            std::cout << "None";
        } else if (it.is<std::shared_ptr<anyV_t>>()) {
            std::cout << "(";
            printVector(*it.as<std::shared_ptr<anyV_t>>());
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

    /*
     * Visit each statements
    */
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
        auto ret = std::make_shared<std::vector<sjtu::funcArg>>
                        (std::vector<sjtu::funcArg>(tfps.size()));
        size_t testSize = tests.size();
        size_t noTstSize = tfps.size() - testSize;
        for (size_t i = 0;i < noTstSize;++i) {
            ret->operator[](i) = sjtu::funcArg(Any(), 0, visit(tfps[i]).as<std::string>());
        }

        for (size_t i = noTstSize;i < tfps.size();++i) {
            ret->operator[](i) = sjtu::funcArg(visit(tests[i - noTstSize]), 
                                               1, visit(tfps[i]).as<std::string>());
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
            
            //To deal with augassignment statement.

            program.checkIsName = true;
            auto testEle = *visit(ctx->testlist(0)).as<std::shared_ptr<anyV_t>>();
            program.checkIsName = false;

            if (testEle.size() != 1 || result.size() != 1) {
                //err
            }
            auto content = testEle[0].as<Any*>();

            if (result[0].is<sjtu::none_t>()) {
            	//err
            }

            //bool, double, BigInt, std:string
            if (ctx->augassign()->ADD_ASSIGN() != nullptr) {
            	*content = op(*content, result, 0);
                //*content += result;
            } else if (ctx->augassign()->SUB_ASSIGN() != nullptr) {
				*content = op(*content, result, 1);
                //*content -= result;
            } else if (ctx->augassign()->MULT_ASSIGN() != nullptr) {
				*content = op(*content, result, 2);
                //*content *= result;
            } else {
				*content = op(*content, result, 3);
                //*content /= result;
            }

        } else if (ctx->ASSIGN().size()){

            //To deal with assignment statement. 

            anyV_t contents;
            program.checkIsName = true;
            //Since all lvalues are namelists
            size_t m = ctx->testlist().size();
            for (size_t i = 0;i < ctx->testlist().size() - 1;++i) {

                contents = *visit(ctx->testlist(i)).as<std::shared_ptr<anyV_t>>();


                if (contents.size() != result.size()) {
                    //err occurs like a,b = 1,2,3
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
        //No need to visit augassign in this version
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
        auto ret = visit(ctx->testlist()).as<std::shared_ptr<anyV_t>>();
        if (ret->size() == 1) {
            return sjtu::flowRet(3, ret->operator[](0));
        } else {
            return sjtu::flowRet(3, ret);
        }
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
                    //break, continue and return should be reversed instead of unpacking
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

        I think it should be solved in higher level, 
        so every visit(ctx->suite()) should be checked twice.
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
            return visit(ctx->comparison());
        }
    }


    antlrcpp::Any visitComparison(Python3Parser::ComparisonContext *ctx) override 
    {
        auto comp_op = ctx->comp_op();
        if (!comp_op.size()) {
            return visit(ctx->arith_expr(0));
        }

        Any expre[2];
        size_t num = 0;
        bool fir = 0;
        expre[0] = visit(ctx->arith_expr(num));
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


        for (size_t i = 1; i < num; ++i) {
			if (addN >= addMax) {
				ret = op(ret, visit(ctx->term(i)), 1);
                ++minusN;
            } else if (minusN >= minusMax) {
				ret = op(ret, visit(ctx->term(i)), 0);
                ++addN;
            } else if (getNodeIndex(ctx->ADD(addN)) > getNodeIndex(ctx->MINUS(minusN))) {
				ret = op(ret, visit(ctx->term(i)), 1);
                ++minusN;
            } else {
				ret = op(ret, visit(ctx->term(i)), 0);
                ++addN;
            }
        }
        return ret;
    }

    antlrcpp::Any visitTerm(Python3Parser::TermContext *ctx) override 
    {
        auto ret = visit(ctx->factor(0));
        size_t num = ctx->factor().size();
        size_t starN = 0, divN = 0, starMax = ctx->STAR().size(), divMax = ctx->DIV().size();

		if (num == 1) {
			return ret;
		}

		if (program.checkIsName || ret.is<sjtu::none_t>()) {
			//err
		}
		if (isList(ret)) {
			//err
		}


		for (size_t i = 1; i < num; ++i) {
			if (divN >= divMax) {
				ret = op(ret, visit(ctx->factor(i)), 2);
				++starN;
			} else if (starN >= starMax) {
				ret = op(ret, visit(ctx->factor(i)), 3);
				++divN;
			} else if (getNodeIndex(ctx->DIV(divN)) > getNodeIndex(ctx->STAR(starN))) {
				ret = op(ret, visit(ctx->factor(i)), 2);
				++starN;
			} else {
				ret = op(ret, visit(ctx->factor(i)), 3);
				++divN;
			}
		}
        return ret;
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

            int flag = ctx->ADD() != nullptr ? 1 : -1;
            if (ret.is<bool>()) {
            	return BigInt(int(ret.as<bool>())) * BigInt(flag);
            }
            else if (ret.is<double>()) {
				return ret.as<double>() * flag;
            }
            else if (ret.is<BigInt>()) {
				return ret.as<BigInt>() * BigInt(flag);
            }
            else {
				//err
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
                auto paras = *visit(ctx->trailer()).as<std::shared_ptr<anyV_t>>();

                if (funcName == "print") {
                    printVector(paras);
                    std::cout << std::endl;
                    return sjtu::none_t();
                }
                
                if (!program.funcs.count(funcName)) {
                    //err
                }
                
                Function *func = &program.funcs[funcName];
                //needs to be improved since it is slow.
                program.frames.push(Frame());
                
                std::map<std::string, antlrcpp::Any> *mem = &program.frames.top().memory;
                
                size_t funcNum = func->params.size();
                size_t paraNum = paras.size();

                bool isPositional = false;
                std::string nowName;

                size_t nowFunc = 0;
                //assign now
                for (size_t i = 0;i < paraNum;++i) {
                    if (isPositional || paras[i].as<sjtu::funcArg>().type) {
                        isPositional = true;
                        nowName = paras[i].as<sjtu::funcArg>().name;
                    } else {
                        nowName = (func->params)[nowFunc++].name;
                    }
                    if (mem->count(nowName)) {
                        //err
                    } else {
                        mem->insert(std::pair<std::string, Any>
                                        (nowName, paras[i].as<sjtu::funcArg>().value));
                    }
                }
                //check now
                for (size_t i = 0;i < funcNum;++i) {
                    nowName = func->params[i].name;
                    if (!mem->count(nowName)) {
                        if (func->params[i].type) {
                            mem->insert(std::pair<std::string, Any>
                                            (nowName, func->params[i].value));
                        } else {
                            //err
                        }
                    }
                }

                auto ret = visit(func->suite);

                program.frames.pop();

                if (ret.is<sjtu::flowRet>()) {
                    if (ret.as<sjtu::flowRet>().type != 3) {
                    //err like: def a(): break/continue
                    } else {
                        return ret.as<sjtu::flowRet>().retValue;        
                    }
                } else if (ret.is<sjtu::none_t>()){
                    return ret;
                } else {
                    //err
                }
            }
        } else {
            return visit(ctx->atom());
        }
    }

    antlrcpp::Any visitTrailer(Python3Parser::TrailerContext *ctx) override 
    {
        if (ctx->arglist() != nullptr) {
            return visit(ctx->arglist()).as<std::shared_ptr<anyV_t>>();
        } else {
            return std::make_shared<anyV_t>(anyV_t());
        }
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
            if (ctx->NUMBER()->toString().find('.') != std::string::npos)
            	return std::stod(ctx->NUMBER()->toString().c_str());
            else
            	return BigInt(ctx->NUMBER()->toString());
        } else if (ctx->NAME() != nullptr) {
            std::string name = ctx->NAME()->toString();
            return *program.getValue(name);
            //no need to return name if checkIsName=false
        } else if (ctx->STRING().size() != 0) {
            std::string tmp = "";
            size_t num = ctx->STRING().size();
            for (auto &str : ctx->STRING()) {
                tmp += str->toString();
            }
            std::string ret = "";
            for (size_t i = 1;i < tmp.size() - 1;++i) {
                ret += tmp[i];
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

        if (!args.size()) {
            return std::make_shared<anyV_t>(anyV_t());
        }

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
            auto ret = visit(tests[0]);
            return sjtu::funcArg(visit(tests[1]), 1, ret.as<std::string>());
        }
    }
};


#endif //PYTHON_INTERPRETER_EVALVISITOR_H
