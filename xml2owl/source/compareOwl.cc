/*

This compares two files that are expected to have the same lines, but in
a different order, such as an automatically generated OWL file and a
hand-written OWL file. It reads the two files and saves the lines of
each one in two sets in alphabetical order (set::insert puts strings
in alphabetical order by default). Then it compares the lines of the
two sets in order. If it finds two lines that do not match, it prints
the line from the first file followed by the line from the second file.
If all lines match, that is reported.

If a file has duplicate lines, only one copy is saved, and the fact that
it is a duplicate is not recorded.

*/

#include <stdio.h>     // for printf
#include <string>      // for string
#include <set>         // for set

int main(int argc, char * argv[])
{
  FILE * inFile1;
  FILE * inFile2;
  FILE * outFile1;
  FILE * outFile2;
  char buffer[200];
  std::set<std::string> set1;
  std::set<std::string> set2;
  std::set<std::string>::iterator iter1;
  std::set<std::string>::iterator iter2;

  if (argc != 3)
    {
      fprintf(stderr, "Usage: %s <firstFile> <secondFile>\n", argv[0]);
      return 1;
    }
  inFile1 = fopen(argv[1], "r");
  if (inFile1 == 0)
    {
      fprintf(stderr, "could not open file %s\n", argv[1]);
      return 1;
    }
  inFile2 = fopen(argv[2], "r");
  if (inFile2 == 0)
    {
      fprintf(stderr, "could not open file %s\n", argv[2]);
      return 1;
    }
  for (; fgets(buffer, 199, inFile1); )
    set1.insert(buffer);
  for (; fgets(buffer, 199, inFile2); )
    set2.insert(buffer);
  outFile1 = fopen("junk1", "w");
  for (iter1 = set1.begin(); iter1 != set1.end(); iter1++)
    fprintf(outFile1, "%s", (*iter1).c_str());
  fclose(outFile1);
  outFile2 = fopen("junk2", "w");
  for (iter2 = set2.begin(); iter2 != set2.end(); iter2++)
    fprintf(outFile2, "%s", (*iter2).c_str());
  fclose(outFile2);
  for (iter1 = set1.begin(), iter2 = set2.begin();
       ((iter1 != set1.end()) && (iter2 != set2.end()));
       iter1++, iter2++)
    if ((*iter1) != (*iter2))
      {
	printf("%s%s", (*iter1).c_str(), (*iter2).c_str());
	return 1;
      }
  if (iter1 != set1.end())
    {
      fprintf(stderr, "%s: %s", argv[1], (*iter1).c_str());
      return 1;
    }
  if (iter2 != set2.end())
    {
      fprintf(stderr, "%s: %s", argv[2], (*iter2).c_str());
      return 1;
    }
  printf("%s and %s have the same lines\n", argv[1], argv[2]);
  return 0;
}
