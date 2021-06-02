#include<stdio.h>
#include"tcb.h"
#include"serverD.h"

using namespace std;

    void Server::openStcp(){
        status=LISTEN;
        sstatuStri ts=showSStatus(status); 
         printf("baisc information:\nserver name:%s\nsourcePort:%d\ncserver statu:%s\n\n"
        ,c_name,tcb.sourcePort,ts.stb);   
    }

    TCB Server::stcpInit(int port){
        tcb.sourcePort=600;
        tcb.denstinationPort=port;
        tcb.number=1;//确认码，接收方接收到发送时自动加一
        //标识
        tcb.ct=FIN;
        taStri ts=showconnectTag(tcb.ct);
        printf("server tcb have prepared!\n");
        printf("tcb information:\n");
        printf("sourcePort:%d\ntransform type:%s\n\n"
                ,tcb.sourcePort,ts.sta);
        return tcb;
     }
    void Server::stcpWork(){
             if(Tcb.ct == SYN)
            {
                tcb=Tcb;
                taStri ts=showconnectTag(tcb.ct);
                printf("tcb information from server:\n");
                printf("sourcePort:%d\ndestinPort:%d\nnumber:%d\ntransform type:%s\ncheckSum:%f\ndata:%s\n\n"
                ,tcb.sourcePort,tcb.denstinationPort,tcb.number,ts.sta,tcb.checkSum,tcb.data);
                tcb.ct=SYN;
                tcb.sourcePort=600;
                tcb.denstinationPort=500;
                tcb.number++;
                tcb.checkSum++;
                Tcb=tcb;

            }

            
    }
    
        Server::Server(){
        status=sCLOSE;
        sstatuStri ts=showSStatus(status);
        addr.ip1=192;
        addr.ip2=168;
        addr.ip3=0;
        addr.ip4=5;
        printf("baisc information:\nserver name:%s\ncserver statu:%s\nipadd:%d.%d.%d.%d\n\n"
        ,c_name,ts.stb,addr.ip1,addr.ip2,addr.ip3,addr.ip4);


    }



 