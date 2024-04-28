#ifndef __STACK__H__
#define __STACK__H__

#ifdef __cplusplus
extern "C" {
#endif  //

#include <stdbool.h>
#include <stdlib.h>

typedef enum { STACK_OK = 0, ERR_MALLOC, ERR_EMPTY } stack_err;

#define STACK_NODE(prefix, T)    \
  typedef struct prefix##_node { \
    struct prefix##_node* next;  \
    T val;                       \
  } prefix##_node;

// STACK_STRUCT (int_stack, int)
#define STACK_STRUCT(prefix) \
  typedef struct prefix {    \
    size_t count;            \
    prefix##_node* head;     \
  } prefix;

#define STACK_INIT(prefix)        \
  void prefix##_init(prefix* s) { \
    s->count = 0;                 \
    s->head = NULL;               \
  }

#define STACK_EMPTY(prefix) \
  bool prefix##_empty(prefix* s) { return s->count == 0; }

#define STACK_PUSH(prefix, T)                                          \
  stack_err prefix##_push(prefix* s, T x) {                            \
    prefix##_node* n;                                                  \
    if ((n = (prefix##_node*)malloc(sizeof(prefix##_node))) == NULL) { \
      return ERR_MALLOC;                                               \
    }                                                                  \
    n->val = x;                                                        \
    n->next = s->head;                                                 \
    s->head = n;                                                       \
    s->count++;                                                        \
    return STACK_OK;                                                   \
  }

#define STACK_POP(prefix, T)                \
  stack_err prefix##_pop(prefix* s, T* x) { \
    if (s->count == 0) {                    \
      return ERR_EMPTY;                     \
    }                                       \
    prefix##_node* n;                       \
    n = s->head;                            \
    s->head = s->head->next;                \
    s->count--;                             \
    *x = n->val;                            \
    free(n);                                \
    return STACK_OK;                        \
  }

#define STACK_DECLARE(prefix, T) \
  STACK_NODE(prefix, T)          \
  STACK_STRUCT(prefix)           \
  STACK_INIT(prefix)             \
  STACK_EMPTY(prefix)            \
  STACK_PUSH(prefix, T)          \
  STACK_POP(prefix, T)

#ifdef __cplusplus
}
#endif  //__cplusplus

#endif  //!__STACK__H__