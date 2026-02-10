/* sdes.c
 *
 * Author: <YOUR NAME>
 * Date  : <DATE>
 * 
 * This file contains the implementation of S-DES.
*/

/* Task:
 *   Add implementation for S-DES permutation functionality.
 */


/* Task:
 *   Add implementation for S-DES roundkey generate logic
 */

/* Encrypt */
char sbox[][16] = {{  2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
                   { 14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
                   {  4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
                   { 11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3}};

/* Task:
 *   Add implementation for substitution boxes (S-BOX) to
 *   be used in encryption.
 */


/* Task:
 *   Add implementation for S-DES one encryption round.
 */


/* Task:
 *   Add implementation for S-DES single block encryption.
 */


/* Task:
 *   Add implementation for main S-DES encryption.
 */

/* Decrypt */
char xobs[][16] = {{ 13,  3,  0, 10,  2,  9,  7,  4,  8, 15,  5,  6,  1, 12, 14, 11},
                   {  9,  7,  2, 12,  4,  8, 15,  5, 14, 13, 11,  1,  3,  6,  0, 10},
                   { 14,  2,  1, 13,  0, 11, 12,  6,  7,  9,  4,  3, 10,  5, 15,  8},
                   { 10,  4,  6, 15, 13, 14,  8,  3,  1, 11, 12,  0,  2,  7,  5,  9}};

/* Task:
 *   Add implementation for reverse substitution boxes (XOB-S) to
 *   be used in decryption.
 */


/* Task:
 *   Add implementation for S-DES single decryption round.
 */


/* Task:
 *   Add implementation for S-DES single block decryption.
 */


/* Task:
 *   Add implementation for main S-DES decryption.
 */


/* Hash Password */
/* Task:
 *   Add implementation to generate key by hashing ASCII
 *   string password.
 */


/* Calculate Length */
/* Task:
 *   Add implementation to calculate the length of output
 *   buffers required in bytes.
 */


/* Number of blocks */
/* Task:
 *   Add implementation to calculate the number of blocks
 *   in a given input length.
 */
