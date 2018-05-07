/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			general.h
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * General usable definitions.
 * ----------------------------------------------------------
 */
#ifndef ___GENERAL_H
#define ___GENERAL_H

/** Convenience macro do get maximum of two numbers */
#define MAX(x, y) ((x) > (y) ? (x) : (y))
/** Convenience macro do get maximum of two numbers */
#define MIN(x, y) ((x) < (y) ? (x) : (y))

/**
*
*/
void init_free_list();
void sfree(void* address);
void** get_free_list();
int get_free_list_length();
#endif
