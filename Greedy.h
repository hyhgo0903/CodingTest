#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Changes
{
    int _number;
public:
    Changes(int number)
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
    vector<int> _numList;
public:
    LawOfGreatNumbers(int m, int k, vector<int> numList)
    {
        _m = m;
        _k = k;
        _numList = numList;
        Start();
    }

    void Start();
};