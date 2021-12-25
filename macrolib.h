/* SPDX-License-Identifier: 0BSD */
/* Copyright 2021 Alexander Kozhevnikov <mentalisttraceur@gmail.com> */

#ifndef MACROLIB_H
#define MACROLIB_H

#define MACROLIB_DELETE(x)
#define MACROLIB_UNWRAP(x) x
#define MACROLIB_CATENATE(left, right) left##right
#define MACROLIB_SCAN_CATENATE(left, right) \
    MACROLIB_CATENATE(left, right)
#define MACROLIB_HEAD(sequence) MACROLIB_HEAD_ sequence)
#define MACROLIB_HEAD_(x) x MACROLIB_DELETE(
#define MACROLIB_TAIL(sequence) MACROLIB_DELETE sequence

#define MACROLIB_REDUCE(macro, state_initial, sequence) \
    MACROLIB_REDUCE_SCAN(MACROLIB_REDUCE_SCAN(MACROLIB_REDUCE_SCAN( \
    MACROLIB_DELETE MACROLIB_DELETE \
        MACROLIB_WALK(MACROLIB_REDUCE_OPEN_1 sequence) \
        (macro)state_initial \
        MACROLIB_WALK(MACROLIB_CLOSE_1 sequence) \
    )))
#define MACROLIB_REDUCE_SCAN(x) x

#define MACROLIB_WALK(macro_sequence) \
    MACROLIB_CATENATE(macro_sequence, _END)

#define MACROLIB_REDUCE_OPEN_1(x) \
    MACROLIB_REDUCE_STEP MACROLIB_OPEN MACROLIB_UNWRAP(()) \
    MACROLIB_REDUCE_OPEN_2
#define MACROLIB_REDUCE_OPEN_2(x) \
    MACROLIB_REDUCE_STEP MACROLIB_OPEN MACROLIB_UNWRAP(()) \
    MACROLIB_REDUCE_OPEN_1
#define MACROLIB_REDUCE_OPEN_1_END
#define MACROLIB_REDUCE_OPEN_2_END
#define MACROLIB_OPEN() (

#define MACROLIB_CLOSE_1(x) \
    MACROLIB_CLOSE MACROLIB_UNWRAP((x)) MACROLIB_CLOSE_2
#define MACROLIB_CLOSE_2(x) \
    MACROLIB_CLOSE MACROLIB_UNWRAP((x)) MACROLIB_CLOSE_1
#define MACROLIB_CLOSE_1_END
#define MACROLIB_CLOSE_2_END
#define MACROLIB_CLOSE(x) , x)

#define MACROLIB_REDUCE_STEP(macro_state_result, x) \
    (MACROLIB_HEAD(macro_state_result)) \
    MACROLIB_HEAD(macro_state_result)( \
        MACROLIB_HEAD(MACROLIB_DELETE macro_state_result), \
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

#define MACROLIB_MAP(macro, parameter, sequence) \
    MACROLIB_MAP_SCAN(MACROLIB_MAP_SCAN(MACROLIB_MAP_SCAN( \
    MACROLIB_DELETE MACROLIB_DELETE \
        MACROLIB_WALK(MACROLIB_MAP_OPEN_1 sequence) \
        (macro)(parameter) \
        MACROLIB_WALK(MACROLIB_CLOSE_1 sequence) \
    )))
#define MACROLIB_MAP_SCAN(x) x

#define MACROLIB_MAP_OPEN_1(x) \
    MACROLIB_MAP_STEP MACROLIB_OPEN MACROLIB_UNWRAP(()) MACROLIB_MAP_OPEN_2
#define MACROLIB_MAP_OPEN_2(x) \
    MACROLIB_MAP_STEP MACROLIB_OPEN MACROLIB_UNWRAP(()) MACROLIB_MAP_OPEN_1
#define MACROLIB_MAP_OPEN_1_END
#define MACROLIB_MAP_OPEN_2_END

#define MACROLIB_MAP_STEP(macro_parameter_result, x) \
    macro_parameter_result \
    MACROLIB_HEAD(macro_parameter_result) \
        (MACROLIB_HEAD(MACROLIB_DELETE macro_parameter_result), x)
#endif /* MACROLIB_H */
