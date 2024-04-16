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
        delete _numList;
    }

    void Start();
};