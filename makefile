#build executable
all: main.cpp
	g++ main.cpp helloworld.cc -o example `pkg-config --cflags gtkmm-3.0 --libs gtk+-3.0`
clean:
	$(RM) example

