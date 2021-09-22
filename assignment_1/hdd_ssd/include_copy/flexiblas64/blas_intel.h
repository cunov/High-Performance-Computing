#ifndef BLAS_H
#define BLAS_H

#include <stdint.h>

#include "fortran_mangle.h"
#include <complex.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(USE_BLAS_32) && defined(USE_BLAS_64)
#error Either USE_BLAS_32 or USE_BLAS_64 must be defined!
#endif

#ifndef blasint 
#define blasint int
#define CAXPY    caxpy_  
#define CCOPY    ccopy_  
#define CDOTC    cdotc_  
#define CDOTU    cdotu_  
#define CGBMV    cgbmv_  
#define CGEMM    cgemm_  
#define CGEMV    cgemv_  
#define CGERC    cgerc_  
#define CGERU    cgeru_  
#define CHBMV    chbmv_  
#define CHEMM    chemm_  
#define CHEMV    chemv_  
#define CHER     cher_   
#define CHER2    cher2_  
#define CHER2K   cher2k_ 
#define CHERK    cherk_  
#define CHPMV    chpmv_  
#define CHPR     chpr_   
#define CHPR2    chpr2_  
#define CROTG    crotg_  
#define CSCAL    cscal_  
#define CSROT    csrot_  
#define CSSCAL   csscal_ 
#define CSWAP    cswap_  
#define CSYMM    csymm_  
#define CSYR2K   csyr2k_ 
#define CSYRK    csyrk_  
#define CTBMV    ctbmv_  
#define CTBSV    ctbsv_  
#define CTPMV    ctpmv_  
#define CTPSV    ctpsv_  
#define CTRMM    ctrmm_  
#define CTRMV    ctrmv_  
#define CTRSM    ctrsm_  
#define CTRSV    ctrsv_  
#define DASUM    dasum_  
#define DAXPY    daxpy_  
#define DCOPY    dcopy_  
#define DDOT     ddot_   
#define DGBMV    dgbmv_  
#define DGEMM    dgemm_  
#define DGEMV    dgemv_  
#define DGER     dger_   
#define DNRM2    dnrm2_  
#define DROT     drot_   
#define DROTG    drotg_  
#define DROTM    drotm_  
#define DROTMG   drotmg_ 
#define DSBMV    dsbmv_  
#define DSCAL    dscal_  
#define DSDOT    dsdot_  
#define DSPMV    dspmv_  
#define DSPR     dspr_   
#define DSPR2    dspr2_  
#define DSWAP    dswap_  
#define DSYMM    dsymm_  
#define DSYMV    dsymv_  
#define DSYR     dsyr_   
#define DSYR2    dsyr2_  
#define DSYR2K   dsyr2k_ 
#define DSYRK    dsyrk_  
#define DTBMV    dtbmv_  
#define DTBSV    dtbsv_  
#define DTPMV    dtpmv_  
#define DTPSV    dtpsv_  
#define DTRMM    dtrmm_  
#define DTRMV    dtrmv_  
#define DTRSM    dtrsm_  
#define DTRSV    dtrsv_  
#define DZASUM   dzasum_ 
#define DZNRM2   dznrm2_ 
#define ICAMAX   icamax_ 
#define IDAMAX   idamax_ 
#define ISAMAX   isamax_ 
#define IZAMAX   izamax_ 
#define SASUM    sasum_  
#define SAXPY    saxpy_  
#define SCASUM   scasum_ 
#define SCNRM2   scnrm2_ 
#define SCOPY    scopy_  
#define SDOT     sdot_   
#define SDSDOT   sdsdot_ 
#define SGBMV    sgbmv_  
#define SGEMM    sgemm_  
#define SGEMV    sgemv_  
#define SGER     sger_   
#define SNRM2    snrm2_  
#define SROT     srot_   
#define SROTG    srotg_  
#define SROTM    srotm_  
#define SROTMG   srotmg_ 
#define SSBMV    ssbmv_  
#define SSCAL    sscal_  
#define SSPMV    sspmv_  
#define SSPR     sspr_   
#define SSPR2    sspr2_  
#define SSWAP    sswap_  
#define SSYMM    ssymm_  
#define SSYMV    ssymv_  
#define SSYR     ssyr_   
#define SSYR2    ssyr2_  
#define SSYR2K   ssyr2k_ 
#define SSYRK    ssyrk_  
#define STBMV    stbmv_  
#define STBSV    stbsv_  
#define STPMV    stpmv_  
#define STPSV    stpsv_  
#define STRMM    strmm_  
#define STRMV    strmv_  
#define STRSM    strsm_  
#define STRSV    strsv_  
#define ZAXPY    zaxpy_  
#define ZCOPY    zcopy_  
#define ZDOTC    zdotc_  
#define ZDOTU    zdotu_  
#define ZDROT    zdrot_  
#define ZDSCAL   zdscal_ 
#define ZGBMV    zgbmv_  
#define ZGEMM    zgemm_  
#define ZGEMV    zgemv_  
#define ZGERC    zgerc_  
#define ZGERU    zgeru_  
#define ZHBMV    zhbmv_  
#define ZHEMM    zhemm_  
#define ZHEMV    zhemv_  
#define ZHER     zher_   
#define ZHER2    zher2_  
#define ZHER2K   zher2k_ 
#define ZHERK    zherk_  
#define ZHPMV    zhpmv_  
#define ZHPR     zhpr_   
#define ZHPR2    zhpr2_  
#define ZROTG    zrotg_  
#define ZSCAL    zscal_  
#define ZSWAP    zswap_  
#define ZSYMM    zsymm_  
#define ZSYR2K   zsyr2k_ 
#define ZSYRK    zsyrk_  
#define ZTBMV    ztbmv_  
#define ZTBSV    ztbsv_  
#define ZTPMV    ztpmv_  
#define ZTPSV    ztpsv_  
#define ZTRMM    ztrmm_  
#define ZTRMV    ztrmv_  
#define ZTRSM    ztrsm_  
#define ZTRSV    ztrsv_  
#define CAXPBY   caxpby_ 
#define DAXPBY   daxpby_ 
#define ZAXPBY   zaxpby_ 
#define SAXPBY   saxpby_ 
#define COMATCOPY comatcopy_
#define ZOMATCOPY zomatcopy_
#define DOMATCOPY domatcopy_
#define SOMATCOPY somatcopy_
#define CIMATCOPY cimatcopy_
#define ZIMATCOPY zimatcopy_
#define DIMATCOPY dimatcopy_
#define SIMATCOPY simatcopy_
#define SGEADD   sgeadd_ 
#define DGEADD   dgeadd_ 
#define CGEADD   cgeadd_ 
#define ZGEADD   zgeadd_ 
#endif

