#include "CSocketServer.hpp"
#include <iostream>
#include <string.h>
#include <string>

#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()

#define MAX 80
#define PORT 8080
#define SA struct sockaddr
CSocketServer::CSocketServer(int port) {
  std::cout << "created server" << std::endl;
  this->port = port;
}

void CSocketServer::createSocket() {

  // struct sockaddr_in servaddr, cli;

  // socket create and verification
  this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (this->sockfd == -1) {
    printf("socket creation failed...\n");
    exit(0);
  } else
    printf("Socket successfully created..\n");
  // bzero(&servaddr, sizeof(servaddr));

  // assign IP, PORT
  this->servaddr.sin_family = AF_INET;
  this->servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  this->servaddr.sin_port = htons(this->port);
}
void CSocketServer::bindServer() {
  // Binding newly created socket to given IP and verification
  if ((bind(this->sockfd, (SA *)&this->servaddr, sizeof(this->servaddr))) !=
      0) {
    printf("socket bind failed...\n");
    exit(0);
  } else
    printf("Socket successfully binded..\n");
}

void CSocketServer::listenForClient() {
  // Now server is ready to listen and verification
  if ((listen(this->sockfd, 5)) != 0) {
    printf("Listen failed...\n");
    exit(0);
  } else
    printf("Server listening..\n");
  this->len = sizeof(this->cli);
}
void CSocketServer::acceptClient() {

  // Accept the data packet from client and verification

  connfd = accept(sockfd, (SA *)&cli, &this->len);
  if (this->connfd < 0) {
    printf("server accept failed...\n");
    exit(0);
  } else
    printf("server accept the client...\n");
}

void CSocketServer::sendStringToClient(std::string msg) {

  char buff[] = "helloWorld";
  write(this->connfd, buff, sizeof(buff));
}

void CSocketServer::waitForClient() {
  char buff[80];
  read(this->connfd, buff, sizeof(buff));
 
}