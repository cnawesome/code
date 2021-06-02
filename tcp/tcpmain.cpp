#include<stdio.h>
#include<thread>
#include"tcb.h"
#include"clientD.h"
#include"serverD.h"
#include"clientDemo.h"
#include"serverDemo.h"

using namespace std;



int main(){
    ipAdd ipaddr;
    ipaddr.ip1=198;
    ipaddr.ip2=168;
    ipaddr.ip3=0;
    ipaddr.ip4=3;

    int i=0;
    Client client(ipaddr);
    char data[100]="this is a example!";
    Server ser;
    ser.stcpInit(500);
    ser.openStcp();
    Cstatus cs=client.tcpInit(600,data,Tcb);
    //printf("%d",Tcb.ct);
    ser.stcpWork();

    client.tcpLink(data,Tcb);
    while(true){
        /* code */
    }

return 0;

}