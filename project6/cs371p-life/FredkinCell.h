#ifndef __AbstractCell_H_INCLUDED 
#define __AbstractCell_H_INCLUDED  
#include "AbstractCell.h"
#endif

class FredkinCell: public AbstractCell{
    private:
    int _age;
    
    public:
    /**
	 * default FredkinCell Constructor
	 */
    FredkinCell(){}
    
    /**
	 * @param isAlive bool Start the cell as a live or dead cell
	 * Constructs a FredkinCell that is either alive or dead at age 0.
	 */
    FredkinCell(bool isAlive):
        AbstractCell(isAlive){
        _age = 0;
    }
    
    /**
	 * @param isDiagonal bool Pass whether or not the neigbor is diagonal
	 * increment the neighbor counter Only on the non-diagonal
	 */
    void incrementNeighbors(bool isDiagonal){
        if(!isDiagonal)
            ++_numberOfNeighbors;
    }
    
    /**
	 * Takes the turn of the cell.
	 */
    void takeTurn(){
    
        if(!_isAlive && (_numberOfNeighbors == 3 || _numberOfNeighbors == 1)){
            _isAlive = true;
        }
        else if(_isAlive && (_numberOfNeighbors == 0 || _numberOfNeighbors == 2 || _numberOfNeighbors == 4)){
            _isAlive = false;
        }
        else if(_isAlive)
            ++_age;
            
        _numberOfNeighbors = 0;
    }

    /**
	 * @return bool if the age of the cell is exactly two
	 * Returns true if the cell is of age two
	 */
	bool cellAgeTwo(){
		return _age == 2;
	}
    
    /**
	 * @return char changes based on dead or alive
	 * Return the correct state of the cell in char format.
	 */
    char printCell(){
        if(_isAlive)
            return _age < 10 ? _age + '0' : '+' ;
        else
            return '-';
    }
};
