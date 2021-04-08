object: Curso.cc Plataforma.cc Problema.cc Sesion.cc Usuario.cc
	g++ -c Curso.cc Plataforma.cc Problema.cc Sesion.cc Usuario.cc

exe: main.cc Curso.o Plataforma.o Problema.o Sesion.o Usuario.o
	g++ -o exe main.cc Curso.o Plataforma.o Problema.o Sesion.o Usuario.o
