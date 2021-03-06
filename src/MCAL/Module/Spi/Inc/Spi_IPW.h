/**
*   @file    Spi_IPW.h
*   @version 1.0.1
*
*   @brief   AUTOSAR Spi - Spi middle level driver header file.
*   @details This file is the header containing all the necessary information for SPI
*            LLD.
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.0 MCAL
*   Platform             : PA
*   Peripheral           : DSPI
*   Dependencies         : 
*
*   Autosar Version      : 4.0.3
*   Autosar Revision     : ASR_REL_4_0_REV_0003
*   Autosar Conf.Variant :
*   SW Version           : 1.0.1
*   Build Version        : MPC5777C_MCAL_1_0_1_RTM_ASR_REL_4_0_REV_0003_20170519
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
*   All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef SPI_IPW_H
#define SPI_IPW_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_IPW_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Spi_IPW_h_REF_2
* Violates MISRA 2004 Required Rule 19.4,
* C macros shall only expand to a braced initialiser, a constant, a string literal, a parenthesised expression,
* a type qualifier, a storage class specifier, or a do-while-zero construct.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi_DSPI.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_MODULE_ID                       83
#define SPI_IPW_VENDOR_ID                       43
#define SPI_IPW_AR_RELEASE_MAJOR_VERSION        4
#define SPI_IPW_AR_RELEASE_MINOR_VERSION        0
#define SPI_IPW_AR_RELEASE_REVISION_VERSION     3
#define SPI_IPW_SW_MAJOR_VERSION                1
#define SPI_IPW_SW_MINOR_VERSION                0
#define SPI_IPW_SW_PATCH_VERSION                1

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_IPW_VENDOR_ID != SPI_VENDOR_ID_DSPI)
    #error "Spi_IPW.h and Spi_DSPI.h have different vendor ids"
#endif

#if (( SPI_IPW_AR_RELEASE_MAJOR_VERSION    != SPI_AR_RELEASE_MAJOR_VERSION_DSPI) || \
     ( SPI_IPW_AR_RELEASE_MINOR_VERSION    != SPI_AR_RELEASE_MINOR_VERSION_DSPI) || \
     ( SPI_IPW_AR_RELEASE_REVISION_VERSION != SPI_AR_RELEASE_REVISION_VERSION_DSPI))
#error "AutoSar Version Numbers of Spi_DSPI.h and Spi_IPW.h are different"
#endif

#if (( SPI_IPW_SW_MAJOR_VERSION != SPI_SW_MAJOR_VERSION_DSPI) || \
     ( SPI_IPW_SW_MINOR_VERSION != SPI_SW_MINOR_VERSION_DSPI) || \
     ( SPI_IPW_SW_PATCH_VERSION != SPI_SW_PATCH_VERSION_DSPI))
#error "Software Version Numbers of Spi_IPW.h and Spi_DSPI.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_Init(HWUnit, pStatus) \
        (Spi_Dspi_Init((HWUnit), (pStatus)))

/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_DeInit(HWUnit) \
        (Spi_Dspi_DeInit((HWUnit)))

#if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_PrepareCacheInformation() \
        (Spi_Dspi_PrepareCacheInformation())
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define  Spi_Ipw_SyncTransmit(Sequence) \
        (Spi_Dspi_SyncTransmit((Sequence)))
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_SyncTransmit_Fast(pcSequence) \
        (Spi_Dspi_SyncTransmit_Fast((pcSequence)))
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_JobTransfer(pcJobConfig) \
        (Spi_Dspi_JobTransfer((pcJobConfig)))
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_IrqConfig(HWUnit, AsyncMode) \
        (Spi_Dspi_IrqConfig((HWUnit), (AsyncMode)))
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_IrqPoll(HWUnit) \
        (Spi_Dspi_IrqPoll((HWUnit)))
#endif

#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_SlaveCancel(Sequence) \
        (Spi_Dspi_SlaveCancel((Sequence)))
#endif

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_SetTSBMode(TSBJob) \
        (Spi_Dspi_SetTSBMode((TSBJob)))

/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_StopTSBMode(TSBJob) \
        (Spi_Dspi_StopTSBMode((TSBJob)))

/*
* @violates @ref Spi_IPW_h_REF_1 A function should be used in preference to a function-like macro.
*/
#define Spi_Ipw_TSB_ASDR_DataUpdate(TSBJob, ASDR_Data) \
        (Spi_Dspi_TSB_ASDR_DataUpdate((TSBJob), (ASDR_Data)))

#endif /*(SPI_TSB_MODE == STD_ON)*/
#endif /*TSB_MODE_SUPPORTED*/

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/*
* @violates @ref Spi_IPW_h_REF_2 C macros shall only expand to a braced initialiser, a constant, a string literal,
* a parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define Spi_Ipw_apOneJobSeqsOptimized Spi_Dspi_apOneJobSeqsOptimized
#endif /*SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON*/

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/*
* @violates @ref Spi_IPW_h_REF_2 C macros shall only expand to a braced initialiser, a constant, a string literal,
* a parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct.
*/
#define SPI_IPW_SET_CLOCK_MODE DSPI_SET_CLOCK_MODE
#endif /*SPI_DUAL_CLOCK_MODE == STD_ON*/
/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
typedef Spi_Dspi_SequenceCacheAttrsType Spi_HW_SequenceCacheAttrsType;
#endif /*SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SPI_IPW_H*/

/** @} */
