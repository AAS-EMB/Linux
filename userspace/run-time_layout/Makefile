all: lib
	gcc solution.c -fPIC -ldl -Wl,-rpath,. -o solution

lib:  libSolution.c
	gcc libSolution.c -shared -fPIC -o libSolution.so

clean:
	rm libSolution.so solution

