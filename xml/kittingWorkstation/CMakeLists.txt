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
message("In xml/kittingWorkstation/xmlSchemas/ directory")
project(kittingWorkstation)

set(LIBRARY_OUTPUT_PATH ${IPMAS_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${IPMAS_DIR}/bin)
include_directories(${IPMAS_DIR}/xml/common/source)

SET(kittingWorkstationParser_SOURCES
    source/kittingWorkstationParser.cc
    source/kittingWorkstationClasses.cc
    source/kittingWorkstationLex.cc
    source/kittingWorkstationYACC.cc
    ../common/source/xmlSchemaInstance.cc)

SET(owlKittingWorkstationPrinter_SOURCES
  source/owlKittingWorkstationPrinter.cc
  source/owlKittingWorkstationYACC.cc
  source/owlKittingWorkstationLex.cc
  source/owlKittingWorkstationClasses.cc
  ../common/source/owlInstancePrinter.cc
  ../common/source/xmlSchemaInstance.cc)

SET(kittinWorkstationParser_LIBS pthread)
SET(owlKittinWorkstationPrinter_LIBS pthread)

add_executable(kittingWorkstationParser ${kittingWorkstationParser_SOURCES})
add_executable(owlKittingWorkstationPrinter ${owlKittingWorkstationPrinter_SOURCES})

link_directories(${LIBRARY_OUTPUT_PATH})

add_custom_command(
  COMMAND flex -L -o source/kittingWorkstationLex.cc source/kittingWorkstation.lex
  DEPENDS source/kittingWorkstation.lex
  OUTPUT source/kittingWorkstationLex.cc)

add_custom_command(
  COMMAND flex -L -o source/owlKittingWorkstationLex.cc source/kittingWorkstation.lex
  DEPENDS source/kittingWorkstation.lex
  OUTPUT source/owlKittingWorkstationLex.cc)

add_custom_command(
  COMMAND bison -d -l -o source/kittingWorkstationYACC.cc source/kittingWorkstation.y
  OUTPUT source/kittingWorkstationYACC.cc source/kittingWorkstationYACC.hh
  DEPENDS source/kittingWorkstation.y source/kittingWorkstationYACC.hh)

add_custom_command(
  COMMAND bison -d -l -o source/owlKittingWorkstationYACC.cc source/kittingWorkstation.y
  OUTPUT source/owlKittingWorkstationYACC.cc 
  DEPENDS source/kittingWorkstation.y source/kittingWorkstationYACC.hh)

add_custom_command(
  COMMAND ${IPMAS_DIR}/bin/xmlInstanceParserGenerator -x ./xmlSchemas/kittingWorkstation.xsd
  COMMAND mv ./xmlSchemas/*.cc ./xmlSchemas/*.hh ./xmlSchemas/*.lex ./xmlSchemas/*.y ./source
  OUTPUT source/kittingWorkstation.lex source/kittingWorkstation.y source/kittingWorkstationClasses.cc source/kittingWorkstationClasses.hh source/kittingWorkstationParser.cc
  DEPENDS xmlSchemas/kittingWorkstation.xsd)

add_custom_command(
  COMMAND ${IPMAS_DIR}/bin/xml2owlGenerator ./xmlSchemas/kittingWorkstation.xsd kittingWorkstation
  COMMAND mv owlKittingWorkstationClasses.cc owlKittingWorkstationClasses.hh owlKittingWorkstationPrinter.cc ./source
  OUTPUT source/owlKittingWorkstationClasses.cc owlKittingWorkstationClasses.hh owlKittingWorkstationPrinter.cc
  DEPENDS xmlSchemas/kittingWorkstation.xsd)

set_source_files_properties(source/kittingWorkstation.lex GENERATED)
set_source_files_properties(source/kittingWorkstation.y GENERATED)
set_source_files_properties(source/kittingWorkstationClasses.cc GENERATED)
set_source_files_properties(source/kittingWorkstationClasses.hh GENERATED)
set_source_files_properties(source/kittingWorkstationParser.cc GENERATED)
set_source_files_properties(source/kittingWorkstationYACC.cc GENERATED)
set_source_files_properties(source/kittingWorkstationYACC.hh GENERATED)
set_source_files_properties(source/kittingWorkstationLex.cc GENERATED)
set_source_files_properties(source/owlKittingWorkstationClasses.cc GENERATED)
set_source_files_properties(source/owlKittingWorkstationClasses.hh GENERATED)
set_source_files_properties(source/owlKittingWorkstationPrinter.cc GENERATED)
set_source_files_properties(source/owlKittingWorkstationYACC.cc GENERATED)
set_source_files_properties(source/owlKittingWorkstationYACC.cc PROPERTIES COMPILE_FLAGS -DOWL)
set_source_files_properties(source/owlKittingWorkstation.lex GENERATED)
set_source_files_properties(source/owlKittingWorkstation.lex PROPERTIES COMPILE_FLAGS -DOWL)
