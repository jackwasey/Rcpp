// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
// newDateVector.h: Rcpp R/C++ interface class library -- Date vector support
//
// Copyright (C) 2016         Dirk Eddelbuettel
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp__newDateVector_h
#define Rcpp__newDateVector_h

#include <RcppCommon.h>

namespace Rcpp {

    class newDateVector : public NumericVector {
    public:
        newDateVector(SEXP vec) : NumericVector(vec) { setClass(); }
        newDateVector(int n) : NumericVector(n) { setClass(); }

        inline std::vector<Date> getDates() const {
            int n = this->size();
            std::vector<Date> v(n);
            for (int i=0; i<n; i++)
                v[i] = (*this)[i];
            return v;
        }

    private:

        void setClass() {
            Shield<SEXP> dateclass(Rf_mkString("Date"));
            Rf_setAttrib(*this, R_ClassSymbol, dateclass);
        }
    };
}

#endif
