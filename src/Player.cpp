#include "Player.h"
#include "Game.h"
#include "Resources.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

GLuint Player::playerTexture{};
VertexList Player::head{};
VertexList Player::body{};
VertexList Player::leftArm{};
VertexList Player::rightArm{};
VertexList Player::leftLeg{};
VertexList Player::rightLeg{};

void Player::init(Game* game)
{
	Entity::init(game);

	this->footSize = 0.5f;
	this->heightOffset = 1.62f;
	this->noPhysics = true;

	this->updates = 0;
	this->flushUpdates = false;

	static bool initialized = false;
	if (!initialized)
	{
		playerTexture = game->textureManager.load(playerResourceTexture, sizeof(playerResourceTexture));

		head.init(game, 36);
		body.init(game, 36);
		leftArm.init(game, 36);
		rightArm.init(game, 36);
		leftLeg.init(game, 36);
		rightLeg.init(game, 36);

		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.000000f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.000000f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.062500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.000000f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.062500f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.062500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.125000f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, -0.117500f, 0.125000f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.187500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, -0.117500f, 0.125000f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, 0.117500f, 0.187500f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.187500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.062500f, 0.250000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.062500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.125000f, 0.250000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.062500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.125000f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.125000f, 0.250000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, 0.117500f, 0.125000f, 0.250000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, -0.117500f, 0.125000f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.187500f, 0.250000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, -0.117500f, 0.125000f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.187500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.187500f, 0.250000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.187500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, 0.117500f, 0.187500f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.250000f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, 0.117500f, 0.187500f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.250000f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.250000f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.062500f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.062500f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.125000f, 0.312500f, 1.000000f));
		leftLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.062500f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.000000f, -0.117500f, 0.125000f, 0.500000f, 1.000000f));
		leftLeg.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.125000f, 0.312500f, 1.000000f));

		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.250000f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, 0.117500f, 0.250000f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.312500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, 0.117500f, 0.250000f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, -0.117500f, 0.312500f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.312500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.375000f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.375000f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.437500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.375000f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.437500f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.437500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.312500f, 0.750000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.312500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.375000f, 0.750000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.312500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.375000f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.375000f, 0.750000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.375000f, 0.750000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.375000f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, 0.117500f, 0.437500f, 0.750000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.375000f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, -0.117500f, 0.437500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, 0.117500f, 0.437500f, 0.750000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, 0.117500f, 0.437500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.437500f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.500000f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, 0.117500f, 0.437500f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, 0.117500f, 0.500000f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.500000f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.312500f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, -0.117500f, 0.312500f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.375000f, 0.812500f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.235000f, 0.000000f, -0.117500f, 0.312500f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.000000f, -0.117500f, 0.375000f, 1.000000f, 1.000000f));
		rightLeg.push(VertexList::Vertex(0.000000f, 0.705000f, -0.117500f, 0.375000f, 0.812500f, 1.000000f));

		body.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.250000f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.250000f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.312500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.250000f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.312500f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.312500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.437500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.437500f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.500000f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.437500f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.500000f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.500000f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.312500f, 0.250000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.312500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.437500f, 0.250000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.312500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.437500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.437500f, 0.250000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.437500f, 0.250000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.437500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.562500f, 0.250000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.437500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.562500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.562500f, 0.250000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.500000f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.500000f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.625000f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.500000f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.625000f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.625000f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.312500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.312500f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.437500f, 0.312500f, 1.000000f));
		body.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.312500f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.437500f, 0.500000f, 1.000000f));
		body.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.437500f, 0.312500f, 1.000000f));

		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.625000f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.625000f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.687500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.625000f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.687500f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.687500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, -0.117500f, 0.812500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, -0.117500f, 0.812500f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, 0.117500f, 0.875000f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, -0.117500f, 0.812500f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, 0.117500f, 0.875000f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, 0.117500f, 0.875000f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, -0.117500f, 0.687500f, 0.250000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, 0.117500f, 0.687500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.750000f, 0.250000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, 0.117500f, 0.687500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.750000f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.750000f, 0.250000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, 0.117500f, 0.750000f, 0.250000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, -0.117500f, 0.750000f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.812500f, 0.250000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, -0.117500f, 0.750000f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.812500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.812500f, 0.250000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, 0.117500f, 0.750000f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, 0.117500f, 0.750000f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.812500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, 0.117500f, 0.750000f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, 0.117500f, 0.812500f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.117500f, 0.812500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.117500f, 0.687500f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.687500f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, -0.117500f, 0.750000f, 0.312500f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.235000f, 0.705000f, -0.117500f, 0.687500f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 0.705000f, -0.117500f, 0.750000f, 0.500000f, 1.000000f));
		leftArm.push(VertexList::Vertex(-0.470000f, 1.410000f, -0.117500f, 0.750000f, 0.312500f, 1.000000f));

		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, 0.117500f, 0.500000f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, 0.117500f, 0.500000f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, -0.117500f, 0.562500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, 0.117500f, 0.500000f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, -0.117500f, 0.562500f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, -0.117500f, 0.562500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.687500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.687500f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.750000f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.687500f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.750000f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.750000f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.562500f, 0.750000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.562500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, -0.117500f, 0.625000f, 0.750000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.562500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, 0.117500f, 0.625000f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, -0.117500f, 0.625000f, 0.750000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.625000f, 0.750000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.625000f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, 0.117500f, 0.687500f, 0.750000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.625000f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, -0.117500f, 0.687500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, 0.117500f, 0.687500f, 0.750000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, 0.117500f, 0.625000f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.625000f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, 0.117500f, 0.687500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, 0.117500f, 0.625000f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, 0.117500f, 0.687500f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, 0.117500f, 0.687500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 1.410000f, -0.117500f, 0.562500f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, -0.117500f, 0.562500f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.625000f, 0.812500f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.470000f, 0.705000f, -0.117500f, 0.562500f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 0.705000f, -0.117500f, 0.625000f, 1.000000f, 1.000000f));
		rightArm.push(VertexList::Vertex(0.235000f, 1.410000f, -0.117500f, 0.625000f, 0.812500f, 1.000000f));

		head.push(VertexList::Vertex(0.235000f, 1.880000f, 0.235000f, 0.000000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, 0.235000f, 0.000000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.880000f, -0.235000f, 0.125000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, 0.235000f, 0.000000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, -0.235000f, 0.125000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.880000f, -0.235000f, 0.125000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, -0.235000f, 0.250000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.235000f, 0.250000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, 0.235000f, 0.375000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.235000f, 0.250000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.235000f, 0.375000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, 0.235000f, 0.375000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, -0.235000f, 0.125000f, 0.000000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, 0.235000f, 0.125000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.880000f, -0.235000f, 0.250000f, 0.000000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, 0.235000f, 0.125000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.880000f, 0.235000f, 0.250000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.880000f, -0.235000f, 0.250000f, 0.000000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.235000f, 0.250000f, 0.000000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.235000f, 0.250000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, 0.235000f, 0.375000f, 0.000000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.235000f, 0.250000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, -0.235000f, 0.375000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, 0.235000f, 0.375000f, 0.000000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, 0.235000f, 0.375000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.235000f, 0.375000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.880000f, 0.235000f, 0.500000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, 0.235000f, 0.375000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, 0.235000f, 0.500000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.880000f, 0.235000f, 0.500000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.880000f, -0.235000f, 0.125000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, -0.235000f, 0.125000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, -0.235000f, 0.250000f, 0.125000f, 1.000000f));
		head.push(VertexList::Vertex(0.235000f, 1.410000f, -0.235000f, 0.125000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.410000f, -0.235000f, 0.250000f, 0.250000f, 1.000000f));
		head.push(VertexList::Vertex(-0.235000f, 1.880000f, -0.235000f, 0.250000f, 0.125000f, 1.000000f));

		head.update();
		body.update();
		leftArm.update();
		rightArm.update();
		leftLeg.update(); 
		rightLeg.update();

		initialized = true;
	}
}

