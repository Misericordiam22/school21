CC=gcc
CFLAGS= -Wall -Werror -Wextra

LIB1=s21_string.c
LIB1_H=s21_string.h
TEST=s21_string_test.c
TEST_O=s21_string_test.o

ALL_FILES_CH=*.c *.h

run1: 
	../build/Quest1

run2: 
	../build/Quest2

run3: 
	../build/Quest3

run4: 
	../build/Quest4

strlen_tests: clean lib1.o
	$(CC) $(CFLAGS) $(TEST) -DLEN -c 
	$(CC) $(CFLAGS) $(TEST_O) $^ -o ../build/Quest1

strcmp_tests: clean lib1.o
	$(CC) $(CFLAGS) $(TEST) -DCMP -c 
	$(CC) $(CFLAGS) $(TEST_O) $^ -o ../build/Quest2

strcpy_tests: lib1.o
	$(CC) $(CFLAGS) $(TEST) -DCPY -c 
	$(CC) $(CFLAGS) $(TEST_O) $^ -o ../build/Quest3

lib1.o: $(LIB1) $(LIB1_H)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o ../build/*

rebuild: clean strlen_tests

clang: $(ALL_FILES_CH)
	clang-format -i $(ALL_FILES_CH)

git: add commit push

add:
	git add $(ALL_FILES_CH) Makefile

commit: 
	git commit -m "it is auto commit and push"

push:
	git push origin develop
