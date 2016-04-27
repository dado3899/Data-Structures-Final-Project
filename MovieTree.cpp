#include "MovieTree.h"

#include "MovieTree.h"
void MovieTree::deleteMovieNode(std::string Name, MovieNode *root)
{
    MovieNode *tmp=root;
    while(tmp!=NULL)
    {
        if(Name==tmp->title)
        {
            MovieNode *tmp2=tmp;
            if(tmp2->rightChild!=NULL)
            {
                tmp2=tmp2->rightChild;

                if(tmp->leftChild==NULL && tmp->rightChild!=NULL)
                {
                    tmp->parent->rightChild=tmp2;
                    tmp2->parent=tmp->parent;
                    delete tmp;
                    return;
                }

                if(tmp2->leftChild==NULL && tmp2->rightChild==NULL)
                {
                    tmp->rightChild=NULL;
                    tmp->quantity=tmp2->quantity;
                    tmp->ranking=tmp2->ranking;
                    tmp->title=tmp2->title;
                    tmp->year=tmp2->year;
                    delete tmp2;
                    return;
                }
                else if(tmp2->leftChild==NULL)
                {
                    tmp->rightChild=tmp2->rightChild;
                    tmp2->rightChild->parent=tmp;
                    tmp->quantity=tmp2->quantity;
                    tmp->ranking=tmp2->ranking;
                    tmp->title=tmp2->title;
                    tmp->year=tmp2->year;
                    delete tmp2;
                    return;
                }
                while(tmp2->leftChild!=NULL)
                {
                    tmp2=tmp2->leftChild;
                }
                if(tmp2->rightChild!=NULL)
                {
                    tmp2->rightChild->parent=tmp2->parent;
                    tmp2->parent->leftChild=tmp2->rightChild;
                }
                else
                {
                    tmp2->parent->leftChild=NULL;
                }
                tmp->quantity=tmp2->quantity;
                tmp->ranking=tmp2->ranking;
                tmp->title=tmp2->title;
                tmp->year=tmp2->year;
                delete tmp2;
                return;
            }
            else
            {
                if(tmp2->leftChild==NULL)
                {
                    if((Name).compare(tmp->parent->title) < 0)
                    {
                        tmp2->parent->leftChild=NULL;
                    }
                    else
                    {
                        tmp2->parent->rightChild=NULL;
                    }
                    delete tmp2;
                    return;
                }
                tmp2=tmp2->leftChild;
                tmp->leftChild=NULL;
                tmp->quantity=tmp2->quantity;
                tmp->ranking=tmp2->ranking;
                tmp->title=tmp2->title;
                tmp->year=tmp2->year;
                delete tmp2;
                return;
            }
        }
        else if((Name).compare(tmp->title) < 0)
        {
            tmp=tmp->leftChild;

        }
        else
        {
            tmp=tmp->rightChild;
        }
    }
    std::cout << "Movie not found." << std::endl;
}
void MovieTree::fc()
{
    std::cout<<"Tree contains: "<< tmpCount <<" movies."<< std::endl;
}
void MovieTree::countMovieNodes(MovieNode *root,int counter)
{
    tmpCount=counter;
    MovieNode *tmp=root;
    if(tmp->leftChild!=NULL)
    {
        countMovieNodes(tmp->leftChild,tmpCount);
    }
    tmpCount=tmpCount+1;
    if(tmp->rightChild!=NULL)
    {
        countMovieNodes(tmp->rightChild,tmpCount);
    }
}
void MovieTree::findMovie(std::string Name, MovieNode *root)
{
    MovieNode *tmp=root;
    while(tmp!=NULL)
    {
        if(Name==tmp->title)
        {
            std::cout << "Movie Info:" << std::endl;
            std::cout << "===========" << std::endl;
            std::cout << "Ranking:" << tmp->ranking << std::endl;
            std::cout << "Title:" << tmp->title << std::endl;
            std::cout << "Year:" << tmp->year << std::endl;
            std::cout << "Quantity:" << tmp->quantity << std::endl;
            std::cout << "Genre:" << tmp->genre << std::endl;
            return;
        }
        else if((Name).compare(tmp->title) < 0)
        {
            tmp=tmp->leftChild;

        }
        else
        {
            tmp=tmp->rightChild;
        }
    }
    std::cout << "Movie not found." << std::endl;
}

bool MovieTree::testformovie(std::string Name, MovieNode *root)
{
    MovieNode *tmp=root;
    while(tmp!=NULL)
    {
        if(Name==tmp->title)
        {
            return true;
        }
        else if((Name).compare(tmp->title) < 0)
        {
            tmp=tmp->leftChild;

        }
        else
        {
            tmp=tmp->rightChild;
        }
    }
    return false;
}

