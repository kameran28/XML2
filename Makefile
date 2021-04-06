# For GNU conventions and targets see https://www.gnu.org/prep/standards/standards.html
# Using GNU standards makes it easier for some users to keep doing what they are used to.

# 'mkdir -p' is non-portable, but it is widely supported. A portable solution
# is elusive due to race conditions on testing the directory and creating it.
# Anemic toolchain users can sidestep the problem using MKDIR="mkdir".

AR = ar
ARFLAGS = cr
RM = rm -f
RANLIB = ranlib
MKDIR = mkdir -p
CXXFLAGS = -fPIC

INSTALL = install
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644

prefix = /usr/local
bindir = $(prefix)/bin
libdir = $(prefix)/lib
includedir = $(prefix)/include

all: mytest staticlib

rebuild: clean all

mytest: mytest.cpp libtinyxml2.a

effc:
	gcc -Werror -Wall -Wextra -Wshadow -Wpedantic -Wformat-nonliteral \
        -Wformat-security -Wswitch-default -Wuninitialized -Wundef \
        -Wpointer-arith -Woverloaded-virtual -Wctor-dtor-privacy \
        -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo \
        -Wno-unused-parameter -Weffc++ mytest.cpp tinyxml2.cpp -o mytest

clean:
	-$(RM) *.o mytest libtinyxml2.a

# Standard GNU target
distclean:
	-$(RM) *.o mytest libtinyxml2.a

test: mytest
	./mytest

# Standard GNU target
check: mytest
	./mytest

staticlib: libtinyxml2.a

libtinyxml2.a: tinyxml2.o
	$(AR) $(ARFLAGS) $@ $^
	$(RANLIB) $@

tinyxml2.o: tinyxml2.cpp tinyxml2.h

directories:
	$(MKDIR) $(DESTDIR)$(prefix)
	$(MKDIR) $(DESTDIR)$(bindir)
	$(MKDIR) $(DESTDIR)$(libdir)
	$(MKDIR) $(DESTDIR)$(includedir)

# Standard GNU target.
install: mytest staticlib directories
	$(INSTALL_PROGRAM) mytest $(DESTDIR)$(bindir)/mytest
	$(INSTALL_DATA) tinyxml2.h $(DESTDIR)$(includedir)/tinyxml2.h
	$(INSTALL_DATA) libtinyxml2.a $(DESTDIR)$(libdir)/libtinyxml2.a

# Standard GNU target
uninstall:
	$(RM) $(DESTDIR)$(bindir)/mytest
	$(RM) $(DESTDIR)$(includedir)/tinyxml2.h
	$(RM) $(DESTDIR)$(libdir)/libtinyxml2.a
