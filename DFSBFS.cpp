#include "DFSBFS.h"

void DFSBFS::ZeroSpace(int x, int y, int arr[])
{
  auto count = 1;

  int** mapArray = new int* [x];
  for (int i = 0; i < x; ++i)
  {
    mapArray[i] = new int[y];
    for (int j = 0; j < y; ++j)
    {
      mapArray[i][j] = arr[j * x + i];
    }
  }

  cout << "결과: " << count << endl;
}

void DFSBFS::Maze(int x, int y, int arr[])
{
  auto count = 1;

  int** mapArray = new int* [x];
  for (int i = 0; i < x; ++i)
  {
    mapArray[i] = new int[y];
    for (int j = 0; j < y; ++j)
    {
      mapArray[i][j] = arr[j * x + i];
    }
  }

  // 일단 내 식대로 (한번씩 다 돌면 될 듯)

  cout << "결과: " << count << endl;
}