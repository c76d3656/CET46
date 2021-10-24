//
// Created by c76 on 2021/10/21.
//

#include "EngToCh.h"
bool numIsRight(int a);
void fourNumFormat(int (&four)[4],int b);
int printfOut(int (&four)[4]);
void isSelectZero(int (&four)[4]);

void EngToCh::eToC(const int b) {
    int count=0;
    for(int i=0;i<20;++i){
        int four[4]={-1,-1,-1,-1};
        fourNumFormat(four,b);
        int temp=printfOut(four);
        if(temp!=-1)
            words[four[temp]].flag1= true;
        else if(++count==2){
            std::cout<<"\nWrong so much!\n"<<std::endl;
            isSelectZero(four);
            system("pause");
            return;
        }
        isSelectZero(four);
        std::cout<<"\ngood job! go on\n"<<std::endl;
        system("pause");
        system("cls");
    }



}
void isSelectZero(int (&four)[4]){
    for(auto &i:four)
        words[i].isSelect= false;
}
int printfOut(const int (&four)[4]){
    int rn= randNum(3);
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

bool numIsRight(int const a) {
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
void fourNumFormat(int (&four)[4],int const b){
    for(int & i : four){
        int rn;
        while (true){
            rn= randNum(b);
            if(numIsRight(rn))
                break;
            else
                continue;
        }
        i=rn;
        words[rn].isSelect= true;
    }
}

