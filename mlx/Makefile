#
#

LIBNAME = mlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

all: $(LIBNAME)

$(LIBNAME):	$(LIBNAME)
	ar -r $(LIBNAME) $(OBJ)
	ranlib $(LIBNAME)

clean:
	rm -f $(LIBNAME) $(OBJ) *~
	rm -f mlx_app

re: clean all
