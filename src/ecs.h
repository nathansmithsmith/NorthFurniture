#include "gameData.h"

#ifndef ECS_H
#define ECS_H

typedef uint16_t EntityId;
typedef uint16_t EntitySignature; // Bit field full of data on a entity.

// Bit field stuff for entity signature.
enum {
	NONE_COMPONENT = 0x0,
	POSITION_COMPONENT = 0x1,
	ANGLE_COMPONENT = 0x1 << 1,
	TEXTURE_COMPONENT = 0x1 << 2,
	RECT_COMPONENT = 0x1 << 3,
	PHYSICSBODY_COMPONENT = 0x1 << 4
};

//  
typedef struct ComponentData {
	Vector2 * position;
	double angle;
	Texture2D * texture;
	Rectangle * rect;
	PhysicsBody physicsBody;
} ComponentData;

typedef struct EcsData EcsData;

// Arguments to pass to a system.
typedef struct SystemArgs {
	GameData * gameData;
	EcsData * ecsData;
	ComponentData * componentData;
	EntityId id;
	EntitySignature signature;
} SystemArgs;

// System callback stuff (--:
typedef void (*SYSTEM_CB)(SystemArgs args);

// A linked list full of systems for a entity 🐱
typedef struct EntitySystems {
	SYSTEM_CB system;
	struct EntitySystems * next;
} EntitySystems;

// Entities, components, and systems.
typedef struct EcsData {
	size_t entityCount;

	// Entity  
	EntityId * entityIds; // Every entity id.
	EntitySignature * entitySignatures; // A signature for each entity.

	// Components.
	ComponentData * components;

	// Systems.
	EntitySystems * systems;
} EcsData;

void initEcs(EcsData * ecsData);
void closeEcs(EcsData * ecsData);

#endif
