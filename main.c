#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int opt;
  enum { C_MODE } language = C_MODE;
  char *program_name = argv[0];
  char *outfilename = "NO_OUT";
  while ((opt = getopt(argc, argv, "o:l:h")) != -1) {
    switch (opt) {
    case 'l':
      if (strcmp(optarg, "c") == 0) {
        language = C_MODE;
      } else {
        fprintf(stderr, "You have to supply a valid language! The program only "
                        "supports C at the moment!\n");
        exit(EXIT_FAILURE);
      }
      break;
    case 'o':
      outfilename = optarg;
      break;
    case 'h':
    default:
      fprintf(stderr, "Usage: %s (-l [c]) [file...] (-o file...)\n",
              program_name);
      exit(EXIT_FAILURE);
    }
  }
  argc -= optind;
  argv += optind;
  char *lang_ending;
  if (language == C_MODE) {
    lang_ending = ".c";
  }
  if (argc < 1) {
    fprintf(stderr, "Usage: %s (-l [c]) [file...] (-o file...)\n",
            program_name);
    exit(EXIT_FAILURE);
  }

  // Open/Create Files
  FILE *infile;
  FILE *outfile;
  infile = fopen(argv[0], "rb");
  if (strcmp(outfilename, "NO_OUT") == 0) {
    outfilename = concat(argv[0], lang_ending);
    outfile = fopen(outfilename, "w");
    free(outfilename);
  } else {
    outfile = fopen(outfilename, "w");
  }
  // If converting to C
  if (language == C_MODE) {
    fprintf(outfile, "#include <stdlib.h>\n\n");
    fprintf(outfile, "const char %s[] = {\n", argv[0]);
    unsigned char buf[256];
    size_t nread = 0;
    size_t linecount = 0;
    do {
      nread = fread(buf, 1, sizeof(buf), infile);
      size_t i;
      for (i = 0; i < nread; i++) {
        fprintf(outfile, "0x%02x, ", buf[i]);
        if (++linecount == 10) {
          fprintf(outfile, "\n");
          linecount = 0;
        }
      }
    } while (nread > 0);
    if (linecount > 0)
      fprintf(outfile, "\n");
    fprintf(outfile, "};\n");

    fprintf(outfile, "const size_t %s_len = sizeof(%s);\n", argv[0], argv[0]);
  }
  // Close the outfile again
  fclose(outfile);
  // Close the infile again
  fclose(infile);
  return 0;
}
