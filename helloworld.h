// File: helloworld.h

#ifndef GTKMM_EXAMPLE_HELLOWORLD_H
#define GTKMM_EXAMPLE_HELLOWORLD_H
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>
/**
 * @brief Brief description of Class HelloWorld
 * @param m_button is a Button from Class Button...
 * @authors ak23
 * @warning you have to add widgets to the window?
 * @var ? 
 * 
 */
class HelloWorld : public Gtk::Window
{

public:
  HelloWorld();
  virtual ~HelloWorld();

protected:
  //Signal handlers:
  void on_button_clicked();
  void on_button_clicked2();
  void on_button_clicked3();
  //Member widgets:
  Gtk::Box m_box1;
  //
  Gtk::Button m_button;
  Gtk::Button m_button2;
  Gtk::Button m_button3;
};
#endif