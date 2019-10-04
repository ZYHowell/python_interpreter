#ifndef PYTHON_INTERPRETER_PROGRAM_H
#define PYTHON_INTERPRETER_PROGRAM_H

#include <map>
#include <stack>
#include <memory>
#include "exceptions.h"
#include "antlr4-runtime.h"

struct Frame 
{
    std::map<std::string,antlrcpp::Any> *memory;
    antlr4::tree::ParseTree* returnnode;
    Frame():
    {
        memory = new std::map<std::string, antlrcpp::Any>;
    }
    ~Frame()
    {
        delete memory;
    }
};

struct Function 
{
    antlr4::tree::ParseTree* suite;
    //really a parseTree? or a SuiteContext?
    std::vector<std::string> params;///暂时不支持默认参数
public:
    Function(antlr4::tree::ParseTree* tree, 
             std::vector<std::string> &params)
             :suite(tree),params(params){}
};

class Program 
{
    using Any = antlrcpp::Any;
    std::stack<Frame> tmp_frames;
    bool checkIsName;
public:
    std::stack<Frame> frames;
    std::map<std::string,Function> funcs;
public:
    Any *getValue(std::string name);
};

class ERRORS 
{
    
}


#endif //PYTHON_INTERPRETER_PROGRAM_H
