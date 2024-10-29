#include "deck.h"


/**
 * str_cmp - function that compares two strings
 * @str1: string to be compared
 * @str2: string to be compared
 * Return: 0 if true
 */
int str_cmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
		str1++, str2++;

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}


/**
 * get_value - Returns the numeric value of a card.
 * @card: Pointer to the card.
 *
 * Return: Numeric value of the card.
 */
char get_value(deck_node_t *card)
{
	if (str_cmp(card->card->value, "Ace") == 0)
		return (0);
	if (str_cmp(card->card->value, "1") == 0)
		return (1);
	if (str_cmp(card->card->value, "2") == 0)
		return (2);
	if (str_cmp(card->card->value, "3") == 0)
		return (3);
	if (str_cmp(card->card->value, "4") == 0)
		return (4);
	if (str_cmp(card->card->value, "5") == 0)
		return (5);
	if (str_cmp(card->card->value, "6") == 0)
		return (6);
	if (str_cmp(card->card->value, "7") == 0)
		return (7);
	if (str_cmp(card->card->value, "8") == 0)
		return (8);
	if (str_cmp(card->card->value, "9") == 0)
		return (9);
	if (str_cmp(card->card->value, "10") == 0)
		return (10);
	if (str_cmp(card->card->value, "Jack") == 0)
		return (11);
	if (str_cmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}


/**
 * insertion_sort_deck_kind - Sorts a deck
 *		of cards by kind using insertion sort.
 *
 * @deck: Pointer to the deck.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}


/**
 * insertion_sort_deck_value - Sorts a deck of cards
 *		by value using insertion sort.
 *
 * @deck: Pointer to the deck.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
		       insert->card->kind == iter->card->kind &&
		       get_value(insert) > get_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}



/**
 * sort_deck - Sorts a deck of cards first by kind, then by value.
 * @deck: Pointer to the deck.
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !*deck || !(*deck)->next)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
