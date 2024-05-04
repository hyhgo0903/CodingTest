#include <iostream>
using namespace std;
#pragma once

class Camera
{
public:
  static Camera* getInstance();
  void capture();
private:
  Camera()  {	cout << "Created" << endl;  }

  static Camera* instance;
};