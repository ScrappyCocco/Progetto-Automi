grammar swl;

program   : 'start' statement+ 'end';
          
statement : assign | add | print | meno | ifoperator;

assign    : 'sia' ID 'be' (NUMBER | ID) ;
print     : 'print' (NUMBER | ID | comparison) ;
add       : 'add' (NUMBER | ID) 'to' ID ;
meno       : 'sub' (NUMBER | ID) 'to' ID ;
comparison : (NOTOPERATOR)* (NUMBER | ID) (COMPARE) (NUMBER | ID);

booloperator: comparison (BOOLOPERATORLIST) comparison;

ifoperator: 'if' (comparison | booloperator) 'do' statement+ 'endif';

ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;
WS        : [ \n\t]+ -> skip;
COMPARE: '<' | '>' | '==' | '!=';
BOOLOPERATORLIST: 'and' | 'or';
NOTOPERATOR: 'not';
ErrorChar : . ;
