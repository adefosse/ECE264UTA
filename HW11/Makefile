CC = gcc
CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror

SRCS = main.c hw11.c
OBJS = $(SRCS:.c=.o)

hw11: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o hw11

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

testall: test1 test2 test3 test4 test5 test6 test7 test8 test9 test10 test11

test1: hw11
	./hw11 input/input1.xml > output1.txt
	diff output1.txt expected/expected1.txt

test2: hw11
	./hw11 input/input2.xml > output2.txt
	diff output2.txt expected/expected2.txt

test3: hw11
	./hw11 input/input3.xml > output3.txt
	diff output3.txt expected/expected3.txt

test4: hw11
	./hw11 input/input4.xml > output4.txt
	diff output4.txt expected/expected4.txt

test5: hw11
	./hw11 input/input5.xml > output5.txt
	diff output5.txt expected/expected5.txt

test6: hw11
	./hw11 input/input6.xml > output6.txt
	diff output6.txt expected/expected6.txt

test7: hw11
	./hw11 input/input7.xml > output7.txt
	diff output7.txt expected/expected7.txt

test8: hw11
	./hw11 input/input8.xml > output8.txt
	diff output8.txt expected/expected8.txt

test9: hw11
	./hw11 input/input9.xml > output9.txt
	diff output9.txt expected/expected9.txt

test10: hw11
	./hw11 input/input10.xml > output10.txt
	diff output10.txt expected/expected10.txt

test11: hw11
	./hw11 input/input11.xml > output11.txt
	diff output11.txt expected/expected11.txt

clean:
	rm -f *.o a1 output.txt