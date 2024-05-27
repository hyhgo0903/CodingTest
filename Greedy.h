#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Changes
{
    int _number;
public:
    Changes(int number = 1260)
    {
        _number = number;
        Start();
    }

    void Start();
};

class LawOfGreatNumbers
{
    // n�� �ʿ����� �ʾ� ��������
    int _m, _k;
    vector<int>* _numList;
public:
    LawOfGreatNumbers(int m, int k, vector<int>* numList) : _m{m}, _k{k}, _numList{numList}
    {
        Start();
    }

    ~LawOfGreatNumbers()
    {
    }

    void Start();
};

class NumCard
{
  int _row, _col;
  std::unique_ptr<int[]> _intArray;

public:
  NumCard(int row, int col, int* intArray) : _row{row}, _col{col}, _intArray{ std::make_unique<int[]>(row * col) }
  {
    // intArray�� ���� �����Ͽ� ���� �迭�� �Ҵ�
    for (int i = 0; i < row * col; ++i)
    {
      _intArray[i] = intArray[i];
    }

    Start();
  }

  void Start();
};

class UntilOne
{
public:
  UntilOne(int num, int divisionValue)
  {
    auto times = 0;
    while (num > 1)
    {
      auto leftover = num % divisionValue;
      if (leftover == 0)
      {
        num /= divisionValue;
        ++times;
      }
      else
      {
        num -= leftover;
        times += leftover;
      }
    }

    cout << "���: " << times << endl;
  }
};