void FC_GLOBAL(caxpy,CAXPY)(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cy, blasint* incy);

void FC_GLOBAL(ccopy,CCOPY)(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy);

void FC_GLOBAL(cdotc,CDOTC)( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy);

void FC_GLOBAL(cdotu,CDOTU)( float complex* returnvalue, blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy);

void FC_GLOBAL(cgbmv,CGBMV)(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy);

void FC_GLOBAL(cgemm,CGEMM)(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc);

void FC_GLOBAL(cgemv,CGEMV)(char* trans, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy);

void FC_GLOBAL(cgerc,CGERC)(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda);

void FC_GLOBAL(cgeru,CGERU)(blasint* m, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda);

void FC_GLOBAL(chbmv,CHBMV)(char* uplo, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy);

void FC_GLOBAL(chemm,CHEMM)(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc);

void FC_GLOBAL(chemv,CHEMV)(char* uplo, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy);

void FC_GLOBAL(cher,CHER)(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* a, blasint* lda);

void FC_GLOBAL(cher2,CHER2)(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* a, blasint* lda);

void FC_GLOBAL(cher2k,CHER2K)(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float* beta, float complex* c, blasint* ldc);

void FC_GLOBAL(cherk,CHERK)(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float complex* a, blasint* lda, float* beta, float complex* c, blasint* ldc);

void FC_GLOBAL(chpmv,CHPMV)(char* uplo, blasint* n, float complex* alpha, float complex* ap, float complex* x, blasint* incx, float complex* beta, float complex* y, blasint* incy);

void FC_GLOBAL(chpr,CHPR)(char* uplo, blasint* n, float* alpha, float complex* x, blasint* incx, float complex* ap);

