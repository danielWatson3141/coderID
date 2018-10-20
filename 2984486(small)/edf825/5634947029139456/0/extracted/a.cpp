#include <stdio.h>

char in[256][256];
char out[256][256];

int inparity[256];
int outparity[256];

int shouldflip[256];

void solve(void)
{
  int n,l;
  scanf("%d%d", &n, &l);

  for (int i = 0; i < 256; i++) {
    shouldflip[i] = inparity[i] = outparity[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    scanf("%s", in[i]);
    for (int j = 0; j < l; j++) {
      inparity[j] += in[i][j] == '1' ? 1 : 0;
    }
  }

  for (int i = 0; i < n; i++) {
    scanf("%s", out[i]);
    for (int j = 0; j < l; j++) {
      outparity[j] += out[i][j] == '1' ? 1 : 0;
    }
  }

  int flips = 0;

  // Check parities
  for (int i = 0; i < l; i++) {
    if (inparity[i] != outparity[i]) {
      if (inparity[i] == n - outparity[i]) {
        shouldflip[i] = 1;
      } else {
        goto fail;
      }
    }
  }

  // Check sanity
  for (int i = 0; i < n; i++) {
  }

  for (int i = 0; i < l; i++) {
    if (shouldflip[i]) {
      flips++;
    }
  }

  printf("%d\n", flips);
  return;
fail:
  printf("NOT POSSIBLE\n");
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    printf("Case #%d: ", i + 1);
    solve();
  }

  return 0;
}
