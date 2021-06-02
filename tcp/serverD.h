#ifndef _SERVERD_H_
#define _SERVERD_H_
#include<stdio.h>
#include<string.h>
#include"tcb.h"


typedef struct sSt{
    char stb[20];
}sstatuStri;

typedef enum sst{sCLOSE,LISTEN,sLINKED,sDISCONNECT} Sstatus;


sstatuStri showSStatus(int t){
    sstatuStri ss;
   switch (t)
    {
    case 0:
        strcpy(ss.stb,"sCLOSE");
        break;
    
    case 1:
        strcpy(ss.stb,"LISTEN");
        break;
    
    case 2:
        strcpy(ss.stb,"sLINKED"); 
        break;

    case 3:
        strcpy(ss.stb,"sDISCONNECT");
        break; 
    default:
        break;
    }
    return ss;
}


class Server {
    char  c_name[20]="server001";
public:  
    Sstatus status;  
    ipAdd addr;
    TCB tcb;

public:
    TCB stcpInit(int port);
    void openStcp();
    void stcpWork();

public: 
    Server();

};

#endif