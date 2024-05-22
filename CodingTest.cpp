#include "Greedy.h"
#include "Camera.h"
using namespace std;

int main()
{
  Changes changes;

  vector<int> *numList = new vector<int>{ 2, 4, 5, 4, 6 };
  LawOfGreatNumbers gn(8, 3, numList);
  delete numList;

  int* intArray = new int[9] { 3, 1, 2, 4, 1, 4, 2, 2, 2 };
  NumCard numCard(3, 3, intArray);
}