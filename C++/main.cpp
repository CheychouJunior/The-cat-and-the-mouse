#include<iostream>
#include<unistd.h>
#include"cat.hpp"
#include"mouse.hpp"

using namespace std;

// function to print a line corresponding to the size of a matrice
void print_line(int size){
    for(int i= 0; i< size * 4.2; i++) // 4.2 represents the number of '-' per cell
        cout<<"-";
    cout<<endl;
}

// function to print the map
void print_grid(int grid[][SIZE], vector<Cat> c, vector<Mouse> m){				   
    system("clear"); //clear the screen
    cout<<"\n\t\t";
    print_line(SIZE);
    for(int i = 0; i < SIZE; i++){
        cout<<"\t\t|";
        for(int j = 0; j < SIZE; j++){
            if(grid[i][j] == 0)
                cout<<"   |";
            else if(grid[i][j] == 1)
                cout<<" O |";
            else if(grid[i][j] == 2)
                cout<<" o |";
            else if(grid[i][j] == 3)
                cout<<" x |";
            else if(grid[i][j] == 4)
                cout<<" × |";
            else if(grid[i][j] == 5)
                cout<<" . |";
        }
        cout<<"\n\t\t";
        print_line(SIZE);
    }
    cout<<"\nKey :";
    cout<<"\t'O' = male cat, 'o' = female cat, 'x' = male mouse, '×' = female mouse, '.' = maize";
    cout<<"\n\n";
    for(int i = 0; i < c.size(); i++){
        if(c.at(i).isAlive)
            cout<<"cat"<<i+1<<" TTL = "<<c.at(i).TTL<<"\t";
    }
    cout<<"\n\n";
    for(int i = 0; i < m.size(); i++){
        if(m.at(i).isAlive)
            cout<<"mouse"<<i+1<<" TTL = "<<m.at(i).TTL<<"\t";
    }
    cout<<endl;
    sleep(1);
}

int main(){
    srand(time(0));
    int grid[SIZE][SIZE] = {0};
    int pos[2], x;
    vector<Mouse> m;
    vector<Cat> cat;
    vector<Maize> mais;

    for(int i = 0; i < 5; i++){
        pos[0] = rand()%SIZE;
        pos[1] = rand()%SIZE;
        while(grid[pos[0]][pos[1]] != 0){
            pos[0] = rand()%SIZE;
            pos[1] = rand()%SIZE;
        }
        Cat cat_elt((rand()%2)+1, pos, grid);
        cat.push_back(cat_elt);
    }

    for(int i = 0; i < 5; i++){
        pos[0] = rand()%SIZE;
        pos[1] = rand()%SIZE;
        while(grid[pos[0]][pos[1]] != 0){
            pos[0] = rand()%SIZE;
            pos[1] = rand()%SIZE;
        }
        Mouse m_elt((rand()%2)+3, pos, grid);
        m.push_back(m_elt);
    }

    for(int i = 0; i < 5; i++){
        pos[0] = rand()%SIZE;
        pos[1] = rand()%SIZE;
        while(grid[pos[0]][pos[1]] != 0){
            pos[0] = rand()%SIZE;
            pos[1] = rand()%SIZE;
        }
        Maize mais_elt(pos, grid);
        mais.push_back(mais_elt);
    }

    int j;
    while(true){
        for(int i = 0; i < cat.size(); i++){
            if(cat.at(i).isAlive){
                j = -1;
                j = cat.at(i).reproduce(&cat,grid);
                print_grid(grid, cat, m);
                if(j != -1){
                    grid[cat.at(i).pos[0]][cat.at(i).pos[1]] = cat.at(i).gender;
                    grid[cat.at(j).pos[0]][cat.at(j).pos[1]] = cat.at(j).gender;
                    print_grid(grid, cat, m);
                }
                cat.at(i).move(grid);
                cat.at(i).eat(&m);
                print_grid(grid, cat, m);
            }
        }

        for(int i = 0; i < m.size(); i++){
            if(m.at(i).isAlive){
                j = -1;
                j = m.at(i).reproduce(&m,grid);
                print_grid(grid, cat, m);
                if(j != -1){
                    grid[m.at(i).pos[0]][m.at(i).pos[1]] = m.at(i).gender;
                    grid[m.at(j).pos[0]][m.at(j).pos[1]] = m.at(j).gender;
                    print_grid(grid, cat, m);
                }
                m.at(i).move(grid);
                m.at(i).eat(&mais);
                print_grid(grid, cat, m);
            }
        }
    }
    return 0;
}
   