void FC_GLOBAL(chpr2,CHPR2)(char* uplo, blasint* n, float complex* alpha, float complex* x, blasint* incx, float complex* y, blasint* incy, float complex* ap);

void FC_GLOBAL(crotg,CROTG)(float complex* ca, float complex* cb, float* c, float complex* s);

void FC_GLOBAL(cscal,CSCAL)(blasint* n, float complex* ca, float complex* cx, blasint* incx);

void FC_GLOBAL(csrot,CSROT)(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy, float* c, float* s);

void FC_GLOBAL(csscal,CSSCAL)(blasint* n, float* sa, float complex* cx, blasint* incx);

void FC_GLOBAL(cswap,CSWAP)(blasint* n, float complex* cx, blasint* incx, float complex* cy, blasint* incy);

void FC_GLOBAL(csymm,CSYMM)(char* side, char* uplo, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc);

void FC_GLOBAL(csyr2k,CSYR2K)(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb, float complex* beta, float complex* c, blasint* ldc);

void FC_GLOBAL(csyrk,CSYRK)(char* uplo, char* trans, blasint* n, blasint* k, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* c, blasint* ldc);

void FC_GLOBAL(ctbmv,CTBMV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx);

void FC_GLOBAL(ctbsv,CTBSV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float complex* a, blasint* lda, float complex* x, blasint* incx);

void FC_GLOBAL(ctpmv,CTPMV)(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx);

void FC_GLOBAL(ctpsv,CTPSV)(char* uplo, char* trans, char* diag, blasint* n, float complex* ap, float complex* x, blasint* incx);

void FC_GLOBAL(ctrmm,CTRMM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb);

void FC_GLOBAL(ctrmv,CTRMV)(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx);

void FC_GLOBAL(ctrsm,CTRSM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb);

void FC_GLOBAL(ctrsv,CTRSV)(char* uplo, char* trans, char* diag, blasint* n, float complex* a, blasint* lda, float complex* x, blasint* incx);

double FC_GLOBAL(dasum,DASUM)(blasint* n, double* dx, blasint* incx);

void FC_GLOBAL(daxpy,DAXPY)(blasint* n, double* da, double* dx, blasint* incx, double* dy, blasint* incy);

void FC_GLOBAL(dcopy,DCOPY)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy);

double FC_GLOBAL(ddot,DDOT)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy);

void FC_GLOBAL(dgbmv,DGBMV)(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy);

void FC_GLOBAL(dgemm,DGEMM)(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc);

void FC_GLOBAL(dgemv,DGEMV)(char* trans, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy);

void FC_GLOBAL(dger,DGER)(blasint* m, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda);

double FC_GLOBAL(dnrm2,DNRM2)(blasint* n, double* x, blasint* incx);

void FC_GLOBAL(drot,DROT)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* c, double* s);

void FC_GLOBAL(drotg,DROTG)(double* da, double* db, double* c, double* s);

void FC_GLOBAL(drotm,DROTM)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy, double* dparam);

void FC_GLOBAL(drotmg,DROTMG)(double* dd1, double* dd2, double* dx1, double* dy1, double* dparam);

void FC_GLOBAL(dsbmv,DSBMV)(char* uplo, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy);

void FC_GLOBAL(dscal,DSCAL)(blasint* n, double* da, double* dx, blasint* incx);

double FC_GLOBAL(dsdot,DSDOT)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy);

void FC_GLOBAL(dspmv,DSPMV)(char* uplo, blasint* n, double* alpha, double* ap, double* x, blasint* incx, double* beta, double* y, blasint* incy);

void FC_GLOBAL(dspr,DSPR)(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* ap);

void FC_GLOBAL(dspr2,DSPR2)(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* ap);

void FC_GLOBAL(dswap,DSWAP)(blasint* n, double* dx, blasint* incx, double* dy, blasint* incy);

void FC_GLOBAL(dsymm,DSYMM)(char* side, char* uplo, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc);

void FC_GLOBAL(dsymv,DSYMV)(char* uplo, blasint* n, double* alpha, double* a, blasint* lda, double* x, blasint* incx, double* beta, double* y, blasint* incy);

