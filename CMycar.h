#include <iostream>
#include <string.h>
using namespace std;
/**
 * @brief Brief description
 * @param maxSpeed containst the speed
 * @param color contains the color
 *
 */

class CWheel {
public:
  std::string typeName;

protected:
private:
};
/**
 * @brief This is a class which describes a Window of a car
 * @page www.google.de
 */
class CWindow {
public:
  int areaInmeter;
};
/**
 * @brief This is a class which describes a car
 * @param testStatic just a test
 * @param color color of the car
 * @page www.google.de
 */
class Car {
public:
  static int testStatic;
  int maxSpeed;
  int color;
  CWindow window;
  int sizeInMeter=22;
  //--------
  static int testMethodStatic(int a) { return 123; };
  int testMethod(int b);
  int getSizeInMeter();
  int extraFileWhy();
protected:
private:
  float kilometers;
};



/**
 * @brief Brief description
 * @param maxSpeed containst the speed
 * @param color contains the color
 *
 */
class CBus {
public:
  int sizeInMeter;
  CBus(){};
  CBus(int sizeInMeter) {
    this->sizeInMeter = sizeInMeter;
    cout << "\n Bus created!";
    cout << " \n size of = " << this->sizeInMeter << " m " << endl;
  };
};
/** @brief this will overload the + function for adding 2 cars
 * @brief it will create a bus
 */
// operation overloading:
//

// int Car::extraFileWhy (){
//   return 1;
// }
CBus operator+(Car car1, Car car2);