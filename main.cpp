
// File: main.cc

#include "helloworld.h"
#include <gtkmm/application.h>
#include <iostream>
/*
 @brief asdasd

*/
int main(int argc, char *argv[]) {
   extern int myExternVar1;
   myExternVar1=321;
  //myExternVar1 = 123;
  std::cout << "\nHello World:" << std::endl;
  std::cout <<"CHECK:"<< myExternVar1;

  auto app = Gtk::Application::create(
      argc, argv, "org.gtkmm.example"); // creates application?
  auto app2 = Gtk::Application::create(
      argc, argv, "org.gtkmm.example"); // creates application?

  HelloWorld helloworld; // creates window?
  app2->run(helloworld);
  // Shows the window and returns when it is closed.
  return app->run(helloworld);
}
