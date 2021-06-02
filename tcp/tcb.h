#ifndef _TCP_H_
#define _TCP_H_
#include<stdio.h>
#include<string.h>



typedef struct tStr{
    char sta[15];
}taStri;


typedef enum connectTagx{ACK,RST,SYN,FIN}CT;

typedef struct ipadd
{
  int ip1;
  int ip2;
  int ip3;
  int ip4;

}ipAdd;


//tcb块
typedef struct tcb
{
    int sourcePort;
    int denstinationPort;
    int number;
    //标识
    CT ct;
    int winSize;
    double checkSum;
    //数据
    char data[100];

}TCB;
TCB Tcb;



taStri showconnectTag(int t){
    taStri ts;
    switch (t)
    {
    case 0:
        strcpy(ts.sta,"ACK");
        break;
    case 1:
        strcpy(ts.sta,"RST");
        break;
    case 2:
        strcpy(ts.sta,"SYN");
        break;
    case 3:
        strcpy(ts.sta,"FIN");
        break;
    default:
        break;
    }
         return ts; 
}


#endif