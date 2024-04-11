#include "Changes.cpp"
#include "LawOfGreatNumbers.cpp"

int main()
{
  Changes changes = Changes();
  changes.Start(1260);

  LawOfGreatNumbers lawOfGreatNumbers = LawOfGreatNumbers();
  lawOfGreatNumbers.Start(8, 3, vector<int> { 2, 4, 5, 4, 6 });
}