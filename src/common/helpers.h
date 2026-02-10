/* types.h
 *
 * Author: Khalid Al-Hawaj
 * Date  : 13 Nov. 2023
 * 
 * This file contains various inline helper functions.
 * THESE FUNCTIONS MUST BE INLINED TO AVOID LINKING HEADACHES.
*/

#ifndef __COMMON_HELPERS_H_
#define __COMMON_HELPERS_H_

inline
char get_hex_digit_value(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  } else if (c >= 'A' && c <= 'F') {
    return c - 'A' + 10;
  } else if (c >= 'a' && c <= 'f') {
    return c - 'a' + 10;
  } else {
    return -1;
  }
}

inline
char get_hex_digit(char c) {
  char lut[16] = {'0', '1', '2', '3',
                  '4', '5', '6', '7',
                  '8', '9', 'a', 'b',
                  'c', 'd', 'e', 'f'};

  return lut[c];
}

inline
void sanitize_string(char* ptr) {
  while(*ptr) {
    if (*ptr == '\r' || *ptr == '\n')
      *ptr = 0x00;
    ptr++;
  }
}

#endif //__COMMON_HELPERS_H_

