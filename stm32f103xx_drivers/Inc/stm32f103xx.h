/*
 * stn32f103xx.h
 *
 *  Created on: Jan 29, 2025
 *      Author: sohai
 */

#ifndef INC_STN32F103XX_H_
#define INC_STN32F103XX_H_

#include <stdint.h>

#define __vo volatile
/* Base address of Flash and SRAM */

#define FLASH_BASE_ADDR               0x08000000U 
#define SRAM_BASE_ADDR                0x20000000U
#define ROM_BASE_ADDR                 0x1FFFF000U


/* AHBx, APB1x, APB2 Base addresses */

#define PERIPH_BASE_ADDR              0x40000000U
#define APB1_BASE_ADDR                PERIPH_BASE_ADDR
#define APB2_BASE_ADDR                0x40010000U
#define AHB_BASE_ADDR                 0x40018000U


/*Base Addresses of peripheral hanginig on APB2*/

/*GPIO's peripheral Base addresses*/
#define GPIOA_BASE_ADDR               (APB2_BASE_ADDR + 0x0800)
#define GPIOB_BASE_ADDR               (APB2_BASE_ADDR + 0x0C00)
#define GPIOC_BASE_ADDR               (APB2_BASE_ADDR + 0x1000)
#define GPIOD_BASE_ADDR               (APB2_BASE_ADDR + 0x1400)
#define GPIOE_BASE_ADDR               (APB2_BASE_ADDR + 0x1800)
#define GPIOF_BASE_ADDR               (APB2_BASE_ADDR + 0x1C00)
#define GPIOG_BASE_ADDR               (APB2_BASE_ADDR + 0x2000)

/*TIMER's peripheral Base addresses */
#define TIM1_BASE_ADDR                (APB2_BASE_ADDR + 0x2C00)
#define TIM8_BASE_ADDR                (APB2_BASE_ADDR + 0x3400)
#define TIM9_BASE_ADDR                (APB2_BASE_ADDR + 0x4C00)
#define TIM10_BASE_ADDR               (APB2_BASE_ADDR + 0x5000)
#define TIM11_BASE_ADDR               (APB2_BASE_ADDR + 0x5400)


/*USART1 peripheral Base address*/

#define USART1_BASE_ADDR              (APB2_BASE_ADDR + 0x3800)

/*SPI1 peripheral Base address*/

#define SPI1_BASE_ADDR                (APB2_BASE_ADDR + 0x3000)

/*EXTI peripheral Base address*/

#define EXTI_BASE_ADDR                (APB2_BASE_ADDR + 0x0400)

/*AFIO peripheral Base address*/

#define AFIO_BASE_ADDR               APB2_BASE_ADDR


/*Base Addresses of peripheral hanginig on APB1*/

/*TIMER's peripheral Base addresses */
#define TIM2_BASE_ADDR                APB1_BASE_ADDR
#define TIM3_BASE_ADDR                (APB1_BASE_ADDR + 0x0400)
#define TIM4_BASE_ADDR                (APB1_BASE_ADDR + 0x0800)
#define TIM5_BASE_ADDR                (APB1_BASE_ADDR + 0x0C00)
#define TIM6_BASE_ADDR                (APB1_BASE_ADDR + 0x1000)
#define TIM7_BASE_ADDR                (APB1_BASE_ADDR + 0x1400)
#define TIM12_BASE_ADDR               (APB1_BASE_ADDR + 0x1800)
#define TIM13_BASE_ADDR               (APB1_BASE_ADDR + 0x1C00)
#define TIM14_BASE_ADDR               (APB1_BASE_ADDR + 0x2000)

/*SPI1 peripheral Base address*/

#define SPI2_I2S_BASE_ADDR            (APB1_BASE_ADDR + 0x3800)
#define SPI3_I2S_BASE_ADDR            (APB1_BASE_ADDR + 0x3C00)


/*USART's peripheral Base address*/

#define USART2_BASE_ADDR              (APB1_BASE_ADDR + 0x4400)
#define USART3_BASE_ADDR              (APB1_BASE_ADDR + 0x4800) 
#define UART4                         (APB1_BASE_ADDR + 0x4C00)
#define UART5                         (APB1_BASE_ADDR + 0x5000)


/*I2c peripheral Base address*/

#define I2C1_BASE_ADDR                (APB1_BASE_ADDR + 0x5400)
#define I2C2_BASE_ADDR                (APB1_BASE_ADDR + 0x5800)


