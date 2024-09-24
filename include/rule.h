/*
 *    RULE.H
 *      Header file defining the struct "rule", used to defines filtering rules.
 *
 * */

typedef struct rule {
  int protocol;
  char* src_ip;
  char* dest_ip;
  int src_port;
  int dest_port;
} rule;
