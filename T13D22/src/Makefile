
all: main

main: cipher

cipher: cipher.c
	gcc -Wall -Werror -Wextra $< -o ../build/cipher

run:
	../build/cipher

list_test: list_test.c
	gcc -Wall -Werror -Wextra $< -o ../build/Quest2

rebuild: clean all

clean: 
	rm -rf *.o *.out ../build/*

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c

dev:
	git checkout -b develop

git:
	git add *.c
	git commit -m "ok"
	git push origin develop

new:
	touch main.c

cpp1:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

leak:
	leaks -atExit -- ./*.out