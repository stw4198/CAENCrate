DIR=sethv
CXX=g++
CXXFLAGS=-pthread -std=c++11 -m64 -g -I./$(DIR)/include -L/usr/lib/CAEN -I/usr/include/CAEN -Wall
LDFLAGS=-m64
LDLIBS=-pthread -lm -ldl -rdynamic -lCAENVME
SRCDIR=$(DIR)/src
SOURCES=$(SRCDIR)/sethv.cpp $(SRCDIR)/V6534P.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=$(DIR)/sethv

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS) 
	
DIR_SH=script
SOURCES_SH=$(DIR_SH)/script.cpp
OBJECTS_SH=$(SOURCES_SH:.cpp=.o)
EXECUTABLE_SH=$(DIR_SH)/script

all: $(SOURCES_SH) $(EXECUTABLE_SH)

$(EXECUTABLE_SH): $(OBJECTS_SH)
	$(CXX) -o $@ $^

.cc.o:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(CFLAGS) -W -Wall -c $<

clean:
	rm -f ./*~ $(OBJECTS) ./$(DIR)/sethv $(OBJECTS_SH) ./$(DIR_SH)/script





