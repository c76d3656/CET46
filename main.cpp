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
    formal();
    int choice;
    auto b=words.size();
    while (true){
        welcomePrint();
        std::cin>>choice;
//        system("cls");
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
//            system("cls");
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
    //test
    individual test=individual("hello","你好");
    words.push_back(test);
    test=individual("world","世界");
    words.push_back(test);
    test=individual("code","代码");
    words.push_back(test);
    test=individual("hub","俱乐部");
    words.push_back(test);
    test=individual("who","谁");
    words.push_back(test);
    test=individual("her","她");
    words.push_back(test);
    test=individual("give","给予");
    words.push_back(test);
    test=individual("accept","同意");
    words.push_back(test);
    //读取文件格式化
}