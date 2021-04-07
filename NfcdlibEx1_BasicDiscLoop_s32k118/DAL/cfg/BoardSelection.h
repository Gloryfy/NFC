/*
*         Copyright (c), NXP Semiconductors Bangalore / India
*
*                     (C)NXP Semiconductors
*       All rights are reserved. Reproduction in whole or in part is
*      prohibited without the written consent of the copyright owner.
*  NXP reserves the right to make changes without notice at any time.
* NXP makes no warranty, expressed, implied or statutory, including but
* not limited to any implied warranty of merchantability or fitness for any
*particular purpose, or that the use will not infringe any third party patent,
* copyright or trademark. NXP must not be liable for any loss or damage
*                          arising from its use.
*/

/** \file
* Generic phDriver Component of Reader Library Framework.
* $Author$
* $Revision$
* $Date$
*
* History:
*  RS: Generated 24. Jan 2017
*
*/

#ifndef BOARDSELECTION_H
#define BOARDSELECTION_H

/* Select one of the boards through defined symbols (-D).
 * Board Header files. */

#ifdef PHDRIVER_LPC1769NCx3330_BOARD
#    include <Board_Lpc1769Ncx3330.h>
#endif

#ifdef PHDRIVER_PINCx3330_BOARD
#    include <Board_PiNcx3330.h>
#endif

#ifdef PHDRIVER_FRDM_K82FNCx3330_BOARD
#    include <Board_FRDM_K82FNcx3330.h>
#endif

#ifdef PHDRIVER_LPC1769NCx3320_BOARD
#    include <Board_Lpc1769Ncx3320.h>
#endif

#ifdef PHDRIVER_FRDM_K82FNCx3320_BOARD
#    include <Board_FRDM_K82FNcx3320.h>
#endif

#ifdef PHDRIVER_PINCx3320_BOARD
#    include <Board_PiNcx3320.h>
#endif

#ifdef PHDRIVER_FRDM_S32K144NCx3320_BOARD
#	include <Board_FRDM_S32K144Ncx3320.h>
#endif

#ifdef PHDRIVER_FRDM_S32K118NCx3320_BOARD
#	include <Board_FRDM_S32K118Ncx3320.h>
#endif
#endif /* BOARDSELECTION_H */

