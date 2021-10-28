
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
//Linux下无法使用cls
        }
    }
}

void welcomePrint(){
    //欢迎洁面
    printf("\t-CET-\t\n");
    printf("1.Eng to Ch\n");
    printf("2.Ch to Eng\n");
    printf("0.To exit\n");
    printf("Please input......\n");
}

void formal(){
    //读取文件格式化
    std::fstream fs;
    fs.open("C4ET.txt",std::ios::in);
    std::string eng,ch;
    //当文件流不出现问题时进行读取
    while (fs.good()){
        fs>>eng;
        fs>>ch;
        //构造函数，将其初始化并存入vector
        words.emplace_back(eng,ch);
    }
    fs.close();
}