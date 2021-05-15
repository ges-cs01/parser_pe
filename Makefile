all:
	gcc -o parserpe parserpe.c -L./lib/ -lparserpetest

clean:
	rm -f parserpe
