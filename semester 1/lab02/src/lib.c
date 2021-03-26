/**
 * @file lib.c
 * @brief Файл з реалізацією функцій оперування тваринами
 *
 * @author Davydov V.
 * @date 14-apr-2020
 * @version 1.3
 */

#include "lib.h"

char *get_animal_type_name(enum animal_type type)
{
	char *result;
	switch (type) {
	case CAT:
		result = "Kotik";
		break;
	case DOG:
		result = "Schenok";
		break;
	case COW:
		result = "Telenok";
		break;
	case PIG:
		result = "Porosenok";
		break;
	case HUMAN:
		result = "Chelovek";
		break;
	default:
		result = "N/A";
	}
	return result;
}

void generate_animal(struct animal *entity)
{
	entity->height = (unsigned int)rand() % INT8_MAX;
	entity->weight = (unsigned int)rand() % INT8_MAX;
	entity->type = (unsigned int)rand() % ANIMAL_TYPE_COUNT;
}

void show_animals(struct animal animals[], unsigned int count)
{
	for (unsigned int i = 0; i < count; i++) {
		printf("Інформація про тварину №%02u: ", i + 1);
		printf("%s: зріст = %u см, маса = %u гр. \n",
		       get_animal_type_name(animals[i].type), animals[i].height,
		       animals[i].weight);
	}
}
