#include "CTCPClient.hpp"
#include <iostream>
#include <string>

CTCPClient::CTCPClient(){}
/// @brief /is there to create a object..
/// @param ip ip address 
/// @param port port number
CTCPClient::CTCPClient(std::string ip,int port){
  std::cout << "TCP-Client created" << std::endl;
  this->ip= ip;
  this->port=port;
  std::cout << "TCP-Client created" << std::endl;
  std::cout << "ip = " << ip << ", Port= " << port << std::endl;
}
