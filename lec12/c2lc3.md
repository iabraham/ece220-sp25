# A summary of function call/return

There are a lot of steps involved in using the runtime stack. However, the
steps are very mechanical and straightforward if you follow the steps
precisely. Normally the code is created by a compiler.

 1. caller pushes arguments right to left
 1. caller executes JSR
 1. callee makes space for return value (ADD R6,R6,#-1)
 1. callee pushes return address (PUSH R7)
 1. callee pushes old frame pointer (PUSH R5)
 1. callee resets frame pointer (ADD R5, R6 #-1) This makes the frame pointer
    point to the first local. When the locals are removed in step 9 the old
    frame pointer will be at the top of the stack and can be popped (step 10).
 1. callee allocates locals by decrementing stack pointer(ADD R6, R6, #-numLocals)
 1. callee does its work (includes saving return value STR Rx,R5,#3)
 1. callee removes locals by incrementing stack pointer (ADD R6, R6, #numLocals)
 1. callee restores old frame pointer (POP R5)
 1. callee pops return address (POP R7)
 1. callee executes RET
 1. caller pops return value
 1. caller removes parameters by incrementing stack pointer (ADD R6, R6, #numParams)
 1. caller continues its execution

Notice the symmetry of the steps. The actions taken in the beginning to build
the stack frame are done in the reverse order to remove the stack frame. 
 
 * See steps 7/9, 5/10, 4/11, 1/14. These are symmetric. 
 * Steps 2/12 and 3/13 on the other hand are assymetric.

 Further reading: https://www.cs.colostate.edu/~fsieker/misc/runtimeStack/runtimeStack.html
