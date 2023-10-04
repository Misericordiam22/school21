
CC=gcc
CFLAGS= -Wall -Werror -Wextra
LIB1=../data_libs/data_io.c
LIB2=../data_libs/data_stat.c
LIB1_H=../data_libs/data_io.h
LIB2_H=../data_libs/data_stat.h

MODULE=../data_module/data_module_entry.c
PROCESS=../data_module/data_process.c
PROCESS_H=../data_module/data_process.h

YET_MAIN=../yet_another_decision_module/yet_another_decision_module_entry.c
YET_C=../yet_another_decision_module/decision.c
YET_H=../yet_another_decision_module/decision.h

MAIN_C=main_executable_module.c

ALL_FILES_C=$(LIB1) $(LIB2) $(PROCESS) $(YET_C) $(MODULE) $(YET_MAIN) $(MAIN_C)
ALL_FILES_H=$(LIB1_H) $(LIB2_H) $(PROCESS_H) $(YET_H)
ALL_FILES_CH=$(ALL_FILES_C) $(ALL_FILES_H)


all: main

main: main.o lib1.o lib2.o process.o yet.o 
	$(CC) $(CFLAGS) main.o lib1.o lib2.o process.o yet.o  -o ../../build/Quest3

main.o: $(MAIN_C) $(ALL_FILES_H)
	$(CC) $(CFLAGS) -c $(MAIN_C) -o main.o

lib1.o: $(LIB1) $(LIB1_H)
	$(CC) $(CFLAGS) -c $(LIB1) -o lib1.o

lib2.o: $(LIB2) $(LIB2_H)
	$(CC) $(CFLAGS) -c $(LIB2) -o lib2.o

process.o: $(PROCESS) $(PROCESS_H)
	$(CC) $(CFLAGS) -c $(PROCESS) -o process.o

yet.o: $(YET_C) $(YET_H)
	$(CC) $(CFLAGS) -c $(YET_C) -o yet.o

clean:
	rm -rf *.o ../../build/* *.a *.so

rebuild: clean all

clang: $(ALL_FILES_CH)
	clang-format -i $(ALL_FILES_CH)

clear:
	clear && clear

git: add commit push

add:
	git add $(ALL_FILES_CH) Makefile

commit: 
	git commit -m "fix"

push:
	git push origin develop

build_with_static: main.o lib1.o data_stat.a process.o yet.o
	$(CC) $(CFLAGS) main.o lib1.o process.o yet.o -L. data_stat.a -o ../../build/Quest5

data_stat.a: lib2.o
	ar rc data_stat.a lib2.o
	ranlib data_stat.a

build_with_dynamic: main.o lib1.o lib2.o data_process.so yet.o
	gcc main.o lib1.o lib2.o yet.o -L. data_process.so -o ../../build/Quest6

data_process.so: dynamic_process lib2.o
	gcc -shared dynamic_process.o lib2.o -o data_process.so

dynamic_process: $(PROCESS)
	$(CC) -fPIC -c $^ -o dynamic_process.o