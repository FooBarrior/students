task: task.c students.o
	gcc -std=gnu99 -o task task.c students.o -lm

students.o: students.txt
	ld -b binary -i -o students.o students.txt

clean:
	rm -f task students.o
