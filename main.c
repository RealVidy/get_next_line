#include "get_next_line.h"

int main(int argc, char const *argv[])
{
  const char c = argv[1][0];

  char *myStr = "Ah que coucou";

  const int count = ft_count(myStr, c);

  printf("The count is %d", count);
  return 0;
}
