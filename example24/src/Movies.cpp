#include <iostream>
#include "Movies.h"

// Constructor
Movies::Movies() {}

// Destructor
Movies::~Movies() {}

// Methods
bool Movies::add_movie(std::string name, std::string rating, int watched) {
  // Faster with reference, specify const vs auto + copies
  for (const Movie &movie: movies) {
    if (movie.get_name() == name) {
      return false;
    }
  }
  Movie tmp {name, rating, watched};
  movies.push_back(tmp);
  return true;
}

bool Movies::increment_watched(std::string name) {
  for (Movie &movie: movies) {
    if (movie.get_name() == name) {
      movie.increment_watched();
      return true;
    }
  }
  return false;
}

void Movies::display() const {
  if (movies.size() == 0) {
    std::cout << "Sorry, no movies to display!" << std::endl;
  } else {
    // Can also use const auto to get the Movie type here
    for (const auto &movie: movies) {
      movie.display();
    }    
  }
}
