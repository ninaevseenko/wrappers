/*
 *  wrappers.h
 *
 *  This file is WRAPPERS software.
 *
 *  (C) 2017  Nina Evseenko <anvoebugz@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef __WRAPPERS_H
#define __WRAPPERS_H


#include "log.h"


#define __WRAPPER(some_code) do{\
    some_code\
} while(0);


/*
 * If the invariant is false then log error and return error code
 * upward for the following consideration.
 */

#ifdef WRAPPERS_ERROR_STR
#define THROW(invariant, errnum, actions...) __WRAPPER(\
        if (!(invariant)) {\
            WRAPPERS_LOGERROR("%s", emsg(errnum));\
            actions;\
            return errnum;\
        }\
)
#else
#define THROW(invariant, errnum, actions...) __WRAPPER(\
        if (!(invariant)) {\
            WRAPPERS_LOGERROR("%d", errnum);\
            actions;\
            return errnum;\
        }\
)
#endif


/*
 * If the invariant is false then log error without compulsory return.
 */
#ifdef WRAPPERS_ERROR_STR
#define TRACE(invariant, errnum, actions...) __WRAPPER(\
        if (!(invariant)) {\
            WRAPPERS_LOGERROR("%s", emsg(errnum));\
            actions;\
        }\
)
#else
#define TRACE(invariant, errnum, actions...) __WRAPPER(\
        if (!(invariant)) {\
            WRAPPERS_LOGERROR("%d", errnum);\
            actions;\
        }\
)
#endif


/*
 * RIFER - return if error;
 * If the func returns OK do nothing, else return error code
 * upward for the following consideration. Optionally do some actions in
 * the case of error.
 */

#ifdef WRAPPERS_ERROR_STR
#define RIFER(func, actions...) __WRAPPER(\
        int _ret = func;\
        if (_ret != OK) { \
            WRAPPERS_LOGERROR("%s", emsg(_ret));\
            actions;\
            return _ret;\
       }\
)
#else
#define RIFER(func, actions...) __WRAPPER(\
        int _ret = func;\
        if (_ret != OK) { \
            WRAPPERS_LOGERROR("%d", _ret);\
            actions;\
            return _ret;\
       }\
)
#endif


/*
 * LIFER - loop if error;
 * If the func returns OK do nothing, else logs error.
 * Optionally do some actions in the case of error.
 */

#ifdef WRAPPERS_ERROR_STR
#define LIFER(func, actions...) __WRAPPER(\
        int _ret = func;\
        if (_ret != OK) { \
            WRAPPERS_LOGERROR("%s", emsg(_ret));\
            actions;\
            while (1);\
       }\
)
#else
#define LIFER(func, actions...) __WRAPPER(\
        int _ret = func;\
        if (_ret != OK) { \
            WRAPPERS_LOGERROR("%d", _ret);\
            actions;\
            while (1);\
       }\
)
#endif


/*
 * FASSERT - function assert;
 * If the func returns OK do nothing, else logs an error.
 * Optionally do some actions in the case of the error.
 */

#ifdef WRAPPERS_ERROR_STR
#define FASSERT(func, actions...) __WRAPPER(\
        int _ret = func;\
        if (_ret != OK) { \
            WRAPPERS_LOGERROR("%s", emsg(_ret));\
            actions;\
       }\
)
#else
#define FASSERT(func, actions...) __WRAPPER(\
        int _ret = func;\
        if (_ret != OK) { \
            WRAPPERS_LOGERROR("%d", _ret);\
            actions;\
       }\
)
#endif


#endif
