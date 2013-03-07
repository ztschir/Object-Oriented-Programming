#ifndef __AbstractCell_H_INCLUDED 
#define __AbstractCell_H_INCLUDED  
#include "AbstractCell.h"
#endif

class ConwayCell: public AbstractCell{
 
    public:
    /**
	 * default ConwayCell Constructor
	 */
    ConwayCell(){}
    
    /**
	 * @param isAlive bool Start the cell as a live or dead cell
	 * Constructs a ConwayCell that is either alive or dead
	 */
    ConwayCell(bool isAlive):
        AbstractCell(isAlive){}
    
    /**
	 * @param isDiagonal bool Pass whether or not the neigbor is diagonal
	 * increment the neighbor counter no matter what value of isDiagonal is passed.
	 */
    void incrementNeighbors(bool isDiagonal){
        ++_numberOfNeighbors;
    }
    /**
	 * Takes the turn of the cell.
	 */
    void takeTurn(){
    
        if(_numberOfNeighbors == 3 && !_isAlive){
            _isAlive = true;
        }
        else if(_isAlive && (_numberOfNeighbors < 2 || _numberOfNeighbors > 3)){
            _isAlive = false;
        }
            
        _numberOfNeighbors = 0;
    }
    /**
	 * @return char changes based on dead or alive
	 * Return the correct state of the cell in char format.
	 */
    char printCell(){
        if(_isAlive)
            return '*';
        else
            return '.';
    }
};
