# Nom de l'exécutable
EXECUTABLE = simulation

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++11 -I. -O2

# Fichiers source
SOURCES = main.cpp Schema.cpp Lagrangienne.cpp

# Fichiers objets correspondants
OBJECTS = $(SOURCES:.cpp=.o)

# Règle par défaut
all: $(EXECUTABLE)

# Création de l'exécutable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Règle pour compiler les fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Cible pour exécuter le programme
run: $(EXECUTABLE)
	./$(EXECUTABLE)
