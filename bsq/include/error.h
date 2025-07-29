#ifndef ERROR_H
#define ERROR_H

void handle_error(const char *message);
void handle_memory_error(void);
void handle_file_error(const char *filename);

#endif // ERROR_H