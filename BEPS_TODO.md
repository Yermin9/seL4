# Object Changes:
Endpoint: -DONE
- Add Threshold field
- Add IPC_Hold_queue pointer


Add node_state queues: - Done
- IPCHoldReleaseHeadHead
- IPCHoldReleaseNextHead
-Need boot initialisation - Done (in boot.c)
-Need addqueue and dequeue function - INPROGRESS

Add to thread_state: tcbInHoldReleaseHeadQueue, tcbInHoldReleaseNextQueue
- Make sure is initialised to 0 properly
    - Seems memory is pre-zeroed?


Add required_budget field to SC's

Change setNextInterrupt()
Change awaken()

Change fastpath up
Change slowpath:
- Check if threshold set
- Reject on incorrect syscalls
- Check budget against threshold


Adjust configuration syscalls:
- Create seL4\_Endpoint\_SetThreshold
- Alteration of SC parameters
- All revocation or deletion operations


TODO: Put a CONFIG_KERNEL_MCS 1 at the top of tcb.c