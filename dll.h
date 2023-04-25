typedef struct DLLNode {
  char *value;
  struct DLLNode *prev;
  struct DLLNode *next;
} dllnode;
typedef dllnode *dll;

int dllInsert(dll *list, char *value, int index);

int dllDelete(dll *list, int index);

int dllAppend(dll *list, char *value);

int dllRemove(dll *list);

void dllPrepend(dll *list, char *value);

void dllTail(dll *list);

int dllGet(dll list, int index, dllnode **pnode);

int dllFind(dll list, char *value);

int dllLength(dll list);

int dllnodePrint(dllnode node);

int dllPrint(dll list);
