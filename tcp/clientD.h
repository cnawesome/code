#ifndef _CLIENTD_H_
#define _CLIENTD_H_
#include<stdio.h>
#include<string.h>
#include"tcb.h"
#include"serverD.h"

typedef struct cSt{
    char stc[20];
}cstatuStri;

typedef enum cst{CLOSE,LINKED,DISCONNECT} Cstatus;

class Client{
    char  c_name[20]="client001";
    Cstatus cstatus;
    ipAdd addr;
    TCB tcb;
public:
    Cstatus tcpInit(int des,char *c,TCB &tcb);
    void tcpLink( char *c,TCB &tcb);
public: 
    Client(ipAdd ip);

};

cstatuStri showCStatus(int t){
    cstatuStri cs;
    switch (t)
    {
    case 0:
        strcpy(cs.stc,"CLOSE");
        break;
    
    case 1:  
        strcpy(cs.stc,"LINKED");
        break;
    
    case 2:
        strcpy(cs.stc,"DISCONNECT");
        break;
    
    default:
        break;
    }
    return cs;
}

#endif