
all: main

main: clear_state state_sort state_search

state_sort: state_sort.c
	gcc -Wall -Werror -Wextra $< -o ../build/Quest1

state_search: state_search.c
	gcc -Wall -Werror -Wextra $< -o ../build/Quest2

clear_state: clear_state.c
	gcc -Wall -Werror -Wextra $< -o ../build/Quest3

run1:
	../build/Quest1

run2:
	../build/Quest2

run3:
	../build/Quest3


rebuild: clean all

clean: 
	rm -rf *.o *.out ../build/*

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c

dev:
	git checkout -b develop

git:
	git add clear_state.c state_sort.c state_search.c Makefile
	git commit -m "autopush"
	git push origin develop

new:
	touch main.c

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

leak:
	leaks -atExit -- ./*.out