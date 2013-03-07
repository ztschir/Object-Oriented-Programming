#ifndef __AbstractCell_H_INCLUDED 
#define __AbstractCell_H_INCLUDED  
#include "AbstractCell.h"
#include "FredkinCell.h"
#include "ConwayCell.h"
#endif
#include <typeinfo> 

class Cell{
	AbstractCell* cell;
	int _age;
	
    public:

    /**
	 * default Cell Constructor
	 */
    Cell(){}
    
    /**
	 * @param isAlive bool Start the cell as a live or dead cell
	 * Constructs a Cell that is either alive or dead and starts as a FredkinCell
	 */
    Cell(bool isAlive){
        cell = new FredkinCell(isAlive);
    }
    
    /**
	 * @param isDiagonal bool Pass whether or not the neigbor is diagonal
	 * increment the neighbor of the internal Abstract Cell
	 */
    void incrementNeighbors(bool isDiagonal){
        cell->incrementNeighbors(isDiagonal);
    }
    
    /**
	 * Takes the turn of the cell.
	 */
    void takeTurn(){
        cell->takeTurn();
        if(cell->isCellAlive() && typeid(*cell) == typeid(FredkinCell) && static_cast<FredkinCell *>(cell)->cellAgeTwo()){
            AbstractCell* temp = new ConwayCell(true);
            std::swap(temp, cell);
            delete temp;
        }
    }
    
    /**
	 * @return char changes based on dead or alive
	 * Return the correct state of the internal cell.
	 */
    char printCell(){
        
        return cell->printCell();
    }
    
    /**
	 * @return bool whether or not the cell is alive
	 * Returns state of cell (Dead or alive)
	 */
    bool isCellAlive(){
        return cell->isCellAlive();
    }
	
	
};
