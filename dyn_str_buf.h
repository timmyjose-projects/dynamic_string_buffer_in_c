#ifndef DYN_STR_BUF_H
#define DYN_STR_BUF_H

#ifdef __cplusplus
extern "C" {
#endif

  #include <stdlib.h>
  #include <string.h>
  #include "error.h"
  
  // the dynamically growing string buffer
  typedef struct str_buf {
    char **buf;

    size_t len;
    size_t cap;
  } str_buf;


  // insert at the end
  void push_back_sb(str_buf*, const char*);

  // insert at the front
  void push_front_sb(str_buf*, const char*);

  // remove fron the end
  char *pop_back_sb(str_buf*);

  // remove from the front
  char *pop_front_sb(str_buf*);

  // retrieve element at index
  char *get_sb(str_buf*, size_t);

  // update the element at index
  void set_sb(str_buf*, size_t, const char*);

  // used space
  size_t used_sb(str_buf *);

  // available space
  size_t available_sb(str_buf*);
  
  // delete entry at index
  void remove_sb(str_buf*, size_t);
  
  // initialiser 
  str_buf *init_str_buf();

  // de-initialiser
  void free_str_buf(str_buf*);


#ifdef __cplusplus
}
#endif
#endif
  
