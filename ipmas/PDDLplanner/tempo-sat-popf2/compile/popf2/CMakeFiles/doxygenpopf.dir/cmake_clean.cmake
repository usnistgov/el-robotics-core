FILE(REMOVE_RECURSE
  "doc/html"
  "doc/latex"
  "CMakeFiles/doxygenpopf"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/doxygenpopf.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
