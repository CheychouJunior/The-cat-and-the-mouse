#include<iostream>
#include<cstdlib>
#include<ctime>
#include"cat.hpp"

Cat::Cat(int gender, int position[], int map[][SIZE]){
    this->gender = gender;
    this->pos[0] =  position[0];
    this->pos[1] = position[1];
    map[this->pos[0]][this->pos[1]] = this->gender;
    this->TTL = 5;
    this->Total_moves = 0;
    this->isAlive = true;
}

bool Cat::isvalid(int row, int col, int map[][SIZE], vector<vector<bool>> visited){
    bool result = false;

    //check if cell is in the bounds of the matrix
    if (row >= 0 && row < SIZE  && col >= 0 && col < SIZE && visited[row][col] == false)
        //check if cell is not blocked and not previously tried
        if (map[row][col] != 5 && map[row][col] != this->gender)
            result = true;
    return result;
}

int Cat::minDistance(int grid[][SIZE], int row, int col){
    QItem source(row, col, 0);

    // Applying BFS on matrix cells starting from source
    vector <QItem> queue;
    queue.insert(queue.begin(), QItem(source.row, source.col, 0));
    vector <vector<bool> > visited(SIZE,vector<bool>(SIZE));
    visited[source.row][source.col] = true;

    while(queue.size() > 0){
        QItem p = queue.at(queue.size()-1);
        queue.pop_back();

        if(grid[p.row][p.col] == 3 || grid[p.row][p.col] == 4)
            return p.dist;
        
        // moving up
        if(isvalid(p.row - 1, p.col, grid, visited)){
            queue.insert(queue.begin(), QItem(p.row-1, p.col, p.dist+1));
            visited[p.row-1][p.col] = true;
        }

        // moving down
        if(isvalid(p.row + 1, p.col, grid, visited)){
            queue.insert(queue.begin(), QItem(p.row+1, p.col, p.dist+1));
            visited[p.row+1][p.col] = true;
        }

        // moving left
        if(isvalid(p.row, p.col - 1, grid, visited)){
            queue.insert(queue.begin(), QItem(p.row, p.col - 1, p.dist+1));
            visited[p.row][p.col - 1] = true;
        }

        // moving right
        if(isvalid(p.row, p.col + 1, grid, visited)){
            queue.insert(queue.begin(), QItem(p.row, p.col+1, p.dist+1));
            visited[p.row][p.col +1] = true;
        }
    }
    return -1;
}

void Cat::move(int grid[][SIZE]){
    int dist, row, column;

    if(this->TTL == 0){
        grid[this->pos[0]][this->pos[1]] = 0;
        this->isAlive = false;
    }

    if(this->isAlive){
        dist = this->minDistance(grid, this->pos[0], this->pos[1]);
        for(int i = 0; i< 4; i++){
            row = this->pos[0] + d_row[i];
            column = this->pos[1] + d_col[i];

            if(row < 0 || column < 0) continue;
            if(row >= SIZE || column >= SIZE) continue;
            if(grid[row][column] == 5 || grid[row][column] == this->gender) continue;

            if(this->minDistance(grid, row, column) == dist - 1){
                grid[this->pos[0]][this->pos[1]] = 0;
                grid[row][column] = this->gender;
                this->pos[0] = row;
                this->pos[1] = column;
                this->TTL--;
                this->Total_moves++;
                break;
            }
        }
    }
}

void Cat::eat(vector<Mouse> *m){
    if(this->isAlive){
        for(int i = 0; i < m->size(); i++){
            if(this->pos[0] == m->at(i).pos[0] && this->pos[1] == m->at(i).pos[1] && m->at(i).isAlive){
                m->at(i).isAlive = false;
                this->TTL += 4; //increases his lifetime by 3 when he eats
            }
        }
    }
}

int Cat::reproduce(vector<Cat> *c, int map[][SIZE]){
    int j = -1, row, column, x, y;
    srand(time(0));
    
    for(int i = 0; i < c->size(); i++){
        if(this->isAlive){
            if(this->pos[0] == c->at(i).pos[0] && this->pos[1] == c->at(i).pos[1] && this->gender != c->at(i).gender && c->at(i).isAlive){
                map[this->pos[0]][this->pos[1]] = 0;
                //map[c.get(i).pos[0]][c.get(i).pos[1]] = 0;
                Cat c_elt((rand()%2)+1, this->pos , map);
                c->push_back(c_elt);
                row = this->pos[0];
                column = this->pos[1];
                
                // the cat moves to the next adjacent cell
                for(int k = 0; k< 8; k++){
                    x = row + d_row[k];
                    y = column + d_col[k];
    
                    if(x < 0 || y < 0) continue;
                    if(x >= SIZE || y >= SIZE) continue;
                    if(map[x][y] != 0) continue;

                    this->pos[0] = x;
                    this->pos[1] = y;
                    break;
                }

                // his or her partner moves to the next free adjacent cell
                for(int k = 0; k< 8; k++){
                    x = row + d_row[k];
                    y = column + d_col[k];
    
                    if(x < 0 || y < 0) continue;
                    if(x >= SIZE || y >= SIZE) continue;
                    if(map[x][y] != 0) continue;

                    c->at(i).pos[0] = x;
                    c->at(i).pos[1] = y;
                    break;
                }

                j = i;
                break;
            }
        }
    }
    return j;
}
