#include <algorithm>
#include <iostream>
#include <vector>

#include "Greedy.h"

using namespace std;

// 큰 단위부터 수행하는 규칙. 그리디의 대표 예시

// 이 문제의 경우 큰 단위가 항상 작은 단위의 배수이므로 작은 단위의 동전을 종합해 다른 해가 나올 수 없기 때문에 이 규칙은 정당하다.
// 이처럼 아이디어가 정당한지 확인할 필요가 있다.

void Changes::Start(int amount)
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

// N 번째마다 두 번째 큰 수를 사용하는 방식

void LawOfGreatNumbers::Start(int m, int k, vector<int> intVector)
{
    auto size = intVector.size();
    sort(intVector.begin(), intVector.end());
    int biggest = intVector[size - 1];
    int secondBiggest = intVector[size - 2];
    int gap = biggest - secondBiggest;

    // 수학을 이용하여 풀었지만 이렇게 풀리는 경우는 적음. 한 단계 씩 진행하는게 옳을 때가 많다
    int secondBiggestUsedCount = m / (k + 1);
    int result = biggest * m - secondBiggestUsedCount * gap;

    cout << "결과: " << result << endl;
}