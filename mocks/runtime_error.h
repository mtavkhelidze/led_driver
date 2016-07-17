#ifndef __RUNTIME_ERROR_H
#define __RUNTIME_ERROR_H

/*
 * This function is supposed to use syslog(3)
 */

void runtime_error(const char *message, int parameter,
                       const char *file, int line);

#define RUNTIME_ERROR(description, param) \
    runtime_error(description, param, __FILE__, __LINE__)

#endif /* __RUNTIME_ERROR_H */
