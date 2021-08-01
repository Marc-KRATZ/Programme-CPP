# Programme-CPP
 
Structure d'application

If it is a library, this structure is ok.

lib/ (class implementations *.cpp .h)
include/ (class definitions *.h) <- Only those to be installed in your system
tests/ (main.cpp for quick tests)
doc/ (doxygen or any kind of documentation)

If it is a application

src/ (source for the application)
lib/ (source for the application library *.cpp *.hpp)
include/ (interface for the library *.h)
tests/ (main.cpp for quick tests) <- use cppunit for this part
doc/ (doxygen or any kind of documentation)

makefile

See pdf in doc directory




quid cmake ?