/*Base Addresses of peripheral hanginig on AHB*/
/*RCC Base Addresses*/

#define RCC_BASE_ADDR                 (AHB_BASE_ADDR + 0x9000)




/************************************** Peripheral Register Defenation *****************************************/

/*GPIO Peripheral Register Defenation*/
typedef struct
{
    __vo uint32_t CRL;
    __vo uint32_t CRH;
    __vo uint32_t IDR;
    __vo uint32_t ODR;
    __vo uint32_t BSRR;
    __vo uint32_t BRR;
    __vo uint32_t LCKR;

}GPIO_RegDef_t;


/*RCC Peripheral Register Defenation*/

typedef struct
{
    __vo uint32_t CR;
    __vo uint32_t CFGR;
    __vo uint32_t CIR;
    __vo uint32_t APB2RSTR;
    __vo uint32_t APB1RSTR;
    __vo uint32_t AHBENR;
    __vo uint32_t APB2ENR;
    __vo uint32_t APB1ENR;
    __vo uint32_t BDCR;
    __vo uint32_t CSR;
}RCC_RegDef_t;
/* Peripheral Defenation (Peripheral base addresses typrcasting to xxx RegDef) */

/*GPIO Peripheral base addresses typrcasting to xxx RegDef*/
#define GPIOA                           ((GPIO_RegDef_t *)GPIOA_BASE_ADDR)
#define GPIOB                           ((GPIO_RegDef_t *)GPIOB_BASE_ADDR)
#define GPIOC                           ((GPIO_RegDef_t *)GPIOC_BASE_ADDR)
#define GPIOD                           ((GPIO_RegDef_t *)GPIOD_BASE_ADDR)
#define GPIOE                           ((GPIO_RegDef_t *)GPIOE_BASE_ADDR)
#define GPIOF                           ((GPIO_RegDef_t *)GPIOF_BASE_ADDR)
#define GPIOG                           ((GPIO_RegDef_t *)GPIOG_BASE_ADDR)

/*RCC Peripheral base addresses typrcasting to xxx RegDef*/
#define RCC                             ((RCC_RegDef_t *)RCC_BASE_ADDR)


/*Clock Enable macros fo GPIOx Peripheral*/
#define GPIOA_PHCLK_EN()                (RCC->APB2ENR |=(1 << 2))
#define GPIOB_PHCLK_EN()                (RCC->APB2ENR |=(1 << 3))
#define GPIOC_PHCLK_EN()                (RCC->APB2ENR |=(1 << 4))
#define GPIOD_PHCLK_EN()                (RCC->APB2ENR |=(1 << 5))
#define GPIOE_PHCLK_EN()                (RCC->APB2ENR |=(1 << 6))
#define GPIOF_PHCLK_EN()                (RCC->APB2ENR |=(1 << 7))
#define GPIOG_PHCLK_EN()                (RCC->APB2ENR |=(1 << 8))

#define GPIOA_REG_RESET()               do{(RCC->APB2RSTR |= (1 << 2)); (RCC->APB2RSTR &= ~(1 << 2));}while(0)
#define GPIOB_REG_RESET()               do{(RCC->APB2RSTR |= (1 << 3)); (RCC->APB2RSTR &= ~(1 << 3));}while(0)
#define GPIOC_REG_RESET()               do{(RCC->APB2RSTR |= (1 << 4)); (RCC->APB2RSTR &= ~(1 << 4));}while(0)
#define GPIOD_REG_RESET()               do{(RCC->APB2RSTR |= (1 << 5)); (RCC->APB2RSTR &= ~(1 << 5));}while(0)
#define GPIOE_REG_RESET()               do{(RCC->APB2RSTR |= (1 << 6)); (RCC->APB2RSTR &= ~(1 << 6));}while(0)
#define GPIOF_REG_RESET()               do{(RCC->APB2RSTR |= (1 << 7)); (RCC->APB2RSTR &= ~(1 << 7));}while(0)
#define GPIOG_REG_RESET()               do{(RCC->APB2RSTR |= (1 << 8)); (RCC->APB2RSTR &= ~(1 << 8));}while(0)
/* Gerneric macros */

#define ENABLE                          1
#define DISABLE                         0
#define SET                             ENABLE
#define RESET                           DISABLE
#include "stm32f103xx_drivers_gpio.h"
#endif /* INC_STN32F103XX_H_ */
