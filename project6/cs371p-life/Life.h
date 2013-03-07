#include <vector>
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <utility>
#include "ConwayCell.h"
#include "FredkinCell.h"
#include "Cell.h"

using namespace std;

template<typename T>
class Life{
    private:
    typedef pair<int,int> coordinate;
    
    vector< vector<T> > _grid;
    vector<coordinate> _aliveCells;
    
    int _numberOfMoves;
    
    public:
    /**
	 * @param in istream& the file input of the grid and sizes
	 * Constructor for the Life class
	 */
    Life(std::istream& in){
        _numberOfMoves = 0;
        parse(in);
    }
    
    private:
    void parse(std::istream& in){
        int rows;
        int columns;
        
        in >> rows;
        in >> columns;
        
        for(int i = 0; i < rows; ++i){
        
            vector<T> row(columns);
            for(int j = 0; j < columns; ++j){
                char input;
                in >> input;
                T cell;
                
                if(input == '.' || input == '-'){
                    cell = T(false);
                }
                else if(input == '0' || input == '*'){
                    cell = T(true);
                    _aliveCells.push_back(make_pair(i,j));
                }
                row[j] = cell;
            }
            _grid.push_back(row);
        }
    }
    
    public:
    /**
	 * Prints the grid and any flavor text around it.
	 */
    void print(){
        cout << "Generation = " << _numberOfMoves << ", Population = " << _aliveCells.size() << "." << endl;
    
        for(unsigned int i = 0; i < _grid.size(); ++i){
            for(unsigned int j = 0; j < _grid[i].size(); ++j){
                cout << _grid[i][j].printCell();
            }
            cout << endl;
        }
        cout << endl;
    }
    
    /**
	 * @param turns int the number of turns the user wants to simulate
	 * Start the simulation for the specified number of turns.
	 */
    void simulate(int turns){
        int totalTurns = _numberOfMoves + turns;
        
        while(_numberOfMoves < totalTurns){
        
            for(unsigned int k = 0; k < _aliveCells.size(); ++k){
                int column = _aliveCells[k].second;
                int row = _aliveCells[k].first;
                
                int rowSize = _grid.size() - 1;
                int columnSize = _grid[0].size() - 1;
                
                // Corner cases
                if(column == 0 && row == 0){
                    _grid[0][1].incrementNeighbors(false);
                    _grid[1][1].incrementNeighbors(true);
                    _grid[1][0].incrementNeighbors(false);
                    continue;
                }
                else if(column == 0 && row == rowSize){
                    _grid[rowSize - 1][0].incrementNeighbors(false);
                    _grid[rowSize - 1][1].incrementNeighbors(true);
                    _grid[rowSize    ][1].incrementNeighbors(false);  
                    continue;          
                }
                else if(column == columnSize && row == 0){
                    _grid[0][columnSize - 1].incrementNeighbors(false);
                    _grid[1][columnSize - 1].incrementNeighbors(true);
                    _grid[1][columnSize    ].incrementNeighbors(false);   
                    continue;         
                }
                else if(column == columnSize && row == rowSize){
                    _grid[rowSize - 1][columnSize    ].incrementNeighbors(false);
                    _grid[rowSize - 1][columnSize - 1].incrementNeighbors(true);
                    _grid[rowSize    ][columnSize - 1].incrementNeighbors(false);   
                    continue;         
                }
                
                // Edge Cases
                if(column == 0){
                    _grid[row + 1][0].incrementNeighbors(false);
                    _grid[row - 1][0].incrementNeighbors(false);
                    _grid[row + 1][1].incrementNeighbors(true);       
                    _grid[row    ][1].incrementNeighbors(false); 
                    _grid[row - 1][1].incrementNeighbors(true);   
                    continue;         
                }
                else if(column == columnSize){
                    _grid[row + 1][columnSize    ].incrementNeighbors(false);
                    _grid[row - 1][columnSize    ].incrementNeighbors(false);
                    _grid[row + 1][columnSize - 1].incrementNeighbors(true);       
                    _grid[row    ][columnSize - 1].incrementNeighbors(false); 
                    _grid[row - 1][columnSize - 1].incrementNeighbors(true);  
                    continue;              
                }
                else if(row == 0){
                    _grid[0][column + 1].incrementNeighbors(false);
                    _grid[0][column - 1].incrementNeighbors(false);
                    _grid[1][column + 1].incrementNeighbors(true);       
                    _grid[1][column    ].incrementNeighbors(false); 
                    _grid[1][column - 1].incrementNeighbors(true);  
                    continue;              
                }
                else if(row == rowSize){
                    _grid[rowSize    ][column + 1].incrementNeighbors(false);
                    _grid[rowSize    ][column - 1].incrementNeighbors(false);
                    _grid[rowSize - 1][column + 1].incrementNeighbors(true);       
                    _grid[rowSize - 1][column    ].incrementNeighbors(false); 
                    _grid[rowSize - 1][column - 1].incrementNeighbors(true); 
                    continue;               
                }
                
                // Every other case
                _grid[row + 1][column + 1].incrementNeighbors(true);
                _grid[row - 1][column - 1].incrementNeighbors(true);
                
                _grid[row    ][column + 1].incrementNeighbors(false);
                _grid[row    ][column - 1].incrementNeighbors(false); 
                      
                _grid[row - 1][column    ].incrementNeighbors(false); 
                _grid[row - 1][column + 1].incrementNeighbors(true);
                
                _grid[row + 1][column    ].incrementNeighbors(false); 
                _grid[row + 1][column - 1].incrementNeighbors(true);
                
            }
            
            _aliveCells.clear();
        
            for(unsigned int i = 0; i < _grid.size(); ++i){
                for(unsigned int j = 0; j < _grid[i].size(); ++j){
                    _grid[i][j].takeTurn();
                    if(_grid[i][j].isCellAlive())
                        _aliveCells.push_back(make_pair(i,j));
                }
            }
            
            ++_numberOfMoves;
        }
    } 
};
