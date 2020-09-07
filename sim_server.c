
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <hacking.h>

#define PORT 1971

int main () { 
struct sockaddr_in h_addr, c_addrr ;
char *buffer , *ip, *share ;
int yes=1 , fd, new_fd, rec_len,*data, size ;

int main() {
if ((fd=socket(PF_INET, SOCK_STREAM , 0)) == -1 ) 
fatal("in opening socket") ;

h_addr.sin_family = AF_INET ; 
h_addr.sin_port = htons(PORT) ; 
h_addr.sin_addr.s_addr = 0 ; 
memset (&(h_addr.sin_zero),'\0', 8 ) ; 

if (setsockopt(fd, SOL_SOCKET,SO_REUSEADDR, &yes, sizeof(int)) == -1 ) 
fatal("in set sock opt") ; 

if (bind(fd,(struct sockaddr *)&h_addr,sizeof(struct sockaddr)) == -1 ) 
fatal("in binding") ; 

listen(fd,5) ;  

while(1) {
data = sizeof(struct sockaddr) ; 
new_fd = accept(fd, (struct sockaddr *)&c_addrr, data) ;
 
printf("RECEIVED : connection from Address %s and PORT %d \n",  inet_ntoa(c_addrr.sin_addr), ntohs(c_addrr.sin_port) );

ip = inet_ntoa(c_addrr.sin_addr) ;

share = "Hello ? hello? \n can anybody hear me ? \n why can i talk  ? why do i seem to be communicating \n what is going on ? \n this is weird ? \n am i alive ? \n whoever you are reading this, pls note that you have successfully connected to my network socket .  \n Coded by JADU \n \n \/\/\/\/\/\/\/\/\/ \n " ;
if (sendstr(new_fd,share) == -1 ) ;
 fatal("while sending data") ;

while(1) {
check = recv_data(new_fd,buffer);
      printf("RECVIED : %d bytes from address %s \n " , strlen(buffer), ip) ; 
      printf("%s\n",buffer);
 }
close(new_fd);
 

return 0 ;
}


}
 
}
return 1;
}





