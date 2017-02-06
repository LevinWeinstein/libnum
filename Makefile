LIBNAME = libnum.a

DIRECTORY = ./

CC = @gcc

CFLAGS = -c -Wall -Wextra -Werror

CHEADER = libnum.h  

CFILES = dl_first.c\
		dl_second.c\
		dl_third.c\
		dl_fourth.c\
		dl_fifth.c\
		nl_first.c\
		nl_second.c\
		nl_third.c

FILES = $(addprefix $(DIRECTORY), $(CFILES))

OBJECTS = $(FILES:.c=.o)

all:
	@echo "\t\x1b[96m\x1b[1mCompiling Library:\x1b[0m\x1b[96m [\x1b[93m\x1b[4mlibnum.a\x1b[24m\x1b[96m]"
	@if test ! -f $(LIBNAME); then \
		make innerall; \
	else \
		echo "\t\x1b[33mlibnum.a Already Made!"; \
	fi

innerall: $(LIBNAME)
	@echo "\x1b[96m\t[\x1b[33m\x1b[4mLibnum\x1b[24m\x1b[21m\x1b[96m]:\x1b[21m\x1b[32mlibnum: libnum.a Complete!"

$(LIBNAME): $(OBJECTS)
	@echo "\x1b[96m\t[\x1b[33m\x1b[4mLibnum\x1b[24m\x1b[96m]:\x1b[32mLibnum: Turning Objects Into Library"
	@ar rc $(LIBNAME) $(OBJECTS)
	@echo "\x1b[96m\t[\x1b[33m\x1b[4mLibnum\x1b[24m\x1b[96m]:\x1b[21m\x1b[32mlibnum: Optimizing... (ranlib)"
	@ranlib $(LIBNAME)
	


$(OBJECTS): $(SRCFILES)
	@echo "\x1b[96m\t[\x1b[33m\x1b[4mLibnum\x1b[24m\x1b[96m]:\x1b[21m\x1b[32m Building Objects From Source\x1b[21m"
	$(CC)  $(CFLAGS) $(FILES) -I ./libnum.h
	@if test ! -f $(OBECTS); then\
		echo "Compilation Failure"; \
	else \
		echo "\x1b[96m\t[\x1b[33m\x1b[4mlibnum\x1b[24m\x1b\x1b[96m]:\x1b[21m\x1b[32m Objects Compiled\x1b[21m"; \
	fi

clean: 	
	@/bin/rm -f $(OBJECTS)
	@echo "\x1b[96m\t[\x1b[33m\x1b[4mlibnum\x1b[24m\x1b[21m\x1b[96m]:\x1b[21m\x1b[32mlibnum: clean Complete!"
fclean: clean
	@/bin/rm -f $(LIBNAME)
	@echo "\x1b[96m\t[\x1b[33m\x1b[4mlibnum\x1b[24m\x1b[21m\x1b[96m]:\x1b[21m\x1b[32mlibnum: fclean Complete!"

re:	fclean all	
.PHONY: clean fclean re all
