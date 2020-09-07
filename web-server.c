#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hacking.h"
#include "new.h"

#define PORT 1940 
struct sockaddr_in host,client ; 
int sock,sockk,fd,yes=1 ;
unsigned char buffer[5000] ; 
socklen_t size = sizeof(struct sockaddr) ; 
int main(void){
if(sock = socket(PF_INET,SOCK_STREAM,0) == -1){
fatal("opening socket") ; 
} 

if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1 ) {
fatal("socket options");
}

host.sin_family = AF_INET ; 
host.sin_port = htons(PORT) ; 
host.sin_addr.s_addr = 0 ; 
memset(&host,'\0',8) ; 

if(bind(sock,(struct sockaddr *)&host,1) == -1 ){
fatal("binding socket") ; 
} 

listen(sock,10) ; 

while(1) ; 
if(sockk = accept(sock,(struct sockaddr *)&host,&size) == -1 ){
fatal("accepting connection") ; 
} 



sendstr(sockk,"Hello fuckheads\n") ; 

fd = recv_data(sockk,buffer) ; 
if(fd == 1){

unsigned char *use

use = strstr(buffer, "HTTP/") ; 
if(use){

if(strncmp(buffer,"GET " 4) == 0){
pointer = buffer+4 ;
printf("%s\n",buffer);
if(strcmp(buffer,"/web.html" 10) == 0){
sendstr(fd,"HTTP/1.0 200 OK <Doctypehtml!> <html> <title>PAGE NOT FOUND</title> <head><body><h1>404 NOT FOUND \n sorry content can not be found<\h1><\body><\head><\html>");
}else{sendstr(sockk, m

if(strncmp(buffer, "HEAD " 4) == 0){
pointer = buffer+4 ;

printf("%s\n",buffer) ; 
}
else {
printf("something wrong") ; 
exit(0) ;
}
}
