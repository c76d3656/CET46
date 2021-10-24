//
// Created by c76 on 2021/10/23.
//

#include "ChToEng.h"

bool numIsRight(int num);
bool ansIsRight(std::string const& ans,int num);
bool printOut(int num);



void ChToEng::CtoEn(int const b) {
    int count=0;
    for(int i=0;i<20;++i){
        int num=randNum(b);
        while (!numIsRight(num)){
            num= randNum(b);
        }
        if(!printOut(num))   ++count;
        else if(count==2){
            std::cout<<"\nWrong so much!\n"<<std::endl;
            system("pause");
            return;
        }
    }
    std::cout<<"\ngood job! go on\n"<<std::endl;
    system("pause");
    system("cls");
}

bool printOut(int const num){
    individual temp=words[num];
    std::cout<<"\t"<<temp.ch<<std::endl;
    int size=0;
    auto tempbegin=temp.eng.begin();
    auto tempend=temp.eng.end();
    std::cout<<*tempbegin;
    for(auto i=tempbegin+1;i!=tempend-1;++i){
        std::cout<<"*";
        ++size;
    }
    std::cout<<*tempend-1;
    printf("completion the word length in %d\n",size+2);
    std::string ans;
    std::cin>>ans;
    if(ansIsRight(ans,num)){
        return true;
    } else{
        return false;
    }
}

bool ansIsRight(std::string const& ans,int const num){
    if(ans==words[num].eng){
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
