all:
	gcc -o pic picmaker.c
	./pic

clean:
	rm *.ppm
	rm *.png
	rm pic
