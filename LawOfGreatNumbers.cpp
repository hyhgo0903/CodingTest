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

    // 수학을 이용하여 풀었지만 이렇게 풀리는 경우는 적음. 한 단계 씩 진행하는게 옳을 때가 많다
    int secondBiggestUsedCount = m / (k + 1);
    int result = biggest * m - secondBiggestUsedCount * gap;

    cout << "결과: " << result << endl;
  }
};