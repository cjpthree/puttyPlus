/**
 * free_lock_slist.h
 * Original Author : cjpthree@126.com, 2014-7-3.
 *
 * Description
 * 单进单出免锁链表，应用于单进单出免锁队列挺好。
 * 对于大数据流能优化性能。
 */

#ifndef _FREE_LOCK_SLIST_H_
#define _FREE_LOCK_SLIST_H_

typedef struct free_lock_slist_node {
    struct free_lock_slist_node *next; /* 指向后面的entry */
} free_lock_slist_node_t;

typedef struct free_lock_slist_head_s {
    struct free_lock_slist_node   *next;    /* 总是指向第一个entry */
    struct free_lock_slist_node   *ptail;   /* 总是指向最后一个entry */
} free_lock_slist_head_t;

/**
 * 初始化链表
 */
#define FREE_LOCK_SLIST_HEAD_INIT(name) \
{ \
    (free_lock_slist_node_t *)&(name), \
    (free_lock_slist_node_t *)&(name) \
}

/**
 * 定义并初始化链表
 * @name: 链表的标识符
 */
#define FREE_LOCK_SLIST_HEAD(name) \
    free_lock_slist_t (name) = FREE_LOCK_SLIST_INIT(name)

/**
 * 初始化链表
 * @head: 需要初始化的链表
 */
#define INIT_FREE_LOCK_SLIST(head) \
do { \
    (head)->next = (free_lock_slist_node_t *)(head); \
    (head)->ptail = (free_lock_slist_node_t *)(head); \
} while (0)

/**
 * 初始化entry
 * @node: 需要初始化的entry
 */
#define INIT_FREE_LOCK_SLIST_NODE(s_node) \
    ((s_node)->next = (free_lock_slist_node_t *)(s_node))

/**
 * 判断是否为空链表，空链表只有头结点
 * @head: the list to test.
 */
#define free_lock_slist_empty(head) \
    ((head)->next == (free_lock_slist_node_t *)(head))

/**
 * 判断链表是否只有一个entry
 * @head: the list to test.
 */
#define free_lock_slist_is_singular(head) \
    ((head)->ptail == (head)->next)

/**
 * 获取链表最后一个entry
 * @head: the list to test.
 */
#define free_lock_slist_get_last(head) \
    ((head)->ptail)

/**
 * 获取链表第一个entry
 * @head: the list to test.
 */
#define free_lock_slist_get_first(head) \
    ((head)->next)

/**
 * 在entry后面插入一个新的entry
 * @new_entry:  要插入的entry
 * @prev_entry: 前面那个entry
 */
#define __free_lock_slist_add(new_entry, prev_entry) \
do { \
    (new_entry)->next = (prev_entry)->next; \
    (prev_entry)->next = (free_lock_slist_node_t *)(new_entry);  \
} while (0)

/**
 * 尾插法插入新entry
 * @new_entry:  new entry to be added
 * @head:       头entry
 */
#define free_lock_slist_add_tail(new_entry, head) \
do { \
    if (free_lock_slist_empty(head)) { \
        (head)->ptail = (free_lock_slist_node_t *)(new_entry);  \
         __free_lock_slist_add((new_entry), (head));  \
    } else if (free_lock_slist_is_singular(head)) { \
        __free_lock_slist_add((new_entry), free_lock_slist_get_last(head));  \
        (head)->ptail = (free_lock_slist_node_t *)(new_entry);  \
    } else { \
        __free_lock_slist_add((new_entry), free_lock_slist_get_last(head));  \
        (head)->ptail = (free_lock_slist_node_t *)(new_entry);  \
    } \
} while (0)

/**
 * 从链表删除prev_entry后面的entry
 * @prev_entry: 需要删除的entry的前面那个entry
 */
#define __free_lock_slist_del(prev_entry) \
    ((prev_entry)->next = (prev_entry)->next->next)

/**
 * 删除链表的第一个entry
 * @head: 链表头entry
 *
 * 性能好，推荐使用
 */
#define free_lock_slist_del_head(head) \
do { \
    if (free_lock_slist_empty(head)) { \
        /* do noting */; \
    } else if (free_lock_slist_is_singular(head)) { \
        (head)->ptail = (free_lock_slist_node_t *)(head); \
        __free_lock_slist_del(head); \
    } else { \
        __free_lock_slist_del(head); \
    } \
} while (0)

/**
 * 获取包含该entry的结构体指针
 * @entry:   包含在结构体中的entry
 * @type:    要获取的结构体的类型
 * @member:  entry在结构体中的标识符
 */
#define free_lock_slist_entry(entry, type, member) \
    ((type *)((char *)(entry) - (unsigned long)(&((type *)0)->member)))

#endif      /* _FREE_LOCK_SLIST_H_ */
