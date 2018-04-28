/*
 * main.c
 *
 *  Created on: Jan 7, 2018
 *      Author: hsahu
 */
#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"




int main(){

	struct hash_table *ht = NULL;
	ht = create_ht(10);
	ht_insert(ht, 10);
	ht_insert(ht, 11);
	ht_insert(ht, 12);
	ht_insert(ht, 20);
	ht_insert(ht, 30);
	ht_search(ht, 50);
	ht_search(ht, 10);
	//ht_search(ht, 52);
	ht_remove(ht, 52);
	ht_remove(ht, 11);
	//ht_remove(ht, 10);

	return 0;

}
