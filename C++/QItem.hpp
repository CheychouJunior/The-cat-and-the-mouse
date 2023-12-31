#ifndef __Q_ITEM__
    #define __Q_ITEM__
    #define SIZE 10

    class QItem{
        public:
            int row, col, dist;
            QItem(int row, int col, int dist){
                this->row = row;
                this->col = col;
                this->dist = dist;
            }
    };

#endif