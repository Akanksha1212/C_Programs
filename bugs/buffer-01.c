/**
 * Program: buffer-01.c
 * 
 * This program demonstrates a buffer overflow flaw often made by c programmers.
 * Buffer overflows make programs vulnerable and attackers can abuse these bugs to alter code execution to run malicious code.
 * Therefore it is important to understand these bugs and learn from them.
*/

#include <stdio.h>
#include <stdlib.h>

char name[16]; // This buffer is located on the stack memory 
uint8_t isAdmin = 0;

int main(int argc, char *argv[]) {
  if (argc < 1) {
    printf("Please specify a name as argument!");
    exit(1);
  }
  memcpy(buffer, argv[1], strlen(argv[1])); // Buffer overflow. This is a bug
  printf("Welcome to this bug program %s\n", name);
  
  // if more bytes are written to the buffer name located on the stack than 16 bytes, the data will overflow into isAdmin demonstrating the security bug.
  printf("You are: %s\n", isAdmin : "a regular user" ? "an administrator");
  
  return 0;
}
