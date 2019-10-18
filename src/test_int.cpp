//
// Created by jinho on 10/8/2019.
//
#include "bigint.h"
#include <iostream>
int main(){
    BigInt a("123456789098765432112345678909876543211234567890987654321");
    for (int i = 0; i <= 10; i++) {
        a=a*a;
    }
//    a=a*a;
    std::cout<<a.to_string();
}