#include "Greedy.h"
using namespace std;

// 큰 단위부터 수행하는 규칙. 그리디의 대표 예시

// 이 문제의 경우 큰 단위가 항상 작은 단위의 배수이므로 작은 단위의 동전을 종합해 다른 해가 나올 수 없기 때문에 이 규칙은 정당하다.
// 이처럼 아이디어가 정당한지 확인할 필요가 있다.

void Changes::Start()
{
    auto amount = _number - _number % 10;

    // 사실은 생략해도 결과에 지장없다.
    cout << "보정된 입력값: " << amount << "원. ";

    int wonArray[4] = { 500, 100, 50, 10 };
    int countArray[4];

    for (int i = 0; i < 4; ++i)
    {
        countArray[i] = amount / wonArray[i];
        amount %= wonArray[i];
    }

    cout << "결과 : 500원x" << countArray[0] << "/100원x" << countArray[1] << "/50원x" << countArray[2] << "/10원x" << countArray[3] << endl;
}

// N 번째마다 두 번째 큰 수를 사용하는 방식

void LawOfGreatNumbers::Start()
{
    auto size = _numList->size();
    sort(_numList->begin(), _numList->end());
    int biggest = _numList->at(size - 1);
    int secondBiggest = _numList->at(size - 2);
    int gap = biggest - secondBiggest;

    // 수학을 이용하여 풀었지만 이렇게 풀리는 경우는 적음. 한 단계 씩 진행하는게 옳을 때가 많다
    int secondBiggestUsedCount = _m / (_k + 1);
    int result = biggest * _m - secondBiggestUsedCount * gap;

    cout << "결과: " << result << endl;
}

void NumCard::Start()
{
  auto min = -1;
  for (int i = 0; i < _row; ++i)
  {
    int* tempArray = new int[_col];
    for (int j = 0; j < _col; ++j)
    {
      tempArray[j] = _intArray[i * _col + j];
    }

    // 당연히 기본값은 오름차순이지만 람다함수 연습을 위해
    sort(
      tempArray,
      tempArray + _col,
      [](const int& lh, const int& rh) { return lh < rh; });
    if (min < tempArray[0])
    {
      min = tempArray[0];
    }
    
    delete[] tempArray;
  }

  cout << "결과: " << min << endl;
}