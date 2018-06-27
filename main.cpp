//
//  main.cpp
//  Excel
//
//  Created by 刘洋博 on 2018/6/27.
//  Copyright © 2018年 刘洋博. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
struct student
{
    char num[12];
    char name[15];
    char sex[6];
    int age;
    char class[20];
    char pnum[12];
    int score1,score2,score3,score4,score5;
    int sum;
    struct student *next;
};
int main()
{
    struct student s[20];
    struct student t;
    int total=0;
    ifstream studentdata("studentdata.csv",ios::in);
    if(!studentdata){
        cout<<"Error opening source file."<<endl;
        return 0;
    }
    ofstream markingsystem("markingsystem.csv",ios::out);
    if(!markingsystem){
        studentdata.close();
        cout<<"Error opening destination file."<<endl;
        return 0;
    }
}

