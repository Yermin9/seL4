

BL:

#if defined(CONFIG_KERNEL_IPCTHRESHOLDS) && defined(CONFIG_KERNEL_MCS)

DONE:

SC:
    -Add budget_limit flag
    -Add bl_consumed field
    -Make sure it gets incremented properly.

Reply object:
    -Add budget limit field

Call path:
    -set budget_limit flag + sometimes resest bl_consumed.
    -set budget_limit in reply object.
    -If budget_limit set, only allow donation over thresholded endpoint.

Call path:
    -Make threshold respect budget limit.
        - Immediately return SC down a level.

Timer_interrupt:
    -Change CheckBudget()



Reply path:
    -Fiddle with budgets properly


Timer_interrupt:
    -Set based on budget_limit+SC

TODO:






QUESTIONS:
What if a yield happens??




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


<<<<<<< HEAD
Create a set_Threshold syscall






=======
Create a set_Threshold syscall
>>>>>>> BEPS_simplified
