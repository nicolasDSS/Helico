DIR_CLT_MAIN=$(DIR_SRC)/clt
DIR_SRV_MAIN=$(DIR_SRC)/srv
export EXEC_CLT_MAIN=cltHelico
export EXEC_SRV_MAIN=srvHelico
 
all: cltHelico srvHelico

cltHelico:
	@cd $(DIR_CLT_MAIN) && $(MAKE) && mv $(DIR_CLT_MAIN)/$@ $(DIR_SRC)/$@
	
srvHelico:
	@cd $(DIR_SRV_MAIN) && $(MAKE) && mv $(DIR_SRV_MAIN)/$@ $(DIR_SRC)/$@

clean:
	@find . -maxdepth 1 -type f -not -name "makefile" -print0 | xargs -0 rm -f
	@cd $(DIR_CLT_MAIN) && $(MAKE) clean
	@cd $(DIR_SRV_MAIN) && $(MAKE) clean
