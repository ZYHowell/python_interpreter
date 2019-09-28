//
// Created by jinho on 9/28/2019.
//

#ifndef PYTHON_INTERPRETER_PROGRAM_H
#define PYTHON_INTERPRETER_PROGRAM_H

#include <unordered_map>
#include "antlr4-runtime.h"

struct Frame {
    std::unordered_map<std::string,antlrcpp::Any> memory;
    antlr4::tree::ParseTree* returnnode;
};
struct Function {
    antlr4::tree::ParseTree* suite;
    std::vector<std::string> params;///暂时不支持默认参数
public:
    Function(antlr4::tree::ParseTree* tree,const std::vector<std::string>&params):suite(tree),params(params){}
    
};
class Program {
public:
    std::stack<Frame> frames;
    std::unordered_map<std::string,Function> funcs;
public:

};


#endif //PYTHON_INTERPRETER_PROGRAM_H
