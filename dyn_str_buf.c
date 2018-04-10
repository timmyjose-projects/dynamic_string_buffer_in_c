#include "dyn_str_buf.h"


// insert element at the back of the dynamic array, using the rule
// that if the used space becomes equal to the capacity, then
// increase the capacity of the buffer by a factor of 2.
void push_back_sb(str_buf *sb, const char *s)
{
  if (sb->len == sb->cap) {
    char **new_buf = calloc(sb->cap * 2, sizeof(char*));
    mem_check(new_buf, "unable to resize buffer in push_back_sb");

    sb->cap *= 2;

    for (size_t i = 0; i < sb->len; i++)
      new_buf[i] = sb->buf[i];

    free(sb->buf);
    sb->buf = NULL;
    sb->buf = new_buf;
  }

  size_t n = strlen(s);
  sb->buf[sb->len] = calloc(n, sizeof(char));
  mem_check(sb->buf[sb->len], "unable to allocate memory for string buffer entry in push_back_sb");

  strncpy(sb->buf[sb->len], s, n);

  sb->len++;
}


// insert element at the front of the dynamic array. In case the
// used space is equal to the capacity of the dynamic array, then
// increase the capacity by a factor of 2.
// Then shift over the elements by one position to the right, and then
// insert the element at index 0.
void push_front_sb(str_buf *sb, const char *s)
{
  if (sb->len == sb->cap) {
    char **new_buf = calloc(sb->cap * 2, sizeof(char*));
    mem_check(new_buf, "unable to resize buffer in push_front_sb");

    sb->cap *= 2;

    for (unsigned i = 0; i < sb->len; i++)
      new_buf[i] = sb->buf[i];

    free(sb->buf);
    sb->buf = NULL;
    sb->buf = new_buf;
  }

  for (size_t i = sb->len; i > 0; i--)
    sb->buf[i] = sb->buf[i-1];

  size_t n = strlen(s);
  sb->buf[0] = calloc(n, sizeof(char));
  mem_check(sb->buf[0], "unable to allocate memory for string buffer entry in push_front_sb");

  strncpy(sb->buf[0], s, n);

  sb->len++;
}


// remove and return the element from the back of the dynamic array. If
// the used space is less than half the capacity, then halve the capacity
// of the dynamic array.
char *pop_back_sb(str_buf *sb)
{
  if (!sb->len)
    error("pop_back_sb: string buffer is empty!");
  

  size_t n = strlen(sb->buf[sb->len-1]);
  char *str = calloc(n, sizeof(char));
  mem_check(str, "unable to allocate memory for string in pop_back_sb");
  
  strncpy(str, sb->buf[sb->len-1], n);

  sb->len--;

  if (sb->len < sb->cap/2) {
    char **new_buf = calloc(sb->cap/2, sizeof(char*));
    mem_check(new_buf, "unable to resize buffer in pop_back_sb");

    sb->cap /= 2;
    for (size_t i = 0; i < sb->len; i++)
      new_buf[i] = sb->buf[i];

    free(sb->buf);
    sb->buf = NULL;
    sb->buf = new_buf;
  }

  return str;
}


// remove and return the element from the front of the dynamic array. If
// the used space is less than half the capacity, then halve the capacity
// of the dynamic array.
char *pop_front_sb(str_buf *sb)
{

  if (!sb->len)
    error("pop_front_sb: string buffer is empty");

  
  size_t n = strlen(sb->buf[0]);
  char *str = calloc(n, sizeof(char));
  mem_check(str, "unable to allocate memory for string in pop_back_sb");
  
  strncpy(str, sb->buf[0], n);

  for (size_t i = 0; i < sb->len-1; i++)
    sb->buf[i] = sb->buf[i+1];
  
  sb->len--;

  if (sb->len < sb->cap/2) {
    char **new_buf = calloc(sb->cap/2, sizeof(char*));
    mem_check(new_buf, "unable to resize buffer in pop_back_sb");

    sb->cap /= 2;

    for (size_t i = 0; i < sb->len; i++)
      new_buf[i] = sb->buf[i];

    free(sb->buf);
    sb->buf = NULL;
    sb->buf = new_buf;
  }

  return str;
}


// return the element at the provided index.
char *get_sb(str_buf *sb, size_t idx)
{
  if (idx >= sb->len)
    error("get_sb: index %d is invalid", idx);

  size_t n = strlen(sb->buf[idx]);
  char *str = calloc(n, sizeof(char));
  strncpy(str, sb->buf[idx], n);

  return str;
}


// update the element at the provided index.
void set_sb(str_buf *sb, size_t idx, const char *s)
{
  if (idx >= sb->len)
    error("set_sb: index %d is invalid", idx);

  strcpy(sb->buf[idx], s);
}


// remove the element at the given index.
void remove_sb(str_buf *sb, size_t idx)
{
  if (idx >= sb->len)
    error("remove_sb: index %d is invalid", idx);

  for (size_t i = idx; i < sb->len-1; i++)
    sb->buf[i] = sb->buf[i+1];

  sb->len--;
}


// space occupied in the dynamic array
size_t used_sb(str_buf *sb)
{
  return sb->len;
}


// maximum current size of the dynamic array
size_t available_sb(str_buf *sb)
{
  return sb->cap;
}
    

// initialiser
str_buf *init_str_buf()
{
  str_buf *sb = malloc(sizeof(str_buf));

  mem_check(sb, "unable to allocate memory for string buffer");
  
  // allocate the string buffer contained with the type
  char **buf = malloc(sizeof(char*));

  mem_check(buf, "unable to allocatet memory for string buffer's buffer");

  sb->buf = buf;
  sb->len = 0;
  sb->cap = 1;

  return sb;
}


// deinitialiser
void free_str_buf(str_buf *sb)
{
  if (sb) {
    if (sb->buf) {
      for (size_t i = 0; i < sb->len; i++) {
        if (sb->buf[i]) {
          free(sb->buf[i]);
          sb->buf[i] = NULL;
        }
      }
        
      free(sb->buf);
      sb->buf = NULL;
    }

    free(sb);
    sb = NULL;
  }
}

  

  

  

