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

    // ������ �̿��Ͽ� Ǯ������ �̷��� Ǯ���� ���� ����. �� �ܰ� �� �����ϴ°� ���� ���� ����
    int secondBiggestUsedCount = m / (k + 1);
    int result = biggest * m - secondBiggestUsedCount * gap;

    cout << "���: " << result << endl;
  }
};