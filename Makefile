.PHONY: uninstall install clean

OBJ := main.o common.o
EXE := embedfiles

PREFIX ?= /usr/local

$(EXE): $(OBJ)
	$(CC) -o $@ $^

install: $(EXE)
	install -o root -g root -m 755 $(EXE) $(PREFIX)/bin

uninstall:
	rm -f $(PREFIX)/bin/$(EXE)

clean:
	rm -rf $(OBJ) $(EXE) 
