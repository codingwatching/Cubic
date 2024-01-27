#include "Particle.h"
#include "Game.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>

void Particle::init( 
	float x, float y, float z, 
	float xd, float yd, float zd, 
	unsigned char blockType
) 
{
	Entity::init();

	setSize(0.2f, 0.2f);
	setPosition(x, y, z);

	this->heightOffset = aabbHeight / 2.0f;

	this->velocity.x = xd + float(game.random.uniform() * 2.0f - 1.0f) * 0.4f;
	this->velocity.y = yd + float(game.random.uniform() * 2.0f - 1.0f) * 0.4f;
	this->velocity.z = zd + float(game.random.uniform() * 2.0f - 1.0f) * 0.4f;

	this->size = 0.1f * ((float)game.random.uniform() * 0.5f + 0.5f);
	this->maxAge = int(4.0f / (game.random.uniform() * 0.9f + 0.1f));
	this->age = 0;

	float speed = float(game.random.uniform() + game.random.uniform() + 1.0f) * 0.15f * 0.4f / glm::length(velocity);
	this->velocity.x *= speed;
	this->velocity.y *= speed;
	this->velocity.z *= speed;
	this->velocity.y += 0.1f;

	auto texture = Block::Definitions[blockType].sideTexture;
	auto u = (float)game.random.uniform() * 3.0f;
	auto v = (float)game.random.uniform() * 3.0f;

	this->u0 = (texture % 16 + u / 4.0f) / 16.0f;
	this->v0 = (texture / 16 + v / 4.0f) / 16.0f;
	this->u1 = u0 + 0.015609375f;
	this->v1 = v0 + 0.015609375f;
	this->brightness = game.level.getTileBrightness((int)x, (int)y, (int)z);
}

void Particle::tick()
{
	Entity::tick();

	age++;
	velocity.y -= 0.04f;

	move(velocity.x, velocity.y, velocity.z);

	velocity.x *= 0.98f;
	velocity.y *= 0.98f;
	velocity.z *= 0.98f;

	if (onGround) 
	{
		velocity.x *= 0.7f;
		velocity.z *= 0.7f;
	}
}

void Particle::update(VertexList& vertexList)
{
	if (age >= maxAge)
	{
		return;
	}
	
	const auto viewPosition = oldPosition + ((position - oldPosition) * game.timer.delta);

	const float x = -glm::cos(glm::radians(game.localPlayer.rotation.x));
	const float z = -glm::sin(glm::radians(game.localPlayer.rotation.x));
	const float y = glm::cos(glm::radians(game.localPlayer.rotation.y));

	const float rotX = -z * glm::sin(glm::radians(game.localPlayer.rotation.y));
	const float rotZ = x * glm::sin(glm::radians(game.localPlayer.rotation.y));

	vertexList.push(VertexList::Vertex(viewPosition.x - x * size + rotX * size, viewPosition.y + y * size, viewPosition.z - z * size + rotZ * size, u0, v0, brightness));
	vertexList.push(VertexList::Vertex(viewPosition.x - x * size - rotX * size, viewPosition.y - y * size, viewPosition.z - z * size - rotZ * size, u0, v1, brightness));
	vertexList.push(VertexList::Vertex(viewPosition.x + x * size - rotX * size, viewPosition.y - y * size, viewPosition.z + z * size - rotZ * size, u1, v1, brightness));

	vertexList.push(VertexList::Vertex(viewPosition.x - x * size + rotX * size, viewPosition.y + y * size, viewPosition.z - z * size + rotZ * size, u0, v0, brightness));
	vertexList.push(VertexList::Vertex(viewPosition.x + x * size - rotX * size, viewPosition.y - y * size, viewPosition.z + z * size - rotZ * size, u1, v1, brightness));
	vertexList.push(VertexList::Vertex(viewPosition.x + x * size + rotX * size, viewPosition.y + y * size, viewPosition.z + z * size + rotZ * size, u1, v0, brightness));
}