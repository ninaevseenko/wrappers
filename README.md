# wrappers
Wraps some repetitive parts of code. Actually it doesn't make executable program
more optimal, but source code with such wrappers looks more readable.
The main usage is logging of unexpected behaviour.
The additional advantage is ability to turn off specific macroses without a damage. 


## How to use
Define log.h, then define and declare WRAPPERS\_LOGERROR macros which should being 
mapped to the error logging function. 
