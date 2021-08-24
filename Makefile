# Copyright Dima Petrov leurnkim@gmail.com, 2021. Unlicense.

APP      = simple-window
EXEFILE  = $(APP).exe
OBJFILES = $(APP).obj
#RESFILES = $(APP).res
SRC      = $(APP).c

CC       = cl
LINK     = link

CFLAGS   = /c /nologo /TC
LDFLAGS  = /SUBSYSTEM:WINDOWS /nologo ## /MERGE:.rdata=.text /FIXED

LIBS     = kernel32.lib user32.lib

$(EXEFILE) : $(OBJFILES)
    $(LINK) $(LDFLAGS) $** $(LIBS)

$(OBJFILES) : $(SRC)
    $(CC) $(CFLAGS) $**

simple_window : $(EXEFILE)


.SILENT:
clean :
	if exist *.obj del *.obj
	if exist *.exe del *.exe

all : $(EXEFILE)