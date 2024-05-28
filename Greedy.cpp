#include "Greedy.h"
using namespace std;

// ū �������� �����ϴ� ��Ģ. �׸����� ��ǥ ����

// �� ������ ��� ū ������ �׻� ���� ������ ����̹Ƿ� ���� ������ ������ ������ �ٸ� �ذ� ���� �� ���� ������ �� ��Ģ�� �����ϴ�.
// ��ó�� ���̵� �������� Ȯ���� �ʿ䰡 �ִ�.

void Changes::Start()
{
    auto amount = _number - _number % 10;

    // ����� �����ص� ����� �������.
    cout << "������ �Է°�: " << amount << "��. ";

    int wonArray[4] = { 500, 100, 50, 10 };
    int countArray[4];

    for (int i = 0; i < 4; ++i)
    {
        countArray[i] = amount / wonArray[i];
        amount %= wonArray[i];
    }

    cout << "��� : 500��x" << countArray[0] << "/100��x" << countArray[1] << "/50��x" << countArray[2] << "/10��x" << countArray[3] << endl;
}

// N ��°���� �� ��° ū ���� ����ϴ� ���

void LawOfGreatNumbers::Start()
{
    auto size = _numList->size();
    sort(_numList->begin(), _numList->end());
    int biggest = _numList->at(size - 1);
    int secondBiggest = _numList->at(size - 2);
    int gap = biggest - secondBiggest;

    // ������ �̿��Ͽ� Ǯ������ �̷��� Ǯ���� ���� ����. �� �ܰ� �� �����ϴ°� ���� ���� ����
    int secondBiggestUsedCount = _m / (_k + 1);
    int result = biggest * _m - secondBiggestUsedCount * gap;

    cout << "���: " << result << endl;
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

    // �翬�� �⺻���� �������������� �����Լ� ������ ����
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

  cout << "���: " << min << endl;
}