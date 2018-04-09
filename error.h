#ifndef ERROR_H
#define ERROR_H

#ifdef __cplusplus
extern "C" {
#endif

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdarg.h>
  
  static int BUF_SIZE = 1024;
  
  // a genetic error handler
  void error(const char *, ...);

  void mem_check(void *, const char *, ...);
    
  
#ifdef __cplusplus
}
#endif
#endif
