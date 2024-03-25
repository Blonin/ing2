#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  // Ouvrir le fichier "toto" en lecture et écriture
  FILE *fichier = fopen("toto", "r+");
  if (fichier == NULL) {
    perror("fopen");
    exit(1);
  }

  // Écrire "123456789" dans le fichier
  fprintf(fichier, "123456789");
  fflush(fichier);

  // Forker un processus
  pid_t pid = fork();

  // Si erreur lors du fork
  if (pid < 0) {
    perror("fork");
    exit(1);
  }

  // Processus fils
  if (pid == 0) {
    // Écrire "ab" dans le fichier
    fseek(fichier, 0, SEEK_SET);
    fprintf(fichier, "ab");
    fflush(fichier);

    // Dormir pendant 1 seconde
    sleep(1);

    // Lire 2 caractères du fichier
    char c1, c2;
    fscanf(fichier, "%c%c", &c1, &c2);
    printf("Fils : %c%c\n", c1, c2);

  // Processus père
  } else {
    // Dormir pendant 1 seconde
    sleep(1);

    // Lire 2 caractères du fichier
    char c1, c2;
    fscanf(fichier, "%c%c", &c1, &c2);
    printf("Père : %c%c\n", c1, c2);

    // Écrire "AB" dans le fichier
    fseek(fichier, 0, SEEK_SET);
    fprintf(fichier, "AB");
    fflush(fichier);
  }

  // Fermer le fichier
  fclose(fichier);

  return 0;
}