void MovieTree::rentMovie(std::string Name, MovieNode *root)
{
    MovieNode *tmp=root;
    while(tmp!=NULL)
    {
        if(Name==tmp->title)
        {
            if(tmp->quantity!=0)
            {
                tmp->quantity=tmp->quantity-1;
                std::cout << "Movie has been rented." << std::endl;
                std::cout << "Movie Info:" << std::endl;
                std::cout << "===========" << std::endl;
                std::cout << "Ranking:" << tmp->ranking << std::endl;
                std::cout << "Title:" << tmp->title << std::endl;
                std::cout << "Year:" << tmp->year << std::endl;
                std::cout << "Quantity:" << tmp->quantity << std::endl;
                std::cout << "Genre:" << tmp->genre << std::endl;
                if(tmp->quantity==0)
                {
                    deleteMovieNode(tmp->title, root);
                }
                return;
            }
            else
            {
                std::cout << "Movie out of stock." << std::endl;
                return;
            }
        }
        else if((Name).compare(tmp->title) < 0)
        {
            tmp=tmp->leftChild;
        }
        else
        {
            tmp=tmp->rightChild;
        }
    }
    std::cout << "Movie not found." << std::endl;
}

void MovieTree::printMovieInventory(MovieNode *root)
{
    MovieNode *tmp=root;
    if(tmp->leftChild!=NULL)
    {
        printMovieInventory(tmp->leftChild);
    }
    std::cout<<"Movie: "<<tmp->title<<" "<<tmp->quantity<<std::endl;
    if(tmp->rightChild!=NULL)
    {
        printMovieInventory(tmp->rightChild);
    }
}
void MovieTree::deleteAll(MovieNode *root)
{
    MovieNode *tmp=root;
    if(tmp!=NULL)
    {
        if(tmp->leftChild!=NULL)
        {
            deleteAll(tmp->leftChild);
        }
        if(tmp->rightChild!=NULL)
        {
            deleteAll(tmp->rightChild);
        }
        std::cout<<"Deleting: "<<tmp->title<<std::endl;
        delete tmp;
    }
}
void MovieTree::returnMovie(std::string Name, MovieNode *root)
{
    MovieNode *tmp=root;
    while(tmp!=NULL)
    {
        if(Name==tmp->title)
        {
            tmp->quantity=tmp->quantity+1;
            std::cout << "Movie has been returned." << std::endl;
            return;
        }
        else if((Name).compare(tmp->title) < 0)
        {
            tmp=tmp->leftChild;
        }
        else
        {
            tmp=tmp->rightChild;
        }
    }
    std::cout << "Movie not found." << std::endl;
}

void MovieTree::addnewmovie(MovieNode *test, MovieNode *root)
{
    MovieNode *tmp=root;
    while(tmp!=NULL)
    {
        if((test->title).compare(tmp->title) < 0)
        {
            if(tmp->leftChild==NULL)
            {
                test->parent=tmp;
                tmp->leftChild=test;
                return;
            }
            tmp=tmp->leftChild;
        }
        else
        {
            if(tmp->rightChild==NULL)
            {
                test->parent=tmp;
                tmp->rightChild=test;
                return;
            }
            tmp=tmp->rightChild;
        }
    }
}

void MovieTree::printGenre(std::string genre, MovieNode *root)
{
    //std::cout<<genre<<std::endl;
    MovieNode *tmp=root;
    if(tmp->leftChild!=NULL)
    {
        printGenre(genre, tmp->leftChild);
    }
    //std::cout<<genre<<genre.length()<<" "<<tmp->genre.length()<<tmp->genre<<std::endl;
    if(genre==tmp->genre)
    {
        std::cout<<"Movie: "<<tmp->title<<" "<<tmp->quantity<<std::endl;
    }
    if(tmp->rightChild!=NULL)
    {
        printGenre(genre, tmp->rightChild);
    }
}

void MovieTree::printyear(int starty, int endy, MovieNode *root)
{
    MovieNode *tmp=root;
    if(tmp->leftChild!=NULL)
    {
        printyear(starty, endy, tmp->leftChild);
    }
    int i=tmp->year;
    if(i >= starty && i <= endy)
    {
        std::cout<<"Movie: "<<tmp->title<<" "<<tmp->quantity<<" "<<tmp->year<<std::endl;
    }
    if(tmp->rightChild!=NULL)
    {
        printyear(starty, endy, tmp->rightChild);
    }
}

void MovieTree::editMovie(std::string Name, MovieNode *root, std::string newtitle, int newyear, std::string newgenre)
{
    MovieNode *tmp=root;
    while(tmp!=NULL)
    {
        if(Name==tmp->title)
        {
            if(newtitle == "")
            {
                newtitle=tmp->title;
            }
            if(newyear==-535)
            {
                newyear=tmp->year;
            }
            if(newgenre == "")
            {
                newgenre=tmp->genre;
            }
            tmp->title=newtitle;
            tmp->year=newyear;
            tmp->genre=newgenre;
            return;
        }
        else if((Name).compare(tmp->title) < 0)
        {
            tmp=tmp->leftChild;
        }
        else
        {
            tmp=tmp->rightChild;
        }
    }
}

void MovieTree::test(MovieNode *root)
{
    root2=root;
}
MovieTree::MovieTree()
{
    //ctor
}

MovieTree::~MovieTree()
{
    deleteAll(root2);
}
