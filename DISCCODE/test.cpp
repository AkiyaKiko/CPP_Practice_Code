#include<stdio.h>
#include <malloc.h>

typedef char ElemType;

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LinkList;

void InitList(LinkList *&L); // 初始化链表
void CreateListR(LinkList *&L, ElemType a[], int n); // 尾插法插入元素
bool ListEmpty(LinkList *L); // 判断是否为空表
int ListLength(LinkList *L); // 求单链表长度
void DispList(LinkList *L); // 输出单链表元素
bool GetElem(LinkList *L, int i, ElemType &e); // 查找第i个节点的元素
int LocateList(LinkList *L, ElemType e); // 按元素值查找
bool ListInsert(LinkList *&L, int i, ElemType e); // 插入数据元素
bool ListDelete(LinkList *&L, int i, ElemType &e); // 删除数组元素
void DestroyList(LinkList *&L); // 销毁单链表

// 初始化链表
void InitList(LinkList *&L) {
    L = NULL;
}

// 尾插法插入元素
void CreateListR(LinkList *&L, ElemType a[], int n) {
    LinkList *p, *r;
    int i;
    InitList(L);
    for (i = 0; i < n; i++) {
        p = (LinkList *)malloc(sizeof(LinkList));
        p->data = a[i];
        if (L == NULL) {
            L = p;
            r = L;
        } else {
            r->next = p;
            r = p;
        }
    }
    r->next = NULL;
}

// 判断是否为空表
bool ListEmpty(LinkList *L) {
    return L == NULL;
}

// 求单链表长度
int ListLength(LinkList *L) {
    int i = 0;
    LinkList *p = L;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

// 输出单链表元素
void DispList(LinkList *L) {
    LinkList *p = L;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 查找第i个节点的元素
bool GetElem(LinkList *L, int i, ElemType &e) {
    int j = 1;
    LinkList *p = L;
    if (i < 1 || i > ListLength(L)) {
        return false;
    }
    while (j < i) {
        j++;
        p = p->next;
    }
    e = p->data;
    return true;
}

// 按元素值查找
int LocateList(LinkList *L, ElemType e) {
    int i = 1;
    LinkList *p = L;
    while (p != NULL) {
        if (p->data == e) {
            return i;
        }
        i++;
        p = p->next;
    }
    return -1;
}

// 插入数据元素
bool ListInsert(LinkList *&L, int i, ElemType e) {
    int j = 1;
    LinkList *p, *q;
    if (i < 1 || i > ListLength(L) + 1) {
        return false;
    }
    p = (LinkList *)malloc(sizeof(LinkList));
    p->data = e;
    if (i == 1) {
        p->next = L;
        L = p;
    } else {
        q = L;
        while (j < i - 1) {
            j++;
            q = q->next;
        }
        p->next = q->next;
        q->next = p;
    }
    return true;
}

// 删除数组元素
bool ListDelete(LinkList *&L, int i, ElemType &e) {
    int j = 1;
    LinkList *p, *q;
    if (i < 1 || i > ListLength(L)) {
        return false;
    }
    if (i == 1) {
        p = L;
        L = L->next;
        e = p->data;
        free(p);
    } else {
        q = L;
        while (j < i - 1) {
            j++;
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        e = p->data;
        free(p);
    }
    return true;
}

// 销毁单链表
void DestroyList(LinkList *&L) {
    LinkList *p, *q;
    p = L;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    L = NULL;
}

int main() {
    LinkList *L;
    ElemType a[] = {'a', 'b', 'c', 'd', 'e'};
    int i;
    char e;

    // 初始化链表
    InitList(L);

    // 尾插法插入元素
    CreateListR(L, a, 5);

    // 输出链表
    DispList(L);

    // 输出链表长度
    printf("链表长度为：%d\n", ListLength(L));

    // 判断是否为空表
    if (ListEmpty(L)) {
        printf("链表为空表\n");
    } else {
        printf("链表非空表\n");
    }

    // 输出链表的第3个元素
    GetElem(L, 3, e);
    printf("链表的第3个元素为：%c\n", e);

    // 输出元素'a' 的位置
    i = LocateList(L, 'a');
    printf("元素'a' 的位置为：%d\n", i);

    // 在第4个元素位置上插入'f'元素
    ListInsert(L, 4, 'f');

    // 输出链表
    DispList(L);

    // 删除链表的第3个元素
    ListDelete(L, 3, e);

    // 输出链表
    DispList(L);

    // 销毁链表
    DestroyList(L);

    return 0;
}

