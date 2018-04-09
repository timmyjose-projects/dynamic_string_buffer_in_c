# dynamic_string_buffer_in_c

A growable (and shrinkable) string buffer implementation in C. This is meant for edificational purposes only, and is provided as is. *Caveat emptor!*


## Sample Run

bash-3.2$ !m
make clean && make && ./main
rm -rf *.o
rm -rf main
gcc -Wall -Wextra   -c -o dyn_str_buf.o dyn_str_buf.c
gcc -Wall -Wextra   -c -o error.o error.c
gcc -Wall -Wextra   -c -o main.o main.c
gcc -Wall -Wextra dyn_str_buf.o error.o main.o -o main
again we meet?
hallo welt
quit
again we meet?
hallo welt


[test_push_back]
again we meet?
hallo welt
more
stuff
even!
what!
bleh?


[test_push_front]
first
second
third
fourth
fifth
again we meet?
hallo welt
more
stuff
even!
what!
bleh?


[test_pop_back]
popped: bleh?
popped: what!
popped: even!
popped: stuff
first
second
third
fourth
fifth
again we meet?
hallo welt
more


[test_pop_front]
popped: first
popped: second
popped: third
fourth
fifth
again we meet?
hallo welt
more


test_get
element at index 0 = fourth
element at index 1 = fifth
element at index 2 = again we meet?
element at index 3 = hallo welt
element at index 4 = more

[test_remove]
removing element at index 2
fourth
fifth
hallo welt
more


removing element at index 0
fifth
hallo welt
more


removing element at index 3
remove_sb: index 3 is invalid
```
