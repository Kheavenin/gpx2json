#gpx2json MakeFile
gpx2json.o: gpx2json.c memory_guard.j
	gcc -c gpx2json.c

memory_guard.o: memory_guard.h memory_guard.c
	gcc -c memory_guard.c

gpx2json: gpx2json.o memory_guard.o 
	gcc gpx2json.o memory_guard.o -o gpx2json