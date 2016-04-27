#ifndef MOVIETREE_H
#define MOVIETREE_H
#include <iostream>
struct MovieNode{
    int ranking;
    std::string title;
    int year;
    int quantity;
    std::string genre;
    MovieNode *parent;
    MovieNode *leftChild;
    MovieNode *rightChild;

    MovieNode(){};

    MovieNode(int in_ranking, std::string in_title, int in_year, int in_quantity)
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        quantity = in_quantity;
    }

};

class MovieTree
{
    public:
        MovieTree();
        ~MovieTree();
        void deleteAll(MovieNode *root);
        void printMovieInventory();
        void fc();
        void test(MovieNode *root);
        void deleteMovieNode(std::string title, MovieNode *root);
        void addnewmovie(MovieNode *test, MovieNode *root);
        void returnMovie(std::string title, MovieNode *root);
        void countMovieNodes(MovieNode *root, int counter);
        void printMovieInventory(MovieNode *root);
        void printGenre(std::string genre, MovieNode *root);
        void printyear(int starty, int endy, MovieNode *root);
        void findMovie(std::string title, MovieNode *root);
        void editMovie(std::string title, MovieNode *root, std::string newtitle, int newyear, std::string newgenre);
        bool testformovie(std::string title, MovieNode *root);
        void rentMovie(std::string title, MovieNode *root);
        //MovieNode insertMovie(MovieNode *root, int ranking, std::string title, int year, int quantity);
    protected:
    private:
//        void printMovieInventory(MovieNode * node);
        //MovieNode* treeMinimum(MovieNode *node);
        //MovieNode* search(std::string title);
        MovieNode *root2=new MovieNode;
        //void deleteAll(MovieNode *root);
        int tmpCount=0;

};

#endif // MOVIETREE_H
