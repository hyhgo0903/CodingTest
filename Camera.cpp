#include "Camera.h"
using namespace std;

Camera* Camera::getInstance()
{
  if (!instance)
  {
	instance = new Camera();
  }
  else
  {
	cout << "Return created." << endl;
  }

  return instance;
}

void Camera::capture()
{
  cout << "Capture" << endl;
}

Camera* Camera::instance = nullptr;