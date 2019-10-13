#ifndef PYTHON_INTERPRETER_PROGRAM_H
#define PYTHON_INTERPRETER_PROGRAM_H

#include <map>
#include <stack>
#include <memory>
#include "exceptions.h"
#include "antlr4-runtime.h"

struct Frame 
{
    std::map<std::string,antlrcpp::Any> memory;
    antlr4::tree::ParseTree* returnnode;
    Frame()
    {
        
    }
    ~Frame()
    {
      
    }
};

struct Function 
{
    antlr4::tree::ParseTree* suite;
    //really a parseTree? or a SuiteContext?
    std::vector<sjtu::funcArg> params;
public:
    Function(antlr4::tree::ParseTree* tree, 
             std::vector<sjtu::funcArg> &params)
             :suite(tree),params(params){}
    Function(){}
};

class Program 
{
    using Any = antlrcpp::Any;
public:
    bool checkIsName;
    std::stack<Frame> frames;
    std::map<std::string,Function> funcs;
    Frame global;
public:
    Program():checkIsName(false), frames(), funcs(), global(){}
    antlrcpp::Any* getValue(std::string name)
    {
        if (!frames.empty()) {
            if (frames.top().memory.count(name))
                return &(frames.top().memory.at(name));
            else if (global.memory.count(name))
                return &(global.memory.at(name));
            else {
                if (checkIsName) {
                    frames.top().memory.insert(make_pair(name, Any()));
                    return &(frames.top().memory.at(name));
                }
                else {
                    //err
                }
            }  
        }
        else {
            if (global.memory.count(name))
                return &(global.memory.at(name));
            else {
                if (checkIsName) {
                    global.memory.insert(make_pair(name, Any()));
                    return &(global.memory.at(name));
                }
                else {
                    //err
                }    
            }
        }
        return nullptr;
    }
};


#endif //PYTHON_INTERPRETER_PROGRAM_H
