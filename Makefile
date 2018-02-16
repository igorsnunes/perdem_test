CLOCK=clock
GETTIME=gettime
C_FILE=measure.c
OPT=-O0 -g
all: $(CLOCK) $(GETTIME)

$(CLOCK): $(C_FILE)
	gcc $(OPT) -o $(CLOCK) $(C_FILE) -DCLOCK

$(GETTIME): $(C_FILE)
	gcc $(OPT) -o $(GETTIME) $(C_FILE) -DGETTIME

test: all
	./clock
	./gettime

clean:
	rm -rf $(CLOCK) $(GETTIME)
