#ifndef __CAT__
    #define __CAT__

    #include"mouse.hpp"

    using namespace std;

    class Cat{
        private:
            const int d_row[8] = {1, -1, 0, 0, 1, 1, -1, -1}, d_col[8] = {0, 0, 1, -1, 1, -1, 1, -1};
            int minDistance(int grid[][SIZE], int row, int col);
            bool isvalid(int row, int col, int map[][SIZE], vector<vector<bool>> visited);
        public:
            bool isAlive;
            int gender, pos[2], TTL, Total_moves;
            Cat(int gender, int position[], int map[][SIZE]);
            void move(int grid[][SIZE]);
            void eat(vector<Mouse> *m);
            int reproduce(vector<Cat> *c, int map[][SIZE]);
    };

#endif