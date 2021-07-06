#include "get_next_line.h"

void test_count()
{
  char *myStr = "Ah que coucou";

  assert(ft_count(myStr, 'z') == 0);
  assert(ft_count(myStr, '\0') == 13);
  assert(ft_count(myStr, 'h') == 1);
  assert(ft_count(myStr, ' ') == 2);
  assert(ft_count(NULL, 'h') == 0);
}

void test_strjoin()
{
  char *s1 = "one";
  char *s2 = "two";

  assert(strcmp(ft_strjoin(s1, s2), "onetwo") == 0);
  assert(strcmp(ft_strjoin(NULL, s2), "two") == 0);
  // segfault here
  // assert(strcmp(ft_strjoin(s1, NULL), "one") == 0);
  assert(ft_strjoin(NULL, NULL) == NULL);
}

void test_substr()
{
  char *s1 = "one two three four";

  assert(strcmp(ft_substr(s1, 0, 50), s1) == 0);
  assert(strcmp(ft_substr(s1, 2, 5), "e two") == 0);
  assert(strcmp(ft_substr(s1, 2, 50), "e two three four") == 0);
  assert(strcmp(ft_substr(s1, 2, -1), "e two three four") == 0);
  assert(strcmp(ft_substr(s1, 2, 0), "") == 0);
  assert(strcmp(ft_substr(s1, 30, 10), "") == 0);
  assert(strcmp(ft_substr(s1, -1, 10), "") == 0);
  assert(ft_substr(NULL, 2, 0) == NULL);
}

int main(int argc, char const *argv[])
{
  // test_count();
  // test_strjoin();
  test_substr();

  return 0;
}
