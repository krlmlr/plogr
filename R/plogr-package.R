#' @examplesIf requireNamespace("Rcpp", quietly = TRUE)
#' plogr_demo <- Rcpp::cppFunction(depends = "plogr", '
#' // C++ code begin
#' #include <plogr.h>
#'
#' RObject plogr_demo() {
#'   plog::init_r(plog::info);
#'   LOG_INFO << "shown";
#'   LOG_DEBUG << "not shown";
#'   plog::init_r("DEBUG");
#'   LOG_DEBUG << "shown now";
#'   return R_NilValue;
#' }
#'
#' #include <Rcpp.h> // not necessary to use plogr
#' // C++ code end
#' '
#' )
#'
#' plogr_demo()
"_PACKAGE"
