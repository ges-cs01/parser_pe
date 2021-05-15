all:
	gcc -shared -fPIC -o libparserpetest.so parserpetest.c

clean:
	rm -f libparserpetest.so

install: 
	install -m 0644 libparserpetest.so /usr/lib/libparserpetest.so

uninstall:
	rm -f /usr/lib/libparserpetest.so
