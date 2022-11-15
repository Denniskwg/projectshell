#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
/**
 * struct path_s - defines a new structure
 * @name: first member
 * @next: second member
 */
typedef struct path_s
{
	char name[PATH_MAX];
	struct path_s *next;
} path_h;
char *tokenizepath(char *, char, int *, char **);
void shiftcharacter(char **, int);
void copystring2(char *, char *);
void trim_end(char **);
path_h *add_node_end(path_h **, char *);
int findpath_to_executable(path_h **);
void copystring(char *, char **);
void freevector(char **);
char *getlaststring(char **);
void get_path_string(char **);
void createlinkedlist(char*, path_h **);
char *findpath(char *, path_h *head);
char *searchpath(char *, char *);
int comparestrings(char *, char *);
void string_concat(char **, char *);
void free_list(path_h *);
#endif
