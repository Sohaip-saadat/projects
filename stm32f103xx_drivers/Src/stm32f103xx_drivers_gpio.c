/*
 * stm32f103xx_drivers_gpio.c
 *
 *  Created on: Feb 2, 2025
 *      Author: sohai
 */


#include "Inc/stm32f103xx_drivers_gpio.h"

/*********************************************************************************
 * @fn              - GPIO_PeriClockControl
 * @brief           - This function Enable or Disable for the given GPIO port
 * @param[in]       - Base address of the GPIO peripheral
 * @param[in]       - Enable or Disable macros
 * @return          - None
 * @note            - None
 *
 *
 *********************************************************************************/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t ENoDI)
{
    if(ENoDI == ENABLE)
    {
    if (pGPIOx == GPIOA)
    {
        GPIOA_PHCLK_EN();
    }
    else if (pGPIOx == GPIOB)
    {
        GPIOB_PHCLK_EN();
    }
    else if (pGPIOx == GPIOC)
    {
    	GPIOC_PHCLK_EN();
    }
    else if (pGPIOx == GPIOD)
    {
        GPIOD_PHCLK_EN();
    }
    else if (pGPIOx == GPIOE)
    {
    	GPIOE_PHCLK_EN();
    }
    else if (pGPIOx == GPIOF)
    {
    	GPIOF_PHCLK_EN();
    }
    else if (pGPIOx == GPIOG)
    {
    	GPIOG_PHCLK_EN();
    }
    }
    else
    {
        //code
    }


}

/**************************************************************************************************
 * @fn              - GPIO_Init
 * @brief           - This function initializes the GPIO pin(s) for a given GPIO port
 * @param[in]       - Pointer to GPIO_Handle_t structure that contains:
 *                      - Base address of the GPIO port
 *                      - GPIO pin configuration settings (mode, speed, pull-up/pull-down, etc.)
 * @return          - None
 * @note            - This function configures both input and output modes, 
 *                    including alternate functions and pull-up/pull-down settings.
 *                  - Make sure to enable the GPIO peripheral clock before calling this function.
 *****************************************************************************************************/
void GPIO_Init(GPIO_Handle_t *pHandle)
{
    uint32_t temp = 0;
    if (pHandle->GPIO_PinConfig.GPIO_PinNumber > 7)
    {
        if (pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_OUT_PP | pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_OUT_OD)
        {
            temp = ((pHandle->GPIO_PinConfig.GPIO_PinMode | pHandle->GPIO_PinConfig.GPIO_PinSpeed)<< (4 * pHandle->GPIO_PinConfig.GPIO_PinNumber - 8));
            pHandle->pGPIOx->CRH &= ~(0xF << (4 * pHandle->GPIO_PinConfig.GPIO_PinNumber - 8));
            pHandle->pGPIOx->CRH |= temp;
            temp = 0;
        }
        else if (pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IN_FLOATING | pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IN_PU_PD )
        {
            temp = (pHandle->GPIO_PinConfig.GPIO_PinMode << (4 * pHandle->GPIO_PinConfig.GPIO_PinNumber - 8));
            pHandle->pGPIOx->CRH &= ~(0xF << (4 * pHandle->GPIO_PinConfig.GPIO_PinNumber - 8));
            pHandle->pGPIOx->CRH |= temp;
            temp = 0;
            if (pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IN_PU_PD)
            {
                temp = (pHandle->GPIO_PinConfig.GPIO_PinPuPd << (4* pHandle->GPIO_PinConfig.GPIO_PinNumber));
                pHandle->pGPIOx->ODR |= temp;
                temp = 0;
            }
        }
       
    }
    else
    {
        if (pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_OUT_PP | pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_OUT_OD)
        {
            temp = ((pHandle->GPIO_PinConfig.GPIO_PinMode | pHandle->GPIO_PinConfig.GPIO_PinSpeed)<< (4 * pHandle->GPIO_PinConfig.GPIO_PinNumber));
            pHandle->pGPIOx->CRL &= ~(0xF << (4 * pHandle->GPIO_PinConfig.GPIO_PinNumber));
            pHandle->pGPIOx->CRL |= temp;
            temp = 0;
        }
        else if (pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IN_FLOATING | pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IN_PU_PD)
        {
            temp = (pHandle->GPIO_PinConfig.GPIO_PinMode << (4 * pHandle->GPIO_PinConfig.GPIO_PinNumber));
            pHandle->pGPIOx->CRL &= ~(0xF << (4 * pHandle->GPIO_PinConfig.GPIO_PinNumber));
            pHandle->pGPIOx->CRL |= temp;
            temp = 0;
            if (pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_IN_PU_PD)
            {
                temp = (pHandle->GPIO_PinConfig.GPIO_PinPuPd << (4* pHandle->GPIO_PinConfig.GPIO_PinNumber));
                pHandle->pGPIOx->ODR |= temp;
                temp = 0;
            }
        }
    }    
    if (pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_AF_OD | pHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_Mode_AF_PP)
    {
        //CODE
    }
    
}

