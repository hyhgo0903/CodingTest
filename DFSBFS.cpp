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

void DFSBFS::Maze(int col, int row, int arr[])
{
  auto count = 1;

  int** mapArray = new int* [col];
  for (int i = 0; i < col; ++i)
  {
    mapArray[i] = new int[row];
    for (int j = 0; j < row; ++j)
    {
      mapArray[i][j] = arr[j * col + i];
    }
  }

  cout << "결과: " << count << endl;
}

void dfs(int x, int y, int col, int row, int arr[])
{

}