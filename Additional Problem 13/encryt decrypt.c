#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Xor(char *line, int key){
    for (int i = 0; line[i] != '\0'; i++) {
      line[i] = line[i] ^ key;
    }
}
void Not(char *line){
    for (int i = 0; line[i] != '\0'; i++) {
      line[i] = ~line[i];
    }
}
int main() {
    char text[1000];
    int choice, key, again;
    
    // Prompt the user to enter a text.
    printf("Enter a text: ");
    fgets(text, 1000, stdin);

    // Prompt the user to choose encryption or decryption way.
    printf("Choose encryption or decryption:\n1) XOR each character with a specified key.\n2) Invert each character bit by bit.\n (1/2): ");
    scanf("%d", &choice);
    
    // Perform the operation.
    if (choice == 1) {
            
    // XOR each character with a specified number from the user.
    printf("Enter a key: ");
    scanf("%d", &key);
    Xor(text,key);
  } else if (choice == 2) {
      
    // Invert each character bit by bit.
    Not(text);
  }
  
    // Print the encrypted/decrypted text.
    printf("Encrypted/Decrypted text: %s\n", text);
    
    // Prompt the user to perform the inverse operation again.
    printf("Do you want to perform the inverse operation again (1/0): ");
    scanf("%d", &again);
    while(again){

    // Perform the inverse operation.
    if (choice == 1) {
            
      // XOR each character with the key again.
      Xor(text,key);
    } else if (choice == 2) {
        
      // Invert each character bit by bit again.
      Not(text);
    }

    // Print the decrypted text.
    printf("Decrypted text: %s\n", text);
    printf("Do you want to perform the inverse operation again (1/0): ");
    scanf("%d", &again);
  }

  return 0;
}