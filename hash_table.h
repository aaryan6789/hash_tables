/*
 * hash_table.h
 *
 *  Created on: Jan 7, 2018
 *      Author: hsahu
 */

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

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



// ====== Hash Table Operations ==================
// 1. Each Hash Table needs a Hash Function
unsigned int hash_function(struct hash_table *ht, int key);
struct hash_table* create_ht(int size);
void ht_insert(struct hash_table *ht, int key);
void ht_remove(struct hash_table *ht, int key);
int ht_search(struct hash_table *ht, int key);




#endif /* HASH_TABLE_H_ */
