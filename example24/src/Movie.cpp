#include <iostream>
#include "Movie.h"

// Constructor
Movie::Movie(std::string name, std::string rating, int watched) 
  : name{name}, rating{rating}, watched{watched} {}

// Copy constructor - for practice, as this would be the default
// compiler implementation anyway
Movie::Movie(const Movie &source) 
  : Movie{source.name, source.rating, source.watched} {}

// Destructor
Movie::~Movie() {}

void Movie::display() const {
  std::cout << name << ", " << rating << ", " << watched << std::endl;
}
