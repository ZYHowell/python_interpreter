//
// Created by jinho on 9/19/2019.
//
#include <iostream>
#include "antlr4-runtime.h"
#include "Python3Lexer.h"
#include "Python3Parser.h"
#include "Evalvisitor.h"
using namespace antlr4;
antlrcpp::Any test(){
    std::vector<std::string> a;
    a.push_back("123");
    a.push_back("234");
    return a;
}
antlrcpp::Any test2(){
    return test();
}
int main(int argc, const char* argv[]){
//    const std::string filepath="../test_file/new.py";
//    std::ifstream ifs;
//    ifs.open(filepath);
//    if (!ifs.good()) {
//        std::cout<<"bad";
//    }
//    ANTLRInputStream input(ifs);
//    Python3Lexer lexer(&input);
//    CommonTokenStream tokens(&lexer);
//    tokens.fill();
//    Python3Parser parser(&tokens);
//    tree::ParseTree* tree=parser.file_input();
//    EvalVisitor visitor;
//    visitor.visit(tree);
//
//
//    ifs.close();
//    antlrcpp::Any tmp=1;
//    std::cout<<tmp.is<double>();
    for (int i = 0; i < 2; i++) {
        auto tmp=test2();
        int a=0;
        a++;
        for (int j = 0; j < 10; j++) {
            a++;
        }
        std::cout<<tmp.as<std::vector<std::string>>()[i];
    }
}