#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node *next;
};

struct linked_list {
    struct node *head;
};

void append(struct linked_list *list, char *data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (!list->head) {
        list->head = new_node;
        return;
    }

    struct node *curr = list->head;
    while (curr->next) {
        curr = curr->next;
    }
    curr->next = new_node;
}

void print_list(struct linked_list *list) {
    struct node *curr = list->head;
    while (curr) {
        printf("%s\n", curr->data);
        curr = curr->next;
    }
}

struct linked_list *build_path_linked_list() {
    char *path_var = getenv("PATH");
    if (!path_var) {
        return NULL;
    }

    char *path_dirs = strdup(path_var);
    char *save_ptr;
    char *path_dir = strtok_r(path_dirs, ":", &save_ptr);

    struct linked_list *linked_list = (struct linked_list *)malloc(sizeof(struct linked_list));
    linked_list->head = NULL;

    while (path_dir) {
        append(linked_list, path_dir);
        path_dir = strtok_r(NULL, ":", &save_ptr);
    }

    free(path_dirs);
    return linked_list;
}

int main() {
    struct linked_list *linked_list = build_path_linked_list();
    if (linked_list) {
        print_list(linked_list);
        free(linked_list);
    } else {
        printf("PATH environment variable not set.\n");
    }
    return 0;
}
