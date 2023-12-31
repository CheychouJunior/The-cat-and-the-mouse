#ifndef __MOUSE__
    #define __MOUSE__

    #include"QItem.hpp"
    #include"maize.hpp"
    #include<vector>

    using namespace std;

    class Mouse{
        private:
            const int d_row[8] = {1, -1, 0, 0, 1, 1, -1, -1}, d_col[8] = {0, 0, 1, -1, 1, -1, 1, -1};
            int minDistance(int grid[][SIZE], int row, int col);
            bool isvalid(int row, int col, int map[][SIZE], vector<vector<bool>> visited);
        public:
            bool isAlive;
            int gender, pos[2], TTL, Total_moves;
            Mouse(int gender, int position[], int map[][SIZE]);
            void move(int grid[][SIZE]);
            void eat(vector<Maize> *m);
            int reproduce(vector<Mouse> *m, int map[][SIZE]);
    };

#endif