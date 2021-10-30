//
// Created by c76 on 2021/10/21.
//

#include "EngToCh.h"
bool numIsRight0(int a);
void fourNumFormat(int (&four)[4],unsigned long long b);
void isSelectZero(int (&four)[4]);
int randNum0(unsigned long long b);
int printfOut1(const int (&four)[4]);
//为修复答错后无法显示正确答案的bug
int tempRightAns;

void EngToCh::eToC(const unsigned long long b) {
    //turn为每一轮出现单词次数
    int turn=30;
    //count记录错误个数
    int count=0;
    for(int i=0;i<turn;++i){
        //four用于记录随机数
        int four[4]={-1,-1,-1,-1};
        //随机数初始化
        fourNumFormat(four,b);
        //进入主运行程序,temp返回次次答题的正确与否
        int temp= printfOut1(four);
        //isSelect归零，以免下次随机不出
        isSelectZero(four);
        if(temp!=-1) {
            //如果答对了就将该word的flag1标记为true
            //下一次随机就不会出现
            words[four[temp]].flag1 = true;
            std::cout << "Right ans" << std::endl;
        }else {
            std::cout<<"Wrong ans"<<std::endl;
            ++count;
            std::cout<<"right ans is:\t"<<words[four[tempRightAns]].ch<<std::endl;
        }
        if(count==2){
            //回答错误count先自加1，若为2则退出EngToCh程序
            std::cout<<"\nWrong so much!\n"<<std::endl;
            system("pause");
            return;
        }
    }
    std::cout<<"\ngood job! go on\n"<<std::endl;
    system("pause");
//    system("cls");
}
void isSelectZero(int (&four)[4]){
    for(auto &i:four)
        words[i].isSelect= false;
}

int printfOut1(const int (&four)[4]){
    //从已选4个词中挑选一个
    int rn= randNum0(3);
    tempRightAns=rn;
    //打印
    std::cout<<"\t"<<words[four[rn]].eng<<"\t"<<std::endl;
    //打印中文释义
    for(int i=0;i<4;++i){
        std::cout<<i+1<<". "<<words[four[i]].ch<<std::endl;
    }
    std::cout<<"Please input the number"<<std::endl;
    int i;
    std::cin>>i;
    //判断正误
    if((--i)==rn)
        return rn;
    else
        return -1;
}

bool numIsRight0(int const a) {
    //判断该数值是否合理可选
    //判断isSelect若为true啧false
    if(words[a].isSelect){
        return false;
    }
    //判断flag1&&flag2若为true则false
    if(words[a].flag1){
        return false;
    }
    return true;
}
void fourNumFormat(int (&four)[4],const unsigned long long b){
    for(int & i : four){
        int rn;
        while (true){
            //获得随机数
            rn= randNum0(b);
            //判断随机数是否可用
            if(numIsRight0(rn))
                break;//正确则跳出循环
            else
                continue;//错误继续
        }
        i=rn;//将rn的值放入four中储存
        words[rn].isSelect= true;//标记该word已经被选中
    }
}
int randNum0(const unsigned long long b){
    //获取随机数
    std::random_device rd;//获取种子
    std::mt19937 gen(rd()* std::chrono::high_resolution_clock::now().time_since_epoch().count());//以梅森为播种标准
    std::uniform_int_distribution< > dis(0,(int)b);//播种
    int rn=dis(gen);
    return rn;
}


