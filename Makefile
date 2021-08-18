# dwm - dynamic window manager
# See LICENSE file for copyright and license details.

include config.mk

SRC = drw.cpp dwm.cpp util.cpp
OBJ = ${SRC:.cpp=.o}
BUILDDIR = ./build

all: options dwm

options:
	mkdir -p ${BUILDDIR}
	@echo dwm build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CC       = ${CC}"

.cpp.o:
	${CC} -c ${CFLAGS} $< ${CPPFLAGS}

${OBJ}: config.h config.mk

config.h:
	cp config.def.h ${BUILDDIR}/$@

dwm: ${OBJ}
	${CC} -o ${BUILDDIR}/$@ ${OBJ} ${LDFLAGS}

clean:
	rm -rf ${BUILDDIR}
	rm config.h

dist: clean
	mkdir -p dwm-${VERSION}
	cp -R LICENSE Makefile README config.def.h config.mk\
		dwm.1 drw.hpp util.hpp ${SRC} dwm.png transient.cpp dwm-${VERSION}
	tar -cf dwm-${VERSION}.tar dwm-${VERSION}
	gzip dwm-${VERSION}.tar
	rm -rf dwm-${VERSION}

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f dwm ${DESTDIR}${PREFIX}/bin
	chmod 755 ${DESTDIR}${PREFIX}/bin/dwm
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	sed "s/VERSION/${VERSION}/g" < dwm.1 > ${DESTDIR}${MANPREFIX}/man1/dwm.1
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/dwm.1

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwm\
		${DESTDIR}${MANPREFIX}/man1/dwm.1

run:
	Xephyr -br -ac -noreset -screen 1280x720 :1 & disown ; sleep 1 ; DISPLAY=:1 ${BUILDDIR}/dwm

.PHONY: all options clean dist install uninstall run
