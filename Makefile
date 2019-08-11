SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall  -I$(INC) -c

all: $(BIN)/pruebaarbol $(BIN)/testdiccionario $(BIN)/letras


$(BIN)/letras: $(OBJ)/letras.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o
$(OBJ)/letras.o: $(INC)/Letras.h $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/letras.cpp -o $(OBJ)/letras.o -I$(INC)

$(BIN)/pruebaarbol: $(OBJ)/pruebaarbol.o
	$(CXX) -o $(BIN)/pruebaarbol $(OBJ)/pruebaarbol.o
$(OBJ)/pruebaarbol.o: $(INC)/ArbolGeneral.h $(SRC)/pruebaarbol.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/pruebaarbol.cpp -o $(OBJ)/pruebaarbol.o -I$(INC)
$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o 
$(OBJ)/testdiccionario.o: $(INC)/Diccionario.h $(INC)/ArbolGeneral.h $(SRC)/testdiccionario.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/testdiccionario.cpp  -o $(OBJ)/testdiccionario.o -I$(INC)


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
