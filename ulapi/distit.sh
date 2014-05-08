#!/bin/sh

CVSDIR=`cat CVS/Root`

cd /tmp && rm -rf ulapi && cvs -d $CVSDIR co ulapi && cd ulapi && ./autoconf.sh && make dist && tar xzvf *.tar.gz && cd ulapi-* && ./configure && make && make dist || exit 1

exit 0

