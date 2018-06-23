export CC=gcc
export CFLAGS=-W -Wall -ansi -pedantic
export LDFLAGS=-lpthread

DIR_PROJET=$(PWD)
CLT_BINARY=cltHelico
SRV_BINARY=srvHelico

export DIR_BIN=$(DIR_PROJET)/bin
export DIR_LIB=$(DIR_PROJET)/lib
export DIR_SRC=$(DIR_PROJET)/src
export DIR_TEST=$(DIR_PROJET)/test
 
all: clean $(CLT_BINARY) $(SRV_BINARY)

$(CLT_BINARY):
	@(cd $(DIR_SRC) && $(MAKE) cltHelico && mv $(DIR_SRC)/$@ $(DIR_BIN)/$@)
	
$(SRV_BINARY):
	@(cd $(DIR_SRC) && $(MAKE) srvHelico && mv $(DIR_SRC)/$@ $(DIR_BIN)/$@)
 
clean:
	@(find $(DIR_BIN)/ -maxdepth 1 -type f -print0 | xargs -0 rm -f && cd $(DIR_SRC) && $(MAKE) clean)