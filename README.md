Example macros to help experiment with using
the C pre-processor in non-trivial ways.

If you actually create code based on macrolib macros,
copy and *rename* the macrolib macros! Macros cannot
be expanded recursively, so for exanple if you make
a macro that uses `MACROLIB_REDUCE` without renaming
all the "MACROLIB" prefixes, that macro is unusable
inside another use of `MACROLIB_REDUCE` - but if you
copy and rename all ”MACROLIB" macros that you use,
that problem doesn't happen. So use `macrolib.h` for
experimentation and initial development, then copy
and rename the macros when you got something usable.

TODO: Documentation/comments/explanation/education.