void FC_GLOBAL(dsyr,DSYR)(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* a, blasint* lda);

void FC_GLOBAL(dsyr2,DSYR2)(char* uplo, blasint* n, double* alpha, double* x, blasint* incx, double* y, blasint* incy, double* a, blasint* lda);

void FC_GLOBAL(dsyr2k,DSYR2K)(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* b, blasint* ldb, double* beta, double* c, blasint* ldc);

void FC_GLOBAL(dsyrk,DSYRK)(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double* a, blasint* lda, double* beta, double* c, blasint* ldc);

void FC_GLOBAL(dtbmv,DTBMV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx);

void FC_GLOBAL(dtbsv,DTBSV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double* a, blasint* lda, double* x, blasint* incx);

void FC_GLOBAL(dtpmv,DTPMV)(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx);

void FC_GLOBAL(dtpsv,DTPSV)(char* uplo, char* trans, char* diag, blasint* n, double* ap, double* x, blasint* incx);

void FC_GLOBAL(dtrmm,DTRMM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb);

void FC_GLOBAL(dtrmv,DTRMV)(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx);

void FC_GLOBAL(dtrsm,DTRSM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* b, blasint* ldb);

void FC_GLOBAL(dtrsv,DTRSV)(char* uplo, char* trans, char* diag, blasint* n, double* a, blasint* lda, double* x, blasint* incx);

double FC_GLOBAL(dzasum,DZASUM)(blasint* n, double complex* zx, blasint* incx);

double FC_GLOBAL(dznrm2,DZNRM2)(blasint* n, double complex* x, blasint* incx);

int FC_GLOBAL(icamax,ICAMAX)(blasint* n, float complex* cx, blasint* incx);

int FC_GLOBAL(idamax,IDAMAX)(blasint* n, double* dx, blasint* incx);

int FC_GLOBAL(isamax,ISAMAX)(blasint* n, float* sx, blasint* incx);

int FC_GLOBAL(izamax,IZAMAX)(blasint* n, double complex* zx, blasint* incx);

float FC_GLOBAL(sasum,SASUM)(blasint* n, float* sx, blasint* incx);

void FC_GLOBAL(saxpy,SAXPY)(blasint* n, float* sa, float* sx, blasint* incx, float* sy, blasint* incy);

float FC_GLOBAL(scasum,SCASUM)(blasint* n, float complex* cx, blasint* incx);

float FC_GLOBAL(scnrm2,SCNRM2)(blasint* n, float complex* x, blasint* incx);

void FC_GLOBAL(scopy,SCOPY)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy);

float FC_GLOBAL(sdot,SDOT)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy);

float FC_GLOBAL(sdsdot,SDSDOT)(blasint* n, float* sb, float* sx, blasint* incx, float* sy, blasint* incy);

void FC_GLOBAL(sgbmv,SGBMV)(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy);

void FC_GLOBAL(sgemm,SGEMM)(char* transa, char* transb, blasint* m, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc);

void FC_GLOBAL(sgemv,SGEMV)(char* trans, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy);

void FC_GLOBAL(sger,SGER)(blasint* m, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda);

float FC_GLOBAL(snrm2,SNRM2)(blasint* n, float* x, blasint* incx);

void FC_GLOBAL(srot,SROT)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* c, float* s);

void FC_GLOBAL(srotg,SROTG)(float* sa, float* sb, float* c, float* s);

void FC_GLOBAL(srotm,SROTM)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy, float* sparam);

void FC_GLOBAL(srotmg,SROTMG)(float* sd1, float* sd2, float* sx1, float* sy1, float* sparam);

void FC_GLOBAL(ssbmv,SSBMV)(char* uplo, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy);

void FC_GLOBAL(sscal,SSCAL)(blasint* n, float* sa, float* sx, blasint* incx);

void FC_GLOBAL(sspmv,SSPMV)(char* uplo, blasint* n, float* alpha, float* ap, float* x, blasint* incx, float* beta, float* y, blasint* incy);

void FC_GLOBAL(sspr,SSPR)(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* ap);

void FC_GLOBAL(sspr2,SSPR2)(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* ap);

