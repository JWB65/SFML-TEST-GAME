#pragma once

#include <string>
#include <vector>
#include <array>

#include "spriteObject.hpp"

template <typename T>
class Character {
private:
	std::array<T, 4> m_stats;

	T m_currentHealth; // JAN: added prefix m_ to be consistent

	std::string* m_theInventory;

	int m_inventoryMaxItems;
	int m_amountOfItems;

	std::string m_name;

	SpriteObject* m_theCharacterSprite;

public:
	// JAN: changed NULL to nullptr
	Character(T health, T attack, T defense, T agility, int inventoryMaxItems, const std::string& name, const SpriteObject* theSprite = nullptr); 
	~Character();

	// JAN: changed to const string reference (avoids a unecessary string copy)
	void addItem(const std::string& theItem);
	bool removeItem(int index);

	void info();

	void printItems();

	void switchSprite(SpriteObject* theSprite);
};

// Because template class generation happens at compile-time, both the class's declaration and definition needs to be in the same file
template <typename T>
Character<T>::Character(T health, T attack, T defense, T agility, int inventoryMaxItems, const std::string& name, const SpriteObject* theSprite)
	: m_inventoryMaxItems(inventoryMaxItems), m_amountOfItems(0), m_name(name), m_theCharacterSprite(m_theCharacterSprite)
{
	printf("Character constructed\n"); // JAN: added

	m_stats = { health, attack, defense, agility };

	m_currentHealth = static_cast <T> (0); // JAN: TODO

	m_theInventory = new std::string[m_inventoryMaxItems]; //size: string bytes * amount of items

	for (int i = 0; i < m_inventoryMaxItems; i++) {
		m_theInventory[i] = "[|NO ITEM|]";
	}
}

template <typename T>
void Character<T>::switchSprite(SpriteObject* theSprite)
{
	m_theCharacterSprite = theSprite;
}

template <typename T>
Character<T>::~Character()
{
	printf("Character destructed\n");

	delete[] m_theInventory; //free inventory items
	
	// JAN: this gives problems. The object pointed to by m_theCharacterSprite is not created by this class so should also
	//      not be deleted by the class. This class does NOT OWN this pointer.
	//delete m_theCharacterSprite;
}

// Adds items (strings) to the Character inventory
template <typename T>
void Character<T>::addItem(const std::string& theItem)
{
	if (m_amountOfItems < m_inventoryMaxItems) //if there's enough spaace
	{
		for (int i = 0; i < m_inventoryMaxItems; i++) {

			if (m_theInventory[i] == "[|NO ITEM|]") {

				printf("Item added \n");

				m_theInventory[i] = theItem;
				m_amountOfItems++;

				return;
			}
		}
	}
	else {
		printf("Inventory full \n");
	}
}

// Remove item based on its index
template <typename T>
bool Character<T>::removeItem(int index)
{
	if (index >= 0 && index < m_inventoryMaxItems && !(m_theInventory[index] == "[|NO ITEM|]")) {
		m_theInventory[index] = "[|NO ITEM|]";
		m_amountOfItems--;
		// printf("Item removed \n");
		return true;
	}
	else {
		printf("Unable to remove item with this index");
	}
	return false;
}

// Prints information of the character
template <typename T>
void Character<T>::info()
{
	typename std::array<T, 4>::iterator statPoint = m_stats.begin();

	printf("- stats -\n");
	printf("Health: %.2f\n", *statPoint); // JAN: do we need casts here?
	printf("Attack: %.2f\n", *(statPoint + 1));
	printf("Defense: %.2f\n", *(statPoint + 2));
	printf("Agility: %.2f\n", *(statPoint + 3));
	printf("Name: %s\n", m_name.c_str());
}

// Prints the entire inventory to the console
template <typename T>
void Character<T>::printItems()
{
	printf("Items:\n");

	for (int i = 0; i < m_inventoryMaxItems; ++i) {
		if (!m_theInventory[i].empty()) {
			printf("%d: %s\n", i, m_theInventory[i].c_str()); //c_str() converts the string to c-style string
		}
	}
}
