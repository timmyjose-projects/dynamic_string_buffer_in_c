#include "error.h"


// a genetic error handler
void error(const char *fmt, ...)
{
  char err_message[BUF_SIZE];
  va_list valist;

  va_start(valist, fmt);
  vsnprintf(err_message, BUF_SIZE, fmt, valist);
  va_end(valist);

  fprintf(stderr, "%s\n", err_message);

  exit(1);
}

void mem_check(void *ptr, const char *fmt, ...)
{
  if (ptr)
    return;
    
  char err_message[BUF_SIZE];
  va_list valist;

  va_start(valist, fmt);
  vsnprintf(err_message, BUF_SIZE, fmt, valist);
  va_end(valist);

  fprintf(stderr, "%s\n", err_message);

  exit(2);
}
