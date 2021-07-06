#include "get_next_line.h"

int main(int argc, char const *argv[])
{
  char *myStr = "Ah que coucou";
  char *nullStr = NULL;

  assert(ft_count(myStr, 'z') == 0);
  assert(ft_count(myStr, '\0') == 13);
  assert(ft_count(myStr, 'h') == 1);
  assert(ft_count(myStr, ' ') == 2);
  assert(ft_count(NULL, 'h') == 0);
  assert(ft_count(nullStr, 'h') == 0);

  return 0;
}
