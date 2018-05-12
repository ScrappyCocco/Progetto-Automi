grammar swl;

program   : 'start' statement+ 'end';
          
statement : assign | add | sub | mul | div | incrementExpression | decrementExpression | print | ifoperator | ifelseoperator | whilecycle | dowhilecycle;

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

dowhilecycle: 'do' statement* 'while' '(' (comparison | booloperator) ')';
whilecycle: 'while' '(' (comparison | booloperator) ')' 'do' statement* 'endwhile';

incrementExpression : 'increment' (ID); /* Ancora da implementare */
decrementExpression : 'decrement' (ID); /* Ancora da implementare */

ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;
WS        : [ \n\t]+ -> skip;
bool_compare_operators	: 'lower' | 'greater' | 'equal' | 'different' | 'grequal' | 'lwequal'; /*Sono minuscoli per non rendere la grammatica ambigua con ID  */
operator_list: 'and' | 'or';
not_operator: 'not';
else_word: 'else';
ErrorChar : . ;
