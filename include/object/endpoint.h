/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#pragma once

#include <types.h>
#include <object/structures.h>

static inline tcb_queue_t PURE ep_ptr_get_queue(endpoint_t *epptr)
{
    tcb_queue_t queue;

    queue.head = (tcb_t *)endpoint_ptr_get_epQueue_head(epptr);
    queue.end = (tcb_t *)endpoint_ptr_get_epQueue_tail(epptr);

    return queue;
}

#ifdef CONFIG_KERNEL_MCS
void sendIPC(bool_t blocking, bool_t do_call, word_t badge,
             bool_t canGrant, bool_t canGrantReply, bool_t canDonate, tcb_t *thread,
             endpoint_t *epptr);
void receiveIPC(tcb_t *thread, cap_t cap, bool_t isBlocking, cap_t replyCPtr);
void reorderEP(endpoint_t *epptr, tcb_t *thread);


#ifdef CONFIG_ENDPOINT_THRESHOLDS
/* Associates a thread in the IPC_Hold state (insufficient budget) with the endpoint */
void addHoldEP(endpoint_t * epptr, tcb_t *thread);

/* Removes from the Held IPC queue */
void removeHoldEP(tcb_t *thread);

/* Completes the Held IPC operation. To be called when the thread has sufficient budget */
void completeHoldEP(tcb_t *thread);

#endif /* CONFIG_ENDPOINT_THRESHOLDS */

#else
void sendIPC(bool_t blocking, bool_t do_call, word_t badge,
             bool_t canGrant, bool_t canGrantReply, tcb_t *thread,
             endpoint_t *epptr);
void receiveIPC(tcb_t *thread, cap_t cap, bool_t isBlocking);
#endif
void cancelIPC(tcb_t *tptr);
void cancelAllIPC(endpoint_t *epptr);
void cancelBadgedSends(endpoint_t *epptr, word_t badge);
void replyFromKernel_error(tcb_t *thread);
void replyFromKernel_success_empty(tcb_t *thread);

