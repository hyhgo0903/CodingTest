﻿#include "Greedy.h"
#include "Camera.h"
#include "Implementation.h"
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

  s1->see<>(3.14);
  delete numList;
  int* intArray = new int[12] { 7, 3, 1, 8, 3, 3, 3, 4, 4, 4, 4, 2 };
  NumCard numCard(3, 4, intArray);
  delete[] intArray;
  UntilOne untilOne(17, 4);
  
  Implementation implementation;
  implementation.UDLR(5, "RRRUDD");
  implementation.TimeInclude3(5);
  implementation.ChessKnight("f2");
  implementation.Map(4, 5, 1, 1, 0, new int[20] { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1});
}