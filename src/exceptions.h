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
        exception(const exception &ec) : variant(ec.variant), detail(ec.detail) {}
        virtual std::string what() {
            return variant + " " + detail;
        }
    };


    class index_out_of_bound : public exception {};

    class runtime_error : public exception {};

    class invalid_iterator : public exception {};

    class container_is_empty : public exception {};

    class flowRet 
    {
        using Any = antlrcpp::Any;
    public:
        int type;
        //1 for break, 2 for continue and 3 for return
        antlrcpp::Any retValue;
        flowRet(int tp = 0, Any ret = Any()): type(tp), retValeu(ret){}
        ~flowRet() {}
    }
    class none_t{}
    struct funcArg
    {
        std::string name;
        antlrcpp::Any value;
        bool type;
        funcArg(antlrcpp::Any &val, bool tp = 0, std::string n = ""):
            value(val), type(tp), name(n) {}
    }
}

#endif