.global reset
reset:
    ldr sp, = stackPointer
    bl main
stop: bl stop
