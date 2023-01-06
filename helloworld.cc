// File: helloworld.cc

#include "helloworld.h"
#include <iostream>
#include "TCPServer.h"


TCPServer tcp;
pthread_t msg1[MAX_CLIENT];
int num_message = 0;
int time_send   = 2700;
void * send_client(void * m) {
        struct descript_socket *desc = (struct descript_socket*) m;

	while(1) {
		if(!tcp.is_online() && tcp.get_last_closed_sockets() == desc->id) {
			cerr << "Connessione chiusa: stop send_clients( id:" << desc->id << " ip:" << desc->ip << " )"<< endl;
			break;
		}
		std::time_t t = std::time(0);
		std::tm* now = std::localtime(&t);
		int hour = now->tm_hour;
		int min  = now->tm_min;
		int sec  = now->tm_sec;

		std::string date = 
			    to_string(now->tm_year + 1900) + "-" +
			    to_string(now->tm_mon + 1)     + "-" +
			    to_string(now->tm_mday)        + " " +
			    to_string(hour)                + ":" +
			    to_string(min)                 + ":" +
			    to_string(sec)                 + "\r\n";
		cerr << date << endl;
		tcp.Send(date, desc->id);
		sleep(time_send);
	}
	pthread_exit(NULL);
	return 0;
}
void * received(void * m)
{
        pthread_detach(pthread_self());
	vector<descript_socket*> desc;
	while(1)
	{
		desc = tcp.getMessage();
		for(unsigned int i = 0; i < desc.size(); i++) {
			if( desc[i] )
			{
				if(!desc[i]->enable_message_runtime) 
				{
					desc[i]->enable_message_runtime = true;
			                if( pthread_create(&msg1[num_message], NULL, send_client, (void *) desc[i]) == 0) {
						cerr << "ATTIVA THREAD INVIO MESSAGGI" << endl;
					}
					num_message++;
					// start message background thread
				}
				cout << "id:      " << desc[i]->id      << endl
				     << "ip:      " << desc[i]->ip      << endl
				     << "message: " << desc[i]->message << endl
				     << "socket:  " << desc[i]->socket  << endl
				     << "enable:  " << desc[i]->enable_message_runtime << endl;
				tcp.clean(i);
			}
		}
		usleep(1000);
	}
	return 0;
}

HelloWorld::HelloWorld()
    : m_button("press me"), m_button2("Run Bash Command"),
      m_button3(
          "Open TCP Server") // creates a new button with label "Hello World".
{
 
  m_button2 = Gtk::Button("_Something", true);
  // opens a tcp server
  m_button3 = Gtk::Button("Open TCP Server",true);
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
  m_button3.signal_clicked().connect(
      sigc::mem_fun(*this, &HelloWorld::on_button_clicked3));
  // put the box into the main window.
  add(m_box1);
  m_box1.add(m_button);
  m_box1.add(m_button2);
  m_box1.add(m_button3);
// show buttons
  m_button.show();
  m_button2.show();
  m_button3.show();
  //show the box...
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
//
void HelloWorld::on_button_clicked3() {
  int myExternVar1;
  // int myExternVar1=222;
  std::cout << "OPEN A TCP SERVER" << std::endl;
  pthread_t msg;
        vector<int> opts = { SO_REUSEPORT, SO_REUSEADDR };

	if( tcp.setup(5050 == 0)) {
		if( pthread_create(&msg, NULL, received, (void *)0) == 0)
		{
			while(1) {
				tcp.accepted();
				std::cerr << "Accepted" << std::endl;
			}
		}
	}
	else
		{std::cerr << "Errore apertura socket" << std::endl;}

  //system("nc -l 5050");
 
}