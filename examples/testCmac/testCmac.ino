#include <cmac.h>
#include <TI_aes_128.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  testCmac();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void testCmac() {
  unsigned char T[BLOCK_SIZE];
  const unsigned char T64[BLOCK_SIZE] = { 0x51, 0xf0, 0xbe, 0xbf, 0x7e, 0x3b, 0x9d, 0x92,
                                          0xfc, 0x49, 0x74, 0x17, 0x79, 0x36, 0x3c, 0xfe
                                        };
  const unsigned char M[64] = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96,
                                0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a,
                                0xae, 0x2d, 0x8a, 0x57, 0x1e, 0x03, 0xac, 0x9c,
                                0x9e, 0xb7, 0x6f, 0xac, 0x45, 0xaf, 0x8e, 0x51,
                                0x30, 0xc8, 0x1c, 0x46, 0xa3, 0x5c, 0xe4, 0x11,
                                0xe5, 0xfb, 0xc1, 0x19, 0x1a, 0x0a, 0x52, 0xef,
                                0xf6, 0x9f, 0x24, 0x45, 0xdf, 0x4f, 0x9b, 0x17,
                                0xad, 0x2b, 0x41, 0x7b, 0xe6, 0x6c, 0x37, 0x10
                              };
  const unsigned char key[BLOCK_SIZE] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6,
                                          0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c
                                        };

  const unsigned char key2[BLOCK_SIZE] = "password\0\0\0\0\0\0";
  const unsigned char M2[] = "1234567890;09876543";
  const unsigned char T2[BLOCK_SIZE] = { 0xef, 0xf2, 0x2d, 0x3a, 0x78, 0x7b,
                                         0xd8, 0xa5, 0x2b, 0xd4, 0x7e, 0xd5, 0x87, 0xd9, 0xb0, 0xd6
                                       };

  Serial.print("--------------------------------------------------\n");
  printBuffer("K", key, BLOCK_SIZE);

  /*
   unsigned char L[BLOCK_SIZE], K1[BLOCK_SIZE], K2[BLOCK_SIZE];
   Serial.print("\nSubkey Generation\n"); //TODO: restore
   //AES_128(key, const_Zero, L);
   Serial.print("AES_128(key,0) ");
   print128(L);
   Serial.print("\n");
   generate_subkey(key, K1, K2);
   Serial.print("K1             ");
   print128(K1);
   Serial.print("\n");
   Serial.print("K2             ");
   print128(K2);
   Serial.print("\n");
   */

  Serial.print("\nExample 1: len = 0\n");
  Serial.print("M              ");
  Serial.print("<empty string>\n");

  AES_CMAC(key, M, 0, T);
  printBuffer("AES_CMAC", T, BLOCK_SIZE);

  Serial.print("\nExample 2: len = 16\n");
  printBuffer("M", M, 16);
  AES_CMAC(key, M, 16, T);
  printBuffer("AES_CMAC", T, BLOCK_SIZE);
  Serial.print("\nExample 3: len = 40\n");
  Serial.print("M              ");
  printBuffer("M", M, 40);
  AES_CMAC(key, M, 40, T);
  printBuffer("AES_CMAC", T, BLOCK_SIZE);

  Serial.print("\nExample 4: len = 64\n");
  Serial.print("M              ");
  printBuffer("M", M, 64);
  AES_CMAC(key, M, 64, T);
  printBuffer("AES_CMAC", T, BLOCK_SIZE);

  Serial.print("AES_CMAC_CHECK: ");
  Serial.println(!AES_CMAC_CHECK(key, M, 64, T64) ? "OK" : "Failed");

  int ms2 = sizeof(M2) - 1;//-1 to remove the trailing /0.
  AES_CMAC(key2, M2, ms2, T);
  Serial.print("M2sz:");
  Serial.println(ms2);
  printBuffer("AES_CMAC", T, BLOCK_SIZE);
  Serial.print("AES_CMAC_CHECK: ");

  Serial.println(!AES_CMAC_CHECK(key2, M2, ms2, T2) ? "OK" : "Failed");
  Serial.print("--------------------------------------------------\n");
}

void printBuffer(const char* name, const byte* buf, byte len) {
  Serial.print(name);
  Serial.print(": ");
  for (int i = 0; i < len; i++) {
    Serial.print(buf[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
}
