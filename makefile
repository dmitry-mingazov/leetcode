CC = gcc
CCFLAGS = -Wall
SRCDIR = src
OUTDIR = out
SRC = $(wildcard $(SRCDIR)/*.c)
OUT = $(patsubst $(SRCDIR)/%.c, $(OUTDIR)/%, $(SRC))
CLEAN = rm -f
CLEANDIR = rm -fd
MKDIR = mkdir -p

all: $(OUTDIR) $(OUT)

$(OUTDIR)/%: $(SRCDIR)/%.c
	$(CC) -g -o $@ $< $(CCFLAGS)

$(OUTDIR):
	$(MKDIR) $(OUTDIR)

clean:
	$(CLEAN) $(OUTDIR)/*
	$(CLEANDIR) $(OUTDIR)