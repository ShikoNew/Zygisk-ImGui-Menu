#pragma once
#ifndef ZYCHEATS_Struct
#define ZYCHEATS_Struct


///bugg


struct CryptoBool {
    unsigned char a;
    unsigned char b;
    bool c;
};

struct CryptoInt {
    int a;
    int b;
    bool c;
};

struct CryptoFloat {
    int a;
    int b;
    bool c;
};


struct ObscuredInt{
    int cryptoKey;
    int currentCryptoKey;
    int hiddenValue;
    bool inited;
    int fakeValue;
    bool fakeValueActive;
};
#endif
