#include "ecs.h"

void initEcs(EcsData * ecsData) {
	ecsData->entityCount = 0;
	ecsData->entityIds = NULL;
	ecsData->entitySignatures = NULL;
	ecsData->components = NULL;
	ecsData->systems = NULL;
}

void closeEcs(EcsData * ecsData) {
	// Free ids and signatures.
	if (ecsData->entityIds != NULL)
		free(ecsData->entityIds);
	if (ecsData->entitySignatures != NULL)
		free(ecsData->entitySignatures);

	ecsData->entityCount = 0;
	ecsData->entityIds = NULL;
	ecsData->entitySignatures = NULL;
	ecsData->components = NULL;
	ecsData->systems = NULL;
}
