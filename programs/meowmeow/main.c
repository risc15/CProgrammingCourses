/* main.c - MeowMeow, a stream encoder/decoder */

/*
 * 00 system includes
 * 01 project includes
 * 02 externs
 * 03 defines
 * 04 typedefs
 * 05 globals (but don't)
 * 06 ancillary function prototypes if any
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <getopt.h>

#include "main.h"
#include "mmencode.h"
#include "mmdecode.h"

extern char *optarg;
extern int   optopt;
extern int   opterr;
extern int   opterr;

#define OPTARG "i:o:hV"

#define MM_OP_INVALID 0
#define MM_OP_ENCODE  1
#define MM_OP_DECODE  2

int usage(char *, int);
int pick_operation(char *);


int main(int argc, char *argv[])
{
  options_t options = OPTIONS_INIT;
  int retval        = -1;
  int codec_op      = MM_OP_INVALID;
  int opt;

  opterr = 0;

  if ((codec_op = pick_operation(argv[0])) == MM_OP_INVALID) {
    errno = EINVAL;
    perror("meow/unmeow argv[0] unrecognized!");
    exit(-1);
    /* NOTREACHED */
  }
  
  while( (opt=getopt(argc, argv, OPTARG)) != EOF)
    switch(opt) {
      case 'i':
	/* XXX handle "-" explicitly as stdin */
	if (!(options.in_stream = fopen(optarg, "r"))) {
	  perror("Error opening input stream");
	  exit(-1);
	  /* NOTREACHED */
	}
	break;
	
      case 'o':
	/* XXX handle "-" explicitly as stdout */
	if (!(options.out_stream = fopen(optarg, "w"))) {
	  perror("Error opening output stream");
	  exit(-1);
	  /* NOTREACHED */
	}
	break;
	
      case 'V':
	printf("%s version %s\n",
	       basename(argv[0]),
	       MEOWMEOW_VERSION);
	exit(0);
	/* NOTREACHED */
	break;
	
      case '?':
      case 'h':
      default:
	usage(basename(argv[0]), optopt);
	break;
    }

  switch(codec_op) {
    case MM_OP_ENCODE:
      retval = mm_encode(options.in_stream, options.out_stream);
      break;
      
    case MM_OP_DECODE:
      retval = mm_decode(options.in_stream, options.out_stream);
      break;
      
    default:
      retval = -1;
      errno = EINVAL;
      fprintf(stderr, "Impossible state: %s codec=%d\n", argv[0], codec_op);
      break;
  }

  if (retval < 0) {
    perror("codec failed");
  }
  

  return retval;
}


int usage(char *argv0, int opt)
{
  if (!argv0) {
    errno = EINVAL;
    perror("main:usage called with NULL argv[0]");
    exit(-1);
  }
  
  fprintf(stderr, "usage: %s [-i input] [-o output] [-V]\n",
	  basename(argv0));
  if (opt != '?')
    fprintf(stderr, "unknown option: \"%c\"\n", opt);
  exit(-1);
  /* NOTREACHED */
}


int pick_operation(char *argv0)
{
  char *name;
  
  if (!argv0) {
    errno = EINVAL;
    return MM_OP_INVALID;
  }
  
  name = basename(argv0);

  if (strncmp(name, CMD_MEOW, strlen(CMD_MEOW)) == 0)
    return MM_OP_ENCODE;

  if (strncmp(name, CMD_UNMEOW, strlen(CMD_UNMEOW)) == 0) 
    return MM_OP_DECODE;  
  
  return MM_OP_INVALID;
}

// 11 ancillary functions if any
