//
// Created by jinho on 9/28/2019.
//

#ifndef PYTHON_INTERPRETER_PROGRAM_H
#define PYTHON_INTERPRETER_PROGRAM_H

#include <map>
#include <stack>
#include "antlr4-runtime.h"

struct Frame {
    std::map<std::string,antlrcpp::Any> memory;
    antlr4::tree::ParseTree* returnnode;
};

struct Function {
    antlr4::tree::ParseTree* suite;
    std::vector<std::string> params;///暂时不支持默认参数
public:
    Function(antlr4::tree::ParseTree* tree,const std::vector<std::string>&params):suite(tree),params(params){}
    
};

class Program {
    using Any = antlrcpp::Any;
public:
    std::stack<Frame> frames;
    std::map<std::string,Function> funcs;
public:
    std::stack<Frame> tmp_frames;
    Any getValue(std::string name);
    bool setValue(std::string name, const Any &value);
};


#endif //PYTHON_INTERPRETER_PROGRAM_H
