  #include "CMycar.h"

  int Car::getSizeInMeter(){
    return this->sizeInMeter;
  }


int Car::testMethod(int b) {
  cout << "this is a Car" << endl;
  window.areaInmeter = 123;
  return b + 1;
}

CBus operator+(Car car1, Car car2) {

  return CBus(car1.getSizeInMeter() + car2.getSizeInMeter());
}