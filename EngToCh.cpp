//
// Created by c76 on 2021/10/21.
//

#include "EngToCh.h"
bool numIsRight0(int a);
void fourNumFormat(int (&four)[4],unsigned long long b);
void isSelectZero(int (&four)[4]);
int randNum0(unsigned long long b);
int printfOut1(const int (&four)[4]);

void EngToCh::eToC(const unsigned long long b) {
    int count=0;
    for(int i=0;i<3;++i){
        int four[4]={-1,-1,-1,-1};
        fourNumFormat(four,b);
        int temp= printfOut1(four);
        if(temp!=-1) {
            words[four[temp]].flag1 = true;
            std::cout << "Right ans" << std::endl;
        }
        else if(++count==2){
            std::cout<<"\nWrong so much!\n"<<std::endl;
            isSelectZero(four);
//            system("pause");
            return;
        }else{
            std::cout<<"Wrong ans"<<std::endl;
        }
        isSelectZero(four);
    }
    std::cout<<"\ngood job! go on\n"<<std::endl;
//    system("pause");
//    system("cls");
}
void isSelectZero(int (&four)[4]){
    for(auto &i:four)
        words[i].isSelect= false;
}

int printfOut1(const int (&four)[4]){
    int rn= randNum0(3);
    std::cout<<"\t"<<words[four[rn]].eng<<"\t"<<std::endl;
    for(int i=0;i<4;++i){
        std::cout<<i+1<<". "<<words[four[i]].ch<<std::endl;
    }
    std::cout<<"Please input the number"<<std::endl;
    int i;
    std::cin>>i;
    if((--i)==rn)
        return rn;
    else
        return -1;
}

bool numIsRight0(int const a) {
    //判断该数值是否合理可选
    //判断isSelect若为1啧false
    if(words[a].isSelect){
        return false;
    }
    //判断flag1&&flag2若为真则false
    if(words[a].flag1){
        return false;
    }
    return true;
}
void fourNumFormat(int (&four)[4],const unsigned long long b){
    for(int & i : four){
        int rn;
        while (true){
            rn= randNum0(b);
            if(numIsRight0(rn))
                break;
            else
                continue;
        }
        i=rn;
        words[rn].isSelect= true;
    }
}
int randNum0(const unsigned long long b){
    //获取随机数
//    std::random_device rd;//获取种子
//    std::mt19937 gen(rd());//以梅森为播种标准
//    std::uniform_int_distribution< > dis(0,b);//播种
//    int rn=dis(gen);
    srand(time(nullptr));
    int rn=rand() % (b);
    return rn;
}


