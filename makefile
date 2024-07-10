all: mst

mst: mst.o smpl.o rand.o cisj.o
	$(LINK.c) -o $@ -Bstatic mst.o smpl.o rand.o cisj.o -lm

mst.o: mst.c cisj.h smpl.h
	$(COMPILE.c) -g mst.c

cisj.o: cisj.c cisj.h
	$(COMPILE.c) -g cisj.c

smpl.o: smpl.c smpl.h
	$(COMPILE.c) -g smpl.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o mst
