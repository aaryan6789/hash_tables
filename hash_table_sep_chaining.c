/* hash_table_sep_chaining.c *      Author: hsahu */
#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
/*
// Array of Linked Lists.
// ======= Hash Table Structures ================
struct ht_node{
	int key;			// Key
	//int value;			// Value
	struct ht_node* next;	// Pointer to the next element is the list
};

struct hash_table{
	int table_size;			// Size of the Hash Table
	int element_count;		// Count of the number of elements
	struct ht_node** ht_node_list;
};
*/

/**
 * create_ht - Create a new Hash Table
 * It creates a new hash table by allocating memory as big as the size.
 */
struct hash_table* create_ht(int size){
	// Allocate Memory to the HASH TABLE
	struct hash_table *ht = (struct hash_table *)malloc(sizeof(struct hash_table));
	if(!ht){
		printf("malloc error on ht.\n");
		return NULL;
	}

	// Set size of the table as per the asked size
	ht->table_size = size;

	// Establish separate chaining by allocating memory for each of the node in the table
	ht->ht_node_list = (struct ht_node**)malloc(size * sizeof(struct ht_node));
	if(!ht->ht_node_list){
		printf("malloc error on ht->ht_node_list.\n");
		return NULL;
	}

	ht->element_count = 0;

	// 1. Allocate memory for each linked list node of the hash table.
	// 2. Initialize each node of the Hash table with NULL
	for(int i = 0; i<size; i++){
		ht->ht_node_list[i] = (struct ht_node *)malloc(sizeof(struct ht_node));
		if(!ht->ht_node_list[i]){
			printf("malloc error on ht->ht_node_list[%d].\n", i);
			return NULL;
		}
		ht->ht_node_list[i] = NULL;
	}

	printf("Hash Table of size %d is created.\n", size);
	return ht;
}

/**
 *  hash_function - Hash Function
 *  It will run the Key value and transforms it into a value to be represented in the
 *  Array as an index.
 */
unsigned int hash_function(struct hash_table *ht, int key){
	int hash = key;

	//hash = (hash >> 3) * 2654435761;		// Knuth's Math Method

	hash = hash / (ht->table_size);			// Divide by table size to fit in table boundaries

	printf("The hash_index for key %d is %d\n", key, hash);
	return hash;							// Index in the table returned
}

/**
 * ht_insert - Insert a key in the hash table
 * In separate chaining Hash table insertion the new key will be inserted in the
 * linked list at the front of the hash value slot for that key.
 */
void ht_insert(struct hash_table *ht, int key){

	// Get the hash slot for the key
	unsigned int hash_index = hash_function(ht, key);
	printf("Hash_index = %d for key = %d\n", hash_index, key);

	// Get the linked list node of the hash slot
	struct ht_node *new_ht_node = ht->ht_node_list[hash_index];

	// Insert the key at its slot now
	// Create a New Node
	new_ht_node = (struct ht_node*)malloc(sizeof(struct ht_node));

	new_ht_node->key = key;
	new_ht_node->next = ht->ht_node_list[hash_index];
	ht->ht_node_list[hash_index] = new_ht_node;

	// Increment the count of the hash table elements
	ht->element_count++;

	printf("Inserted %d on the hash map at %d\n Element count %d\n",
			key, hash_index, ht->element_count);

	return;
}

/**
 * ht_search - Search for a key in the hash table
 * In separate chaining Hash table searching for a key will be in the
 * linked list at the hash value slot for that key.
 */
int ht_search(struct hash_table *ht, int key){
	printf("Searching %d key in the hash table\n", key);

	// Get the hash index for the key
	unsigned int hash_index = hash_function(ht, key);

	struct ht_node *ht_node = ht->ht_node_list[hash_index];

	if (ht_node != NULL){
		// If the Linked list is not empty then lest look for the key now.
		while (ht_node != NULL){
			if(ht_node->key == key){
				printf("Key found at hash_index %d\n", hash_index);
				return 1;
			}
			ht_node = ht_node->next;
		}
	}
	else{
		printf("Key %d Not found.\n", key);
		return 0;
	}

	return 0;
}

/**
 * ht_remove - Remove a key in the hash table
 * When removing from a separately chained hash table, a search is required for
 * the old key. Fortunately, this is the hardest part of the algorithm and the
 * key is gone, which is a welcome change from the other collision resolution strategies.
 */
void ht_remove(struct hash_table *ht, int key){
	printf("Removing %d key from the hash table\n", key);
	// Get the hash index for the key
	unsigned int hash_index = hash_function(ht, key);
	int found = ht_search(ht, key);
	struct ht_node *ht_node =  ht->ht_node_list[hash_index];
	int count = 0;

	if(found && ht_node != NULL){
		// Remove the node from the hash Index
		while (ht_node->key != key){
			ht_node = ht_node->next;
			count++;
		}

		printf("ht_node->key = %d count %d ht_node->next->key %d\n", ht_node->key, count, ht_node->next->key);

		if(ht_node->next == NULL){
			free(ht_node);
			ht->element_count--;
			return;
		}

		struct ht_node *next_node = ht_node->next;
		ht_node->key = next_node->key;
		ht_node->next = next_node->next;
		free(next_node);
		ht->element_count--;

		printf("Deleted %d key from the hash table. Elem_count %d\n", key, ht->element_count);
		return;
	}
	else{
		return;
	}

}


