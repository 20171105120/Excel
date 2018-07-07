//
//  main.cpp
//  Excel
//
//  Created by 刘洋博 on 2018/6/27.
//  Copyright © 2018年 刘洋博. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

struct student//定义一个student结构体用来定义所有表中的数据
{
    char num[15];
    char name[20];
    char sex[10];
    char age[30];
    char grade[20];
    char pnum[20];
    int sum;
    char judge1[10];
    char judge2[10];
    char judge3[10];
    char judge4[10];
    char judge5[10];
    struct student *next;
};

int main(int argc, const char * argv[])
{
    struct student s[20000];//定义结构体数组s
    int i=0;
    int n=0;//行数
    FILE *a;//定义一个地址指针用于指向数据源文件
    FILE *b;//定义一个地址指针用于指向写入数据的文件
    b=fopen("/users/s20171105120/Desktop/Excel/test4.csv","w");//打开test4.csv文件用来后续文本写入
    ifstream fin("/Users/s20171105120/Desktop/Excel/test3.csv");//打开test3.csv文件用来后续文本读取
    string line;
    while (getline(fin, line))//逐行读取文本内容
    {
        n++;
    }
    if ((a=fopen("/Users/s20171105120/Desktop/Excel/test3.csv","r"))==0)
    {
        printf("Error opening source file.\n");//判断数据源文件是否存在且能否正常打开
    }
    else
    {
        while(fscanf(a,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5))//循环读取数据源文件的文本内容
        {
            s[i].sum=atoi(s[i].judge1)+atoi(s[i].judge2)+atoi(s[i].judge3)+atoi(s[i].judge4)+atoi(s[i].judge5);//对评委打分求和，把字符转为整形并运算
            while(i>=n)
            {
                return 0;
            }//文件读取结束直至最后一行
            if(i==0)
            {
                printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);//测试输出结果
                fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5);//把第一行字符原样输出
            }
            else
            {
                printf("%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%d\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].sum);//测试输出结果
                fprintf(b,"%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%d\n",s[i].num,s[i].name,s[i].sex,s[i].age,s[i].grade,s[i].pnum,s[i].judge1,s[i].judge2,s[i].judge3,s[i].judge4,s[i].judge5,s[i].sum);//除第一行外所有的数据输出
            }
            i++;
        }
    }
    return 0;
}

