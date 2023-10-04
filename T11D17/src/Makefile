
all: door_struct list_test

door_struct: dmanager_module.c
	gcc -Wall -Werror -Wextra $< -o ../build/Quest1

list_test: list_test.c
	gcc -Wall -Werror -Wextra $< -o ../build/Quest2

main: main1 main2

main1: dmanager_module.c
	gcc -Wall -Werror -Wextra $< -o ./a.out


main2: list_test.c list.o
	gcc -Wall -Werror -Wextra $< -o ./a2.out

list.o: list.c list.h
	gcc -Wall -Werror -Wextra -c list.c -o list.o

rebuild: clean all

clean: 
	rm -rf *.o *.out ../build/*

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c *.h


cpp3:
	cppcheck --enable=all --suppress=missingIncludeSystem list.c

cpp2:
	cppcheck --enable=all --suppress=missingIncludeSystem list_test.c

cpp1:
	cppcheck --enable=all --suppress=missingIncludeSystem dmanager_module.c

leak:
	leaks -atExit -- ./*.out