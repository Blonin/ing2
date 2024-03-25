#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 2048

void main() {
  char line[MAX_LINE];
  pid_t pid;

  while (1) {
    // Lire la ligne de commande
    printf("> ");
    fgets(line, MAX_LINE, stdin);

    // Analyser la ligne de commande (on ne s'en occupe pas ici)

    // Découper la ligne en arguments
    char *argv[MAX_LINE / 2];
    int argc = 0;
    char *token = strtok(line, " ");
    while (token != NULL) {
      argv[argc++] = token;
      token = strtok(NULL, " ");
    }

    // Si la commande est "exit", quitter le shell
    if (strcmp(argv[0], "exit") == 0) {
      break;
    }

    // Forker un processus
    pid = fork();

    // Si erreur lors du fork
    if (pid < 0) {
      perror("fork");
      exit(1);
    }

    // Processus fils
    if (pid == 0) {
      // Exécuter la commande
      execvp(argv[0], argv);

      // Si la commande n'existe pas
      perror(argv[0]);
      exit(1);
    }

    // Processus père
    else {
      // Attendre la fin du processus fils
      wait(NULL);
    }
  }
}
