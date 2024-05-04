#include "Greedy.h"
#include "Camera.h"
using namespace std;

int main()
{
  Changes changes;
  vector<int> *numList = new vector<int>{ 2, 4, 5, 4, 6 };
  LawOfGreatNumbers gn(8, 3, numList);

  Camera* s1 = Camera::getInstance();
  Camera* s2 = Camera::getInstance();
  s1->capture();
  s2->capture();
}