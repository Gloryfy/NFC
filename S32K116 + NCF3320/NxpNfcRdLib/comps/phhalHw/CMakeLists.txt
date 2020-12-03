

PROJECT(NxpRdLib_halHw)

FILE(GLOB NxpRdLib_halHw_Sources
    ./src/phhalHw.c
    ./src/DUT/phhalHw_DUT.c
    ./src/DUT/phhalHw_DUT.h
    ./src/DUT/phhalHw_DUT_CL.c
    ./src/DUT/phhalHw_DUT_Int.c
    ./src/DUT/phhalHw_DUT_Int.h
    ./src/Ncx3330/phhalHw_Ncx3330.c
    ./src/Ncx3330/phhalHw_Ncx3330.h
    ./src/Ncx3330/phhalHw_Ncx3330_Instr.c
    ./src/Ncx3330/phhalHw_Ncx3330_Int.c
    ./src/Ncx3330/phhalHw_Ncx3330_Int.h
    ./src/Ncx3330/phhalHw_Ncx3330_Wait.c
    ./src/Ncx3330/phhalHw_Ncx3330_Wait.h
    ./src/PN7462AU/phhalHw_PN7462AU.c
    ./src/PN7462AU/phhalHw_PN7462AU.h
    ./src/PN7462AU/phhalHw_PN7462AU_Int.c
    ./src/PN7462AU/phhalHw_PN7462AU_Int.h
    ./src/Ncx3320/phhalHw_Ncx3320.c
    ./src/Ncx3320/phhalHw_Ncx3320.h
    ./src/Ncx3320/phhalHw_Ncx3320_Cmd.c
    ./src/Ncx3320/phhalHw_Ncx3320_Config.h
    ./src/Ncx3320/phhalHw_Ncx3320_Int.c
    ./src/Ncx3320/phhalHw_Ncx3320_Int.h
    ./src/Ncx3320/phhalHw_Ncx3320_Wait.c
)

ADD_LIBRARY(NxpRdLib_halHw
    ${NxpRdLib_halHw_Sources}
)


TARGET_LINK_LIBRARIES(
    NxpRdLib_halHw
    NxpRdLib_phTools
    phOsal
    NxpRdLib_KeyStore
#    NxpRdLib_balReg
    DAL
)
