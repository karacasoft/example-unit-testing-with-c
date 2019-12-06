CC=gcc
CFLAGS=-O2 -g

SRC=some_app_logic.c
HDR=$(patsubst %.c, %.h, $(SRC))

OBJ:=$(patsubst %.c, %.o, $(SRC))

TEST:=$(patsubst %.c, %.test.c, $(SRC))
TEST_OBJ:=$(patsubst %.c, %.o, $(TEST))

all: $(OBJ) $(HDR)

test: $(TEST_OBJ) $(OBJ) $(HDR)
	@for f in $(patsubst %.test.c, %, $(TEST)); do \
		$(CC) $(CFLAGS) $$f.test.o $$f.o -o $$f.test ; \
		./$$f.test ; \
	done

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.test