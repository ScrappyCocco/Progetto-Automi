@echo off
echo Executing java command to re-create antlr files...
@echo on
java -cp "..\..\antlr4\lib\*;." org.antlr.v4.Tool %* -Dlanguage=Cpp ".\VisualStudioAntlrProject\VisualStudioAntlrProject\swl.g4"
@echo off
pause