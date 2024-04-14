#include <algorithm>
#include <iostream>
#include <vector>

#include "Greedy.h"

using namespace std;

// ū �������� �����ϴ� ��Ģ. �׸����� ��ǥ ����

// �� ������ ��� ū ������ �׻� ���� ������ ����̹Ƿ� ���� ������ ������ ������ �ٸ� �ذ� ���� �� ���� ������ �� ��Ģ�� �����ϴ�.
// ��ó�� ���̵� �������� Ȯ���� �ʿ䰡 �ִ�.

void Changes::Start(int amount)
{
    amount = amount - amount % 10;

    // ����� �����ص� ����� �������.
    cout << "������ �Է°�: " << amount << endl;

    int wonArray[4] = { 500, 100, 50, 10 };
    int countArray[4];

    for (int i = 0; i < 4; ++i)
    {
        countArray[i] = amount / wonArray[i];
        amount %= wonArray[i];
    }

    cout << "500��: " << countArray[0] << endl;
    cout << "100��: " << countArray[1] << endl;
    cout << "50��: " << countArray[2] << endl;
    cout << "10��: " << countArray[3] << endl << endl;
}

// N ��°���� �� ��° ū ���� ����ϴ� ���

void LawOfGreatNumbers::Start(int m, int k, vector<int> intVector)
{
    auto size = intVector.size();
    sort(intVector.begin(), intVector.end());
    int biggest = intVector[size - 1];
    int secondBiggest = intVector[size - 2];
    int gap = biggest - secondBiggest;

    // ������ �̿��Ͽ� Ǯ������ �̷��� Ǯ���� ���� ����. �� �ܰ� �� �����ϴ°� ���� ���� ����
    int secondBiggestUsedCount = m / (k + 1);
    int result = biggest * m - secondBiggestUsedCount * gap;

    cout << "���: " << result << endl;
}