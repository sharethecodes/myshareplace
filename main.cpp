
// File: main.cc

#include <gtkmm/application.h>
#include <iostream>
#include "helloworld.h"
/*
 @brief asdasd

*/
int main (int argc, char *argv[])
{
  std::cout<<"\nHello World:"<<std::endl;

  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example"); // creates application?
   auto app2 = Gtk::Application::create(argc, argv, "org.gtkmm.example"); // creates application?

  HelloWorld helloworld; // creates window?

  //Shows the window and returns when it is closed.
  return app->run(helloworld); 
}
