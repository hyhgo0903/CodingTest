#include <iostream>
using namespace std;

// ��Ʈ : ū �������� �����ϴ� ��Ģ. �׸����� ��ǥ ����

class Changes
{
public:
  void Start(int amount)
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
};