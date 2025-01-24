/*
    startup file for CortexM32
    Eng. Sohaib saadat 
*/

/*Remove this file from a project if you will use a startup.c*/

/*Vetctor section  this section will be start at address 0x80000000 in flash*/

.section .vetctor 
.word 0x20001000            /* stack pointer address */
.word _vector_hnadler                /* reset section handler*/
.word _vector_hnadler                /* Hard Fault */
.word _vector_hnadler                /* NMI Fault */
.word _vector_hnadler                /* Bus Fault */
.word _vector_hnadler                /* Usage Fault */
.word _vector_hnadler                /* RESERVERD */
.word _vector_hnadler                /* RESERVERD */
.word _vector_hnadler                /* RESERVERD */
.word _vector_hnadler                /* RESERVERD */
.word _vector_hnadler                /* SV call */
.word _vector_hnadler                /* Debug RESERVERD */
.word _vector_hnadler                /* bendSV */
.word _vector_hnadler                /* sysTick */
.word _vector_hnadler                /* IRQ0 */
.word _vector_hnadler                /* IRQ1 */
.word _vector_hnadler                /* IRQ2 */
.word _vector_hnadler                /* IRQ3 */



/*Vetctor section */
.section .text
_reset :
    bl main
    b .                 /* loop on yourself */
.thumb_func
_vector_hnadler :
    b _reset
