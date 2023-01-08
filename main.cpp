
// File: main.cc
#include "CTCPClient.hpp"
#include "CMycar.h"
#include "CSocketServer.hpp"
#include "helloworld.h"
#include <gtkmm/application.h>
#include <iostream>
#include <string>
/*
 @brief asdasd

*/
static int counter = 0;
int Car::testStatic = 123;
static void activate(GtkApplication *app, void *user_data);
void greet(GtkWidget *widget, gpointer data) {
  // printf equivalent in GTK+
  g_print("Hi there! Welcome to GTK\n");
  g_print("%s clicked %d times\n", (char *)data, ++counter);
}
void destroy(GtkWidget *widget, gpointer data) { gtk_main_quit(); }
//##############################################################################
// MAIN
//###############################################################################
int main(int argc, char *argv[]) {
  extern int myExternVar1;
  myExternVar1 = 321;
  extern int abc;
  extern int abc;
  int a = 1;
  int c = 1;

  CSocketServer serverSocket(5050);
  serverSocket.createSocket();
  serverSocket.bindServer();
  serverSocket.listenForClient();
  serverSocket.acceptClient();
  serverSocket.waitForClient();
  serverSocket.sendStringToClient("Hello World");
  serverSocket.waitForClient();
  //
  std::cout << "asdkasdkasp";
  std::cout << "CCC =2?" << ++c << ",3?" << ++c << ",3?" << c++ << ",4? " << c++
            << ",5?" << c++ << endl;
  std::cout << "Res:" << (a++) * (++a) << endl;


 CTCPClient tcpClient1("192.168.56.111", 5050);
  //
  std::cout << "\nyxxHello World:" << std::endl;
  std::cout << "CHECK:" << myExternVar1;
  Car car1;
  CBus Bus1;
  Bus1 = car1 + car1;
  car1.testStatic = 123;
  auto app = Gtk::Application::create(
      argc, argv, "org.gtkmm.example"); // creates application?
  auto app2 = Gtk::Application::create(
      argc, argv, "org.gtkmm.example"); // creates application?

  HelloWorld helloworld; // creates window?

  return app->run(helloworld);
}
