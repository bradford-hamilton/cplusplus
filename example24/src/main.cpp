#include <iostream>
#include <vector>
#include "Movies.h"
#include "Movie.h"

int main() {
  Movies my_fav_movies;

  my_fav_movies.display(); // Sorry, no movies to display!
  
  my_fav_movies.add_movie("Neat Movie 1", "R", 0);      // true
  my_fav_movies.add_movie("Neat Movie 2", "PG-13", 0);  // true
  my_fav_movies.add_movie("Neat Movie 3", "PG", 0);     // true

  my_fav_movies.display();

  my_fav_movies.add_movie("Neat Movie 1", "R", 0);  // false
  my_fav_movies.add_movie("Neat Movie 4", "R", 0);  // true
  my_fav_movies.add_movie("Neat Movie 3", "PG", 0); // false

  // Displays movies 1-4 since two were already in collection.
  my_fav_movies.display();

  return 0;
}
