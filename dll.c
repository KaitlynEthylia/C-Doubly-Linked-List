#include "dll.h"
#include <stdio.h>
#include <stdlib.h>

int dllInsert(dll *list, char *value, int index) {
  if (index == 0) {
    dllPrepend(list, value);
    return 0;
  }
  dllnode *node;
  int result = dllGet(*list, index, &node);
  if (result) {
    return result;
  }
  dllnode *new = malloc(sizeof(dllnode));
  new->value = value;
  node->prev->next = new;
  new->prev = node->prev;
  node->prev = new;
  new->next = node;
  return 0;
}

int dllDelete(dll *list, int index) {
  if (index == 0) {
    dllTail(list);
    return 0;
  }
  dllnode *node;
  int result = dllGet(*list, index, &node);
  if (result) {
    return result;
  }
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
  return 0;
}

int dllAppend(dll *list, char *value) {
  dllnode *node = malloc(sizeof(dllnode));
  node->value = value;
  node->next = NULL;
  if (*list == NULL) {
    *list = node;
    return 0;
  }
  dllnode *follow = *list;
  while (follow->next != NULL) {
    follow = follow->next;
  }
  node->prev = follow;
  follow->next = node;

  return 0;
}

int dllRemove(dll *list) {
  if (*list == NULL) {
    return 1;
  }
  dllnode *follow = *list;
  while (follow->next != NULL) {
    follow = follow->next;
  }
  if (follow->prev != NULL) {
    follow->prev->next = NULL;
  }
  if (*list == follow) {
    *list = NULL;
  }

  return 0;
}

void dllPrepend(dll *list, char *value) {
  dllnode *new = malloc(sizeof(dllnode));
  new->value = value;
  new->next = *list;
  if (*list != NULL) {
    (*list)->prev = new;
  }
  *list = new;
}

void dllTail(dll *list) {
  free(*list);
  *list = (*list)->next;
  (*list)->prev = NULL;
}

int dllGet(dll list, int index, dllnode **pnode) {
  dllnode *node = list;
  if (node == NULL) {
    return 1;
  }
  for (int i = 0; i < index; i++) {
    if (node->next == NULL) {
      return 1;
    }
    node = node->next;
  }
  *pnode = node;
  return 0;
}

int dllLength(dll list) {
  dllnode *node = list;
  int count = 0;
  while (node != NULL) {
    count++;
    node = node->next;
  }
  return count;
}

int dllFind(dll list, char *value) {
  dllnode *node = list;
  int count = -1;
  while (node != NULL) {
    count++;
    if (node->value == value) {
      return count;
    }
    node = node->next;
  }
  return -1;
}

int dllnodePrint(dllnode node) {
  char *prev = "NULL";
  if (node.prev != NULL) {
    prev = node.prev->value;
  }
  char *next = "NULL";
  if (node.next != NULL) {
    next = node.next->value;
  }

  return printf("%s <- %s -> %s\n", prev, node.value, next);
}

int dllPrint(dll list) {
  int result = printf("dll:\n");
  dllnode *follow = list;
  while (follow != NULL) {
    result = result | dllnodePrint(*follow);
    follow = follow->next;
  }
  return result;
}
