/* SPDX-License-Identifier: 0BSD */
/* Copyright 2021 Alexander Kozhevnikov <mentalisttraceur@gmail.com> */

#ifndef MACROLIB_H
#define MACROLIB_H

#define MACROLIB_DELETE(x)
#define MACROLIB_UNWRAP(x) x
#define MACROLIB_CATENATE(left, right) left##right
#define MACROLIB_SCAN_CATENATE(left, right) \
    MACROLIB_CATENATE(left, right)
#define MACROLIB_FIRST(sequence) MACROLIB_FIRST_ sequence)
#define MACROLIB_FIRST_(x) x MACROLIB_DELETE(

#define MACROLIB_REDUCE(macro_state_result, sequence) \
    MACROLIB_SCAN(MACROLIB_SCAN(MACROLIB_SCAN( \
        MACROLIB_DELETE MACROLIB_DELETE \
            MACROLIB_WALK(MACROLIB_OPEN_1 sequence) \
            macro_state_result \
            MACROLIB_WALK(MACROLIB_CLOSE_1 sequence) \
    )))
#define MACROLIB_SCAN(x) x

#define MACROLIB_WALK(macro_sequence) \
    MACROLIB_CATENATE(macro_sequence, _END)

#define MACROLIB_OPEN_1(x) \
    MACROLIB_STEP MACROLIB_OPEN MACROLIB_UNWRAP(()) \
    MACROLIB_OPEN_2
#define MACROLIB_OPEN_2(x) \
    MACROLIB_STEP MACROLIB_OPEN MACROLIB_UNWRAP(()) \
    MACROLIB_OPEN_1
#define MACROLIB_OPEN_1_END
#define MACROLIB_OPEN_2_END
#define MACROLIB_OPEN() (

#define MACROLIB_CLOSE_1(x) \
    MACROLIB_CLOSE MACROLIB_UNWRAP((x)) MACROLIB_CLOSE_2
#define MACROLIB_CLOSE_2(x) \
    MACROLIB_CLOSE MACROLIB_UNWRAP((x)) MACROLIB_CLOSE_1
#define MACROLIB_CLOSE_1_END
#define MACROLIB_CLOSE_2_END
#define MACROLIB_CLOSE(x) , x)

#define MACROLIB_STEP(macro_state_result, x) \
    (MACROLIB_FIRST(macro_state_result)) \
    MACROLIB_FIRST(macro_state_result)( \
        MACROLIB_FIRST(MACROLIB_DELETE macro_state_result), \
        MACROLIB_DELETE MACROLIB_DELETE macro_state_result, \
        x \
    )

#define MACROLIB_COMMAS(sequence) MACROLIB_WALK(MACROLIB_COMMA_0 sequence)
#define MACROLIB_COMMA_0(x) x MACROLIB_COMMA_1
#define MACROLIB_COMMA_1(x) \
    MACROLIB_COMMA MACROLIB_UNWRAP((x)) MACROLIB_COMMA_2
#define MACROLIB_COMMA_2(x) \
    MACROLIB_COMMA MACROLIB_UNWRAP((x)) MACROLIB_COMMA_1
#define MACROLIB_COMMA_1_END
#define MACROLIB_COMMA_2_END
#define MACROLIB_COMMA(x) , x

#endif /* MACROLIB_H */
