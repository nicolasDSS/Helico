SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

# Inclusion depuis le niveau du package.
CCINCLUDE += -I..

all: $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)
 
clean:
	@rm -f $(OBJ)