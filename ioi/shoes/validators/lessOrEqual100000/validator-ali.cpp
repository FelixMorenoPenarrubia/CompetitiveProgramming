//In the Name of God
//Ya Ali

#include "testlib.h"

using namespace std;

const int maxn = 100000;

int _mark[maxn * 2 + 100];
int *mark = _mark + maxn + 50;

int main()
{
  registerValidation();

  string secret = inf.readLine();
  ensuref(secret == (string)"08f55b3f-c300-4051-a472-59ca2a776178", "Secret not found!");

  int n = inf.readInt(1, maxn, "n");
  inf.readEoln();
  for (int i = 0; i < n * 2; i++)
    {
      if (i)
	inf.readSpace();
      int x = inf.readInt(-n, +n, "s_i");
      ensuref(x != 0, "zero value");
      mark[x]++;
    }

  for (int i = 0; i < n; i++)
	  ensuref(mark[i+1] == mark[-(i+1)], "the number of left and right shoes of the same type should be equal");
  inf.readEoln();
  inf.readEof();
  return 0;
}
