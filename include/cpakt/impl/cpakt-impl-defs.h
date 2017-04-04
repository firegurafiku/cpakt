#ifndef CPAKT_IMPL_DEFS_H_
#define CPAKT_IMPL_DEFS_H_ 

/*  Make C++ compatibility a bit less painful by declaring helper macros.
    They're to be used instead of the #ifdef-#endif spells at the top and bottom
    of each header file which is supposed to be included by C++ compiler. */
#ifdef __cplusplus
    #define CPAKT_EXTERN_C  extern "C"
#else
    #define CPAKT_EXTERN_C
#endif

/* TODO: Determine longest available int type. */

#endif
