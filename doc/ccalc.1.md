% CCALC(1) | User Commands
% Guy Wilson
% Sep 12, 2026

# NAME

ccalc - interactive command-line scientific calculator

# SYNOPSIS

**ccalc**

# DESCRIPTION

**ccalc** evaluates calculations entered at an interactive prompt.
Enter an expression to calculate its result, **help** to display usage
information, or **exit** to leave the calculator.

Use parentheses `()` to group expressions and nest calculations.

# OPERATORS

`+`, `-`, `*`, `/`
:   Addition, subtraction, multiplication, and division.

`%`
:   Modulo.

`&`, `|`, `~`
:   Bitwise AND, OR, and XOR, respectively.

`<`, `>`
:   Left shift and right shift, respectively.

`^`
:   Power. For example, `x ^ y` raises x to the power y.

`:`
:   Root. For example, `x : y` calculates the yth root of x.

# FUNCTIONS

`sin(x)`, `cos(x)`, `tan(x)`
:   Sine, cosine, and tangent of x, with x expressed in degrees.

`asin(x)`, `acos(x)`, `atan(x)`
:   Arcsine, arccosine, and arctangent of x, returning an angle in degrees.

`sinh(x)`, `cosh(x)`, `tanh(x)`
:   Hyperbolic sine, cosine, and tangent of x, with x expressed in radians.

`asinh(x)`, `acosh(x)`, `atanh(x)`
:   Inverse hyperbolic sine, cosine, and tangent of x, returning a value
    in radians.

`sqrt(x)`
:   Square root of x.

`log(x)`
:   Base-10 logarithm of x.

`ln(x)`
:   Natural logarithm of x.

`fact(x)`
:   Factorial of x.

`rad(x)`
:   Convert x degrees to radians.

`deg(x)`
:   Convert x radians to degrees.

# CONSTANTS

`pi`
:   The ratio pi.

`eu`
:   Euler's constant (the Euler-Mascheroni constant).

`c`
:   The speed of light in a vacuum.

# COMMANDS

Enter these commands at the calculator prompt.

**dec**
:   Switch to decimal mode.

**hex**
:   Switch to hexadecimal mode.

**bin**
:   Switch to binary mode.

**oct**
:   Switch to octal mode.

**setpn**
:   Set the output precision to n. Append the number directly to the
    command; for example, `setp6` sets the precision to 6.

**fmton**
:   Switch on output formatting. Formatting is enabled by default.

**fmtoff**
:   Switch off output formatting.

**help**
:   Display help text.

**test**
:   Run the calculator's self-test.

**version**
:   Print the calculator version.

**exit**
:   Exit the calculator.

# AUTHOR

Guy Wilson.

# COPYRIGHT

Copyright © Guy Wilson 2026

This program comes with ABSOLUTELY NO WARRANTY.
This is free software, and you are welcome to redistribute it under
certain conditions. See the accompanying LICENSE file for details.
