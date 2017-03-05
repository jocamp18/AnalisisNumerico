all: amethods

amethods:
	g++ -o amethods methods.cpp

clean:
	rm -f amethods
