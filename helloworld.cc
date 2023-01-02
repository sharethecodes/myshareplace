// File: helloworld.cc

#include "helloworld.h"
#include <iostream>

HelloWorld::HelloWorld()
    : m_button("press me") // creates a new button with label "Hello World".
{
Gtk::Button* pButton = new Gtk::Button("_Something", true);
  // Sets the border width of the window.
 set_border_width(100);
 set_title("My Program");
  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  m_button.signal_clicked().connect(
      sigc::mem_fun(*this, &HelloWorld::on_button_clicked));

  // This packs the button into the Window (a container).
  add(m_button);
  add(m_button2);

  // The final step is to display this newly created widget...
  m_button.show();
  m_button2.show();
}

HelloWorld::~HelloWorld() {}

void HelloWorld::on_button_clicked() {
  int myExternVar1;
  //int myExternVar1=222;
  std::cout << "!Hello asdasdasdasdWorld!" << std::endl;
  std::cout << "extern:"<<myExternVar1;
}
