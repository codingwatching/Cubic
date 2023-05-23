#include "Block.h"

static const auto DEFAULT_BOUNDING_BOX = AABB{ 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f };

const Block::Definition Block::Definitions[] = {
	{  0,  0,  0, 1.0f,  DEFAULT_BOUNDING_BOX , false, false, Block::DrawType::DRAW_GAS,    Block::CollideType::COLLIDE_NONE,  Block::SoundType::SOUND_NONE,   Block::SoundType::SOUND_NONE}, /* AIR */
	{  1,  1,  1, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE,  Block::SoundType::SOUND_STONE  }, /* STONE */
	{  0,  3,  2, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_GRASS,  Block::SoundType::SOUND_GRASS  }, /* GRASS */
	{  2,  2,  2, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_GRAVEL, Block::SoundType::SOUND_GRAVEL }, /* DIRT */
	{ 16, 16, 16, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE,  Block::SoundType::SOUND_STONE  }, /* COBBLE */
	{  4,  4,  4, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_WOOD,   Block::SoundType::SOUND_WOOD   }, /* WOOD */
	{ 15, 15, 15, 1.0f,  DEFAULT_BOUNDING_BOX , false, false, Block::DrawType::DRAW_SPRITE, Block::CollideType::COLLIDE_NONE,  Block::SoundType::SOUND_GRASS,  Block::SoundType::SOUND_NONE   }, /* SAPLING */
	{ 17, 17, 17, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE,  Block::SoundType::SOUND_STONE  }, /* BEDROCK */
	{ 14, 14, 14, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_TRANSLUCENT, Block::CollideType::COLLIDE_LIQUID, Block::SoundType::SOUND_NONE, Block::SoundType::SOUND_NONE },/* WATER */
	{ 14, 14, 14, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_TRANSLUCENT, Block::CollideType::COLLIDE_LIQUID, Block::SoundType::SOUND_NONE, Block::SoundType::SOUND_NONE },/* STILL_WATER */
	{ 30, 30, 30, 1.0f,  DEFAULT_BOUNDING_BOX ,  true,  true, Block::DrawType::DRAW_TRANSLUCENT, Block::CollideType::COLLIDE_LIQUID,  Block::SoundType::SOUND_NONE,  Block::SoundType::SOUND_NONE   }, /* LAVA */
	{ 30, 30, 30, 1.0f,  DEFAULT_BOUNDING_BOX ,  true,  true, Block::DrawType::DRAW_TRANSLUCENT, Block::CollideType::COLLIDE_LIQUID,  Block::SoundType::SOUND_NONE,  Block::SoundType::SOUND_NONE   }, /* STILL_LAVA */
	{ 18, 18, 18, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_SAND,  Block::SoundType::SOUND_SAND   }, /* SAND */
	{ 19, 19, 19, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_GRAVEL,Block::SoundType::SOUND_GRAVEL }, /* GRAVEL */
	{ 32, 32, 32, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE, Block::SoundType::SOUND_STONE  }, /* GOLD_ORE */
	{ 33, 33, 33, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE, Block::SoundType::SOUND_STONE  }, /* IRON_ORE */
	{ 34, 34, 34, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE, Block::SoundType::SOUND_STONE  }, /* COAL_ORE */
	{ 21, 20, 21, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_WOOD,  Block::SoundType::SOUND_WOOD   }, /* LOG */
	{ 22, 22, 22, 1.0f,  DEFAULT_BOUNDING_BOX , false, false, Block::DrawType::DRAW_TRANSPARENT_THICK, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_GRASS, Block::SoundType::SOUND_GRASS }, /* LEAVES */
	{ 48, 48, 48, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_GRASS,  Block::SoundType::SOUND_GRASS  }, /* SPONGE */
	{ 49, 49, 49, 1.0f,  DEFAULT_BOUNDING_BOX , false, false, Block::DrawType::DRAW_TRANSPARENT, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_GLASS, Block::SoundType::SOUND_STONE},/* GLASS */
	{ 64, 64, 64, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* RED */
	{ 65, 65, 65, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* ORANGE */
	{ 66, 66, 66, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* YELLOW */
	{ 67, 67, 67, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* LIME */
	{ 68, 68, 68, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* GREEN */
	{ 69, 69, 69, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* TEAL */
	{ 70, 70, 70, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* AQUA */
	{ 71, 71, 71, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* CYAN */
	{ 72, 72, 72, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* BLUE */
	{ 73, 73, 73, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* INDIGO */
	{ 74, 74, 74, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* VIOLET */
	{ 75, 75, 75, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* MAGNETA */
	{ 76, 76, 76, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* PINK */
	{ 77, 77, 77, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* BLACK */
	{ 78, 78, 78, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* GRAY */
	{ 79, 79, 79, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_CLOTH, Block::SoundType::SOUND_CLOTH  }, /* WHITE */
	{ 13, 13, 13, 1.0f,  AABB{0.30f, 0.0f, 0.30f, 0.70f, 0.55f, 0.70f}, false, false, Block::DrawType::DRAW_SPRITE, Block::CollideType::COLLIDE_NONE,  Block::SoundType::SOUND_GRASS, Block::SoundType::SOUND_NONE   }, /* DANDELION */
	{ 12, 12, 12, 1.0f,  AABB{0.30f, 0.0f, 0.30f, 0.70f, 0.70f, 0.70f}, false, false, Block::DrawType::DRAW_SPRITE, Block::CollideType::COLLIDE_NONE,  Block::SoundType::SOUND_GRASS, Block::SoundType::SOUND_NONE   }, /* ROSE */
	{ 29, 29, 29, 1.0f,  AABB{0.30f, 0.0f, 0.30f, 0.70f, 0.45f, 0.70f}, false, false, Block::DrawType::DRAW_SPRITE, Block::CollideType::COLLIDE_NONE,  Block::SoundType::SOUND_GRASS, Block::SoundType::SOUND_NONE   }, /* BROWN_SHROOM */
	{ 28, 28, 28, 1.0f,  AABB{0.23f, 0.0f, 0.23f, 0.77f, 0.43f, 0.77f}, false, false, Block::DrawType::DRAW_SPRITE, Block::CollideType::COLLIDE_NONE,  Block::SoundType::SOUND_GRASS, Block::SoundType::SOUND_NONE   }, /* RED_SHROOM */
	{ 24, 40, 56, 1.0f,  DEFAULT_BOUNDING_BOX ,  false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_METAL, Block::SoundType::SOUND_METAL  }, /* GOLD */
	{ 23, 39, 55, 1.0f,  DEFAULT_BOUNDING_BOX ,  false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_METAL, Block::SoundType::SOUND_METAL  }, /* IRON */
	{  6,  5,  6, 1.0f,  DEFAULT_BOUNDING_BOX ,  false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE, Block::SoundType::SOUND_STONE  }, /* DOUBLE_SLAB */
	{  6,  5,  6, 0.5f,  AABB{0.0f, 0.0f, 0.0f, 1.0f, 0.5f, 1.0f}, false,  true, Block::DrawType::DRAW_OPAQUE_SMALL, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE, Block::SoundType::SOUND_STONE  }, /* SLAB */
	{  7,  7,  7, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE, Block::SoundType::SOUND_STONE  }, /* BRICK */
	{  9,  8, 10, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_GRASS, Block::SoundType::SOUND_GRASS  }, /* TNT */
	{  4, 35,  4, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_WOOD,  Block::SoundType::SOUND_WOOD   }, /* BOOKSHELF */
	{ 36, 36, 36, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE, Block::SoundType::SOUND_STONE  }, /* MOSSY_ROCKS */
	{ 37, 37, 37, 1.0f,  DEFAULT_BOUNDING_BOX , false,  true, Block::DrawType::DRAW_OPAQUE, Block::CollideType::COLLIDE_SOLID, Block::SoundType::SOUND_STONE, Block::SoundType::SOUND_STONE  }, /* OBSIDIAN */
};