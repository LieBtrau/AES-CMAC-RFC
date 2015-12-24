# AES-CMAC-RFC
AES-CMAC implementation from [RFC4493](http://tools.ietf.org/html/rfc4493):

AES-CMAC is appropriate for information systems in which AES is more readily available than a hash function.
This memo specifies the authentication algorithm based on CMAC with AES-128.

AES-CMAC uses the Advanced Encryption Standard [NIST-AES] as a building block.  To generate a MAC, AES-CMAC takes a secret key, a message of variable length, and the length of the message in octets as inputs and returns a fixed-bit string called a MAC.
