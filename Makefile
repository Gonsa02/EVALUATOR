OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: object
	g++ -o program.exe program.cc *.o $(OPCIONS)

object:
	g++ -c *.cc $(OPCIONS)

tar:
	tar -cvf practica.tar *.hh *.cc Makefile

clean:
	rm *.o
	rm *.exe
	rm *.tar
