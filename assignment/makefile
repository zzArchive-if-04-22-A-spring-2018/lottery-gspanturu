CC					= g++
CCLINK			= g++
LIBS				=
CCOPTIONS		= -Wall -pedantic -g
LDOPTIONS		=
HDRS				= lottery.h test_lottery.h general.h shortcut.h

TEST = test_lottery
PROGRAM =

TESTOBJECT = lottery_test_driver.o
MAINOBJECT =
OBJS = general.o shortcut.o lottery.o test_lottery.o

DOXY            = /Applications/Doxygen/Doxygen.app/Contents/Resources/doxygen

all: $(PROGRAM)
	./$(PROGRAM)

$(TEST): $(OBJS) $(TESTOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(TESTOBJECT)

$(PROGRAM): $(OBJS) $(MAINOBJECT)
	$(CCLINK) -o $@ $(LDOPTIONS) $(OBJS) $(MAINOBJECT)

.PHONY: clean cleanall doxy test setsample setassignment definesample defineassignment assignmentfolder

clean:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS)

cleanall:
	rm -f $(PROGRAM) $(TEST) $(TESTOBJECT) $(MAINOBJECT) $(OBJS) index.html
	rm -R html

doxy:
	$(DOXY)
	ln -s html/index.html index.html

test: $(TEST)
	./$(TEST)

#sets project as sample solution
setsample:
	cp lottery.cpp.sample lottery.cpp
	cp lottery.h.sample lottery.h

#sets project as assignment
setassignment:
	cp lottery.cpp.assignment lottery.cpp
	cp lottery.h.assignment lottery.h

# defines current state of project as sample solution
definesample:
	cp lottery.cpp lottery.cpp.sample
	cp lottery.h lottery.h.sample

# defines current sate of project as assignment
defineassignment:
	cp lottery.cpp lottery.cpp.assignment
	cp lottery.h lottery.h.assignment

# creates a folder which can serve as a publishable assignment
assignmentfolder:
	make setsample
	make doxy
	make setassignment
	mkdir ../assignment
	cp -R * ../assignment
	rm ../assignment/*.sample
	rm ../assignment/*.assignment
	make cleanall

%.o: %.cpp $(HDRS)
	$(CC) $(CCOPTIONS) -c $<
