#include <iostream>
#include <string>
#include <vector>
#include "SturctFront.h"
#include "EngToCh.h"
#include "ChToEng.h"
std::vector<individual> words;

void welcomePrint();
void formal();

int main() {
    while (true){
        formal();
        welcomePrint();
        int choice,b;
        b=words.size();
        std::cin>>choice;
        system("cls");
        if(choice==1){
            //Eng to Ch
            EngToCh::eToC(b);
            continue;
        } else if(choice==2){
            //Ch to Eng
            ChToEng::CtoEn(b);
            continue;
        } else if(choice==0){
            printf("Thanks for use");
            system("pause");
            return 0;
        } else{
            printf("Input Wrong");
            system("pause");
            system("cls");
        }
    }
}

void welcomePrint(){
    printf("\t-CET-\t\n");
    printf("1.Eng to Ch\n");
    printf("2.Ch to Eng\n");
    printf("0.To exit\n");
    printf("Please input......\n");
}

void formal(){
    //读取文件格式化
}