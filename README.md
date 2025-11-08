
<!-- README.md is generated from README.Rmd. Please edit that file -->

# plogr

<!-- badges: start -->

[![R-CMD-check](https://github.com/krlmlr/plogr/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/krlmlr/plogr/actions/workflows/R-CMD-check.yaml)
[![CRAN
status](https://www.r-pkg.org/badges/version/plogr)](https://CRAN.R-project.org/package=plogr)
<!-- badges: end -->

Provides the header files for a stripped-down version of the
[plog](https://github.com/SergiusTheBest/plog) header-only C++ logging
library, and a method to log to R’s standard error stream.

## Installation

You can install `plogr` from GitHub with:

``` r
# install.packages("devtools")
devtools::install_github("krlmlr/plogr")
```

## Usage

Add `LinkingTo: plogr` to your `DESCRIPTION`, and add
`#include <plogr.h>` to all modules where you want to access the
logging. If your package has a universal header file which you include
from all modules, it’s probably a good idea to insert the `#include`
directive there, so that all of your code has access to logging. The
following system header files will be included:

- `sstream`
- `iostream`
- `vector`
- `cassert`
- `cstring`
- `time.h` (on Linux/OS X)
- `sys/time.h` (on Windows)
- `R.h`

## Example

The code shows a small usage example and a demo which we’ll call from R
below. (`Rcpp` is *not* necessary to use `plogr`, it is only needed to
run the C++ code chunk.) The `init_r()` function is the only new
function added by the R package, and initializes a logger that logs to
R’s standard error stream. For further details consult the [plog
documentation](https://github.com/SergiusTheBest/plog#readme); for
compatibility reasons you won’t find the file appenders in this package.

``` cpp
// If we omit this, logging is disabled altogether.
// In a package, you would probably add -DPLOGR_ENABLE to PKG_CPPFLAGS.
#define PLOGR_ENABLE

// [[Rcpp::depends(plogr)]]
#include <plogr.h>

// [[Rcpp::export]]
void plogr_demo() {
  LOG_INFO << "test 1";
  plog::init_r(plog::info);
  LOG_INFO << "test 2";
  LOG_DEBUG << "test 3";
  plog::init_r("DEBUG"); // You can also pass a string
  LOG_INFO << "test 4";
  LOG_DEBUG << "test 5";
}

#include <Rcpp.h> // not necessary to use plogr
```

The R code below calls the `plogr_demo()` C++ function defined above.
Currently, the messages are printed straight to the standard error
stream, so the message capturing mechanisms employed by `knitr` don’t
work. We use a sink with a text connection to capture the messages, and
print the contents of the variable to which the text connection assigns.

``` r
output <- character()
con <- textConnection("output", "a")
withr::with_message_sink(con, plogr_demo())
close(con)
cat(output, sep = "\n")
#> void plogr_demo@12: test 2
#> void plogr_demo@15: test 4
#> void plogr_demo@16: test 5
```

Nothing is printed before we actually initialize the logger. Because it
is initialized to the `info` level, the debug log message is not shown,
and only “test 2” comes through. After changing the log level, the debug
message is also shown.
