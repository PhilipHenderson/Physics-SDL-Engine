#pragma once
#ifndef __AGENT__
#define __AGENT__

#include <glm/vec4.hpp>
#include "DisplayObject.h"


/*
* The Agent class inherits from display object which inherits from GameObject.
* The Agent class has variables which classes who inherit from it can use,
* For example in decision trees Conditions are passed these variables using the
* getters in this class. Through out your code you can set these variables
* to change the AI character's decisions. Agent can be used for other things
* in your game such as the player and tiles though.
*/

class Agent : public DisplayObject
{
public:
	Agent();
	~Agent();

	// Inherited via GameObject
	void draw() override = 0;
	void update() override = 0;
	void clean() override = 0;

	// getters
	glm::vec2 getTargetPosition() const;
	glm::vec2 getCurrentDirection() const;
	float getLOSDistance() const;
	bool hasLOS() const;
	float getCurrentHeading() const;
	glm::vec4 getLOSColour() const;

	// setters
	void setTargetPosition(glm::vec2 new_position);
	void setCurrentDirection(glm::vec2 new_direction);
	void setLOSDistance(float distance);
	void setHasLOS(bool state);
	void setCurrentHeading(float heading);
	void setLOSColour(glm::vec4 colour);

private:
	void m_changeDirection();
	float m_currentHeading;
	glm::vec2 m_currentDirection;
	glm::vec2 m_targetPosition;

	// LOS
	float m_LOSDistance;
	bool m_hasLOS;
	glm::vec4 m_LOSColour;
};



#endif /* defined ( __AGENT__) */