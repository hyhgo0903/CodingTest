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


void Implementation::TimeInclude3(int number)
{
  if (number >= 24)
  {
    number = 23;
  }

  auto count = 0;
  // �ܼ��� ����� �� �����̹Ƿ� �������� Ǯ����� �屸�� �����
  for (int i = 0; i <= number; ++i)
  {
    if (i == 3 || i == 13 || i == 23)
    {
      count += 60 * 60;
      continue;
    }

    // n(A U B) = n(A) + n(B) - n(A n B) ����� ���ϻ����ϴ�
    // �� 60���� : x3 �� ��� 6���� 3x �� ��� 10���� 33�� ��� 1���� => 6 + 10 - 1 = 15
    // 15 * 60 + 15 * 60 - 225 = 1575
    count += 1575;
  }

  // å Ǯ�̴�� ���ڿ� �Ľ����� Ǫ�� ���
  auto count2 = 0;
  auto func = [](string& str)
  {
    for (char& a : str)
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

  if (count == count2) cout << "���: " << count << endl;
  else cout << "����: ī��Ʈ�� ����ġ�մϴ�. - " << count << "!=" << count2 << endl;
}

void Implementation::ChessKnight(string str)
{
  if (str.length() != 2)
    return;
  const int chessSize = 8;

  const int x = (str[0] - 'a');
  const int y = (str[1] - '1');

  if (x < 0 || y < 0 || x >= chessSize || y >= chessSize)
    return;

  auto count = 0;
  const tuple<int, int> commandArray[8]
  {
    make_tuple(-2, -1), make_tuple(-2, 1), make_tuple(-1, -2), make_tuple(-1, 2),
    make_tuple(1, -2), make_tuple(1, 2), make_tuple(2, -1), make_tuple(2, 1)
  };

  for (auto& tuple : commandArray)
  {
    auto simulatedX = x + get<0>(tuple);
    auto simulatedY = y + get<1>(tuple);
    if (simulatedX < 0 || simulatedY < 0 || simulatedX >= chessSize || simulatedY >= chessSize)
      continue;
    ++count;
  }

  cout << "���: " << count << endl;
}

void Implementation::Map(int x, int y, int startX, int startY, int startDir, int number[])
{
  auto visited = 1;
  auto currentDir = startDir;
  auto currentX = startX;
  auto currentY = startY;
  const tuple<int, int> dirArray[4] { make_tuple(0, -1), make_tuple(1, 0), make_tuple(0, 1), make_tuple(-1, 0) };

  int** mapArray = new int*[x];
  for (int i = 0; i < x; ++i)
  {
    mapArray[i] = new int[y];
    for (int j = 0; j < y; ++j)
    {
      mapArray[i][j] = number[j * x + i];
    }
  }

  mapArray[currentX][currentY] = 2;

  while (true)
  {
    // simulate
    auto found = false;
    for (int i = 0; i < 4; ++i)
    {
      --currentDir;
      if (currentDir < 0)
      {
        currentDir = 3;
      }

      auto simulatedX = currentX + get<0>(dirArray[currentDir]);
      auto simulatedY = currentY + get<1>(dirArray[currentDir]);

      if (simulatedX < 0 || simulatedX > x || simulatedY < 0 || simulatedY > y)
      {
        continue;
      }

      if (mapArray[simulatedX][simulatedY] == 0)
      {
        found = true;
        mapArray[simulatedX][simulatedY] = 2;
        currentX = simulatedX;
        currentY = simulatedY;
        break;
      }
    }

    if (found)
    {
      ++visited;
      continue;
    }

    auto backward = (currentDir + 2) % 4;
    auto simulatedX = currentX + get<0>(dirArray[backward]);
    auto simulatedY = currentY + get<1>(dirArray[backward]);

    if (simulatedX < 0 || simulatedX > x || simulatedY < 0 || simulatedY > y)
    {
      break;
    }

    if (mapArray[simulatedX][simulatedY] == 1)
    {
      break;
    }
    else
    {
      ++visited;
      mapArray[simulatedX][simulatedY] = 2;
      currentX = simulatedX;
      currentY = simulatedY;
    }
  }

  cout << "���: " << visited << endl;
}