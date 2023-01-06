
// File: main.cc

#include "CMycar.h"
#include "helloworld.h"
#include <gtkmm/application.h>
#include <iostream>
/*
 @brief asdasd

*/
static int counter = 0;
int Car::testStatic = 123;
static void activate(GtkApplication *app, void *user_data);
void greet( GtkWidget *widget, gpointer   data )
{
   // printf equivalent in GTK+
   g_print ("Hi there! Welcome to GTK\n");
   g_print ("%s clicked %d times\n",
      (char*)data, ++counter);
}
void destroy(GtkWidget *widget, gpointer data) { gtk_main_quit(); }
//##############################################################################
//MAIN
int main(int argc, char *argv[]) {
  extern int myExternVar1;
  myExternVar1 = 321;
  extern int abc;
  extern int abc;
int a=1;
int c = 1;


std::cout <<"asdkasdkasp";
std::cout<< "CCC =2?"<< ++c<<",3?"<<++c<<",3?"<<c++ <<",4? "<< c++<<",5?"<<c++<<endl;
std::cout<<"Res:"<<(a++)*(++a)<<endl;
  // myExternVar1 = 123;
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

  //                        // app2->run(helloworld);
  // //  Shows the window and returns when it is closed.
  // // extra program
  // GtkWidget *window;
  // GtkWidget *button;
  // gtk_init(&argc, &argv);
  // window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  // gtk_container_set_border_width(GTK_CONTAINER(window), 20);
  //    button = gtk_button_new_with_label ("Click Me!");
  // /* Let's set the border width of the window to 20.
  //  * You may play with the value and see the
  //  * difference. */

  // /* Let's set the border width of the window to 20.
  //  * You may play with the value and see the
  //  * difference. */
  // gtk_container_set_border_width(GTK_CONTAINER(window), 20);
  // //
  // gtk_container_add (GTK_CONTAINER (window), button);
  //   gtk_widget_show_all(window);

  //  gtk_main ();
  return app->run(helloworld);
}
