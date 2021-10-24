//
// Created by c76 on 2021/10/21.
//

#ifndef CET46_STURCTFRONT_H
#define CET46_STURCTFRONT_H
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <iostream>
#pragma once
struct  individual{
    std::string eng;
    std::string ch;
    bool flag1= false;
    bool flag2= false;
    bool isSelect= false;
};
extern std::vector<individual> words;

int randNum(int const b){
    //获取随机数
    std::random_device rd;//获取种子
    std::mt19937 gen(rd());//以梅森为播种标准
    std::uniform_int_distribution< > dis(0,b);//播种
    int rn=dis(gen);
    return rn;
}

class SturctFront {

};


#endif //CET46_STURCTFRONT_H
