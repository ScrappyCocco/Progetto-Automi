grammar swl;

program   : 'start' statement+ 'end';
          
statement : assign | add | sub | mul | div | print | ifoperator;

assign    : 'let' ID 'be' (NUMBER | ID) ;
print     : 'print' (NUMBER | ID) ;

add       : 'add' (NUMBER | ID) 'to' ID ;
sub       : 'sub' (NUMBER | ID) 'to' ID ;
mul       : 'mul' (NUMBER | ID) 'to' ID ;
div       : 'div' (NUMBER | ID) 'to' ID ;

comparison : not_operator* ID SPACE* bool_compare_operators SPACE* (NUMBER | ID);
booloperator: comparison ((operator_list) comparison)+;
ifoperator: 'if' '(' (comparison | booloperator) ')' 'do' statement+ 'endif';
ifelseoperator: 'if' '(' (comparison | booloperator) ')' 'do' statement+ 'else' statement+ 'endif'; /* Ancora da implementare */

incrementExpression : 'increment' (ID); /* Ancora da implementare */
decrementExpression : 'decrement' (ID); /* Ancora da implementare */

ID        : [a-z]+ ;
NUMBER    : [0-9]+ ;
WS        : [ \n\t]+ -> skip;
bool_compare_operators	: 'lower' | 'greater' | 'equal' | 'different'; /*Sono minuscoli per non rendere la grammatica ambigua con ID  */
operator_list: 'and' | 'or';
not_operator: 'not';
SPACE : ' ' ; /*Sono ancora indeciso se tenerlo o no*/
ErrorChar : . ;
