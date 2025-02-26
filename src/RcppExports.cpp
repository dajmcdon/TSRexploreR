// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// ShiftScoreFast
double ShiftScoreFast(arma::vec x, arma::vec y, int k, int xn, int yn, arma::uvec w);
RcppExport SEXP _TSRexploreR_ShiftScoreFast(SEXP xSEXP, SEXP ySEXP, SEXP kSEXP, SEXP xnSEXP, SEXP ynSEXP, SEXP wSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< int >::type k(kSEXP);
    Rcpp::traits::input_parameter< int >::type xn(xnSEXP);
    Rcpp::traits::input_parameter< int >::type yn(ynSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type w(wSEXP);
    rcpp_result_gen = Rcpp::wrap(ShiftScoreFast(x, y, k, xn, yn, w));
    return rcpp_result_gen;
END_RCPP
}
// ShiftScore
arma::vec ShiftScore(arma::sp_mat x, arma::sp_mat y, int calcP, int nresamp);
RcppExport SEXP _TSRexploreR_ShiftScore(SEXP xSEXP, SEXP ySEXP, SEXP calcPSEXP, SEXP nresampSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::sp_mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::sp_mat >::type y(ySEXP);
    Rcpp::traits::input_parameter< int >::type calcP(calcPSEXP);
    Rcpp::traits::input_parameter< int >::type nresamp(nresampSEXP);
    rcpp_result_gen = Rcpp::wrap(ShiftScore(x, y, calcP, nresamp));
    return rcpp_result_gen;
END_RCPP
}
// allTheShiftScores
arma::mat allTheShiftScores(CharacterVector fhash, arma::uvec dists, arma::vec scores, arma::vec sample, int calcP, int nresamp, int ntests);
RcppExport SEXP _TSRexploreR_allTheShiftScores(SEXP fhashSEXP, SEXP distsSEXP, SEXP scoresSEXP, SEXP sampleSEXP, SEXP calcPSEXP, SEXP nresampSEXP, SEXP ntestsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type fhash(fhashSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type dists(distsSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type scores(scoresSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sample(sampleSEXP);
    Rcpp::traits::input_parameter< int >::type calcP(calcPSEXP);
    Rcpp::traits::input_parameter< int >::type nresamp(nresampSEXP);
    Rcpp::traits::input_parameter< int >::type ntests(ntestsSEXP);
    rcpp_result_gen = Rcpp::wrap(allTheShiftScores(fhash, dists, scores, sample, calcP, nresamp, ntests));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_TSRexploreR_ShiftScoreFast", (DL_FUNC) &_TSRexploreR_ShiftScoreFast, 6},
    {"_TSRexploreR_ShiftScore", (DL_FUNC) &_TSRexploreR_ShiftScore, 4},
    {"_TSRexploreR_allTheShiftScores", (DL_FUNC) &_TSRexploreR_allTheShiftScores, 7},
    {NULL, NULL, 0}
};

RcppExport void R_init_TSRexploreR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