void Player::tick()
{
	oldRotation = rotation;
	oldBobbing = bobbing;
	oldPosition = position;
	oldWalkDistance = walkDistance;
}

void Player::rotate(float x, float y)
{
	rotation.x = x;
	rotation.y = y;
}

void Player::move(float x, float y, float z)
{
	float distance = glm::sqrt((oldPosition.x - x) * (oldPosition.x - x) + (oldPosition.z - z) * (oldPosition.z - z));

	position.x = x; 
	position.y = y - 1.62f;
	position.z = z;

	walkDistance += distance;

	if (distance > 0.1f)
	{ 
		distance = 0.1f;
	}

	bobbing += (distance - bobbing) * 0.4f;
}

void Player::render()
{
	const auto viewPosition = oldPosition + ((position - oldPosition) * game->timer.delta);
	const auto viewRotation = oldRotation + ((rotation - oldRotation) * game->timer.delta);
	const auto viewBobbing = oldBobbing + ((bobbing - oldBobbing) * game->timer.delta);
	const auto viewWalkDistance = oldWalkDistance + ((walkDistance - oldWalkDistance) * game->timer.delta);

	const float headHeight = 1.410000f;
	const float armHeight = 1.410000f;
	const float legHeight = 0.705f;

	const float angle = 600.0f * glm::sin(viewWalkDistance * float(M_PI)) * viewBobbing;

	auto matrix = game->IDENTITY_MATRIX;
	matrix = glm::translate(matrix, viewPosition);
	matrix = glm::rotate(matrix, viewRotation.x + glm::radians(180.0f), glm::vec3(0, 1, 0));

	auto subMatrix = matrix;
	subMatrix = glm::translate(subMatrix, glm::vec3(0, headHeight, 0));
	subMatrix = glm::rotate(subMatrix, viewRotation.y, glm::vec3(1.0f, 0.0f, 0.0f));
	subMatrix = glm::translate(subMatrix, glm::vec3(0, -headHeight, 0));

	glUniformMatrix4fv(game->modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(subMatrix));
	head.render();

	subMatrix = matrix;
	subMatrix = glm::translate(subMatrix, glm::vec3(0, armHeight, 0));
	subMatrix = glm::rotate(subMatrix, glm::radians(-angle), glm::vec3(1.0f, 0.0f, 0.0f));
	subMatrix = glm::translate(subMatrix, glm::vec3(0, -armHeight, 0));

	glUniformMatrix4fv(game->modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(subMatrix));
	leftArm.render();

	subMatrix = matrix;
	subMatrix = glm::translate(subMatrix, glm::vec3(0, armHeight, 0));
	subMatrix = glm::rotate(subMatrix, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
	subMatrix = glm::translate(subMatrix, glm::vec3(0, -armHeight, 0));

	glUniformMatrix4fv(game->modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(subMatrix));
	rightArm.render();

	subMatrix = matrix;
	subMatrix = glm::translate(subMatrix, glm::vec3(0, legHeight, 0));
	subMatrix = glm::rotate(subMatrix, glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));
	subMatrix = glm::translate(subMatrix, glm::vec3(0, -legHeight, 0));

	glUniformMatrix4fv(game->modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(subMatrix));
	leftLeg.render();

	subMatrix = matrix;
	subMatrix = glm::translate(subMatrix, glm::vec3(0, legHeight, 0));
	subMatrix = glm::rotate(subMatrix, glm::radians(-angle), glm::vec3(1.0f, 0.0f, 0.0f));
	subMatrix = glm::translate(subMatrix, glm::vec3(0, -legHeight, 0));

	glUniformMatrix4fv(game->modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(subMatrix));
	rightLeg.render();

	glUniformMatrix4fv(game->modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(matrix));
	body.render();

	glUniformMatrix4fv(game->modelMatrixUniform, 1, GL_FALSE, glm::value_ptr(game->IDENTITY_MATRIX));
}
