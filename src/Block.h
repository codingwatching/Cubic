#pragma once
#include "AABB.h"

class Block 
{
public:
	enum class DrawType 
	{
		DRAW_OPAQUE,     
		DRAW_TRANSPARENT,   
		DRAW_TRANSPARENT_THICK,
		DRAW_TRANSLUCENT,
		DRAW_GAS,
		DRAW_SPRITE,
		DRAW_OPAQUE_SMALL,
	};

	enum class CollideType 
	{
		COLLIDE_NONE,         
		COLLIDE_LIQUID,       
		COLLIDE_SOLID, 
	};

	enum class Type 
	{
		BLOCK_AIR = 0,
		BLOCK_STONE = 1,
		BLOCK_GRASS = 2,
		BLOCK_DIRT = 3,
		BLOCK_COBBLE = 4,
		BLOCK_WOOD = 5,
		BLOCK_SAPLING = 6,
		BLOCK_BEDROCK = 7,
		BLOCK_WATER = 8,
		BLOCK_STILL_WATER = 9,
		BLOCK_LAVA = 10,
		BLOCK_STILL_LAVA = 11,
		BLOCK_SAND = 12,
		BLOCK_GRAVEL = 13,
		BLOCK_GOLD_ORE = 14,
		BLOCK_IRON_ORE = 15,
		BLOCK_COAL_ORE = 16,
		BLOCK_LOG = 17,
		BLOCK_LEAVES = 18,
		BLOCK_SPONGE = 19,
		BLOCK_GLASS = 20,
		BLOCK_RED = 21,
		BLOCK_ORANGE = 22,
		BLOCK_YELLOW = 23,
		BLOCK_LIME = 24,
		BLOCK_GREEN = 25,
		BLOCK_TEAL = 26,
		BLOCK_AQUA = 27,
		BLOCK_CYAN = 28,
		BLOCK_BLUE = 29,
		BLOCK_INDIGO = 30,
		BLOCK_VIOLET = 31,
		BLOCK_MAGENTA = 32,
		BLOCK_PINK = 33,
		BLOCK_BLACK = 34,
		BLOCK_GRAY = 35,
		BLOCK_WHITE = 36,
		BLOCK_DANDELION = 37,
		BLOCK_ROSE = 38,
		BLOCK_BROWN_SHROOM = 39,
		BLOCK_RED_SHROOM = 40,
		BLOCK_GOLD = 41,
		BLOCK_IRON = 42,
		BLOCK_DOUBLE_SLAB = 43,
		BLOCK_SLAB = 44,
		BLOCK_BRICK = 45,
		BLOCK_TNT = 46,
		BLOCK_BOOKSHELF = 47,
		BLOCK_MOSSY_ROCKS = 48,
		BLOCK_OBSIDIAN = 49
	};

	struct Definition 
	{
		unsigned char topTexture;
		unsigned char sideTexture;
		unsigned char bottomTexture;
		float height;
		AABB boundingBox; 
		bool blocksLight;
		DrawType draw; 
		CollideType collide;
	};

	const static Definition Definitions[50];
};