all:
	gcc -o parserpe -g parserpe.c -L./lib/ -lparserpetest

clean:
	rm -f parserpe
