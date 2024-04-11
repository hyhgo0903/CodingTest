#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// N ��°���� �� ��° ū ���� ����ϴ� ���
// ���� ����

class LawOfGreatNumbers
{
public:
  // n�� �ʿ����� �ʾ� ��������
  void Start(int m, int k, vector<int> intVector)
  {
    int size = intVector.size();
    sort(intVector.begin(), intVector.end());
    int biggest = intVector[size - 1];
    int secondBiggest = intVector[size - 2];
    int gap = biggest - secondBiggest;
    int result = biggest * m - gap * m / (k + 1);

    cout << "���: " << result << endl;
  }
};