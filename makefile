CFLAGS = -Wall -g -ansi -O2
OBJS2 = primegap.o main_primegap.o timing.o

primegap: $(OBJS2)	
	$(CC) -o $@ $? -lgmp
	
clean:
	rm -rf $(OBJS1)  $(OBJS2) $(programs) *~ 
