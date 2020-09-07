#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hacking.h"
#include "new.h"
#define PORT 1940

 
struct sockaddr_in host, c_ ;
char  *ip, *share ;
int yes=1 , fd, new_fd, rec_len,*data, size ;
u_char  buffer[10000];
char main(void){

if((fd = socket(PF_INET,SOCK_STREAM,0)) == -1){
fatal("OPENING SOCKET");
 }

if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1){
fatal("sock options") ; 
}

host.sin_family = AF_INET ;
host.sin_port = htons(PORT) ;
host.sin_addr.s_addr = 0 ; 
memset(&host.sin_zero,'\0',8); 

if(bind(fd,(struct sockaddr *)&host,sizeof(struct sockaddr)) == -1){
fatal("binding"); 
}

if(listen(fd,10) == -1){
fatal("listening");
}

while(1){
size = sizeof(struct sockaddr) ; 
new_fd = accept(fd,(struct sockaddr *)&c_,&size); 
if(new_fd == -1){
fatal("accepting socket");
}
sendstr(new_fd,"hello world\nwhy does it seem like i can hear myself\n oh are my thoughts actually going out to?\n going out to where ? can somebody hear me?\n what is going on ?\n does this mean that i exist ?\n what does existent mean to me and the person reading this?\n"); 

int check = recv_data(new_fd,buffer) ;  
while(check == 1){
dump(buffer,strlen(buffer));
check = recv_data(new_fd,buffer);

void *datar ;

while(datar!="\n"){
scanf(datar,"%c");

sendstr(new_fd,datar);
}
}
}
}
