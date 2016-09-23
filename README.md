
<!-- README.md is generated from README.Rmd. Please edit that file -->
plogr
=====

Provides the header files for the [plog](https://github.com/SergiusTheBest/plog) header-only C++ logging library, and a method to log to R's standard error stream.

Installation
------------

You can install `plogr` from github with:

``` r
# install.packages("devtools")
devtools::install_github("krlmlr/plogr")
```

Example
-------

This is a basic example which shows you how to solve a common problem:

``` cpp
// [[Rcpp::depends(plogr)]]
#include <Rcpp.h>
#include <plogr.h>

// [[Rcpp::export]]
int init_logging() {
  plog::init_r(plog::info);
}

// [[Rcpp::export]]
int log_info(const std::string& message) {
  LOG_INFO << message;
}

// [[Rcpp::export]]
int log_debug(const std::string& message) {
  LOG_DEBUG << message;
}
```
