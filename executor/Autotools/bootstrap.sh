#!/bin/sh -x

aclocal && \
autoheader && \
automake --gnu --add-missing --copy && \
autoconf && exit 0

exit 1
