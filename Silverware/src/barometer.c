/*
The MIT License (MIT)

Copyright (c) 2016 silverx

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "hardware.h"
#include "barometer.h"
#include "drv_dps310.h"

/*
#ifdef ENABLE_BARO
#undefine THROTTLE_SMOOTH
#undefine AUTO_THROTTLE
#endif
*/

void barometer_init(void)
{
#ifdef USE_BARO_DPS310
    dps310_init();
#endif
}

int barometer_check(void)
{
#ifndef DISABLE_BARO_CHECK
#ifdef USE_BARO_DPS310
    return dps310_check();
#endif

#endif
    return 1;
}

float read_pressure(void)
{
#ifdef USE_BARO_DPS310
    dps310_read_pressure();
    dps310_pcomp_lpf();
#else
    return 0;
#endif
}
