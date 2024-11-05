#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <iomanip>

const int MAXJOB = 20;      //定义最大作业数 

// 结构体
typedef struct node {
    int start;
    int length;
    char tag[20];
} job;

job frees[MAXJOB];//定义空闲区表 
int free_quantity;

job occupys[MAXJOB];//定义已分配区表 
int occupy_quantity;

//初始化函数 
void initial() {
    int i;

    for (i = 0; i < MAXJOB; i++) {
        frees[i].start = 0;
        frees[i].length = 1024;
        strcpy(frees[i].tag, "free"); //标识空闲区"free"

        occupys[i].start = 0;
        occupys[i].length = 0;
        strcpy(occupys[i].tag, ""); //标识已分配区
    }
    free_quantity = MAXJOB;
    //occupy_quantity = 0;
}

//显示 
void print() {
    int i;

    std::cout << std::endl << "----------------------------------------------------------" << std::endl;
    std::cout << "当前空闲表:" << std::endl;
    std::cout << "起始地址    长度     状态" << std::endl;
    for (i = 0; i < free_quantity; i++) {
        std::cout << std::setw(5) << std::right << frees[i].start;
        std::cout << std::setw(9) << std::right << frees[i].length;
        std::cout << std::setw(11) << std::right << frees[i].tag << std::endl;
    }

    std::cout << std::endl << "----------------------------------------------------------" << std::endl;
    std::cout << "当前已分配表:" << std::endl;
    std::cout << "起始地址    长度     作业名" << std::endl;
    for (i = 0; i < occupy_quantity; i++) {
        std::cout << std::setw(5) << std::right << occupys[i].start;
        std::cout << std::setw(9) << std::right << occupys[i].length;
        std::cout << std::setw(11) << std::right << occupys[i].tag << std::endl;
    }
}

void excellent() //分配内存，给定作业采用最佳分配算法分配xk大小的空间(OPT)
{
    char job_name[20];
    int job_length;
    int i, flag;

    std::cout << "请输入新申请内存空间的作业名和空间大小:";
    std::cin >> job_name >> job_length;

    flag = 0; //标记申请空间是否成功,"0"成功,"1"失败
    for (i = 0; i < free_quantity; i++) {
        if (frees[i].length >= job_length) {
            //如果要申请的内存空间小于当前空闲区大小,则标记flag=1表示申请空间成功
            flag = 1;
            break;
        }
    }
    if (flag == 0) //标记是否满足申请要求
    {
        std::cout << std::endl << "对不起,当前没有能满足你申请长度的空闲内存,请稍候再试" << std::endl;
    }
    else {
        //i--;
        int minIndex = i;
        for (int j = 0; j < free_quantity; j++) {
            if ((frees[j].length >= job_length) && (frees[j].length < frees[minIndex].length)) {
                //寻找最合适空闲区,即找到满足申请条件的最小块
                minIndex = j;
            }
        }

        occupys[occupy_quantity].start = frees[minIndex].start; //分配内存,起始地址
        strcpy(occupys[occupy_quantity].tag, job_name); //复制作业号
        occupys[occupy_quantity].length = job_length;    //占有的内存大小(长度)
        occupy_quantity++;

        if (frees[minIndex].length > job_length) //空闲区大于要分配的空间大小
        {
            frees[minIndex].start += job_length; //修改空闲区的起始地址、长度
            frees[minIndex].length -= job_length;
        }
        else                          //相等
        {
            for (int j = minIndex; j < free_quantity - 1; j++) {
                frees[j] = frees[j + 1];
            }
            free_quantity--;
        }
        std::cout << "恭喜你!内存空间成功!" << std::endl << std::endl;
    }
}

//撤消作业 
void mfree() {
    char job_name[20];
    int i, j, flag, p = 0;
    int start;
    int length;

    std::cout << "请输入要撤消的作业名:";
    std::cin >> job_name;

    flag = -1; //标识是否存在要撤消的作业名,"-1"表示没有
    for (i = 0; i < occupy_quantity; i++) {
        if (!strcmp(occupys[i].tag, job_name))//找到要撤消的作业(匹配)
        {
            flag = i; //找到匹配作业的下标
            start = occupys[i].start;
            length = occupys[i].length;
        }
    }
    if (flag == -1) {
        std::cout << "没有这个作业名" << std::endl;
    }
    else {
        //找到作业名;
        //加入空闲表 
        for (i = 0; i < free_quantity; i++) {
            if ((frees[i].start + frees[i].length) == start)  // 寻找回收分区,上邻空闲区，下邻空闲区，三项合并(0 1 0)
            {
                if (((i + 1) < free_quantity) && (frees[i + 1].start == start + length)) {
                    frees[i].length = frees[i].length + frees[i + 1].length + length;
                    for (j = i + 1; j < free_quantity; j++) {
                        frees[j] = frees[j + 1];
                    }
                    free_quantity--;
                    p = 1;
                }
                else //上邻空闲区，下邻非空闲区，与上邻合并(0 1 1)
                {
                    frees[i].length += length;
                    p = 1;
                }
            }
            if (frees[i].start == (start + length)) { // 上邻非空闲区，下邻为空闲区，与下邻合并(1 1 0) or 1 0 1
                frees[i].start = start;
                frees[i].length += length;
                p = 1;
            }
        }

        if (p == 0) {
            frees[free_quantity].start = start;
            frees[free_quantity].length = length;
            free_quantity++;
        }

        //删除分配表中的该作业 

        for (i = flag; i < occupy_quantity; i++) {
            occupys[i] = occupys[i + 1];
        }
        occupy_quantity--;
    }
}

int main() {
    int flag = 0;
    int t = 1;
    int chioce = 0;

    initial();

    while (1) {
        std::cout << "=========================================================" << std::endl;
        std::cout << "=                      存储管理模拟系统                 =" << std::endl;
        std::cout << "=========================================================" << std::endl;
        std::cout << "=                              1.申请空间(最优适配法)   =" << std::endl;
        std::cout << "=                              2.撤消作业               =" << std::endl;
        std::cout << "=                              3.显示空闲表和分配表     =" << std::endl;
        std::cout << "=                              0.退出                   =" << std::endl;
        std::cout << "=========================================================" << std::endl;
        std::cout << "====请你选择操作(0~3):";
        std::cin >> chioce;

        switch (chioce) {
        case 1:
            excellent();  //采用最优算法分配内存
            break;
        case 2:
            mfree();     //释放作业占有的内存
            break;
        case 3:
            print();    //显示内存分配情况
            break;
        case 0:
            exit(0);
        default:
            std::cout << "你选择的操作有误，请重输！" << std::endl;
        }
    }
}