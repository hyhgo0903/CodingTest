#include <iostream>
using namespace std;

// 힌트 : 큰 단위부터 수행하는 규칙. 그리디의 대표 예시

class Changes
{
public:
  void Start(int amount)
  {
    amount = amount - amount % 10;

    // 사실은 생략해도 결과에 지장없다.
    cout << "보정된 입력값: " << amount << endl;

    int wonArray[4] = { 500, 100, 50, 10 };
    int countArray[4];

    for (int i = 0; i < 4; ++i)
    {
      countArray[i] = amount / wonArray[i];
      amount %= wonArray[i];
    }

    cout << "500원: " << countArray[0] << endl;
    cout << "100원: " << countArray[1] << endl;
    cout << "50원: " << countArray[2] << endl;
    cout << "10원: " << countArray[3] << endl << endl;
  }
};