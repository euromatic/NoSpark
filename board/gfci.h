// NoSpark - OpenEVSE charger firmware
// Copyright (C) 2015 Andre Eisenbach
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// See LICENSE for a copy of the GNU General Public License or see
// it online at <http://www.gnu.org/licenses/>.

#pragma once

#include <stdbool.h>

#include "board/pin.h"
#include "utils/cpp.h"

extern "C" void INT0_vect(void) __attribute__((signal));

namespace board
{

// Once instantiated will monitor GFCI pin an trigger
// an event if tripped.
class GFCI
{
public:
    GFCI();

    bool selfTest(const bool sendPostEvent = false);

private:
    board::Pin pinSense;
    board::Pin pinTest;

    bool self_test;
    bool tripped;

    void sendPulses();
    void trip();
    friend void ::INT0_vect();

    DISALLOW_COPY_AND_ASSIGN(GFCI);
};

}
