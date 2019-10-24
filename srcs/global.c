#include "linked_list.h"

t_cmd commands[MAX_COMMAND] = {
	{menu_help, "Help", "Show all command"},
	{menu_add_entrie, "Create", "Create a new string"},
	{print_entries, "Print", "Print all string"},
	{menu_copy, "Copy", "Create a copy of string"},
	{menu_concat, "Concatenate", "Concatenate 2 string. Delete the second."},
	{menu_insert, "Insert", "Insert string at one position. Should be between 1 and len of string"},
	{menu_delete_char, "Delete", "Delete char from string"},
	{menu_search, "Search", "List string that contain substring"},
	{menu_replace, "Replace", "Replace substring by another one"},
	{menu_import, "Import", "Create a string from file"},
	{menu_export, "Export", "Export string to file a string from file"},
	{0x0, "Exit", "Close program"},
};

t_list *lists = 0x0;