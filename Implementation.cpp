#include "Implementation.h"

void Implementation::UDLR(int square, string commandList)
{
  auto x = 1;
  auto y = 1;

  // å�� Ǯ�̴� ���̽� ����Ʈ. ���� �ǽ��� ���� �Ẹ��
  map<char, tuple<int, int>> commandMap
  {
    { 'L', make_tuple(-1, 0) },
    { 'R', make_tuple(1, 0) },
    { 'U', make_tuple(0, -1) },
    { 'D', make_tuple(0, 1) }
  };

  for (int index = 0; index < commandList.size(); ++index)
  {
    // �� Ǯ�� �ּ�ó��
    /*
    switch (commandList[index])
    {
    case 'L':
      if (x > 1) x -= 1;
      break;
    case 'R':
      if (x < square) x += 1;
      break;
    case 'U':
      if (y > 1) y -= 1;
      break;
    case 'D':
      if (y < square) y += 1;
      break;
    default:
      cout << "Bad Request: " << commandList[index] << endl;
    }
    */

    auto iter = commandMap.find(commandList[index]);
    if (iter == commandMap.end())
    {
      cout << "Bad Request: " << commandList[index] << endl;
    }
    else
    {
      auto simulatedX = x + get<0>(iter->second);
      auto simulatedY = y + get<1>(iter->second);
      if (simulatedX <= 0
        || simulatedX > square
        || simulatedY <= 0
        || simulatedY > square)
      {
        continue;
      }

      // commit
      x = simulatedX;
      y = simulatedY;
    }
  }

  cout << "���: (" << x << ',' << y << ')' << endl;
}