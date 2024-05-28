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


void Implementation::TimeInclude3(int number)
{
  if (number >= 24)
  {
    number = 23;
  }

  auto count = 0;
  // 단순한 경우의 수 문제이므로 수학으로 풀고싶은 욕구가 생긴다
  for (int i = 0; i <= number; ++i)
  {
    if (i == 3 || i == 13 || i == 23)
    {
      count += 60 * 60;
      continue;
    }

    // n(A U B) = n(A) + n(B) - n(A n B) 기억이 새록새록하다
    // 총 60가지 : x3 인 경우 6가지 3x 인 경우 10가지 33인 경우 1가지 => 6 + 10 - 1 = 15
    // 15 * 60 + 15 * 60 - 225 = 1575
    count += 1575;
  }

  // 책 풀이대로 문자열 파싱으로 푸는 경우
  auto count2 = 0;
  auto func = [](string& str)
  {
    for (char a : str)
    {  
      if (a == '3') return true;
    }

    return false;
  };

  for (int i = 0; i <= number; ++i)
  {
    auto string = to_string(i);
    if (func(string))
    {
      count2 += 3600;
      continue;
    }

    for (int j = 0; j < 60; ++j)
    {
      string = to_string(j);
      if (func(string))
      {
        count2 += 60;
        continue;
      }

      for (int k = 0; k < 60; ++k)
      {
        string = to_string(k);
        if (func(string))
        {
          ++count2;
        }
      }
    }
  }

  if (count == count2) cout << "결과: " << count << endl;
  else cout << "실패: 카운트가 불일치합니다. - " << count << "!=" << count2 << endl;
}