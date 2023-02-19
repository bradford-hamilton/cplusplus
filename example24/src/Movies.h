#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <vector>
#include <string>
#include "Movie.h"

class Movies {
private:
  std::vector<Movie> movies;
  // No raw pointer members, so no need for custom destructor/copy constructor/move constructor.
public:
  // Constructor
  Movies();
  
  // Destructor
  ~Movies();

  // Methods
  bool add_movie(std::string name, std::string rating, int watched);
  bool increment_watched(std::string name);
  void display() const;
};

#endif // MOVIES_H_
