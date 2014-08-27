###############################################################################
# Find TINYXML
###############################################################################
#
#  TINYXML_FOUND
#  TINYXML_INCLUDE_DIR
#  TINYXML_LIBRARY
#
###############################################################################

find_path(TINYXML_INCLUDE_DIR tinyxml.h
	HINTS $ENV{TINYXMLDIR}
	PATH_SUFFIXES include
	PATHS ~/Library/Frameworks
	      /Library/Frameworks
	      /usr/local
	      /usr
)

find_library(TINYXML_LIBRARY
	tinyxml
	HINTS $ENV{TINYXMLDIR}
	PATH_SUFFIXES lib64 lib
	PATHS ~/Library/Frameworks
	      /Library/Frameworks
	      /usr/local
	      /usr
)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TINYXML DEFAULT_MSG TINYXML_LIBRARY)

mark_as_advanced(TINYXML_LIBRARY TINYXML_INCLUDE_DIR)