# Dafny to C

This is a minimal, dumb 'transpiler' (???) from the [Dafny](http://rise4fun.com/Dafny) program verification language to C


# Features (line-by-line)
`/^ \+\(requires\|invariant\|decreases\|ensures\)/d;`

Remove verifier directives


`s/^ \+var//g;`

Remove `var` keyword from variable declarations



`s/^\(method\|function\|predicate\) //;`

Remove method/function/predicate keywords


`s/^\(\w\+(.\+)\) returns (\w\+:\(\w\+\))/\2 \1/;`

Move the return type parameter to the beginning of function declarations

`f(a: int, b:int) returns (res: bool)` goes to `bool f(a: int, res: int)`


`s/:=/=/g;`

Fix variable assignments'


`s/\(\w\+\): \(\w\+\)/\2 \1/g;`

Swap the order of type annotations

`a: int` goes to `int a`


`s/|\(\w\+\)|/strlen(\1)/g"`

Turn `|str|` into `strlen(str)`



Finally, all of the depended-upon C header files are inserted.
