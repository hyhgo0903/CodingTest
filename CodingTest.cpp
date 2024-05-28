#include "Greedy.h"
#include "Camera.h"
#include "Implementation.h"
using namespace std;

int main()
{
  Changes changes;
  vector<int> *numList = new vector<int>{ 2, 4, 5, 4, 6 };
  LawOfGreatNumbers gn(8, 3, numList);
  delete numList;
  int* intArray = new int[12] { 7, 3, 1, 8, 3, 3, 3, 4, 4, 4, 4, 2 };
  NumCard numCard(3, 4, intArray);
  delete[] intArray;
  UntilOne untilOne(17, 4);
  
  Implementation implementation;
  implementation.UDLR(5, "RRRUDD");
}