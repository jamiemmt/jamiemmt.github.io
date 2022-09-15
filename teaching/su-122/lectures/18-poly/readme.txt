For compilation with debugging (like cc0 -d) use:

% gcc -Wall -Wextra -std=c99 -pedantic -Werror -g -DDEBUG xalloc.c stacks.c stacks-test.c

For compilation without debugging (like cc0) use:

% gcc -Wall -Wextra -std=c99 -pedantic -Werror -g xalloc.c stacks.c stacks-test.c

To run executable in the standard way:

% ./a.out

To perform memory checks and get a report on memory safety and leaks:

% valgrind ./a.out
