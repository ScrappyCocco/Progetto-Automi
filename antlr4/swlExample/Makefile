CXX=g++
CXXFLAGS=-std=c++11 -I $(HOME)/antlr4/include
LDFLAGS=-lantlr4-runtime -L $(HOME)/antlr4/lib
DEPS=swlLexer.h swlParser.h
TDEPS=swlBaseListener.h MyListener.h
OBJS=swlParser.o swlLexer.o
SCOBJS=syncheck.o
TOBJS=translate.o MyListener.o
ANTLRS=swlBaseListener.h \
        swlLexer.cpp \
        swlLexer.tokens \
        swlParser.cpp \
        swlLexer.h \
        swlListener.cpp \
        swlParser.h \
        swlBaseListener.cpp \
        swl.interp \
        swlLexer.interp \
        swlListener.h \
        swl.tokens

syncheck: $(SCOBJS) $(OBJS) $(DEPS)
	$(CXX) -o syncheck $(SCOBJS) $(OBJS) $(LDFLAGS)

translate: $(TOBJS) $(OBJS) $(TDEPS) $(DEPS) 
	$(CXX) -o translate $(TOBJS) $(OBJS) $(LDFLAGS)	

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
	
clean:
	rm -f $(OBJS) $(TOBJS) $(SCOBJS) syncheck translate

distclean:
	rm -f $(ANTLRS)

