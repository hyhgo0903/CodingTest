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
  int _n, _m;
  std::unique_ptr<int[]> _intArray;

public:
  NumCard(int n, int m, int* intArray) : _n{n}, _m{m}, _intArray{ std::make_unique<int[]>(n*m) }
  {
    // intArray�� ���� �����Ͽ� ���� �迭�� �Ҵ�
    for (int i = 0; i < _n; ++i)
    {
      _intArray[i] = intArray[i];
    }
  }

  void Start();
};