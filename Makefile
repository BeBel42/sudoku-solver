all: solve

solve: Sources/a.out Sources/solve.sh
	cp Sources/solve.sh solve

Sources/a.out: Sources/main.o
	gcc Sources/main.o -o Sources/a.out -lm

Sources/main.o: Sources/main.c
	gcc -c Sources/main.c -o Sources/main.o

clean:
	rm -f Sources/main.o
fclean: clean
	rm -f solve Sources/a.out

re: fclean all

.PHONY: all clean fclean re
