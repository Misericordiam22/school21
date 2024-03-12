OS = $(shell uname -o)
FLAGS = -Wall -Wextra -Werror -std=c11
FLAGS_FOR_GCOV = -fprofile-arcs -ftest-coverage
FILES_C = s21_matrix.c

TESTS = s21_tests.c

ifeq ($(OS), GNU/Linux)
	TEST_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
else
	TEST_FLAGS = -lcheck -lm -lpthread
endif

all: s21_matrix.a_gcov test gcov_report

clean:
	@rm -rf s21_tests *.gcda *.gcno *.o *.info *.a report gcov valgrind.log

rebuild:
	@make clean && make gcov_report

test: s21_matrix.a
	gcc $(FLAGS) $(TESTS) --coverage s21_matrix.a $(TEST_FLAGS) -o s21_tests
	./s21_tests

s21_matrix.a: $(FILES_C:.c=.o)
	ar rc $@ $^
	ranlib $@

s21_matrix.a_gcov:
	@gcc $(FLAGS) $(FLAGS_FOR_GCOV) -c $(FILES_C)
	@ar rc s21_matrix.a *.o
	@ranlib s21_matrix.a

gcov_report: s21_matrix.a_gcov test
	mkdir gcov
	mv s21_*.gcda ./gcov
	mv s21_*.gcno ./gcov
	lcov -t "s21_matrix" -o s21_matrix.info -c -d ./gcov/.
	genhtml -o report ./s21_matrix.info
	rm -fr ./gcov 
	rm *.o s21_tests
	
cl_fri:
	@clang-format -i -style=google *.h *.c

cl_fr:
	clang-format -n -style=google *.h *.c

valgrind_check: test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --verbose --log-file="valgrind.log" -v --verbose -q --quiet -s ./s21_tests

valgrind: test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all \
	--track-origins=yes --verbose --read-var-info=yes ./s21_tests