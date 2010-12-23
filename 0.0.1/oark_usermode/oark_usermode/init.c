/*
Copyright (c) <2010> <Dreg aka David Reguera Garcia, dreg@fr33project.org>

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

#include "init.h"

INIT_TABLE_ENTRY_t INIT_TABLE[] =
{
    { {FIN_SSDT_DEFAULTS}, CheckSSDTHooking, TRUE, "SSDT HOOKING DETECTION" },
    { {FIN_IDT_DEFAULTS}, idt, TRUE, "IDT INFORMATION" },
    { {FIN_PEBHOOKING_DEFAULTS}, CheckPEBHooking, TRUE, "PEB HOOKING DETECTION" }
};

STATUS_t InitCalls( HANDLE hdevice )
{
    int i;
    static FUNC_ARGS_GLOBAL_t globals;

    globals.hdevice = hdevice;

    for ( i = 0; i < ( sizeof( INIT_TABLE ) / sizeof( * INIT_TABLE ) ); i++ )
        INIT_TABLE[i].function( & INIT_TABLE[i].function_args, & globals );

    return ST_OK;
}



