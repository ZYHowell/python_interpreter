#include <iostream>
#include "antlr4-runtime.h"
#include "Python3Lexer.h"
#include "Python3Parser.h"
#include "Evalvisitor.h"
using namespace antlr4;
int main(int argc, const char* argv[]){
    const std::string filepath="../testData/test"+std::string(argv[1])+".in";
    // const std::string filepath = "../test.py";
    std::ifstream ifs;
    ifs.open(filepath);
    if (!ifs.good()) {
        std::cout<<"bad";
    }
    ANTLRInputStream input(ifs);
    Python3Lexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    Python3Parser parser(&tokens);
    tree::ParseTree* tree=parser.file_input();
    EvalVisitor visitor;
    visitor.visit(tree);


    ifs.close();
//    antlrcpp::Any tmp=1;
//    std::cout<<tmp.is<double>();
    return 0;
}