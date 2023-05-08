#pragma once
#include "Block.h"
#include "AABBPosition.h"

#include <glm/glm.hpp>
#include <vector>
#include <queue>

class Game;
class AABB;

class Level {
public:
	struct Tile 
	{
		int x, y, z;
		unsigned char blockType;
	};

	void init(Game* game, int width, int depth);
	void tick();

	void setTile(int x, int y, int z, unsigned char value);
	bool setTileWithNeighborChange(int x, int y, int z, unsigned char value);
	bool setTileWithNoNeighborChange(int x, int y, int z, unsigned char tile);

	void addedTile(int x, int y, int z, unsigned char tile);
	void removedTile(int x, int y, int z, unsigned char tile);
	void updateTile(int x, int y, int z, unsigned char tile);

	bool canFlood(int x, int y, int z);

	bool isAirTile(int x, int y, int z);
	bool isAirTile(unsigned char blockType);
	bool isWaterTile(int x, int y, int z);
	bool isRenderWaterTile(float x, float y, float z);
	bool isMovingWaterTile(int x, int y, int z);
	bool isMovingWaterTile(unsigned char blockType);
	bool isWaterTile(unsigned char blockType);
	bool isLavaTile(float x, float y, float z);
	bool isMovingLavaTile(int x, int y, int z);
	bool isMovingLavaTile(unsigned char blockType);
	bool isLavaTile(int x, int y, int z);
	bool isLavaTile(unsigned char blockType);
	bool isInBounds(int x, int y, int z);
	bool isTileLit(int x, int y, int z);

	float getTileBrightness(int x, int y, int z);
	unsigned char getTile(int x, int y, int z);
	unsigned char getRenderTile(int x, int y, int z);

	unsigned int getTileAABBCount(AABB box);
	std::vector<AABB> getTileAABB(AABB box);

	void calculateLightDepths(int x, int z, int offsetX, int offsetZ);
	bool containsAnyLiquid(AABB box);
	bool containsLiquid(AABB box, Block::Type blockType);
	AABBPosition clip(glm::vec3 start, glm::vec3 end, const glm::ivec3* expected = nullptr);

	Game* game;
	std::queue<Level::Tile> liquidUpdates;

	int width;
	int height;
	int depth;
	int groundLevel;
	int waterLevel;
	int* lightDepths;

	float spawnX;
	float spawnY;
	float spawnZ;

	unsigned char* blocks;
};