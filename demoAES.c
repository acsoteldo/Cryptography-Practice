#include<stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>

int main(void)
{
	const unsigned char key[] = {
 	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
   	0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
   // text to encrypt and decrypt
   unsigned char text[]="helloworldaaaaaa";
   unsigned char enc_out[256]; 
   unsigned char dec_out[256]; 
 
   AES_KEY enc_key, dec_key;
 
   AES_set_encrypt_key(key, 256, &enc_key);
   AES_encrypt(text, enc_out, &enc_key);
 
   printf("Plaintext: %s\n", text);
   // printing encrypted data
   printf("Cipher text: %s\n", enc_out);
 
   // printing decrypted data
   AES_set_decrypt_key(key, 256, &dec_key);
   AES_decrypt(enc_out, dec_out, &dec_key); 
   printf("Decrypted message: %s\n", dec_out);
 
   exit(1);
}
