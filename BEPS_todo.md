

TODO:




IN PROGRESS:



DONE:

Add config flag for thresholds
    -#ifdef CONFIG_KERNEL_IPCTHRESHOLDS
    - -DKernelIpcThresholds 

Create available_budget_check in sporadic.c

Add to endpoints:
    -Threshold

Add budget check on slowpath
    -Block Non-call/NBSend invocations

Add budget check on fastpath

Create a YieldUntilBudget() syscall


Create a set_Threshold syscall






Part_2 (Budget_Limits)

IN PROGRESS:

- When reply object deleted:
    - Connect up stack properly
    -In replyRemove

TODO:



-What to do if an SC got bound halfway down?






- Add timer interrupt behaviour:
    - Returns SC if limit expired.


- Merge the bools in SC to save space

- IF threshold value changes, kick everyone off the endpint.


DONE:
- Add fields to reply object: "SCReturn" and "budgetLimit", "replyReturnPtr"

- Add fields to SC: "budgetLimit" that counts down

- Set new fields to 0 on initialisation


-Add changes on IPC Path:
    - Set SC Consumed field
    - Set Reply object fields

    - Change budget check to respect budget limit
        
        -Fastpath - DONE
        -Slowpath


- When reply object invoked:
    - If bottom of stack AND SC_Ret Ptr != NULL
        - Then return SC via SC_Ptr

    -Slowpath 
        - Working in reply_pop
    -Fastpath
        - Just kicks over to slowpath

