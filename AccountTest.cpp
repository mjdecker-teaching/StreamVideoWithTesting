/*
  AccountTest.cpp

  Test program for class Account
*/

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "Account.hpp"

TEST_CASE( "No streaming", "[Account]" ) {

    Account customer("FredFred");

    REQUIRE(customer.name() == "FredFred");
    REQUIRE(customer.data() == "");
}


TEST_CASE( "Movie - lotr", "[Account]" ) {

    Account customer("Jane");

    Video lotr("The Lord of the Rings: The Fellowship of the Ring", Video::MOVIE, 3, 18, 0);

    Stream lotrStream(lotr, 1);

    customer.addStream(lotrStream);

    REQUIRE(customer.name() == "Jane");
    REQUIRE(customer.data() == "Jane,MOVIE,The Lord of the Rings: The Fellowship of the Ring,3,18,3\n");
}

TEST_CASE( "Movie - lotr * 3", "[Account]" ) {

    Account customer("Jane");

    Video lotr1("The Lord of the Rings: The Fellowship of the Ring", Video::MOVIE, 3, 18, 0);
    Video lotr2("The Lord of the Rings: The Two Tower",              Video::MOVIE, 3, 19, 0);
    Video lotr3("The Lord of the Rings: The Return of the King",     Video::MOVIE, 3, 20, 0);

    Stream lotr1Stream(lotr1, 1);
    Stream lotr2Stream(lotr2, 2);
    Stream lotr3Stream(lotr3, 3);

    customer.addStream(lotr1Stream);
    customer.addStream(lotr2Stream);
    customer.addStream(lotr3Stream);

    REQUIRE(customer.name() == "Jane");
    REQUIRE(customer.data() == 
      "Jane,MOVIE,The Lord of the Rings: The Fellowship of the Ring,3,18,3\n"
      "Jane,MOVIE,The Lord of the Rings: The Two Tower,6,38,6\n"
      "Jane,MOVIE,The Lord of the Rings: The Return of the King,9,60,9\n"
    );
}

TEST_CASE( "Original", "[Account]" ) {

    Account customer("L-a");

    Video original("The Original Movie", Video::ORIGINAL, 2, 7, 1);

    Stream originalStream(original, 1);

    customer.addStream(originalStream);

    REQUIRE(customer.name() == "L-a");
    REQUIRE(customer.data() == 
      "L-a,ORIGINAL,The Original Movie,2,7,1\n"
    );
}

TEST_CASE( "Original * 2", "[Account]" ) {

    Account customer("L-a");

    Video original("The Original Movie",     Video::ORIGINAL, 2, 7, 1);
    Video unOriginal("The Unoriginal Movie", Video::ORIGINAL, 1, 23, 1);

    Stream originalStream(original, 1);
    Stream unOriginalStream(unOriginal, 3);

    customer.addStream(originalStream);
    customer.addStream(unOriginalStream);

    REQUIRE(customer.name() == "L-a");
    REQUIRE(customer.data() == 
      "L-a,ORIGINAL,The Original Movie,2,7,1\n"
      "L-a,ORIGINAL,The Unoriginal Movie,3,69,3\n"
    );
}

TEST_CASE( "TVSHOW", "[Account]" ) {

    Account customer("Marcel");

    Video friends("Friends", Video::TVSHOW, 0, 26, 236);

    Stream friendsStream(friends, 1);

    customer.addStream(friendsStream);

    REQUIRE(customer.name() == "Marcel");
    REQUIRE(customer.data() == 
      "Marcel,TVSHOW,Friends,0,26,1\n"
    );
}

TEST_CASE( "TVSHOW - Friends & TNG", "[Account]" ) {

    Account customer("Will");

    Video friends("Friends",                        Video::TVSHOW, 0, 26, 236);
    Video tng("Star Trek: The Next Generation", Video::TVSHOW, 0, 52, 178);

    Stream friendsStream(friends, 1);
    Stream tngStream(tng, 2);

    customer.addStream(friendsStream);
    customer.addStream(tngStream);

    REQUIRE(customer.name() == "Will");
    REQUIRE(customer.data() == 
      "Will,TVSHOW,Friends,0,26,1\n"
      "Will,TVSHOW,Star Trek: The Next Generation,0,104,2\n"
    );
}

TEST_CASE( "All", "[Account]" ) {

    Account customer("Potato");

    Video lotr1("The Lord of the Rings: The Fellowship of the Ring", Video::MOVIE, 3, 18, 0);
    Video lotr2("The Lord of the Rings: The Two Tower",              Video::MOVIE, 3, 19, 0);
    Video lotr3("The Lord of the Rings: The Return of the King",     Video::MOVIE, 3, 20, 0);

    Video original("The Original Movie",     Video::ORIGINAL, 2, 7, 1);
    Video unOriginal("The Unoriginal Movie", Video::ORIGINAL, 1, 23, 1);

    Video friends("Friends",                        Video::TVSHOW, 0, 26, 236);
    Video tng("Star Trek: The Next Generation", Video::TVSHOW, 0, 52, 178);

    Stream lotr1Stream(lotr1, 1);
    Stream lotr2Stream(lotr2, 2);
    Stream lotr3Stream(lotr3, 3);

    Stream originalStream(original, 1);
    Stream unOriginalStream(unOriginal, 3);

    Stream friendsStream(friends, 1);
    Stream tngStream(tng, 2);

    customer.addStream(lotr1Stream);
    customer.addStream(lotr2Stream);
    customer.addStream(lotr3Stream);

    customer.addStream(originalStream);
    customer.addStream(unOriginalStream);

    customer.addStream(friendsStream);
    customer.addStream(tngStream);

    REQUIRE(customer.name() == "Potato");
    REQUIRE(customer.data() == 
      "Potato,MOVIE,The Lord of the Rings: The Fellowship of the Ring,3,18,3\n"
      "Potato,MOVIE,The Lord of the Rings: The Two Tower,6,38,6\n"
      "Potato,MOVIE,The Lord of the Rings: The Return of the King,9,60,9\n"
      "Potato,ORIGINAL,The Original Movie,2,7,1\n"
      "Potato,ORIGINAL,The Unoriginal Movie,3,69,3\n"
      "Potato,TVSHOW,Friends,0,26,1\n"
      "Potato,TVSHOW,Star Trek: The Next Generation,0,104,2\n"
    );
}
