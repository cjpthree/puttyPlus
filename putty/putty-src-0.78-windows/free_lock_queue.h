/**
 * free_lock_queue.h
 * Original Author : cjpthree@126.com, 2014-7-3.
 *
 * Description
 */

#ifndef _FREE_LOCK_QUEUE_H_
#define _FREE_LOCK_QUEUE_H_
#include "free_lock_slist.h"

void test_free_lock_queue();

typedef free_lock_slist_head_t free_lock_link_queue;
typedef free_lock_slist_node_t free_lock_link_queue_node;

#define free_lock_link_queue_init(queue_name) \
    FREE_LOCK_SLIST_HEAD_INIT(queue_name)

#define free_lock_link_queue_init_top(queue) \
    INIT_FREE_LOCK_SLIST_HEAD(queue)

#define free_lock_link_queue_init_node(node) \
    INIT_FREE_LOCK_SLIST_NODE(node)

#define free_lock_link_queue_is_empty(queue) \
    free_lock_slist_empty(queue)

#define free_lock_link_queue_enqueue(new_node, queue) \
    free_lock_slist_add_tail((new_node), (queue))

#define free_lock_link_queue_dequeue(de_node, queue) \
do { \
    de_node = free_lock_slist_get_first(queue); \
    free_lock_slist_del_head(queue); \
} while (0)

#define free_lock_link_queue_get_head(queue) \
    free_lock_slist_get_first(queue)

#endif      /* _FREE_LOCK_QUEUE_H_ */
