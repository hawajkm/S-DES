/* main.c
 *
 * Author: Khalid Al-Hawaj
 * Date  :  7 Feb. 2026
 *
 * The file encrypt/decrypt input dataset n number of times using
 * every available cryptography scheme. It will record the runtime of
 * each invocation through the following Linux API:
 *
 *    clock_gettime() --- with the clk_id set to CLOCK_MONOTONIC
 *
 * Then, the file will calculate the standard deviation and calculate
 * an outlier-free average by excluding runtimes that are larger than
 * 3 standard deviation of the original average.
 */

/* Set features         */
#define _GNU_SOURCE

/* Standard C includes  */
/*  -> Standard Library */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*  -> Scheduling       */
#include <sched.h>
/*  -> Types            */
#include <stddef.h>
#include <stdbool.h>
#include <inttypes.h>
/*  -> Runtimes         */
#include <time.h>
#include <unistd.h>
#include <errno.h>

/* Include all schemes declarations */
#include "schemes/sdes/sdes.h"

/* Include common headers */
#include "common/helpers.h"
#include "common/types.h"
#include "common/macros.h"

int main(int argc, char** argv)
{
  /* Set the buffer for printf to NULL */
  setbuf(stdout, NULL);

  /* Arguments */
  int nruns   = 128;
  int nstdevs = 3;

  /* Parse arguments */
  /* Function pointers */
  /* Task:
   *   Declare and initialize a constant pointer to
   *   the SimpDES scheme.
   */

  /* Chosen */
  void     (*scheme_action_ptr)(byte*, size_t, byte*, size_t*, uint32_t) = NULL;
  void     (*scheme_verify_ptr)(byte*, size_t, byte*, size_t*, uint32_t) = NULL;
  uint32_t (*scheme_hashpwd_ptr)(byte*) = NULL;
  size_t   (*scheme_calclen_ptr)(size_t) = NULL;
  size_t   (*scheme_numblks_ptr)(size_t) = NULL;

  const char* scheme_str = NULL;

  /* Action */
  action_t action = NONE;

  /* Number of blocks per invocation */
  int numBlocks = 0;

  /* Message */
  char*  msg_str = NULL;
  byte*  msg     = NULL;
  size_t msg_sz  =    0;

  /* Password */
  char*    pwd_str = NULL;
  uint32_t pwd     =    0;

  /* Message */
  char*  res_str = NULL;
  byte*  res     = NULL;
  size_t res_sz  =    0;

  /* Boolean variable for help */
  bool help = false;

  /* Boolean variable for an error in parsing */
  bool parse_args_err = false;

  /* Defaults */
  scheme_str = "sdes";

  for (int i = 1; i < argc; i++) {
    /* Scheme */
    if (strcmp(argv[i], "-s") == 0 || strcmp(argv[i], "--scheme") == 0) {
      assert (++i < argc);
      /* Task:
       *   Add parsing logic to select SimpDES scheme
       */
      printf("\n");
      printf("ERROR: Unknown scheme \"%s\".\n", argv[i]);

      parse_args_err = true;

      continue;
    }

    /* Action */
    if (strcmp(argv[i], "-a") == 0 || strcmp(argv[i], "--action") == 0) {
      assert (++i < argc);
      if (strcmp(argv[i], "encrypt") == 0) {
        action = ENCRYPT;
      } else if (strcmp(argv[i], "decrypt") == 0) {
        action = DECRYPT;
      } else {
        action = NONE;

        printf("\n");
        printf("ERROR: Unknown \"%s\" action requsted.\n", argv[i]);

        parse_args_err = true;
      }

      continue;
    }

    /* Task:
     *   Implement an argument parsing routine to get the message from
     *   the arguments instead of stdin.
     */

    /* Task:
     *   Implement an argument parsing routine to get the message from
     *   a file instead of stdin.
     */

    /* Task:
     *   Implement an argument parsing routine to set the password directly
     *   instead of reading it from stdin.
     */

    /* Run parameterization */
    if (strcmp(argv[i], "--nruns") == 0) {
      assert (++i < argc);
      nruns = atoi(argv[i]);

      continue;
    }

    if (strcmp(argv[i], "--nstdevs") == 0) {
      assert (++i < argc);
      nstdevs = atoi(argv[i]);

      continue;
    }

    /* Help */
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
      help = true;

      continue;
    }
  }

  /* Set the correct scheme */
  /* Task:
   *   Add code to set function pointers correctly to
   *   the chosen scheme.
   */

  /* Check the sanity of the argument values */
  if (!parse_args_err && !help && scheme_str == NULL) {
    printf("\n");
    printf("ERROR: No implementation was chosen.\n");
  }

  if (help || scheme_str == NULL || parse_args_err) {
    printf("\n");
    printf("Usage:\n");
    printf("  %s [Options]\n", argv[0]);
    printf("  \n");
    printf("  Required:\n");
    printf("    -a | --action {act:str}  act: cryptographic action\n");
    printf("                               Available = {encrypt, decrypt}\n");
    printf("    \n");
    printf("  Options:\n");
    printf("    -s | --scheme {sch:str}  sch: Cryptography scheme\n");
    printf("                               Default = \"sdes\"\n");
    printf("                               Available = {sdes: S-DES}\n");
    printf("    \n");
    printf("         --nruns  {n:int}    n: Run count for scheme (default = %d)\n", nruns);
    printf("         --stdevs {n:int}    n: Stdev for outlier analysis (default = %d)\n", nstdevs);
    printf("    \n");
    printf("    -h | --help              Print help message and exit.\n");
    printf("\n");

    exit(help? 0 : 1);
  }

  /* Statistics */
  __DECLARE_STATS(nruns, nstdevs);

  /* Initialize Rand */
  srand(0xdeadbeef);

  /* Get the message */
  /* By default, we get the message from stdin */
  /* Task:
   *   Get the message as a string from stdin
   */

  /* Get the message */
  msg = (byte*)msg_str;

  /* Get the password */
  /* By default, we get the password from stdin */
  /* Task:
   *   Get the password as a string from the stdin
   */

  /* Hash the password */
  pwd = scheme_hashpwd_ptr((byte*)pwd_str);

  /* Allocation and initialization */
  res_sz = scheme_calclen_ptr(msg_sz);

  /* Task:
   *   Allocate memory space for output buffer to be
   *   used as a storage for cryptographic action requested.
   */
  // TASK GOES HERE!
  res_str = (char*)res;

  /* Allocation and initialization */
  numBlocks = scheme_numblks_ptr(msg_sz);

  /* Execute the requested scheme */
  /* Start execution */
  for (int i = 0; i < num_runs; i++) {
    __SET_START_TIME();
    for (int j = 0; j < 4; j++) {
      (*scheme_action_ptr)(msg, msg_sz, res, &res_sz, pwd);
    }
    __SET_END_TIME();
    runtimes[i] = __CALC_RUNTIME() / 4;
  }

  printf("\nResult: \"");
  if (action == ENCRYPT) {
    /* Task:
     *   Add code to print the result of encrypted message.
     */
  } else {
    /* Task:
     *   Add code to print the result of decrypted message.
     */
  }
  printf("\"\n");

  /* Running analytics */
  uint64_t min     = -1;
  uint64_t max     =  0;

  uint64_t avg     =  0;
  uint64_t avg_n   =  0;

  uint64_t std     =  0;
  uint64_t std_n   =  0;

  int      n_msked =  0;
  int      n_stats =  0;

  for (int i = 0; i < num_runs; i++)
    runtimes_mask[i] = true;

  do {
    n_stats++;
    avg_n =  0;
    avg   =  0;

    /*   -> Calculate min, max, and avg */
    for (int i = 0; i < num_runs; i++) {
      if (runtimes_mask[i]) {
        if (runtimes[i] < min) {
          min = runtimes[i];
        }
        if (runtimes[i] > max) {
          max = runtimes[i];
        }
        avg += runtimes[i];
        avg_n += 1;
      }
    }
    avg = avg / avg_n;

    /*   -> Calculate standard deviation */
    std   =  0;
    std_n =  0;

    for (int i = 0; i < num_runs; i++) {
      if (runtimes_mask[i]) {
        std   += ((runtimes[i] - avg) *
                  (runtimes[i] - avg));
        std_n += 1;
      }
    }
    std = sqrt(std / std_n);

    /*   -> Calculate outlier-free average (mean) */
    n_msked = 0;
    for (int i = 0; i < num_runs; i++) {
      if (runtimes_mask[i]) {
        if (runtimes[i] > avg) {
          if ((runtimes[i] - avg) > (nstd * std)) {
            runtimes_mask[i] = false;
            n_msked += 1;
          }
        } else {
          if ((avg - runtimes[i]) > (nstd * std)) {
            runtimes_mask[i] = false;
            n_msked += 1;
          }
        }
      }
    }
  } while (n_msked > 0);

  /* Display information */
  const char* tmpStr = (action == ENCRYPT)? "encryption":"decryption";
  printf("Average time per %s: ", tmpStr);
  printf(" %" PRIu64 " ns\n", avg);

  tmpStr = (action == ENCRYPT)? "Encryptions":"Decryptions";
  double th = ((1.0 * numBlocks) / (avg * 1e-9));
  const char* prefix = "";

  if (th > 1000.0) {
    th = th / 1000.0;
    prefix = "K";
  }
  if (th > 1000.0) {
    th = th / 1000.0;
    prefix = "M";
  }
  if (th > 1000.0) {
    th = th / 1000.0;
    prefix = "G";
  }
  if (th > 1000.0) {
    th = th / 1000.0;
    prefix = "T";
  }
  if (th > 1000.0) {
    th = th / 1000.0;
    prefix = "P";
  }
  if (th > 1000.0) {
    th = th / 1000.0;
    prefix = "E";
  }
  if (th > 1000.0) {
    th = th / 1000.0;
    prefix = "Z";
  }
  printf("Throughput: %0.2lf %s%s/s\n", th, prefix, tmpStr);

  /* Dump */
  char const* fn_act_str = (action == ENCRYPT)? "_encr" : "_decr";
  FILE * fp;
  char filename[256];
  strcpy(filename, scheme_str);
  strcat(filename, fn_act_str);
  strcat(filename, "_runtimes.csv");
  fp = fopen(filename, "w");

  if (fp != NULL) {
    fprintf(fp, "scheme,%s", scheme_str);

    fprintf(fp, "\n");
    fprintf(fp, "num_of_runs,%d", num_runs);

    fprintf(fp, "\n");
    fprintf(fp, "runtimes");
    for (int i = 0; i < num_runs; i++) {
      fprintf(fp, ", ");
      fprintf(fp, "%" PRIu64 "", runtimes[i]);
    }

    fprintf(fp, "\n");
    fprintf(fp, "avg,%" PRIu64 "", avg);
    fclose(fp);
  }

  /* Manage memory */
  /* On-going Task:
   *   Do not forget to correctly handle memory managements.
   */

  /* Finished with statistics */
  __DESTROY_STATS();

  /* Done */
  return 0;
}