void FC_GLOBAL(sswap,SSWAP)(blasint* n, float* sx, blasint* incx, float* sy, blasint* incy);

void FC_GLOBAL(ssymm,SSYMM)(char* side, char* uplo, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc);

void FC_GLOBAL(ssymv,SSYMV)(char* uplo, blasint* n, float* alpha, float* a, blasint* lda, float* x, blasint* incx, float* beta, float* y, blasint* incy);

void FC_GLOBAL(ssyr,SSYR)(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* a, blasint* lda);

void FC_GLOBAL(ssyr2,SSYR2)(char* uplo, blasint* n, float* alpha, float* x, blasint* incx, float* y, blasint* incy, float* a, blasint* lda);

void FC_GLOBAL(ssyr2k,SSYR2K)(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* b, blasint* ldb, float* beta, float* c, blasint* ldc);

void FC_GLOBAL(ssyrk,SSYRK)(char* uplo, char* trans, blasint* n, blasint* k, float* alpha, float* a, blasint* lda, float* beta, float* c, blasint* ldc);

void FC_GLOBAL(stbmv,STBMV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx);

void FC_GLOBAL(stbsv,STBSV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, float* a, blasint* lda, float* x, blasint* incx);

void FC_GLOBAL(stpmv,STPMV)(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx);

void FC_GLOBAL(stpsv,STPSV)(char* uplo, char* trans, char* diag, blasint* n, float* ap, float* x, blasint* incx);

void FC_GLOBAL(strmm,STRMM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb);

void FC_GLOBAL(strmv,STRMV)(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx);

void FC_GLOBAL(strsm,STRSM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* b, blasint* ldb);

void FC_GLOBAL(strsv,STRSV)(char* uplo, char* trans, char* diag, blasint* n, float* a, blasint* lda, float* x, blasint* incx);

void FC_GLOBAL(zaxpy,ZAXPY)(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zy, blasint* incy);

void FC_GLOBAL(zcopy,ZCOPY)(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy);

void FC_GLOBAL(zdotc,ZDOTC)( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy);

void FC_GLOBAL(zdotu,ZDOTU)( double complex* returnvalue, blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy);

void FC_GLOBAL(zdrot,ZDROT)(blasint* n, double complex* cx, blasint* incx, double complex* cy, blasint* incy, double* c, double* s);

void FC_GLOBAL(zdscal,ZDSCAL)(blasint* n, double* da, double complex* zx, blasint* incx);

void FC_GLOBAL(zgbmv,ZGBMV)(char* trans, blasint* m, blasint* n, blasint* kl, blasint* ku, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy);

void FC_GLOBAL(zgemm,ZGEMM)(char* transa, char* transb, blasint* m, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc);

void FC_GLOBAL(zgemv,ZGEMV)(char* trans, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy);

void FC_GLOBAL(zgerc,ZGERC)(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda);

void FC_GLOBAL(zgeru,ZGERU)(blasint* m, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda);

void FC_GLOBAL(zhbmv,ZHBMV)(char* uplo, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy);

void FC_GLOBAL(zhemm,ZHEMM)(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc);

void FC_GLOBAL(zhemv,ZHEMV)(char* uplo, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy);

void FC_GLOBAL(zher,ZHER)(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* a, blasint* lda);

void FC_GLOBAL(zher2,ZHER2)(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* a, blasint* lda);

void FC_GLOBAL(zher2k,ZHER2K)(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double* beta, double complex* c, blasint* ldc);

void FC_GLOBAL(zherk,ZHERK)(char* uplo, char* trans, blasint* n, blasint* k, double* alpha, double complex* a, blasint* lda, double* beta, double complex* c, blasint* ldc);

void FC_GLOBAL(zhpmv,ZHPMV)(char* uplo, blasint* n, double complex* alpha, double complex* ap, double complex* x, blasint* incx, double complex* beta, double complex* y, blasint* incy);

void FC_GLOBAL(zhpr,ZHPR)(char* uplo, blasint* n, double* alpha, double complex* x, blasint* incx, double complex* ap);

void FC_GLOBAL(zhpr2,ZHPR2)(char* uplo, blasint* n, double complex* alpha, double complex* x, blasint* incx, double complex* y, blasint* incy, double complex* ap);

