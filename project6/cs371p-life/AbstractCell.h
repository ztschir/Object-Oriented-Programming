class AbstractCell{
    protected:
    bool _isAlive;
    int _numberOfNeighbors;
    
    public:
    /**
	 * default abstractCell Constructor
	 */
    AbstractCell(){}
    
    /**
	 * @param isAlive bool Start the cell as a live or dead cell
	 * Constructs a AbstractCell that can be either a Fredkin or Conway Cell
	 */
    AbstractCell(bool isAlive){
        _isAlive = isAlive;
        _numberOfNeighbors = 0;
    }
    
    /**
	 * @param isDiagonal bool Pass whether or not the neigbor is diagonal
	 * increment the neighbor counter. Overridden by Conway or Fredkin
	 */
    virtual void incrementNeighbors(bool isDiagonal){
    }
    
    /**
	 * Takes the turn of the cell. Overridden by Conway or Fredkin
	 */
    virtual void takeTurn(){
    }
    
    /**
	 * @return char of the Specific overridden cell
	 * Return the correct state of the cell in char format. 
     * Overridden by Conway or Fredkin
	 */
    virtual char printCell(){
        return ' ';
    }
    
    /**
	 * @return bool
	 * returns whether or not the cell is alive.
	 */
    virtual bool isCellAlive(){
        return _isAlive;
    }
};