/************************************************************************
 * @fn              - GPIO_DeInit
 * @brief           - This function resets the given GPIO port to its default state.
 * @param[in]       - Base address of the GPIO peripheral (e.g., GPIOA, GPIOB, etc.)
 * @return          - None
 * @note            - This uses the APB2 peripheral reset register (RCC->APB2RSTR).
 *
 ************************************************************************/
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
    if (pGPIOx == GPIOA)
    {
        GPIOA_REG_RESET();
    }
    else if (pGPIOx == GPIOB)
    {
        GPIOB_REG_RESET();
    }
    else if (pGPIOx == GPIOC)
    {
        GPIOC_REG_RESET();
    }
    else if (pGPIOx == GPIOD)
    {
        GPIOD_REG_RESET();
    }
    else if (pGPIOx == GPIOE)
    {
        GPIOE_REG_RESET();
    }
    else if (pGPIOx == GPIOF)
    {
        GPIOF_REG_RESET();
    }
    else if (pGPIOx == GPIOG)
    {
        GPIOG_REG_RESET();
    }
}

/************************************************************************
 * @fn              - GPIO_ReadFromInputPin
 * @brief           - This function reads the value of a specific GPIO input pin.
 * @param[in]       - Base address of the GPIO peripheral (pGPIOx)
 * @param[in]       - Pin number to be read (pinNO)
 * @return          - 0 or 1 (Low or High state of the pin)
 * @note            - Ensure the pin is configured as input before calling this function.
 ************************************************************************/

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO)
{
    uint8_t value;
    value = (uint8_t) (pGPIOx->IDR >> pinNO ) & 0x00000001;
    return value;
}


/************************************************************************
 * @fn              - GPIO_ReadFromInputPort
 * @brief           - This function reads data from the input port for the given GPIO port
 * @param[in]       - Base address of the GPIO peripheral
 * @return          - 16-bit value representing the input port state
 * @note            - Make sure the GPIO port is configured as input before calling this function
 *
 ************************************************************************/
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
    uint16_t value;
    value = (uint16_t) pGPIOx->IDR;
    return value;
}


/************************************************************************
 * @fn              - GPIO_WriteToOutputPin
 * @brief           - This function writes a value (SET or RESET) to a specific GPIO pin.
 * @param[in]       - Base address of the GPIO peripheral (pGPIOx)
 * @param[in]       - Pin number (pinNO) to which the value needs to be written
 * @param[in]       - Value to write (SET or RESET)
 * @return          - None
 * @note            - Ensure the GPIO pin is configured as output before calling this function
 ************************************************************************/
void GPIO_ReadFromOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO, uint8_t value)
{
    if(value == SET)
    {
        pGPIOx->ODR |= (1 << pinNO);
    }
    else
    {
        pGPIOx->ODR &= ~(1 << pinNO);
    }
}

/************************************************************************
 * @fn              - GPIO_WriteToOutputPort
 * @brief           - This function writes a 16-bit value to the output data 
 *                    register (ODR) of the given GPIO port.
 * @param[in]       - Base address of the GPIO peripheral (e.g., GPIOA, GPIOB, etc.)
 * @param[in]       - 16-bit value to write to the ODR
 * @return          - None
 * @note            - Ensure that the GPIO pins are configured in output mode
 *                    before calling this function.
 ************************************************************************/
void GPIO_ReadFromOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t value)
{
    pGPIOx->ODR = value;
}

/************************************************************************
 * @fn              - GPIO_ToggleOutputPin
 * @brief           - This function toggles the output state of a given GPIO pin
 * @param[in]       - pGPIOx: Base address of the GPIO peripheral (GPIOA, GPIOB, etc.)
 * @param[in]       - pinNO: The pin number to toggle (0-15)
 * @return          - None
 * @note            - This function uses the ODR (Output Data Register) of the GPIO peripheral
 *
 *************************************************************************/
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO)
{
    pGPIOx->ODR ^= (1 << pinNO);
}

/************************************************************************
 * @fn              - GPIO_SetOutputPin
 * @brief           - This function sets the given GPIO pin to a high state
 * @param[in]       - pGPIOx: Base address of the GPIO peripheral (e.g., GPIOA, GPIOB)
 * @param[in]       - pinNO: Pin number (0-15) to be set high
 * @return          - None
 * @note            - This function assumes the pin mode is already configured as output.
 *
 *
 **************************************************************************/
void GPIO_SetOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO)
{
    pGPIOx->ODR |= (1 << pinNO);
}




/************************************************************************
 * @fn              - GPIO_ResetOutputPin
 * @brief           - This function resets (sets to low) the given GPIO pin
 * @param[in]       - Base address of the GPIO peripheral
 * @param[in]       - The pin number to reset (0 to 15)
 * @return          - None
 * @note            - None
 *
 *************************************************************************/
void GPIO_ResetOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t pinNO)
{
    pGPIOx->ODR &= ~(1 << pinNO);
}
