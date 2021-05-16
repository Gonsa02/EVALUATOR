OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: object
	g++ -o program.exe *.o $(OPCIONS)

object:
	g++ -c *.cc $(OPCIONS)

tar:
	zip -r html.zip DOC/html
	tar -cvf practica.tar *.hh *.cc Makefile html.zip

clean:
	rm *.o
	rm *.exe
	rm *.tar
	rm *.zip
	rm *.txt
