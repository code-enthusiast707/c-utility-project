exe= file_io

file_io: file_io.o text_file_io.o binary_file_io.o
	gcc -o $(exe) file_io.o text_file_io.o binary_file_io.o

text_file_io.o: text_file_io.c
	gcc -c text_file_io.c -o text_file_io.o

binary_file_io.o: binary_file_io.c
	gcc -c binary_file_io.c -o binary_file_io.o

file_io.o: file_io.c
	gcc -c file_io.c -o file_io.o

clean: 
	rm -f $(exe) *.o
