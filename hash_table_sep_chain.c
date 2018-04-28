/*
 hash_table_1.c *      Author: hsahu
#include <stdlib.h>
#include <stdio.h>

// Hash Table by "Arrays with Separate Chaining"
// i.e Each node in the array is a Linked List.

 Create a Hash table of given size

// List of Lists
// HashTable is a Linked List whose each node is representing a Linked List for
// chaining,

#define MAX_SIZE 20

struct node {
	int key;
	int data;
	struct node* next;
};

struct hash_table_node{
	int element_count;			// number of elements in the list
	struct node* next;
};

struct hash_table{
	int ht_size;		// Size of the hash table
	int count;			// Number of elements in the table
	struct hash_table_node **table;
};

*
 * create_hash_table - Creates a hash table of size n

struct hash_table *create_hash_table(int size){
	struct hash_table *ht;
	ht = (struct hash_table *)malloc(sizeof(struct hash_table));

	ht->ht_size = size;
	ht->count = 0;
	ht->table = (struct hash_table_node **)malloc(sizeof(struct hash_table_node*)*ht->ht_size);

	// Initialize each node as an empty linked list
	for(int i = 0; i<size; i++){
		ht->table[i]->next = NULL;
		ht->table[i]->element_count = 0;
	}

	return ht;
}

int hash_code(struct hash_table *ht, int key){
	if(key < 0)
		return -(key % (ht->ht_size));

    return (key%(ht->ht_size));
}

int hash_insert(struct hash_table *ht, int data){
	int index;
	struct node *temp, *newNode;

	index = hash_code(data, ht->ht_size);
	temp = ht->table[index]->next;

	newNode = (struct node*)malloc(sizeof(struct node));

	newNode->key = index;
	newNode->data = data;
	newNode->next = temp;

	ht->table[index]->next = newNode;
	ht->table[index]->element_count++;

	ht->count++;

	if(ht->count/ht->ht_size > MAX_SIZE)
		//Regenerate the hash_code

	return 1;
}
*/
