# Object Changes:
Endpoint:
- Add Threshold field
- Add IPC_Hold_queue pointer


Add node_state queues:
- IPCHoldReleaseHeadHead
- IPCHoldReleaseNextHead

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