
#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <vector>
#include <map>
#include <deque>


using namespace std;

enum types{
    hop = 0,
    turn_left,
    turn_right,
    infect,
    if_empty,
    if_wall,
    if_random,
    if_enemy,
    go
};

struct instruction{
    int type;
    int moveToLine;
};

class Species{
    
    private:
        vector<instruction> instructionSet;
        string speciesName;
        char abbreviation;
 
    public:
        Species(){
        }
        Species(string name, char abr) : speciesName(name), abbreviation(abr){
        }

	Species& operator=(Species& rhs){
	    (*this).instructionSet = rhs.instructionSet;
	    (*this).speciesName = rhs.speciesName;
	    (*this).abbreviation = rhs.abbreviation;
	    return *this;
	}
        
        void addInstruction(types t, int mtl = -1){
            instruction newInst = {t, mtl};
            instructionSet.push_back(newInst);
        }
        
        instruction nextInstruction(int line){
            return instructionSet.at(line);
        }
        
        char speciesAbbreviation(){
            return abbreviation;
        }
};


class Grid {
    private: 
        class Creature{
            private:
                Species speciesType;
                char direction;
                int pc;
                Grid& grid;

            public:
                Creature(Species s, char d, Grid& g) : speciesType(s), direction(d), grid(g){
                    pc = 0;
                }
                void run(){
                    instruction currentInstruction = speciesType.nextInstruction(pc);
                    switch (currentInstruction.type){
                        case 0: 
                            hop(); 
                            break;
                        case 1: 
                            left(); 
                            break;
                        case 2: 
                            right(); 
                            break;
                        case 3: 
                            infect(); 
                            break;
                        case 4: 
                            if_empty(currentInstruction.moveToLine); 
                            break;
                        case 5: 
                            if_wall(currentInstruction.moveToLine); 
                            break;
                        case 6: 
                            if_random(currentInstruction.moveToLine); 
                            break;
                        case 7: 
                            if_enemy(currentInstruction.moveToLine); 
                            break;
                        case 8: 
                            go(currentInstruction.moveToLine); 
                            break;    
                    }
                }  
                
                void hop(){
                    if(grid.isEmpty(direction)){
                        grid.move(direction);
                    }
                    ++pc;
                }
        
                void left(){
                    if(direction == 'n')
                        direction = 'w';
                    else if(direction == 'w')
                        direction = 's';
                    else if(direction == 's')
                        direction = 'e';
                    else if(direction == 'e')
                        direction = 'n';
                    ++pc;
                }
                
                void right(){
                    if(direction == 'n')
                        direction = 'e';
                    else if(direction == 'w')
                        direction = 'n';
                    else if(direction == 's')
                        direction = 'w';
                    else if(direction == 'e')
                        direction = 's';
                    ++pc;
                }
                
                void infect(){
                    if(grid.isEnemy(direction)){
                        grid.infection(direction, speciesType);
		    		}
		    		++pc;
                }
                
                void if_empty(int n){
                    // Check grid if the direction in front is empty
                    if(grid.isEmpty(direction))
                        pc = n;
                    else
                        ++pc;
		    		run();
                }
                
                void if_wall(int n){
                    if(grid.isWall(direction))
                        pc = n;
                    else
                        ++pc;
                    run();
                }
                
                void if_random(int n){
                    int random = rand();
                    if(random%2 == 1)
                        pc = n;
                    else
                        ++pc;
                    run();
                }
                
                void if_enemy(int n){
                    if(!grid.isWall(direction) && !grid.isEmpty(direction)){
                        if(grid.isEnemy(direction))
                            pc = n;
						else
			    			++pc;
                    }
		    		else
		    			++pc;
                    run();
                }
                
                void go(int n){
                    pc = n;
                    run();
                }    
           
                
                void reset(Species newSpecies){
                    pc = 0;
                    speciesType = newSpecies;
                }
                  
        };
        
        struct Unit{
            bool isCreature;
            char unitName;
            int unitTurn;
            Creature* unitCreature;
            
            Unit(){
                isCreature = false;
                unitName = '.';
		unitTurn = 0;
            }
        };
        vector< vector< Unit > > mapGrid;
        
        deque<Creature> creatures;
        pair<int, int> currentCoord;
        int turn;
        
