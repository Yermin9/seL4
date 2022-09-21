# Object Changes:
Endpoint: -DONE
- Add Threshold field
- Add IPC_Hold_queue pointer



Add node_state queues: - Done
- ksHoldReleaseHeadHead
- ksHoldReleaseNextHead
-Need boot initialisation - Done (in boot.c)
-Need addqueue and dequeue function - Done

Add to thread_state: tcbInHoldReleaseHeadQueue tcbInHoldReleaseNextQueue - DONE

Add pointer to TCB to endpoint being waited on. - DONE "holdCap"
+ cptr holdCptr
+ holdEP

Add explicit thread_state "BlockedOn_IPC_Hold" - DONE

- Make sure is initialised to 0 properly - PROBABLY DONE
    - Seems memory is pre-zeroed?

Change setNextInterrupt() - DONE

Add threshold field to SC's - DONE
    - Make sure this is set appropriately - TODO



Change fastpath up - Done


Change slowpath:
- Check if threshold set - Done
- Reject on incorrect syscalls -> Returns seL4_IllegalOperation
- Check budget against threshold - Done
- Reject appropriately ipcHold.
    * Objecttype.c  (decodeInvocation)

Create endpoint.c function to addholdEP, removeholdEP, completeholdEP - DONE

Change awaken() - Done
 - Add debug check for stuck threads 

Change scheduler - DONE
 - If a thread in the BlockedOn_IPC_Hold state is picker 
 - Change switchToThread - DONE

completeHoldEp: Check that IPC is still valid before sending. -DONE
    - Shouldn't matter - Anything that makes IPC invalidated will remove from hold state

Adjust configuration syscalls: - TODO
- Create seL4\_Endpoint\_SetThreshold - DONE
    - Only allow original capability
    - Changed how this is invoked. Must be invoked via Cnode style
    - Still need to set manual reference
    - Shuffle between endpoint queues

- Alteration of SC parameters - DONE - But could do with a clean-up
    - Budget etc
    - If budget changed
        - Move between endpoint queue if required
- Unbind SC and UnbindObject - DONE
    - Leave in endpoint, but remove from queues
    - Remove from Normal IPC queue if applicable
- Bind SC - DONE
    - If in threshold, add to appropriate queues
- YieldTo - DONE


- All revocation or deletion operations - TODO
    - TCB - Done
    - SC - Done
    - Endpoint cap - Done


TODO: Need to clear thread->holdCptr and SC->threhsold and stuff
TODO: Need to set sc->threshold and tcb->holdEP

TODO: Wrap everything in ifdef CONFIG_ENDPOINT_THRESHOLDS
 -- Actually use CONFIG_KERNEL_IPCTHRESHOLDS
Config options is -DKernelIpcThresholds 

TODO: Put a CONFIG_KERNEL_MCS 1 at the top of tcb.c

TODO: Handle Round Robin threads


TODO: Look at thread_state_ptr_get_blockingObject()