#ifndef __MAIZE__
    #define __MAIZE__

    using namespace std;

    class Maize{
        public:
            bool isAlive;
            int pos[2], TTL, Total_moves;
            Maize(int position[], int map[][SIZE]){
                this->pos[0] =  position[0];
                this->pos[1] = position[1];
                map[this->pos[0]][this->pos[1]] = 5;
                this->isAlive = true;
            }

    };

#endif