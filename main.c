#include "get_next_line.h"

void test_find()
{
  char *myStr = "Ah que coucou";

  assert(ft_find(myStr, 'z') == 0);
  assert(ft_find(myStr, '\0') == 13);
  assert(ft_find(myStr, 'h') == 1);
  assert(ft_find(myStr, ' ') == 2);
  assert(ft_find(NULL, 'h') == 0);
}

void test_strjoin()
{
  char *s1 = "one";
  char *s2 = "two";

  assert(strcmp(ft_strjoin(s1, s2), "onetwo") == 0);
  assert(strcmp(ft_strjoin(NULL, s2), "two") == 0);
  assert(strcmp(ft_strjoin(s1, NULL), "one") == 0);
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

void assert_next_line(int fd, char *line, int expected_result, char *expected_line)
{
  int result = get_next_line(fd, &line);
  // printf("Line: %s\n", line);
  // printf("Expected line: %s\n", expected_line);
  assert(result == expected_result);
  if (expected_line)
    assert(strcmp(line, expected_line) == 0);
}

void test_get_next_line()
{
  char *line = NULL;
  int fd;
  fd = open("fichiertxt", O_RDONLY);

  assert_next_line(fd, line, 1, "Coucou");
  assert_next_line(fd, line, 1, "C'est");
  assert_next_line(fd, line, 1, "nous");
  assert_next_line(fd, line, 1, "");
  assert_next_line(fd, line, 1, "Oui");
  assert_next_line(fd, line, 1, "Oui");
  assert_next_line(fd, line, 1, "");
  assert_next_line(fd, line, 1, "");
  assert_next_line(fd, line, 0, "0");
  assert_next_line(fd, line, 0, "");

  fd = open("fichiertxtnope", O_RDONLY);

  assert_next_line(fd, line, -1, NULL);
}

int main(int argc, char const *argv[])
{
  // test_find();
  // test_strjoin();
  // test_substr();
  test_get_next_line();

  return 0;
}
