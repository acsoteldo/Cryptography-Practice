#include <stdio.h>
#include <stdlib.h>
#include <openssl/rc4.h>
#include<stdbool.h>
#include<string.h>
 
int main(int argc, char* argv[])
{

   unsigned char data[] = "PASSword123";
   RC4_KEY rc4_key;
   FILE * inFile;
   //define var from structure
   inFile = fopen("/home/ubuntu/cosc4380.txt", "rb+");
 
   fseek(inFile, 0, SEEK_END);
   int size = ftell(inFile); //check files
   
   unsigned char bufferIn[size];
   unsigned char bufferOut[size];
   
   rewind(inFile);
   fread(bufferIn, 1, size, inFile);
   rewind(inFile);
   //rc4 key setup
   RC4_set_key (&rc4_key, sizeof(data), data);
   //rc4 encryption
   RC4(&rc4_key, sizeof(bufferIn), bufferIn, bufferOut);
   //Print Plain
   printf("Plain text: %s\n", bufferIn);
   //print Cipher
   printf("Cipher text: %s\n", bufferOut);
   RC4_set_key (&rc4_key, sizeof(data), data);

   RC4 (&rc4_key, sizeof(bufferOut), bufferOut, bufferIn);
   printf ("Decrypted message: %s\n", bufferIn);
   return 0;
}
