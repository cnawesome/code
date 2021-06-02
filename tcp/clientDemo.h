#include<stdio.h>
#include<iostream>
#include<string.h>
#include"tcb.h"
#include"clientD.h"


using namespace std;

    Cstatus Client::tcpInit(int des,char *c,TCB &tcb){
        tcb.sourcePort=500;
        tcb.denstinationPort=des;
        tcb.number=1;//确认码，接收方接收到发送时自动加一
        //标识
        tcb.ct=SYN;
        taStri ts=showconnectTag(tcb.ct);
        tcb.winSize=0;
        tcb.checkSum=(tcb.sourcePort+tcb.denstinationPort+tcb.winSize)/3;
        for(int i = 0; i < 100; i++)
        {
            tcb.data[i]='i';
        }
        //strcpy(tcb.data,c);

        //发送给server
      
        cout<<"client tcb have tranformed!\n"<<endl;
        printf("tcb information from client:\n");
        printf("sourcePort:%d   destinPort:%d\nnumber:%d\ntransform type:%s\ncheckSum:%f\ndata:%s\n\n"
                ,tcb.sourcePort,tcb.denstinationPort,tcb.number,ts.sta,tcb.checkSum,tcb.data);
        return cstatus;
     }

    void Client::tcpLink(char *c,TCB &tcb){
        if(tcb.ct == FIN ||tcb.ct == SYN){
            tcb.ct=ACK;
            taStri ts=showconnectTag(tcb.ct);
            tcb.number++;
            tcb.checkSum=(tcb.sourcePort+tcb.denstinationPort+tcb.winSize)/3;
            //发送给server
            printf("sourcePort:%d   destinPort:%d\nnumber:%d\ntransform type:%s\ncheckSum:%f\ndata:%s\n\n"
                ,tcb.sourcePort,tcb.denstinationPort,tcb.number,ts.sta,tcb.checkSum,tcb.data);
        }
        else
        {
            cout<<"tcp link error! please rebulid link\n"<<endl;
        }


    }

    Client::Client(ipAdd ip){
        cstatus=CLOSE;
        cstatuStri ts=showCStatus(cstatus);
        addr.ip1=ip.ip1;
        addr.ip2=ip.ip2;
        addr.ip3=ip.ip3;
        addr.ip4=ip.ip4;
        printf("baisc information:\nclient name:%s\nclinent statu:%s\nipadd:%d.%d.%d.%d\n\n"
        ,c_name,ts.stc,ip.ip1,ip.ip2,ip.ip3,ip.ip4);


    }


