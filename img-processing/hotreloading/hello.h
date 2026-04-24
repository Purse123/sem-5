#ifndef HELLO_
#define HELLO_

#ifdef __cplusplus
extern "C" {
#endif
/*
 * function pointer
 * without typedef:   display_t = NULL;
 * with typedef:      display_t display = NULL
 */
typedef void (*display_t)(void);
void display();

#ifdef __cplusplus
}
#endif

#endif //HELLO_
