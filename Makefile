# executable name
output:= brainfuck.out
# source files (without .c extension)
srcs:= brainfuck

# compiler flags
CFLAGS+= -Wall -Wextra -O0 -g
# linker flags
#LDFLAGS+= -lX11 -llua5.3
# shortcut for -l arguments:
# libs:= X11 lua5.3

#(haven't tested this!)
#srcdir:= src

#this will put the files in .junk/whatever
#junkdir:= whatever

######################################################################

include .Nice.mk
