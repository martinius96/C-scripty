#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

void error(char *msg)
{ 						//tato funkcia sa vyuziva ked systemove volanie zlyha
	perror(msg); //vypise spravu o chybe a ukonci program server
	exit(0);
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n; //pomocne premenne
	struct sockaddr_in serv_addr; //obsahuje adresu servera
	struct hostent *server; //informacie o vzdialenom pocitaci
	char buffer[256]; //buffer pre ulozenie znakov zo socketu
if (argc < 3) { //kontrola poctu argumentov
	fprintf(stderr,"usage %s hostname port\n", argv[0]);
	exit(0);
}

portno = atoi(argv[2]); //cislo portu servera
						//vytvorenie socketu
sockfd = socket(PF_INET, SOCK_STREAM, 0);

if (sockfd < 0) error("ERROR opening socket");
						//hostname pc server
server = gethostbyname(argv[1]);

if (server == NULL) {
fprintf(stderr,"ERROR, no such host\n");
exit(0);}
						//naplnenie struktury sockaddr_in
bzero((char *) &serv_addr, sizeof(serv_addr));
serv_addr.sin_family = AF_INET;
bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,
server->h_length);
serv_addr.sin_port = htons(portno);
						//vytvorenie spojenia

if (connect(sockfd, (struct sockaddr *) &serv_addr,
sizeof(serv_addr)) < 0)
error("ERROR connecting");
						//spracovanie dat
printf("Please enter the message: ");
bzero(buffer,256);
fgets(buffer,255,stdin); //zadanie znakov z klavesnice
n = write(sockfd,buffer,strlen(buffer));

if (n < 0)
error("ERROR writing to socket");
bzero(buffer,256);
n = read(sockfd,buffer,255);

if (n < 0)
error("ERROR reading from socket");
printf("%s\n",buffer);
return 0;
}