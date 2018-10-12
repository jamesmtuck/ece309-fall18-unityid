
# list the name of each file (without the .cpp file at the end)
#EXE = example IntArray_test IntegerSetArray_test
EXE = example IntegerSetArray_test


all: $(EXE)

run: all $(addsuffix -run,$(EXE))

clean:
	rm -f $(EXE) *~ logfile.txt $(ECE)

%: %.cpp
	$(CXX) -o $@ $< -std=c++11 -Wall -Werror -I ../include -L ../lib -lece309

%-run:
	@./$*

