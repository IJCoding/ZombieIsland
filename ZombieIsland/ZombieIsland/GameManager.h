#ifndef _GameManager
#define _GameManager

#include <conio.h>
#include "console.h"
#include "Entity.h"
#include "Monster.h"
#include "Character.h"
#include "Hole.h"
#include <vector>

using std::vector;

class GameManager
{
	typedef vector<Entity>::iterator Position;

	Console con;						//Console class

	static vector<Entity> board;		//The board being played on

	vector<Entity> characters;			//All of the characters
	vector<Entity> monsters;			//All of the enemies
	vector<Entity> holes;				//All of the objects
	

	bool isSet;							//Board has been set


	int rows;							//No. rows on the board
	int columns;						//No. columns on the board

	int mon;							//No. Monsters
	int hol;							//No. Holes
	int cha;							//No. Characters

	char up;							//Mapped control for up
	char left;							//Mapped control for left
	char down;							//Mapped control for down
	char right;							//Mapped control for right


public:
	GameManager();
	~GameManager();

	//Setters

	void setGridSize(int numRow = 10, int numCol = 10);											//Set the size of the row and the column
	void setEntityNums(int numMon = 10, int numHol = 10, int numCha = 1);						//Set the number of monsters, holes and characters
	void setControlScheme(char newUp = 'w', char newLeft = 'a',									
						char newDown = 's', char newRight = 'd');								//Set the control scheme for the player				
	

	//Getters

	int getRow(void);										//Get the row size
	int getCol(void);										//Get the column size
															  
	int getNumMon(void);									//Get the number of monsters
	int getNumHol(void);									//Get the number of Holes
	int getNumCha(void);									//Get the number of Player characters

	int getRemMon(void);									//Gets how many remaining monsters there are

	char getUp(void);										//Get the currently mapped control for up
	char getDown(void);										//Get the currently mapped control for down
	char getLeft(void);										//Get the currently mapped control for left
	char getRight(void);									//Get the currently mapped control for right

	bool isBoardSet(void);									//Get whether the board has been set
	
	//Other functions
															
	bool isGameOver(void);									//Is the game over

	void addEntity(Entity newEntity = Entity(), 
				Position newPos = board.begin());			//Adds a given entity to a give position if none given (first tile)


};
#endif