void FC_GLOBAL(zrotg,ZROTG)(double complex* ca, double complex* cb, double* c, double complex* s);

void FC_GLOBAL(zscal,ZSCAL)(blasint* n, double complex* za, double complex* zx, blasint* incx);

void FC_GLOBAL(zswap,ZSWAP)(blasint* n, double complex* zx, blasint* incx, double complex* zy, blasint* incy);

void FC_GLOBAL(zsymm,ZSYMM)(char* side, char* uplo, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc);

void FC_GLOBAL(zsyr2k,ZSYR2K)(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb, double complex* beta, double complex* c, blasint* ldc);

void FC_GLOBAL(zsyrk,ZSYRK)(char* uplo, char* trans, blasint* n, blasint* k, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* c, blasint* ldc);

void FC_GLOBAL(ztbmv,ZTBMV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx);

void FC_GLOBAL(ztbsv,ZTBSV)(char* uplo, char* trans, char* diag, blasint* n, blasint* k, double complex* a, blasint* lda, double complex* x, blasint* incx);

void FC_GLOBAL(ztpmv,ZTPMV)(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx);

void FC_GLOBAL(ztpsv,ZTPSV)(char* uplo, char* trans, char* diag, blasint* n, double complex* ap, double complex* x, blasint* incx);

void FC_GLOBAL(ztrmm,ZTRMM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb);

void FC_GLOBAL(ztrmv,ZTRMV)(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx);

void FC_GLOBAL(ztrsm,ZTRSM)(char* side, char* uplo, char* transa, char* diag, blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb);

void FC_GLOBAL(ztrsv,ZTRSV)(char* uplo, char* trans, char* diag, blasint* n, double complex* a, blasint* lda, double complex* x, blasint* incx);

void FC_GLOBAL(caxpby,CAXPBY)(blasint* n, float complex* ca, float complex* cx, blasint* incx, float complex* cb, float complex* cy, blasint* incy);

void FC_GLOBAL(daxpby,DAXPBY)(blasint* n, double* da, double* dx, blasint* incx, double* db, double* dy, blasint* incy);

void FC_GLOBAL(zaxpby,ZAXPBY)(blasint* n, double complex* za, double complex* zx, blasint* incx, double complex* zb, double complex* zy, blasint* incy);

void FC_GLOBAL(saxpby,SAXPBY)(blasint* n, float* sa, float* sx, blasint* incx, float* sb, float* sy, blasint* incy);

void FC_GLOBAL(comatcopy,COMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, float complex* b, blasint* ldb);

void FC_GLOBAL(zomatcopy,ZOMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, double complex* b, blasint* ldb);

void FC_GLOBAL(domatcopy,DOMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, double* b, blasint* ldb);

void FC_GLOBAL(somatcopy,SOMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, float* b, blasint* ldb);

void FC_GLOBAL(cimatcopy,CIMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, float complex* alpha, float complex* a, blasint* lda, blasint* ldb);

void FC_GLOBAL(zimatcopy,ZIMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, double complex* alpha, double complex* a, blasint* lda, blasint* ldb);

void FC_GLOBAL(dimatcopy,DIMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, double* alpha, double* a, blasint* lda, blasint* ldb);

void FC_GLOBAL(simatcopy,SIMATCOPY)(char* order, char* trans, blasint* rows, blasint* cols, float* alpha, float* a, blasint* lda, blasint* ldb);

void FC_GLOBAL(sgeadd,SGEADD)(blasint* m, blasint* n, float* alpha, float* a, blasint* lda, float* beta, float* b, blasint* ldb);

void FC_GLOBAL(dgeadd,DGEADD)(blasint* m, blasint* n, double* alpha, double* a, blasint* lda, double* beta, double* b, blasint* ldb);

void FC_GLOBAL(cgeadd,CGEADD)(blasint* m, blasint* n, float complex* alpha, float complex* a, blasint* lda, float complex* beta, float complex* b, blasint* ldb);

void FC_GLOBAL(zgeadd,ZGEADD)(blasint* m, blasint* n, double complex* alpha, double complex* a, blasint* lda, double complex* beta, double complex* b, blasint* ldb);


#ifdef __cplusplus
}
#endif
#endif
