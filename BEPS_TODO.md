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

Add pointer to TCB to endpoint being waited on. - DONE "*holdEp"

Add explicit thread_state "BlockedOn_IPC_Hold" - DONE

- Make sure is initialised to 0 properly - PROBABLY DONE
    - Seems memory is pre-zeroed?

Change setNextInterrupt() - DONE

Add threshold field to SC's - DONE



Change fastpath up - Done


Change slowpath:
- Check if threshold set
- Reject on incorrect syscalls
- Check budget against threshold

Change awaken() - IN PROGRESS - WAITING TILL I FINISH THE ABOVE

Change scheduler


Adjust configuration syscalls:
- Create seL4\_Endpoint\_SetThreshold
- Alteration of SC parameters
- All revocation or deletion operations


TODO: Put a CONFIG_KERNEL_MCS 1 at the top of tcb.c