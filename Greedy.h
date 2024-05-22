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
    // n은 필요하지 않아 생략했음
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
    // intArray의 값을 복사하여 동적 배열로 할당
    for (int i = 0; i < _n; ++i)
    {
      _intArray[i] = intArray[i];
    }
  }

  void Start();
};