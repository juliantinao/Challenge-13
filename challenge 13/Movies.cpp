/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
    movies = new std::vector<Movie>;
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
    delete movies;
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // you implement this method

    for (const auto &movie : *movies) {
        if (movie.get_name() == name) { 
            return false; 
        }
    }
    movies->push_back(Movie(name, rating, watched));
    return true;
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {
   // you implement this method
    //Movie* moviepunt{ nullptr };

    for (auto &movie: *movies) {
        //moviepunt = &movies[i];
        if (movie.get_name()== name) {
            movie.increment_watched();
            return true;
        }
        
    }
    return false;
}

/*
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    */
void Movies::display() const {
   // You implement this method
    
    if (movies->empty()) {
        std::cout << "Movies esta vacío" << std::endl;
    }
    else
    {
        for (const auto &movie : *movies) {
            movie.display();
        }
    }
    
}
