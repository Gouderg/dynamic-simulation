pendule_simple: main.o Pendule.o Pvector.o
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp header/Pendule.hpp
	g++ -Wall -std=c++11 -c $<

Pendule.o: src/Pendule.cpp header/Pendule.hpp
	g++ -Wall -std=c++11 -c $<

Pvector.o: src/Pvector.cpp header/Pvector.hpp
	g++ -Wall -std=c++11 -c $<

clean:
	rm *.o pendule_simple
