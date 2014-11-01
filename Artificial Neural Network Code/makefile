output: malignancy_test.o
	gcc -g -o EXE malignancy_test.c -lfann -lm 
malignancy_test.o: malignancy_test.c
	gcc -g -c malignancy_test.c -lfann -lm
clean:
	rm *.o
	rm EXE
