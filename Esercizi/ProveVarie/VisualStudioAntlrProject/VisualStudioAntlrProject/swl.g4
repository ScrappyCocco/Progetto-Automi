grammar swl;

program   : 'start' statement+ 'end' function*;

function  : 'function' ID '(' ID* ')' ':' 'endfunction';
          
statement : assign | add | sub | mul | div | incrementExpression | decrementExpression | print | ifoperator | ifelseoperator | whilecycle | dowhilecycle | forcycle;

assign    : 'let' ID 'be' (NUMBER | ID) ;
print     : 'print' (NUMBER | ID) ;

add       : 'add' (NUMBER | ID) 'to' ID ;
sub       : 'sub' (NUMBER | ID) 'to' ID ;
mul       : 'mul' (NUMBER | ID) 'to' ID ;
div       : 'div' (NUMBER | ID) 'to' ID ;

comparison : not_operator* ID bool_compare_operators (NUMBER | ID);
booloperator: (comparison|boolbrackets)((operator_list)(comparison|boolbrackets))+;
boolbrackets:'(' (booloperator|comparison) ')';
ifoperator: 'if' '(' (comparison | booloperator) ')' 'do' statement* 'endif';
ifelseoperator: 'if' '(' (comparison | booloperator) ')' 'do' statement* else_word statement* 'endif';

forcycle: 'for' ID 'in range' '(' NUMBER ',' NUMBER ')' 'do' statement* 'endfor';
dowhilecycle: 'do' statement* 'while' '(' (comparison | booloperator) ')';
whilecycle: 'while' '(' (comparison | booloperator) ')' 'do' statement* 'endwhile';

incrementExpression : 'increment' (ID);
decrementExpression : 'decrement' (ID);

ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;
WS        : [ \n\t]+ -> skip;
bool_compare_operators	: 'lower' | 'greater' | 'equal' | 'different' | 'grequal' | 'lwequal';
operator_list: 'and' | 'or';
not_operator: 'not';
else_word: 'else';
ErrorChar : . ;
