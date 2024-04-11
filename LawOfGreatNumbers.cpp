#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// N 번째마다 두 번째 큰 수를 사용하는 방식
// 문법 개선

class LawOfGreatNumbers
{
public:
  // n은 필요하지 않아 생략했음
  void Start(int m, int k, vector<int> intVector)
  {
    int size = intVector.size();
    sort(intVector.begin(), intVector.end());
    int biggest = intVector[size - 1];
    int secondBiggest = intVector[size - 2];
    int gap = biggest - secondBiggest;
    int result = biggest * m - gap * m / (k + 1);

    cout << "결과: " << result << endl;
  }
};