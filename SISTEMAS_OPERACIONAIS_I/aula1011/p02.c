#include <stdio.h>

int main() {
  int n;

  while (scanf("%d", &n) == 1)
    printf("%02X\n", n);

  return 0;
}