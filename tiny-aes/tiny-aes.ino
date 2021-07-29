#include "aes.hpp"

//#define CBC 1
//#define AES128 1

uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };

uint8_t iv[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f };

//uint8_t in[]  = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };

//uint8_t in[]  = { 'C','h', 'r', 'i', 's', 't', 'i', 'a', 'n' , ' ', ' ', ' ', ' ',' ', ' ', ' '};
//uint8_t in[]  = { 'H','i', ',', ' ', 'T', 'a', 't', 'i', '-' , 'B', 'o', 'y', '!',' ', ' ', ' '};
//uint8_t in[]  = { "Christian Bobsin" };
uint8_t in[]  = { "Christian       " };

int size = 16;
bool encript = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:  

  //Serial.write(in,9);


  if ( encript == false ) {
    struct AES_ctx ctx;
      
    AES_init_ctx_iv(&ctx, key, iv);
    AES_CBC_encrypt_buffer(&ctx, in, size);      

    encript = true;
  }
  else {
    struct AES_ctx ctx;  
    
    AES_init_ctx_iv(&ctx, key, iv);
    AES_CBC_decrypt_buffer(&ctx, in, size);   

    encript = false;
  }

  Serial.write(in,size);
  
  Serial.print('\n');
  //Serial.println(in,size);

  delay(3000);

}
