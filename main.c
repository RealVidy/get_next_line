#include "get_next_line.h"

void test_count()
{
  char *myStr = "Ah que coucou";
  char *nullStr = NULL;

  assert(ft_count(myStr, 'z') == 0);
  assert(ft_count(myStr, '\0') == 13);
  assert(ft_count(myStr, 'h') == 1);
  assert(ft_count(myStr, ' ') == 2);
  assert(ft_count(NULL, 'h') == 0);
  assert(ft_count(nullStr, 'h') == 0);
}

void test_strjoin()
{
  char *s1 = "one";
  char *s2 = "two";
  char *nullS = NULL;

  assert(strcmp(ft_strjoin(s1, s2), "onetwo") == 0);
  assert(strcmp(ft_strjoin(NULL, s2), "two") == 0);
  // segfault here
  // assert(strcmp(ft_strjoin(s1, NULL), "one") == 0);
  assert(ft_strjoin(NULL, NULL) == NULL);
}

int main(int argc, char const *argv[])
{
  test_count();
  test_strjoin();

  return 0;
}
