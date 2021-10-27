//
// Created by c76 on 2021/10/23.
//

#include "ChToEng.h"

bool numIsRight(int num);
bool ansIsRight(std::string const& ans,int num);
bool printOut(int num);
int randNum(unsigned long long b);


void ChToEng::CtoEn(const unsigned long long b) {
    //turn为每一轮出现单词次数
    int turn=3;
    //count记录错误个数
    int count=0;
    for(int i=0;i<turn;++i){
        //获取随机数
        int num=randNum(b);
        //判断随机数正误
        while (!numIsRight(num)){
            num= randNum(b);
        }
        //进入ChToEng主程序
        if(!printOut(num)){
            //返回错误则计数器count+1
            if(++count==2){
                std::cout<<"\nWrong so much!\n"<<std::endl;
                system("pause");
                return;
            }
        }
    }
    std::cout<<"\ngood job! go on\n"<<std::endl;
//    system("pause");
//    system("cls");
}

bool printOut(int const num){
    //临时存储word
    individual temp=words[num];
    //输出中文
    std::cout<<"\t"<<temp.ch<<std::endl;
    //记录字符长度
    int size=0;
    //记录起始与结尾，避免重复计算
    auto temp_begin=temp.eng.begin();
    auto temp_end=temp.eng.end();
    //输出头字母
    std::cout<<*temp_begin;
    //中间字母使用*隐去
    for(auto i=temp_begin+1;i!=(temp_end-1);++i){
        std::cout<<"*";
        ++size;
    }
    //输出末尾字母
    std::cout<<(*(temp_end-1));
    printf("\ncompletion the word length in %d\n",size+2);
    //输入答案
    std::string ans;
    std::cin>>ans;
    //答案正误判断
    if(ansIsRight(ans,num)){
        std::cout << "Right ans" << std::endl;
        return true;
    } else{
        std::cout<<"Wrong ans"<<std::endl;
        return false;
    }
}

bool ansIsRight(std::string const& ans,int const num){
    if(ans==words[num].eng){
        //正确则记录flag2为true，下次随机不再出现
        words[num].flag2= true;
        return true;
    }else
        return false;
}

bool numIsRight(int const num){
    individual temp=words[num];
    if(temp.flag2)
        return false;
    else
        return true;
}

int randNum(const unsigned long long b){
    //获取随机数
    std::random_device rd;//获取种子
    std::mt19937 gen(rd()* std::chrono::high_resolution_clock::now().time_since_epoch().count());//以梅森为播种标准
    std::uniform_int_distribution< > dis(0,(int)b);//播种
    int rn=dis(gen);
    return rn;
}