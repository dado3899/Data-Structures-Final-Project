#include "MovieTree.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    MovieTree movietree;
    int ranker=0;
    int counter=0;
    ifstream inFile;
    string Data="Blank";
    MovieNode *root=NULL;
    inFile.open(argv[1]);
    //inFile.open("MovieText.txt");
    if(inFile.good())
    {
        while(getline(inFile, Data))
        {
            stringstream ss(Data);
            string newSS="Blank";

            MovieNode *node = new MovieNode();
            node->parent=NULL;
            node->leftChild=NULL;
            node->rightChild=NULL;

            getline(ss, newSS, ',');
            stringstream rank(newSS);
            rank >> node->ranking;

            getline(ss, newSS, ',');
            stringstream title(newSS);
            getline(title, node->title);

            getline(ss, newSS, ',');
            stringstream year(newSS);
            year >> node->year;

            getline(ss, newSS, ',');
            stringstream genre(newSS);
            getline(genre, node->genre);

            getline(ss, newSS, ',');
            stringstream quantity(newSS);
            quantity >> node->quantity;

            ranker=ranker+1;
            MovieNode *tmp=root;
            MovieNode *Parent=NULL;
                while(tmp!=NULL)
                {
                    Parent=tmp;
                    if((node->title).compare(tmp->title) <0)
                    {
                        tmp=tmp->leftChild;
                    }
                    else
                    {
                        tmp=tmp->rightChild;
                    }
                }
                if(Parent==NULL)
                {
                    root=node;
                }
                else if(((node->title).compare(Parent->title)) <0)
                {
                    Parent->leftChild=node;
                    node->parent=Parent;
                }
                else
                {
                    Parent->rightChild=node;
                    node->parent=Parent;
                }
        }
    }
    int input;
    while(input!=11)
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Rent a movie" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Delete a movie" << endl;
        cout << "5. Count the movies" << endl;
        cout << "6. Return a movie" << endl;
        cout << "7. Add a new movie" << endl;
        cout << "8. Find a genre" << endl;
        cout << "9. Find based on release" << endl;
        cout << "10. Update movie info" << endl;
        cout << "11. Quit" << endl;
        cin >> input;

        if(input==1)
        {
            char input[100];
            cin.getline(input,sizeof(input));
            string Name="Blank";
            cout<<"Enter title:"<<endl;
            getline(cin, Name);
            movietree.findMovie(Name, root);
        }
        if(input==2)
        {
            char input[100];
            cin.getline(input,sizeof(input));
            string Name="Blank";
            cout<<"Enter title:"<<endl;
            getline(cin, Name);
            movietree.rentMovie(Name, root);
        }
        if(input==3)
        {
            movietree.printMovieInventory(root);
        }
        if(input==4)
        {
            char input[100];
            cin.getline(input,sizeof(input));
            string Name="Blank";
            cout<<"Enter title:"<<endl;
            getline(cin, Name);
            movietree.deleteMovieNode(Name, root);
        }
        if(input==5)
        {
            movietree.countMovieNodes(root, counter);
            movietree.fc();
        }
        if(input==6)
        {
            char input[100];
            cin.getline(input,sizeof(input));
            string Name="Blank";
            cout<<"Enter title:"<<endl;
            getline(cin, Name);
            movietree.returnMovie(Name, root);
        }
        if(input==7)
        {
            char input[100];
            cin.getline(input,sizeof(input));
            string Name="Blank";
            cout<<"Enter title:"<<endl;
            getline(cin, Name);
            if(movietree.testformovie(Name, root)==true)
            {
                cout<<"Movie is already in the system"<<endl;
            }
            else
            {
                ranker=ranker+1;
                MovieNode *test=new MovieNode;
                test->ranking=ranker;
                cout<<"Enter year:"<<endl;
                cin >> test->year;
                cout<<"Enter quantity:"<<endl;
                cin >> test->quantity;
                char input[100];
                cin.getline(input,sizeof(input));
                string genre2="Blank";
                cout<<"Enter genre:"<<endl;
                getline(cin, genre2);
                test->title=Name;
                test->genre=genre2;
                test->leftChild=NULL;
                test->rightChild=NULL;
                movietree.addnewmovie(test, root);
            }
        }
        if(input==8)
        {
            char input[100];
            cin.getline(input,sizeof(input));
            string genre1="Blank";
            cout<<"Enter genre:"<<endl;
            getline(cin, genre1);
            cout<<"======"<<genre1<<"======"<<endl;
            movietree.printGenre(genre1, root);
        }
        if(input==9)
        {
            int startyear;
            int endyear;
            cout<<"Enter the starting year:"<<endl;
            cin>>startyear;
            cout<<"Enter the ending year:"<<endl;
            cin>>endyear;
            cout<<"======"<<startyear<<"-"<<endyear<<"======"<<endl;
            movietree.printyear(startyear, endyear, root);
        }
        if(input==10)
        {
            int decision;
            char input[100];
            cin.getline(input,sizeof(input));
            string Name="Blank";
            cout<<"Enter title:"<<endl;
            getline(cin, Name);
            if(movietree.testformovie(Name, root)==true)
            {
                cout<<"what would you like to change?"<<endl;
                cout<<"1. Title"<<endl;
                cout<<"2. Year"<<endl;
                cout<<"3. Genre"<<endl;
                cout<<"4. Nevermind"<<endl;
                cin>>decision;
                if(decision==1)
                {
                   char input[100];
                    cin.getline(input,sizeof(input));
                    string newtitle="Blank";
                    cout<<"Enter new title:"<<endl;
                    getline(cin, newtitle);
                    movietree.editMovie(Name, root, newtitle, -535, "");
                }
                if(decision==2)
                {
                    int newyear;
                    cout<<"Enter new year:"<<endl;
                    cin>>newyear;
                    movietree.editMovie(Name, root, "", newyear, "");
                }
                if(decision==3)
                {
                    char input[100];
                    cin.getline(input,sizeof(input));
                    string newgenre1="Blank";
                    cout<<"Enter new genre:"<<endl;
                    getline(cin, newgenre1);
                    movietree.editMovie(Name, root, "", -535, newgenre1);
                }
            }
            else
            {
                cout<<"Movie does not exist"<<endl;
            }
        }
    }
    cout << "Goodbye!" << endl;
    movietree.test(root);
    return 0;
}
