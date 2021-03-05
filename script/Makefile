CXX=g++
SOURCES=script.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=script

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) -o $@ $^

.cc.o:
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $<

clean:
	rm -f ./*~ $(OBJECTS) ./script


