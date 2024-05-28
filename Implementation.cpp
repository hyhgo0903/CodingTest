#include "Implementation.h"

void Implementation::UDLR(int square, string commandList)
{
  auto x = 1;
  auto y = 1;

  // 책의 풀이는 파이썬 리스트. 나는 실습겸 맵을 써보자
  map<char, tuple<int, int>> commandMap
  {
    { 'L', make_tuple(-1, 0) },
    { 'R', make_tuple(1, 0) },
    { 'U', make_tuple(0, -1) },
    { 'D', make_tuple(0, 1) }
  };

  for (int index = 0; index < commandList.size(); ++index)
  {
    // 내 풀이 주석처리
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

  cout << "결과: (" << x << ',' << y << ')' << endl;
}