        void move(char direction){
            pair<int, int> newCoord = newCoordinate(direction);
            mapGrid[newCoord.first][newCoord.second] = mapGrid[currentCoord.first][currentCoord.second];
            if(direction == 's' || direction == 'e')
                mapGrid[newCoord.first][newCoord.second].unitTurn += 1;
            mapGrid[currentCoord.first][currentCoord.second].isCreature = false;
            mapGrid[currentCoord.first][currentCoord.second].unitName = '.';
	    mapGrid[currentCoord.first][currentCoord.second].unitCreature = 0;

        }
        
        void infection(char direction, Species newSpecies){
            pair<int, int> newCoord = newCoordinate(direction);
            (*(mapGrid[newCoord.first][newCoord.second].unitCreature)).reset(newSpecies);
	    mapGrid[newCoord.first][newCoord.second].unitName = mapGrid[currentCoord.first][currentCoord.second].unitName;
	    
        }
        
        bool isWall(char direction){
            if(direction == 'n'){
                if(currentCoord.first == 0) return true;
            }
            else if(direction == 'e'){
                if(currentCoord.second == (int)mapGrid[0].size() - 1) return true;
            }
            else if(direction == 's'){
                if(currentCoord.first == (int)mapGrid.size() - 1) return true;
            }
            else if(direction == 'w'){
                if(currentCoord.second == 0) return true;
            }
            return false;
        }
        
        bool isEnemy(char direction){
            pair<int, int> newCoord = newCoordinate(direction);
            if(mapGrid[newCoord.first][newCoord.second].unitName != mapGrid[currentCoord.first][currentCoord.second].unitName)
                 return true;
            return false;
        }
        
        bool isEmpty(char direction){
            if(direction == 'n'){
                if(currentCoord.first == 0) return false;
                if(mapGrid[currentCoord.first-1][currentCoord.second].isCreature) return false;
            }
            else if(direction == 'e'){
                if(currentCoord.second == (int)mapGrid[0].size() - 1) return false;
                if(mapGrid[currentCoord.first][currentCoord.second+1].isCreature) return false;
            }
            else if(direction == 's'){
                if(currentCoord.first == (int)mapGrid.size() - 1) return false;
                if(mapGrid[currentCoord.first+1][currentCoord.second].isCreature) return false;
            }
            else if(direction == 'w'){
                if(currentCoord.second == 0) return false;
                if(mapGrid[currentCoord.first][currentCoord.second-1].isCreature) return false;
            }
            return true;
        }
        
        pair<int, int> newCoordinate(char direction){
            pair<int,int> oldCoordinate = currentCoord;
            if(direction == 'n')
                --oldCoordinate.first;
            else if(direction == 'e')
                ++oldCoordinate.second;
            else if(direction == 's')
                ++oldCoordinate.first;
            else if(direction == 'w')
                --oldCoordinate.second;
            return oldCoordinate;
        }

    public:
        //Grid(){}
        Grid(int xLength, int yLength){
           vector< vector< Unit > > newMap(xLength, vector<Unit> (yLength) );
           mapGrid = newMap;
           turn = 0;
        }
        
        void place(Species species, char direction, int yCoord, int xCoord){
            Creature newCreature(species, direction, *this);
            pair<int, int> coord = make_pair(yCoord, xCoord);
        
            mapGrid[yCoord][xCoord].isCreature = true;
            mapGrid[yCoord][xCoord].unitName = species.speciesAbbreviation();
            creatures.push_back(newCreature);
            mapGrid[yCoord][xCoord].unitCreature = &creatures.back();
        }
        
        void simulate(int numberOfTurns, int print){
            srand(0);
            while(turn <= numberOfTurns){
                if(turn%print == 0){
                    printOutput();
                }
                for(int i = 0; i < (int)mapGrid.size(); ++i){
                    for(int j = 0; j < (int)mapGrid[i].size(); ++j){
                        currentCoord = make_pair(i, j);
                        if(mapGrid[i][j].isCreature && mapGrid[i][j].unitTurn <= turn){
                            (*(mapGrid[i][j].unitCreature)).run();
                            ++mapGrid[i][j].unitTurn;
                        }
                    }
                }
                ++turn;
            }
        }
        
        void printOutput(){
            cout << "Turn = " << turn << "." << endl;
            cout << "  ";
            for(unsigned int i = 0; i < mapGrid[0].size(); ++i){
                cout << i%10;
            }
            cout << endl;
            for(unsigned int i = 0; i < mapGrid.size(); ++i){
                cout << i%10 << " ";
                for(unsigned int j = 0; j < mapGrid[i].size(); ++j){
                    cout << mapGrid[i][j].unitName;
                }
                cout << endl;
            }
            cout << endl;
        }

};
