#include <string>


#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>



class CSocketServer {
public:
  int sockfd, connfd,  port;
  unsigned int len;
  struct sockaddr_in servaddr, cli;
  // constructor
  CSocketServer(int port);
  //
void createSocket();
void bindServer();
void listenForClient();
void acceptClient();
void sendStringToClient(std::string msg);
void waitForClient();
};
