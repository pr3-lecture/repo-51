.PHONY: all clean
all: encrypt decrypt runtest

clean:
	rm -f encrypt decrypt test runCrypter.o crypto.o cryptoTest.o

runCrypter.o: runCrypter.c
	gcc -Wall -c runCrypter.c

crypto.o: crypto.c
	gcc -Wall -c crypto.c

cryptoTest.o: cryptoTest.c
	gcc -Wall -c cryptoTest.c

encrypt: runCrypter.o crypto.o
	gcc -o encrypt runCrypter.o crypto.o

decrypt: runCrypter.o crypto.o
	gcc -o decrypt runCrypter.o crypto.o

runtest: cryptoTest.o crypto.o
	gcc -o test cryptoTest.o crypto.o
