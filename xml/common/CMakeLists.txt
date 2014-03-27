#------------------------------------------------------------------------------
#--  Copyright 2012-2013
#--  Georgia Tech Research Institute
#--  505 10th Street
#--  Atlanta, Georgia 30332
#--
#--  This material may be reproduced by or for the U.S. Government
#--  pursuant to the copyright license under the clause at DFARS
#--  252.227-7013 (October 1988).
#------------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.6)
cmake_policy(VERSION 2.6)
message("In xml/common directory")
project(testMe)

set(LIBRARY_OUTPUT_PATH ${IPMAS_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${IPMAS_DIR}/bin)

SET(xml2owlGenerator_SOURCES
    source/xml2owlGenerator.cc
    source/xmlSchemaOwlYACC.cc
    source/xmlSchemaLex.cc
    source/xmlSchemaClasses.cc)
SET(xmlInstanceParserGenerator_SOURCES
    source/xmlInstanceParserGenerator.cc
    source/xmlSchemaYACC.cc
    source/xmlSchemaLex.cc
    source/xmlSchemaClasses.cc
    source/patternLex.cc
    source/patternYACC.cc)
SET(xmlSchemaOwlClassGenerator_SOURCES
    source/xmlSchemaOwlClassGenerator.cc
    source/xmlSchemaOwlYACC.cc
    source/xmlSchemaLex.cc
    source/xmlSchemaClasses.cc)
SET(xmlSchemaParser_SOURCES
    source/xmlSchemaParser.cc
    source/xmlSchemaYACC.cc
    source/xmlSchemaLex.cc
    source/xmlSchemaClasses.cc
    source/patternLex.cc
    source/patternYACC.cc)
SET(compactOwl_SOURCES
    source/compactOwl.cc)
SET(compareOwl_SOURCES
    source/compareOwl.cc)

SET(xml2owlGenerator_LIBS pthread)
SET(xmlInstanceParserGenerator_LIBS pthread)
SET(xmlSchemaOwlClassGenerator_LIBS pthread)
SET(xmlSchemaParser_LIBS pthread)
SET(compactOwl_LIBS pthread)
SET(compareOwl_LIBS pthread)

add_executable(xml2owlGenerator ${xml2owlGenerator_SOURCES})
add_executable(xmlInstanceParserGenerator ${xmlInstanceParserGenerator_SOURCES})
add_executable(xmlSchemaOwlClassGenerator ${xmlSchemaOwlClassGenerator_SOURCES})
add_executable(xmlSchemaParser ${xmlSchemaParser_SOURCES})
add_executable(compactOwl ${compactOwl_SOURCES})
add_executable(compreOwl ${compareOwl_SOURCES})

link_directories(${LIBRARY_OUTPUT_PATH})

# add_custom_target(compactOwlGen echo "Creating compactOwl.cc")
# add_custom_target(patternLexGen echo "Creating patternLex.cc")
# add_custom_target(xmlSchemaLexGen echo "Creating xmlSchemaLex.cc")

add_custom_command(
#  SOURCE source/compactOwl.lex
  COMMAND echo "Running flex on compactOwl.cc"
  COMMAND flex -L -o source/compactOwl.cc source/compactOwl.lex
#  ARGS -L -o source/compactOwl.cc
#  TARGET compactOwlGen
  DEPENDS source/compactOwl.lex
  OUTPUT source/compactOwl.cc)

add_custom_command(
#  SOURCE source/pattern.lex
  COMMAND echo "Running flex on patternLex.cc"
  COMMAND flex -L -Pyyre -o source/patternLex.cc source/pattern.lex
#  ARGS -L -Pyyre -o source/patternLex.cc
#  TARGET patternLexGen
  DEPENDS source/patternYACC.cc source/pattern.lex
  OUTPUT source/patternLex.cc)

add_custom_command(
#  SOURCE source/xmlSchema.lex
  COMMAND echo "Running flex on xmlSchemaLex.cc"
  COMMAND flex -L -o source/xmlSchemaLex.cc source/xmlSchema.lex
#  ARGS -L -o source/xmlSchemaLex.cc
#  TARGET xmlSchemaLexGen
  COMMAND echo "Done Running flex on xmlSchemaLex.cc"
  DEPENDS source/xmlSchema.lex source/xmlSchemaYACC.cc source/xmlSchemaClasses.hh
  OUTPUT source/xmlSchemaLex.cc)

add_custom_command(
#  SOURCE source/pattern.y
  COMMAND echo "Running bison on pattern.y"
  COMMAND bison -d -l -p yyre -o source/patternYACC.cc source/pattern.y
#  ARGS -d -l -p yyre -o source/patternYACC.cc
#  TARGET patternLexGen
  DEPENDS source/pattern.y
  OUTPUT source/patternYACC.cc)

add_custom_command(
#  SOURCE source/xmlSchema.y
  COMMAND bison -d -l -o source/xmlSchemaYACC.cc source/xmlSchema.y
#  ARGS -d -l -p yyre -o source/xmlSchemaYACC.cc
#  TARGET xmlSchemaLexGen
  OUTPUT source/xmlSchemaYACC.cc
  DEPENDS source/xmlSchema.y source/xmlSchemaClasses.hh)

add_custom_command(
  COMMAND bison -d -l -o source/xmlSchemaOwlYACC.cc source/xmlSchema.y
  OUTPUT source/xmlSchemaOwlYACC.cc
  DEPENDS source/xmlSchema.y source/xmlSchemaClasses.hh)

set_source_files_properties(source/xmlSchemaYACC.cc GENERATED)
set_source_files_properties(source/xmlSchemaOwlYACC.cc GENERATED)
set_source_files_properties(source/patternYACC.cc GENERATED)
set_source_files_properties(source/xmlSchemaOwlYACC.cc PROPERTIES COMPILE_FLAGS -DNOPATTERN)
