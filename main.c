#include "dyn_str_buf.h"


const int MAX = 1024;


void display(str_buf *sb)
{
  for (size_t i = 0; i < sb->len; i++) {
    char *s = get_sb(sb, i);
    printf("%s\n", s);
    free(s);
  }

  puts("");
}


void test_push_back(str_buf *sb)
{
  printf("\n[test_push_back]\n");
  
  push_back_sb(sb, "more");
  push_back_sb(sb, "stuff");
  push_back_sb(sb, "even!");
  push_back_sb(sb, "what!");
  push_back_sb(sb, "bleh?");

  display(sb);
}

void test_push_front(str_buf *sb)
{
  printf("\n[test_push_front]\n");

  push_front_sb(sb, "fifth");
  push_front_sb(sb, "fourth");
  push_front_sb(sb, "third");
  push_front_sb(sb, "second");
  push_front_sb(sb, "first");

  display(sb);

}

void test_pop_back(str_buf *sb)
{

  printf("\n[test_pop_back]\n");

  printf("popped: %s\n", pop_back_sb(sb));
  printf("popped: %s\n", pop_back_sb(sb));
  printf("popped: %s\n", pop_back_sb(sb));
  printf("popped: %s\n", pop_back_sb(sb));

  display(sb);
}

void test_pop_front(str_buf *sb)
{
  printf("\n[test_pop_front]\n");

  printf("popped: %s\n", pop_front_sb(sb));
  printf("popped: %s\n", pop_front_sb(sb));
  printf("popped: %s\n", pop_front_sb(sb));

  display(sb);
}

void test_get(str_buf *sb)
{
  printf("\ntest_get\n");

  for (size_t i = 0; i < sb->len; i++) {
    char *str = get_sb(sb, i);
    printf("element at index %lu = %s\n", i, str);
    free(str);
  }
}

void test_remove(str_buf *sb)
{
  printf("\n[test_remove]\n");

  printf("removing element at index %d\n", 2);
  remove_sb(sb, 2);
  display(sb);
  
  printf("\nremoving element at index %d\n", 0);
  remove_sb(sb, 0);
  display(sb);
  
  printf("\nremoving element at index %d\n", 3);
  remove_sb(sb, 3);
  display(sb);
}


int main()
{
  str_buf *sb = init_str_buf();

  char s[BUF_SIZE];
  
  while (1) {
    scanf("%[^\n]%*c", s);

    if (!strcmp(s, "quit"))
      break;

    push_back_sb(sb, s);
  }

  display(sb);
  
  test_push_back(sb);
  test_push_front(sb);
  test_pop_back(sb);
  test_pop_front(sb);
  test_get(sb);
  test_remove(sb);

  free_str_buf(sb);
  
  return 0;
}
  
           
         
