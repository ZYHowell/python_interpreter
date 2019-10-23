#ifndef SJTU_EXCEPTIONS_HPP
#define SJTU_EXCEPTIONS_HPP

#include <cstddef>
#include <cstring>
#include <string>
#include "antlr4-runtime.h"

namespace sjtu 
{

    class exception 
    {
    protected:
        const std::string variant = "";
        std::string detail = "";
    public:
        exception() {}
        exception(const std::string &var, const std::string &det = ""):variant(var), detail(det){}
        exception(const exception &ec) : variant(ec.variant), detail(ec.detail) {}
        virtual std::string what() {
            return variant + ": " + detail;
        }
    };

    class typeError : public exception 
    {
    public:
        typeError(const std::string &var = "", const std::string &det = ""):exception(var, det){}
    };

    class illegalExpression : public exception 
    {
    public:
        illegalExpression(const std::string &var = "", const std::string &det = ""):exception(var, det){}
    };

    class valueError : public exception 
    {
    public:
        valueError(const std::string &var = "", const std::string &det = ""):exception(var, det){}
    };

    class syntaxError : public exception 
    {
    public:
        syntaxError(const std::string &var = "", const std::string &det = ""):exception(var, det){}
    };

    class nameError : public exception 
    {
    public:
        nameError(const std::string &var = "", const std::string &det = ""):exception(var, det){}
    };

    class flowRet 
    {
    public:
        int type;
        //1 for break, 2 for continue and 3 for return
        antlrcpp::Any retValue;
        flowRet(int tp = 0, antlrcpp::Any ret = antlrcpp::Any()): type(tp), retValue(ret){}
        ~flowRet() {}
    };
    class none_t{};
    struct funcArg
    {
        std::string name;
        antlrcpp::Any value;
        bool type;
        funcArg(antlrcpp::Any&& val = antlrcpp::Any(), bool tp = 0, std::string n = ""):
        value(val), type(tp), name(n) {
        }
    };
}

#endif