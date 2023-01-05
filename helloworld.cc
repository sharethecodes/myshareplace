// File: helloworld.cc

#include "helloworld.h"
#include <iostream>

HelloWorld::HelloWorld()
    : m_button("press me"),
      m_button2(
          "Run Bash Command") // creates a new button with label "Hello World".
{
  // Gtk::Button* pButton = new Gtk::Button("_Something", true);
  m_button2 = Gtk::Button("_Something", true);
  // Sets the border width of the window.
  set_border_width(200);
  set_title("My GTK+ C++ Programm!");
  // Sets the margin around the box.
  m_box1.set_margin_left(100);
  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &HelloWorld::on_button_clicked));
  m_button2.signal_clicked().connect(
      sigc::mem_fun(*this, &HelloWorld::on_button_clicked2));
  // put the box into the main window.
  add(m_box1);
  m_box1.add(m_button);
  m_box1.add(m_button2);
  

  m_button.show();
  m_button2.show();
  m_box1.show();
}

HelloWorld::~HelloWorld() {}

void HelloWorld::on_button_clicked() {
  int myExternVar1;
  // int myExternVar1=222;
  std::cout << "!Hello asdasdasdasdWorld!" << std::endl;
  std::cout << "extern:" << myExternVar1;
}
void HelloWorld::on_button_clicked2() {
  int myExternVar1;
  // int myExternVar1=222;
  std::cout << "The other button" << std::endl;
  system("echo hello world from c++ to consoel...");
   system("sudo nautilus");
}