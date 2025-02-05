/*
 * stn32f103xx_drivers_gpio.h
 *
 *  Created on: Feb 2, 2025
 *      Author: sohai
 */

#ifndef INC_STN32F103XX_DRIVERS_GPIO_H_
#define INC_STN32F103XX_DRIVERS_GPIO_H_

#include "stm32f103xx.h"

/*
    *@GPIO_PinNumber
    *GPIO Pin possibl modes
*/
#define GPIO_PIN_NO_0                   0            
#define GPIO_PIN_NO_1                   1            
#define GPIO_PIN_NO_2                   2            
#define GPIO_PIN_NO_3                   3            
#define GPIO_PIN_NO_4                   4            
#define GPIO_PIN_NO_5                   5            
#define GPIO_PIN_NO_6                   6            
#define GPIO_PIN_NO_7                   7            
#define GPIO_PIN_NO_8                   8            
#define GPIO_PIN_NO_9                   9            
#define GPIO_PIN_NO_10                  10            
#define GPIO_PIN_NO_11                  11            
#define GPIO_PIN_NO_12                  12           
#define GPIO_PIN_NO_13                  13         
#define GPIO_PIN_NO_14                  14         
#define GPIO_PIN_NO_15                  15         
/*
    *@GPIO_PinMode
    *GPIO Pin possibl modes
*/
//GPIO Output modes
#define GPIO_Mode_OUT_PP                (0 << 2)
#define GPIO_Mode_OUT_OD                (1 << 2)
#define GPIO_Mode_AF_PP                 (2 << 2)
#define GPIO_Mode_AF_OD                 (3 << 2)

/*GPIO Input Modes*/

#define GPIO_Mode_IN_FLOATING           (1 << 2)
#define GPIO_Mode_IN_PU_PD              (2 << 2)

/*GPIO Alternate Function Modes*/
/*GPIO Pin possibl Output speed*/

#define GPIO_Speed_LOW                   1
#define GPIO_Speed_MED                   2
#define GPIO_Speed_HIGH                  3

/*GPIO Internal Pull-up and Pull-down Config  00*/
#define GPIO_PD                          0
#define GPIO_PU                          1
/**GPIO possibl Output Types*/
typedef struct
{
    uint8_t GPIO_PinNumber;
    uint8_t GPIO_PinMode;
    uint8_t GPIO_PinSpeed;
    uint8_t GPIO_PinPuPd;
    uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

typedef struct
{
    GPIO_RegDef_t *pGPIOx;
    GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;


/***********************************************************************************************
 *                                  APIs Supported by this driver
 *                      For more INFO about this APIs check the function definition  
 * **********************************************************************************************/

/*
 * Peripheral clock setup
*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);

/*
 * GPIO Init and DeInit
 */
void GPIO_Init(GPIO_Handle_t *pHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * GPIO Read Write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_ReadFromOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO, uint8_t value);
void GPIO_ReadFromOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO);
void GPIO_SetOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO);
void GPIO_ResetOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO);

/*
    GPIO IRQ Config and ISR handling
*/
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);


#endif /* INC_STN32F103XX_DRIVERS_GPIO_H_ */