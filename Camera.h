#include <iostream>
using namespace std;
#pragma once

class Camera
{
public:
  static Camera* getInstance();
  void capture();

  template <typename T = int>
  void see(T a)
  {
	cout << a << endl;
  }
private:
  Camera()  {	cout << "Created" << endl;  }

  static Camera* instance;
};