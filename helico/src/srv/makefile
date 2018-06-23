EXEC=srvHelico
PACKAGES= com

# Un niveau de package est accessible.
#SRC  = $(wildcard */*.c)
SRC  = $(wildcard $(PACKAGES)/*.c)
# Pour ajouter un second niveau :		
# SRC += $(wildcard */*/*.c)
OBJ = $(SRC:.c=.o)

# Point d'entrée du programme.
MAIN = main.c

# Inclusion depuis le niveau du package.
CCINCLUDE += -I.
 
all:
	@for p in $(PACKAGES); do (cd $$p; $(MAKE) $@); done
	$(CC) $(CCINCLUDE) $(OBJ) $(MAIN) -o $(EXEC) $(LDFLAGS)

clean:
	@find . -maxdepth 1 -type f -not -name "makefile" -and -not -name "main.c" -print0 | xargs -0 rm -f
	@cd $(PACKAGES) && $(MAKE) clean